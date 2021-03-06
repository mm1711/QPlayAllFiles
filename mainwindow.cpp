/*! \file  mainwindow.cpp

Implementation of QMainWindow GUI class.
Implements all application logic.

<b>Copyright   :</b> (C) 2019 Michael Moser

<b>Last edit	:</b>

<b>History   :</b>
26-09-2019mm	creation by Michael Moser
13-05-2020mm  New setting members: m_bar_numerator, m_bar_denominator, m_shortest_note and m_bar_accent
              Use QT_NO_DEBUG for qDebug() outputs


*/

/**
 ** This file is part of the QPlayAllFiles project.
 ** Copyright 2019 Michael Moser mmoser@moser-engineering.de.
 **
 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/

#include "mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

  QCoreApplication::setOrganizationName("moser-engineering");
  QCoreApplication::setOrganizationDomain("moser-engineering.de");
  QCoreApplication::setApplicationName(qApp->applicationName());

  m_prng.securelySeeded();

  app_caption = qApp->applicationName() + " V";
  setWindowTitle( app_caption + version);

  m_settings.m_current_max_channels = c_max_channel_count;
  m_settings.m_BPM = c_BMP;
  m_settings.m_Staccato = c_Staccato;
  m_settings.m_Loop = c_Loop;
  m_settings.m_FirstSegment = 0;
  m_settings.m_LastSegment = 0;
  m_settings.m_audio_interface = "";
  m_settings.m_audio_codec = "";
  m_settings.m_audio_container = "";
  m_settings.m_audio_sample_rate = c_audio_sample_rate;


  m_buffer_read_size = (m_settings.m_max_segments*m_settings.m_current_max_channels );
  m_buffer = (char *)malloc(m_buffer_read_size);

  m_current_scale = 0;
  m_current_mode = 0;

  QSettings settings;
  m_last_config_file = settings.value("last_config_file", "").toString();
  if(!m_last_config_file.isEmpty())
  {
    QFileInfo fi(m_last_config_file);
    m_last_config_path = fi.path();
  }
  else
  {
    m_last_config_path = QString(".");
  }
  m_last_data_path = settings.value("last_data_path", ".").toString();


  m_playing = false;
  m_init_play = true;

  setupGUI();


  setCentralWidget(centralwidget);

  m_bits_to_bytes = new CBitsToBytes(c_input_buffer_size);

  m_midi_out = nullptr;

  m_midi_clock = new QTimer(this);
  m_midi_clock->setSingleShot(true);
  connect(m_midi_clock, SIGNAL(timeout()), this, SLOT(midi_clock_timeout()));

  m_audioRecorder = new QAudioRecorder(this);

  connect(m_audioRecorder, &QAudioRecorder::durationChanged, this, &MainWindow::updateProgress);
  connect(m_audioRecorder, &QAudioRecorder::statusChanged, this, &MainWindow::updateStatus);
  connect(m_audioRecorder, QOverload<QMediaRecorder::Error>::of(&QAudioRecorder::error), this,
          &MainWindow::displayErrorMessage);


  if(!m_last_config_file.isEmpty())
  {
    loadConfig(m_last_config_file);
  }

}

MainWindow::~MainWindow()
{
  stop_audio_recording();

  closeMIDI();
  closeFile();
  if(m_buffer != nullptr)
  {
    free(m_buffer);
  }
}

/*! Setup User Interface


<b>History   :</b>
20-05-2020mm		created by Michael Moser
*/
void MainWindow::setupGUI()
{

  setupActions();

  centralwidget = new QWidget(this);
  scrollArea = new QScrollArea(centralwidget);
  scrollArea->setGeometry(QRect(0, 0, 1600, 950));
  scrollArea->setMaximumSize(QSize(1600, 950));
  scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
  scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

  scrollAreaWidgetContents = new QWidget();

  QGridLayout *mainGridLayout = new QGridLayout();

  QGridLayout *infoGridLayout = new QGridLayout();
  info_0_0 = new QLabel();
  info_0_0->setText(tr("BPM"));
  infoGridLayout->addWidget(info_0_0, 0, 0);
  info_0_1 = new QLabel();
  info_0_1->setNum(m_settings.m_BPM);
  infoGridLayout->addWidget(info_0_1, 0, 1);
  info_0_2 = new QLabel();
  info_0_2->setText(tr("Shortest"));
  infoGridLayout->addWidget(info_0_2, 0, 2);
  info_0_3 = new QLabel();
  info_0_3->setText(tr("1/%1").arg(m_settings.m_shortest_note));
  infoGridLayout->addWidget(info_0_3, 0, 3);
  info_1_0 = new QLabel();
  info_1_0->setText(tr("Measure"));
  infoGridLayout->addWidget(info_1_0, 1, 0);
  info_1_1 = new QLabel();
  info_1_1->setText(tr("%1/%2").arg(m_settings.m_bar_numerator)
                               .arg(m_settings.m_bar_denominator));
  infoGridLayout->addWidget(info_1_1, 1, 1);
  info_1_2 = new QLabel();
  info_1_2->setText(tr("Max.Segs"));
  infoGridLayout->addWidget(info_1_2, 1, 2);
  info_1_3 = new QLabel();
  info_1_3->setNum(m_settings.m_max_segments);
  infoGridLayout->addWidget(info_1_3, 1, 3);

/*
  QSpacerItem *horizontalSpacer1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

  mainGridLayout->addItem(horizontalSpacer1, 0, 0);
*/
  mainGridLayout->addLayout(infoGridLayout, 0, 0);

  QGridLayout *gridLayout = new QGridLayout();
  gridLayout->setContentsMargins(6, 6, 6, 6);
  gridLayout->setSpacing(10);

  label_currGroupBox = new QLabel();
  label_currGroupBox->setText(tr("Group"));
  gridLayout->addWidget(label_currGroupBox, 0, 0);

  currGroupBox = new QLineEdit();
  currGroupBox->setText("0");
  currGroupBox->setMaximumWidth(50);
  gridLayout->addWidget(currGroupBox, 1, 0);

  label_KeysComboBox = new QLabel();
  label_KeysComboBox->setText(tr("Scale"));
  gridLayout->addWidget(label_KeysComboBox, 0, 1);

  KeysComboBox = new QComboBox();
  KeysComboBox->addItems(c_scale_Names);
  KeysComboBox->setMaximumWidth(150);
  gridLayout->addWidget(KeysComboBox, 1, 1);

  label_ModesComboBox = new QLabel();
  label_ModesComboBox->setText(tr("Mode"));
  gridLayout->addWidget(label_ModesComboBox, 0, 2);

  ModesComboBox = new QComboBox();
  ModesComboBox->addItems(c_scale_Modes);
  ModesComboBox->setMaximumWidth(200);
  gridLayout->addWidget(ModesComboBox, 1, 2);

  label_octaveComboBox  = new QLabel();
  label_octaveComboBox->setText(tr("Octave"));
  gridLayout->addWidget(label_octaveComboBox, 0, 3);

  octaveComboBox = new QComboBox();
  octaveComboBox->addItems(c_octaves);
  octaveComboBox->setCurrentIndex(2);
  octaveComboBox->setMaximumWidth(100);
  gridLayout->addWidget(octaveComboBox, 1, 3);

  btnSetNotes = new QPushButton();
  btnSetNotes->setText(tr("Set Notes"));
  btnSetNotes->setMaximumWidth(150);
  gridLayout->addWidget(btnSetNotes, 1, 4);

  record_checkBox = new QCheckBox();
  record_checkBox->setText(tr("Record"));
  record_checkBox->setMaximumWidth(150);
  gridLayout->addWidget(record_checkBox, 1, 5);

  playBtn = new QPushButton();
  QIcon icon;
  icon.addFile(QString::fromUtf8(":/images/media-play-32.png"), QSize(), QIcon::Normal, QIcon::Off);
  playBtn->setIcon(icon);
  playBtn->setIconSize(QSize(16, 16));
  playBtn->setMaximumWidth(50);
  gridLayout->addWidget(playBtn, 1, 6);

  stopBtn = new QPushButton();
  QIcon icon1;
  icon1.addFile(QString::fromUtf8(":/images/media-stop-32.png"), QSize(), QIcon::Normal, QIcon::Off);
  stopBtn->setIcon(icon1);
  stopBtn->setIconSize(QSize(16, 16));
  stopBtn->setMaximumWidth(50);
  gridLayout->addWidget(stopBtn, 1, 7);

  mainGridLayout->addLayout(gridLayout, 0, 1);

  connect(btnSetNotes, SIGNAL(clicked()), this, SLOT(on_btnSetNotes_clicked()));
  connect(playBtn, SIGNAL(clicked()), this, SLOT(on_playBtn_clicked()));
  connect(stopBtn, SIGNAL(clicked()), this, SLOT(on_stopBtn_clicked()));

  setupChannels(c_max_channel_count);

  mainGridLayout->addWidget(m_channels, 1, 0);

  m_segmentRenderArea = new CSegmentRenderArea(nullptr, c_max_visible_segments, c_max_channel_count);
  m_segmentRenderArea->setPen(QPen(Qt::gray));
  m_segmentRenderArea->setBrush(QBrush(Qt::lightGray));
  m_segmentRenderArea->setChannelHeight(m_channels->getChannelHeight());

  setupControls();

  mainGridLayout->addWidget(m_segmentRenderArea, 1, 1);

  scrollAreaWidgetContents->setLayout(mainGridLayout);

  scrollArea->setWidget(scrollAreaWidgetContents);

  qint32 render_width = m_segmentRenderArea->geometry().x()+m_segmentRenderArea->geometry().width();
  qint32 render_height = m_channels->size().height() + m_channels->geometry().y();

#ifndef QT_NO_DEBUG
  qDebug("render width=%d render height=%d", render_width, render_height);
#endif

  // next 2 lines necessary for scrolling
  scrollArea->setWidgetResizable(false);
  scrollAreaWidgetContents->setGeometry(0,0, render_width, render_height);

  setMaximumWidth(1600);
  setMaximumHeight(1100);

  resize(1600, 1100);
}

void MainWindow::setupActions()
{
  actionOpen = new QAction(this);
  actionClose = new QAction(this);
  actionNew_Config = new QAction(this);
  actionOpen_Config = new QAction(this);
  actionSave_Config = new QAction(this);
  actionSave_Config_As = new QAction(this);
  actionSettings = new QAction(this);
  actionMIDI_Instruments = new QAction(this);

  actionNew_Config->setText(tr("New Config"));
  actionOpen_Config->setText(tr("Open Config"));
  actionSave_Config->setText(tr("Save Config"));
  actionOpen->setText(tr("&Open File"));
  actionClose->setText(tr("Close File"));
  actionSettings->setText(tr("Settings"));
  actionMIDI_Instruments->setText(tr("MIDI Instruments"));
  actionSave_Config_As->setText(tr("Save Config As"));


  menubar = new QMenuBar(this);
  menubar->setGeometry(QRect(0, 0, 1500, 21));
  menuFile = new QMenu(menubar);
  menuFile->setTitle(tr("File"));
  menuSettings = new QMenu(menubar);
  menuSettings->setTitle(tr("Extras"));
  setMenuBar(menubar);
  m_statusbar = new QStatusBar(this);
  setStatusBar(m_statusbar);

  menubar->addAction(menuFile->menuAction());
  menubar->addAction(menuSettings->menuAction());
  menuFile->addAction(actionOpen);
  menuFile->addAction(actionClose);
  menuFile->addSeparator();
  menuFile->addAction(actionNew_Config);
  menuFile->addAction(actionOpen_Config);
  menuFile->addAction(actionSave_Config);
  menuFile->addAction(actionSave_Config_As);
  menuSettings->addAction(actionSettings);
  menuSettings->addAction(actionMIDI_Instruments);

  connect(actionOpen, SIGNAL(triggered()), this, SLOT(on_actionOpen_triggered()));
  connect(actionClose, SIGNAL(triggered()), this, SLOT(on_actionClose_triggered()));
  connect(actionNew_Config, SIGNAL(triggered()), this, SLOT(on_actionNew_Config_triggered()));
  connect(actionOpen_Config, SIGNAL(triggered()), this, SLOT(on_actionOpen_Config_triggered()));
  connect(actionSave_Config, SIGNAL(triggered()), this, SLOT(on_actionSave_Config_triggered()));
  connect(actionSave_Config_As, SIGNAL(triggered()), this, SLOT(on_actionSave_Config_As_triggered()));
  connect(actionSettings, SIGNAL(triggered()), this, SLOT(on_actionSettings_triggered()));
  connect(actionMIDI_Instruments, SIGNAL(triggered()), this, SLOT(on_actionMIDI_Instruments_triggered()));
}
/*! Resize Window

  Event which is fired upon resizing of application main window.
  The size of the scrollArea is adapted to the new size

  \param event    QResizeEvent* from Qt framework

<b>History   :</b>	 01-11-2019mm		created by Michael Moser
*/
void MainWindow::resizeEvent(QResizeEvent* event)
{
  QMainWindow::resizeEvent(event);
  qDebug("resizeEvent: width=%d height=%d", width(), height());
  if(scrollArea != nullptr)
  {
    scrollArea->resize(width(), height()-40);
  }
}

/*! Setup the GUI controls


<b>History   :</b>	 26-09-2019mm		created by Michael Moser
*/
void MainWindow::setupControls()
{
  m_status_bar_label_recording = new QLabel(this);
  m_status_bar_label_recording->setText(tr("Record to: "));
  statusBar()->addPermanentWidget(m_status_bar_label_recording);

  m_status_bar_label = new QLabel(this);
  m_status_bar_label->setText(QString(tr("Current Segment: %1")).arg(0, 16));
  statusBar()->addPermanentWidget(m_status_bar_label);
}

/*! Setup all channels

  Create and setup all channels

  \param max_channels    max. channels

<b>History   :</b>	 26-09-2019mm		created by Michael Moser
*/
void  MainWindow::setupChannels(qint32 max_channels)
{
  int ix;

  qint32 midi_start_note = octaveComboBox->currentIndex() * 12;

  m_channels = new CChannelProperties(nullptr, max_channels);

  for (ix = 0; ix < max_channels; ix++)
  {
//    qDebug("chn=%d y_pos=%d", ix, y_pos);
    m_channels->setNoteIndex(ix, midi_start_note + ix);
  }

  // Resize channels widget
//  QSize s = parent->size();
//  parent->resize(s.width(), ((m_channels->getChannelHeight()+1)*c_max_channel_count));
/*
  s = parent->size();
  qDebug("new size: (%d, %d) calculated height=%d", s.width(), s.height(), (c_channels_y_pos_start+(height+1)*c_max_channel_count));
*/
}


/*! Set the notes per channel

  Set the notes per channel according to the settings
  of the start octave, the key and the mode

<b>History   :</b>	 26-09-2019mm		created by Michael Moser
*/
void MainWindow::on_btnSetNotes_clicked()
{
  int ch_ix;
  int ix;
  int octave_ix = 0;

  qint32 midi_start_note = octaveComboBox->currentIndex() * 12;

  m_current_scale = KeysComboBox->currentIndex();
  m_current_mode = ModesComboBox->currentIndex();

  if ( m_current_scale == 0)
  {
    // chromatic scale selected.
    for (ch_ix = 0; ch_ix < c_max_channel_count; ch_ix++)
    {
      if(m_channels->getCurrentGroup(ch_ix) == currGroupBox->text().toInt())
      {
        int note_ix = (midi_start_note + ch_ix) % c_max_channel_count;
        m_channels->setNoteIndex(ch_ix, note_ix);
      }
    }
  }
  else
  {
    ix = c_start_notes[m_current_scale];
    for (ch_ix = 0; ch_ix < c_max_channel_count; ch_ix++)
    {
      if(m_channels->getCurrentGroup(ch_ix) == currGroupBox->text().toInt())
      {
        int note_ix = midi_start_note + ix;
        if(note_ix >= c_max_channel_count)
        {
          ix = c_start_notes[m_current_scale];
          note_ix = midi_start_note + ix;
          qDebug("note_ix=%d", note_ix);
        }
        m_channels->setNoteIndex(ch_ix, note_ix);
        ix += c_scale_pattern[m_current_mode][octave_ix];
        if (ix > c_max_channel_count)
        {
          ix = c_max_channel_count;
        }
        octave_ix++;
        octave_ix %= 7;
      }
    }
  }
}

/*! Handle the File -> Open Data action

  Ask for a filename and call subroutine openFile()

<b>History   :</b>	 26-09-2019mm		created by Michael Moser
*/
void MainWindow::on_actionOpen_triggered()
{

  m_filename = QFileDialog::getOpenFileName(this, tr("Open File to Play"), m_last_data_path);

  if(!m_filename.isEmpty())
  {
    QFileInfo fi(m_filename);
    m_last_data_path = fi.path();

    QSettings settings;
    settings.setValue("last_data_path", m_last_data_path);

    openFile();
  }
}

/*! Open the data file

  Open the data file and fill the input buffer with initial data
  Pass the data to the m_segmentRenderArea widget to show it graphically
  Update the maximum availabel segment count and initiallize m_LastSegment
  with this value.
  Show the file path in the window header

  \return true  file opened successfully
  \return false file open failed

<b>History   :</b>	 26-09-2019mm		created by Michael Moser
*/
bool MainWindow::openFile()
{
  if(m_bits_to_bytes->openBitFile(m_filename))
  {
    setWindowTitle(app_caption + version + " - " + m_filename);

    if(m_buffer != nullptr)
    {
      free(m_buffer);
    }
    m_segmentRenderArea->setChannelCount(m_settings.m_current_max_channels);
    m_buffer_read_size = m_settings.m_current_max_channels * 2*m_settings.m_max_segments;
    m_buffer = (char *)malloc(m_buffer_read_size);

    m_bits_to_bytes->readBitsAsBytes(m_buffer, static_cast<quint32>(m_buffer_read_size));

    m_segmentRenderArea->setData(m_buffer, 2*m_settings.m_max_segments);

    m_settings.m_LastSegment = (m_bits_to_bytes->getFileSize() / m_settings.m_current_max_channels);
    return true;
  }
  else
  {
    // open file failed
    QMessageBox::critical(this, qApp->applicationName(), tr("Cannot open input file!"));
    return false;
  }
}

/*! Handle the File -> Close Data action

  Call closeFile() subroutine

<b>History   :</b>	 26-09-2019mm		created by Michael Moser
*/
void MainWindow::on_actionClose_triggered()
{
  closeFile();
}

/*! Close the data file


<b>History   :</b>	 26-09-2019mm		created by Michael Moser
*/
void MainWindow::closeFile()
{
  m_bits_to_bytes->closeBitFile();
  setWindowTitle(app_caption + version);
}

/*! Open the MIDI interface

  Create a new instance of QMidiOut and connect it to the selected MIDI interface
  The MIDI interface is selected in File -> Settings

  \return true  MIDI interface opened successfully
  \return false MIDI interface open failed

<b>History   :</b>	 26-09-2019mm		created by Michael Moser
*/
bool MainWindow::openMIDI()
{
  if(m_midi_out != nullptr)
  {
    delete m_midi_out;
    m_midi_out = nullptr;
  }

  if(!m_settings.m_midi_out_name.isEmpty())
  {
    m_midi_out = new QMidiOut();
    if(m_midi_out != nullptr)
    {
      return m_midi_out->connect(m_settings.m_midi_out_name);
    }
    else
    {
      QMessageBox::critical(this, qApp->applicationName(), tr("Cannot create MIDI interface"));
      return false;
    }
  }
  else
  {
    QMessageBox::critical(this, qApp->applicationName(), tr("No MIDI interface selected (Extras -> Settings)"));
    return false;
  }
}

/*! Close the MIDI interface

  Disconnect the selected MIDI interface and destroy the QMidiOut instance

<b>History   :</b>	 26-09-2019mm		created by Michael Moser
*/
void MainWindow::closeMIDI()
{
  if(m_midi_out != nullptr)
  {
    m_midi_out->disconnect();
    delete m_midi_out;
    m_midi_out = nullptr;
  }
}

/*! Set the tone state for all channels to false


<b>History   :</b>	 26-09-2019mm		created by Michael Moser
*/
void MainWindow::clear_tone_state()
{
  for(int ix = 0; ix <   m_settings.m_current_max_channels; ix++)
  {
    m_channels->setChannelState(ix, false);
  }
}

/*! Position the segment in m_segmentRenderArea

  Update the current channel count and calculate the new bit position
  Read the bits starting with bit_pos from data file
  Pass the data to the m_segmentRenderArea widget to show it graphically

  \param segment  new start segment

<b>History   :</b>	 26-09-2019mm		created by Michael Moser
*/
void MainWindow::position_segment(qint64 segment)
{
  m_segmentRenderArea->setChannelCount(  m_settings.m_current_max_channels);
  qint64 bit_pos = segment *   m_settings.m_current_max_channels;
  m_bits_to_bytes->set_bit_position(bit_pos);
  m_buffer_read_size =   m_settings.m_current_max_channels * 2*m_settings.m_max_segments;
  m_bits_to_bytes->readBitsAsBytes(m_buffer, static_cast<quint32>(m_buffer_read_size));
  m_segmentRenderArea->setData(m_buffer, 2*m_settings.m_max_segments);
}

/*! Play button has been clicked

  Check whether data file is open
  Open the MIDI interface
  If not already playing change icon to PAUSE symbol
  Clear the tone states and init the MIDI instruments per channel
  Initialize start, last und current segment numbers
  Position data to current segment number
  Start or resume audio recording if record checkbox is checked
  Start the MIDI timer

  If playing was already active go to pause mode
  Set the icon to PLAY symbol
  Stop the MIDI timer
  Pause audio recording

<b>History   :</b>	 26-09-2019mm		created by Michael Moser
*/
void MainWindow::on_playBtn_clicked()
{
  QIcon icon;

  if(m_bits_to_bytes->isBitFileOpen())
  {
    if(!openMIDI())
    {
      return;
    }

    if(!m_playing)
    {
      icon.addFile(QString::fromUtf8(":/images/media-pause-32.png"), QSize(), QIcon::Normal, QIcon::Off);
      playBtn->setIcon(icon);
      m_playing = true;

      if( m_init_play )
      {
        clear_tone_state();
        init_MIDI_instruments();

        m_current_segment = m_settings.m_FirstSegment;
        m_current_count_time = 0;
        m_current_played_note = 0;

        m_status_bar_label->setText(QString(tr("Current Segment: %1")).arg(m_current_segment, 16));
        position_segment(m_settings.m_FirstSegment);

        if(record_checkBox->isChecked())
        {
          start_audio_recording();
        }
      }
      else
      {
        if(record_checkBox->isChecked())
        {
          resume_audio_recording();
        }
      }

#ifdef WITH_MIDI_TIMER_INTERVAL_TEST
      m_interval_test.avg_counter = 0;
      m_interval_test.avg_sum = 0;
      m_interval_test.nominal_interval = m_midi_clock_interval;
      m_interval_test.start_interval_time = QDateTime::currentMSecsSinceEpoch();
#endif
      m_midi_clock->start(m_midi_clock_interval);
    }
    else
    {
      icon.addFile(QString::fromUtf8(":/images/media-play-32.png"), QSize(), QIcon::Normal, QIcon::Off);
      playBtn->setIcon(icon);
      m_playing = false;
      m_init_play = false;
      all_notes_off();
      m_midi_clock->stop();

      if(record_checkBox->isChecked())
      {
        pause_audio_recording();
      }
    }
  }
  else
  {
    QMessageBox::warning(this, qApp->applicationName(), tr("No file to play."));
  }
}

/*! Stop button has been clicked

  Set the icon to PLAY symbol
  Stop the MIDI timer
  Clear the tone states
  Stop audio recording if applicable

<b>History   :</b>	 26-09-2019mm		created by Michael Moser
*/
void MainWindow::on_stopBtn_clicked()
{
  QIcon icon;
  icon.addFile(QString::fromUtf8(":/images/media-play-32.png"), QSize(), QIcon::Normal, QIcon::Off);
  playBtn->setIcon(icon);
  m_playing = false;
  m_init_play = true;
  all_notes_off();
  m_midi_clock->stop();
  stop_audio_recording();

#ifdef WITH_MIDI_TIMER_INTERVAL_TEST
  qDebug("midi timer interval test: nom=%d avg=%lld",
         m_interval_test.nominal_interval, (m_interval_test.avg_sum/m_interval_test.avg_counter));
#endif

}


/*! Cyclic timer for playing the MIDI notes

  Show current segment number in status bar
  Play the current segment
  If last segment is reached stop the MIDI clock or loop back
  to start segment when loop checkbox is checked in settings
  Finally move the drawing window in m_segmentRenderArea
  Read next chunk of data from file if necessary
  Restart MIDI timer (note: MIDI timer is a one shot timer!)

<b>History   :</b>	 26-09-2019mm		created by Michael Moser
*/
void  MainWindow::midi_clock_timeout()
{
//  qDebug("midi_clock_timeout() segment=%d", m_current_segment);

  m_status_bar_label->setText(QString(tr("Current Segment: %1")).arg(m_current_segment, 16));

  char *pTmpSeg = &m_buffer[(m_current_segment % m_settings.m_max_segments) *   m_settings.m_current_max_channels];
  int played_chns = play_segment(pTmpSeg);
  int delta_interval = 0;

  if(m_settings.m_with_interval_variation)
  {
    if(primeList.indexOf(played_chns) > 0)
    {
      delta_interval = m_prng.bounded(m_settings.m_min_interval_variation,
                                      m_settings.m_max_interval_variation);
      if(primeList.indexOf(m_prng.bounded(0, primeList.last())) > 0)
      {
        delta_interval *= -1;
      }
    }
  }

  if(m_current_segment++ >= m_settings.m_LastSegment)
  {
    if(m_settings.m_Loop)
    {
      m_current_segment = m_settings.m_FirstSegment;
      m_current_count_time = 0;
      m_current_played_note = 0;
      position_segment(m_current_segment);
    }
    else
    {
#ifdef WITH_MIDI_TIMER_INTERVAL_TEST
      qDebug("midi timer interval test: nom=%lld avg=%lld",
             m_interval_test.nominal_interval, (m_interval_test.avg_sum/m_interval_test.avg_counter));
#endif
      m_midi_clock->stop();
    }
  }

  m_current_played_note++;
  int multiplier = m_settings.m_shortest_note / m_settings.m_bar_numerator;
  if((m_current_played_note % multiplier) == 0)
  {
    m_current_count_time++;
    if((m_current_count_time  % m_settings.m_bar_numerator) == 0)
    {
      m_current_count_time = 0;
    }
  }
#ifndef QT_NO_DEBUG
//  qDebug("played=%lld count=%d delta_interval=%d", m_current_played_note, m_current_count_time, delta_interval);
#endif
  if(!m_segmentRenderArea->moveWindow(1))
  {
    // Read next segments
    m_segmentRenderArea->setChannelCount(  m_settings.m_current_max_channels);
    m_buffer_read_size =  (m_settings.m_current_max_channels * 2*m_settings.m_max_segments);
    m_bits_to_bytes->readBitsAsBytes(&m_buffer[m_buffer_read_size/2], static_cast<quint32>(m_buffer_read_size/2));
    m_segmentRenderArea->setData(m_buffer, 2*m_settings.m_max_segments);
  }
  m_midi_clock->start(m_midi_clock_interval+delta_interval);



#ifdef WITH_MIDI_TIMER_INTERVAL_TEST
  qint64 e = QDateTime::currentMSecsSinceEpoch();

  m_interval_test.avg_counter++;
  m_interval_test.avg_sum += (e-m_interval_test.start_interval_time);
  m_interval_test.nominal_interval = m_midi_clock_interval;
  qDebug("midi_clock_timeout() %lldms", e-m_interval_test.start_interval_time);
  m_interval_test.start_interval_time = e;
#endif
}

/*! Play the current segment

  For each channel in the segment send a MIDI message with note, voice and velocity values
  If the current segment is not 0 send a noteOn message
  If the current segment is 0 send a noteOff message

<b>History   :</b>	 26-09-2019mm		created by Michael Moser
*/
int MainWindow::play_segment(char *segment)
{
  qint32 note;
  qint32 voice;
  QString out;
  int played_chns = 0;

  for(int chn = 0; chn <   m_settings.m_current_max_channels; chn++)
  {
    note = m_channels->getCurrentNoteIndex(chn);
    voice = m_channels->getCurrentVoiceIndex(chn);
    if(note != c_invalid_note)
    {
#ifndef QT_NO_DEBUG
//      qDebug("note=%d voice=%d", note, voice);
#endif

      if(segment[chn] != 0)
      {
        if(!m_channels->getChannelState(chn) || m_settings.m_Staccato)
        {
          if(m_settings.m_Staccato)
          {
            m_midi_out->noteOff(note, voice);
          }
          m_channels->setChannelState(chn, true);
          if(m_midi_out != nullptr)
          {
            int velocity = m_channels->getCurrentVelocityValue(chn);
            if((m_current_count_time == (m_settings.m_bar_accent-1)) &&
               ((m_current_played_note % m_settings.m_bar_numerator) == 0))
            {
              velocity = CChannelProperties::c_velocity_fff;
            }
            played_chns++;
            m_midi_out->noteOn(note, voice, velocity);
          }
        }
      }
      else
      {
        m_channels->setChannelState(chn, false);
        if(m_midi_out != nullptr)
        {
          m_midi_out->noteOff(note, voice);
        }
      }
    }
  }

  if(m_settings.m_with_metronome)
  {
    // Always on beat 1
    if((m_current_count_time ==  0 /* (m_settings.m_bar_accent-1) */) &&
       ((m_current_played_note % m_settings.m_bar_numerator) == 0))
    {
      m_midi_out->noteOn(m_settings.m_metronome_note, 9, CChannelProperties::c_velocity_ffff);
    }
    else
    {
       m_midi_out->noteOff(m_settings.m_metronome_note, 9);
    }
  }
#ifndef QT_NO_DEBUG
//  qDebug("played_chns=%d", played_chns);
#endif

//  qDebug() << out;

  return played_chns;
}

/*! Initialize the channels with the assigned MIDI instruments


<b>History   :</b>	 26-09-2019mm		created by Michael Moser
*/
void MainWindow::init_MIDI_instruments()
{
  for(int chn = 0; chn <   m_settings.m_current_max_channels; chn++)
  {
    qint32 voice = m_channels->getCurrentVoiceIndex(chn);
    if(m_midi_out != nullptr)
    {
      m_midi_out->setInstrument(voice, m_midi_instruments[voice]);
    }
  }
}

/*! Send for all channels a MIDI noteOff message


<b>History   :</b>	 26-09-2019mm		created by Michael Moser
*/
void MainWindow::all_notes_off()
{
  qint32 note;
  qint32 voice;

  for(int chn = 0; chn <   m_settings.m_current_max_channels; chn++)
  {
    note = m_channels->getCurrentNoteIndex(chn);
    voice = m_channels->getCurrentVoiceIndex(chn);
    if(note != c_invalid_note)
    {
      m_channels->setChannelState(chn, false);
      if(m_midi_out != nullptr)
      {
        m_midi_out->noteOff(note, voice);
      }
    }
  }
}

/*! Show/hide channels widgets according to   m_settings.m_current_max_channels


<b>History   :</b>	 26-09-2019mm		created by Michael Moser
*/
void MainWindow::show_hide_channels()
{
  for(int chn = 0; chn < c_max_channel_count; chn++)
  {
    if(chn <   m_settings.m_current_max_channels)
    {
      m_channels->show(chn);
    }
    else
    {
      m_channels->hide(chn);
    }
  }
}

/*! Save the config settings to QTextStream

  \param  os  output QTextStream object

<b>History   :</b>	 26-09-2019mm		created by Michael Moser
*/
void MainWindow::saveConfig(QTextStream& os)
{
#ifndef QT_NO_DEBUG
  qDebug("%s", qPrintable(qApp->applicationName()));
#endif
  os << qApp->applicationName() << "\n";

#ifndef QT_NO_DEBUG
  qDebug("%s", qPrintable(c_settings_version));
#endif
  os << c_settings_version << "\n";

#ifndef QT_NO_DEBUG
  qDebug("%s", qPrintable(saveGeneralSettings()));
#endif
  os << saveGeneralSettings() << "\n";

  for(int ix = 0; ix <   m_settings.m_current_max_channels; ix++)
  {
#ifndef QT_NO_DEBUG
    qDebug("%s", qPrintable(m_channels->toString(ix)));
#endif
    os << m_channels->toString(ix) << "\n";
  }

#ifndef QT_NO_DEBUG
  qDebug("%s", qPrintable(saveMIDI_Instruments()));
#endif
  os << saveMIDI_Instruments() << "\n";

#ifndef QT_NO_DEBUG
  qDebug("%s", qPrintable(saveScaleSettings()));
#endif
  os << saveScaleSettings() << "\n";

#ifndef QT_NO_DEBUG
  qDebug("%s", qPrintable(saveAudioSettings()));
#endif
  os << saveAudioSettings() << "\n";
}

/*! Restore the config settings from QFile

  \param  in  open QFile object

<b>History   :</b>	 26-09-2019mm		created by Michael Moser
*/
void MainWindow::restoreConfig(QFile& in)
{
  QString cfg_in;
  QStringList cfg_in_list;
  QString version;
  qint32 current_channel = 0;
  qint32 state = 0;

  while(!in.atEnd())
  {
    cfg_in = in.readLine();
    cfg_in = cfg_in.remove("\n");
#ifndef QT_NO_DEBUG
    qDebug("%s", qPrintable(cfg_in));
#endif
    switch(state)
    {
      case 0:
      {
#ifndef QT_NO_DEBUG
        qDebug("%s %s", qPrintable(cfg_in), qPrintable(qApp->applicationName()));
#endif
        if(cfg_in == qApp->applicationName())
        {
          state++;
        }
        else
        {
          QMessageBox::critical(this, tr("Invalid config file"), tr("Wrong application name"));
          return;
        }
        break;
      }
      case 1:
      {
        cfg_in_list = cfg_in.split(";", QString::SkipEmptyParts);
        if(cfg_in_list.size() == 2)
        {
          if(cfg_in_list.at(0) == "version")
          {
            version = cfg_in_list.at(1);
#ifndef QT_NO_DEBUG
            qDebug("version=%s", qPrintable(version));
#endif
            state = 2;
          }
          else
          {
            QMessageBox::critical(this, tr("Invalid config file"), tr("ID \"version\" not found"));
            return;
          }
        }
        else
        {
          QMessageBox::critical(this, tr("Invalid config file"), tr("Not enough data for \"version\""));
          return;
        }
        break;
      }
      case 2:
      {
        cfg_in_list = cfg_in.split(";", QString::SkipEmptyParts);
        if(cfg_in_list.size() > 0)
        {
          QString id = cfg_in_list.at(0) + ";";
          if(id == c_general_settings)
          {
            if(!restoreGeneralSettings(cfg_in_list, version))
            {
              return;
            }
          }
          else if (id == m_channels->getPropID())
          {
            if(!restoreChannelSettings(cfg_in, current_channel, version))
            {
              return;
            }
            if(++current_channel >= c_max_channel_count)
            {
              QMessageBox::critical(this, tr("Invalid config file"), tr("Too many channel entries"));
              return;
            }
          }
          else if (id == c_midi_instruments)
          {
            if(!restoreMIDI_Instruments(cfg_in_list, version))
            {
              return;
            }
          }
          else if (id == c_scale_settings)
          {
            if(!restoreScaleSettings(cfg_in_list, version))
            {
              return;
            }
          }
          else if (id == c_audio_settings)
          {
            if(!restoreAudioSettings(cfg_in_list, version))
            {
              return;
            }
          }
          else
          {
            QMessageBox::critical(this, tr("Invalid config file"), QString(tr("Unknown ID %1")).arg(id));
            return;
          }
        }
        else
        {
          QMessageBox::critical(this, tr("Invalid config file"), tr("Not enough data available"));
          return;
        }
        break;
      }
    }
  }
}

/*! Save the MIDI instruments settings in a QString

  \return  ";" separated QString

<b>History   :</b>	 26-09-2019mm		created by Michael Moser
*/
QString MainWindow::saveMIDI_Instruments()
{
  QString str = c_midi_instruments;
  for(int ix = 0; ix < c_max_midi_voices; ix++)
  {
    str += QString::number(m_midi_instruments[ix]) + ";" ;
  }
  return str;
}

/*! Restore the MIDI instruments from a QStringList

  \param  instruments_list  QStringList with the MIDI instruments
  \param  version  Version of the config file

  \return status of the operation

<b>History   :</b>	 26-09-2019mm		created by Michael Moser
*/
bool MainWindow::restoreMIDI_Instruments(QStringList instruments_list, QString version)
{
  if(version == "1.0")
  {
    if(instruments_list.size() == c_midi_instruments_len)
    {
      for(int ix = 0; ix < (c_midi_instruments_len-1); ix++)
      {
        m_midi_instruments[ix] = instruments_list.at(ix+1).toInt();
      }
      return true;
    }
    else
    {
      QMessageBox::critical(this, tr("Invalid config file"), QString(tr("Not enough data available for %1")).arg(c_midi_instruments));
      return false;
    }
  }
  else
  {
    QMessageBox::critical(this, tr("Invalid config file"), QString(tr("version: %1 not supported")).arg(version));
    return false;
  }

}

/*! Save the audio recording settings in a QString

  \return  ";" separated QString

<b>History   :</b>	 26-09-2019mm		created by Michael Moser
*/
QString MainWindow::saveAudioSettings()
{
  QString str = c_audio_settings;

  str += m_settings.m_audio_interface + ";";
  str += m_settings.m_audio_codec + ";";
  str += m_settings.m_audio_container + ";";
  str += QString::number(m_settings.m_audio_sample_rate) + ";";

  return str;
}

/*! Restore the audio recording settings from a QStringList

  \param  audio_settings_list  QStringList with the audio recording settings
  \param  version  Version of the config file

  \return status of the operation

<b>History   :</b>	 26-09-2019mm		created by Michael Moser
*/
bool MainWindow::restoreAudioSettings(QStringList audio_settings_list, QString version)
{
  if(version == "1.0")
  {
    if(audio_settings_list.size() == c_audio_settings_v1_0_len)
    {
      m_settings.m_audio_interface = audio_settings_list.at(1);
      m_settings.m_audio_codec = audio_settings_list.at(2);
      m_settings.m_audio_container = audio_settings_list.at(3);
      m_settings.m_audio_sample_rate = audio_settings_list.at(4).toInt();
      return true;
    }
  }
  return false;
}

/*! Save the scale settings in a QString

  \return  ";" separated QString

<b>History   :</b>	 26-09-2019mm		created by Michael Moser
*/
QString MainWindow::saveScaleSettings()
{
  QString str = c_scale_settings;

  str += currGroupBox->text() + ";" ;
  str += QString::number(KeysComboBox->currentIndex()) + ";" ;
  str += QString::number(ModesComboBox->currentIndex()) + ";" ;
  str += QString::number(octaveComboBox->currentIndex()) + ";" ;
  return str;
}

/*! Restore the scale settings from a QStringList

  \param  scales_list  QStringList with the scale settings
  \param  version  Version of the config file

  \return status of the operation

<b>History   :</b>	 26-09-2019mm		created by Michael Moser
*/
bool MainWindow::restoreScaleSettings(QStringList scales_list, QString version)
{
  if(version == "1.0")
  {
    if(scales_list.size() == c_scale_settings_v1_0_len)
    {
      QString item = scales_list.at(1);

      currGroupBox->setText(item);
      item = scales_list.at(2);
      KeysComboBox->setCurrentIndex(item.toInt());
      item = scales_list.at(3);
      ModesComboBox->setCurrentIndex(item.toInt());
      item = scales_list.at(4);
      octaveComboBox->setCurrentIndex(item.toInt());
      return true;
    }
    else
    {
      QMessageBox::critical(this, tr("Invalid config file"), QString(tr("Not enough data available for %1")).arg(c_scale_settings));
      return false;
    }
  }
  else
  {
    QMessageBox::critical(this, tr("Invalid config file"), QString(tr("version: %1 not supported")).arg(version));
    return false;
  }
}

/*! Save the general settings in a QString

  \return  ";" separated QString

<b>History   :</b>
26-09-2019mm  created by Michael Moser
13-05-2020mm  save values m_bar_numerator, m_bar_denominator, m_shortest_note and m_bar_accent

*/
QString MainWindow::saveGeneralSettings()
{
  QString str = c_general_settings;

  str += (!m_filename.isEmpty() ? m_filename : "<no file name>") + ";";
  str += (!m_settings.m_midi_out_name.isEmpty() ? m_settings.m_midi_out_name : "<no midi interface>") + ";";
  str += QString::number(m_settings.m_current_max_channels) + ";" ;
  str += QString::number(m_settings.m_BPM) + ";" ;
  str += (m_settings.m_Staccato ? "1;" : "0;");
  str += (m_settings.m_Loop ? "1;" : "0;");
  str += QString::number(m_settings.m_FirstSegment) + ";" ;
  str += QString::number(m_settings.m_LastSegment) + ";" ;
  str += QString::number(m_settings.m_bar_numerator) + ";" ;
  str += QString::number(m_settings.m_bar_denominator) + ";" ;
  str += QString::number(m_settings.m_bar_accent) + ";" ;
  str += QString::number(m_settings.m_shortest_note) + ";" ;
  str += (m_settings.m_with_interval_variation ? "1;" : "0;");
  str += QString::number(m_settings.m_min_interval_variation ) + ";" ;
  str += QString::number(m_settings.m_max_interval_variation) + ";" ;
  str += (m_settings.m_with_metronome ? "1;" : "0;");
  str += QString::number(m_settings.m_metronome_note) + ";" ;
  str += QString::number(m_settings.m_max_segments) + ";" ;

  return str;
}

/*! Restore the general settings from a QStringList

  \param  general_list  QStringList with the general settings
  \param  version  Version of the config file

  \return status of the operation

<b>History   :</b>
26-09-2019mm	created by Michael Moser
13-05-2020mm  save values m_bar_numerator, m_bar_denominator, m_shortest_note and m_bar_accent
              allow more values in the list

*/
bool MainWindow::restoreGeneralSettings(QStringList general_list, QString version)
{
  int ix = 1;

  if(version == "1.0")
  {
    if(general_list.size() >= c_general_settings_v1_0_len)
    {
      QString item = general_list.at(ix++);
      if(item != "<no file name>")
      {
        m_filename = item;
      }
      else
      {
        m_filename = "";
      }
      item =  general_list.at(ix++);
      if(item != "<no midi interface>")
      {
        m_settings.m_midi_out_name = item;
      }
      else
      {
        m_settings.m_midi_out_name = "";
      }
      item =  general_list.at(ix++);
      m_settings.m_current_max_channels = item.toInt() ;

      show_hide_channels();
      item =  general_list.at(ix++);
      m_settings.m_BPM  = item.toInt() ;

      item =  general_list.at(ix++);
      m_settings.m_Staccato = item.toInt() == 1 ? true : false;
      item =  general_list.at(ix++);
      m_settings.m_Loop = item.toInt() == 1 ? true : false;
      item =  general_list.at(ix++);
      m_settings.m_FirstSegment = item.toLongLong();
      item =  general_list.at(ix++);
      m_settings.m_LastSegment = item.toLongLong();

      if(ix < general_list.size())
      {
        item =  general_list.at(ix++);
        m_settings.m_bar_numerator = item.toInt();
      }
      else
      {
        m_settings.m_bar_numerator = 4;
      }

      if(ix < general_list.size())
      {
        item =  general_list.at(ix++);
        m_settings.m_bar_denominator = item.toInt();
      }
      else
      {
        m_settings.m_bar_denominator = 4;
      }

      if(ix < general_list.size())
      {
        item =  general_list.at(ix++);
        m_settings.m_bar_accent = item.toInt();
      }
      else
      {
        m_settings.m_bar_accent = 1;
      }
      if(ix < general_list.size())
      {
        item =  general_list.at(ix++);
        m_settings.m_shortest_note = item.toInt();
      }
      else
      {
        m_settings.m_shortest_note = 8;
      }


      double interval = calculate_interval();
#ifndef QT_NO_DEBUG
      qDebug("Interval for shortest note = %fms", interval);
#endif

      m_midi_clock_interval = static_cast<int>(interval);


      if(ix < general_list.size())
      {
        item =  general_list.at(ix++);
        m_settings.m_with_interval_variation = item.toInt() == 1 ? true : false;
      }
      else
      {
        m_settings.m_with_interval_variation = true;
      }

      if(ix < general_list.size())
      {
        item =  general_list.at(ix++);
        m_settings.m_min_interval_variation = item.toInt();
      }
      else
      {
        m_settings.m_min_interval_variation = 5;
      }

      if(ix < general_list.size())
      {
        item =  general_list.at(ix++);
        m_settings.m_max_interval_variation = item.toInt();
      }
      else
      {
        m_settings.m_max_interval_variation = 20;
      }

      if(ix < general_list.size())
      {
        item =  general_list.at(ix++);
        m_settings.m_with_metronome = item.toInt() == 1 ? true : false;
      }
      else
      {
        m_settings.m_with_metronome = true;
      }

      if(ix < general_list.size())
      {
        item =  general_list.at(ix++);
        m_settings.m_metronome_note = item.toInt();
      }
      else
      {
        m_settings.m_metronome_note = 75;
      }

      if(ix < general_list.size())
      {
        item =  general_list.at(ix++);
        m_settings.m_max_segments = item.toInt();
      }
      else
      {
        m_settings.m_max_segments = 250;
      }

      m_segmentRenderArea->setMaxSegments(m_settings.m_max_segments);
      qint32 render_width = m_segmentRenderArea->geometry().x()+m_segmentRenderArea->geometry().width();
      qint32 render_height = m_channels->size().height() + m_channels->geometry().y();

#ifndef QT_NO_DEBUG
  qDebug("render width=%d render height=%d", render_width, render_height);
#endif
      scrollAreaWidgetContents->setGeometry(0,0, render_width, render_height);

      closeFile();
      return openFile();
    }
    else
    {
      QMessageBox::critical(this, tr("Invalid config file"), QString(tr("Not enough data available for %1")).arg(c_general_settings));
      return false;
    }
  }
 else
  {
    QMessageBox::critical(this, tr("Invalid config file"), QString(tr("version: %1 not supported")).arg(version));
    return false;
  }
}

double MainWindow::calculate_interval()
{
  double interval = static_cast<double>(m_settings.m_BPM); //Beats per minute
  interval =  60.0 / interval; // Beats per second
  int fraction = 1;
  switch (m_settings.m_bar_denominator)
  {
    case 4:
    {
      // beat is 1/4th
      switch(m_settings.m_shortest_note)
      {
        case 8:
        {
          // shortest note is 1/8th
          fraction = 2;
          break;
        }
        case 16:
        {
          // shortest note is 1/16th
          fraction = 4;
          break;
        }
        case 32:
        {
          // shortest note is 1/32th
          fraction = 8;
          break;
        }
        default:
        {
          // shortest note is 1/4th => no change to interval
          fraction = 1;
          break;
        }
      }
      break;
    }
    case 8:
    {
      // beat is 1/8th
      switch(m_settings.m_shortest_note)
      {
        case 16:
        {
          // shortest note is 1/16th
          fraction = 2;
          break;
        }
        case 32:
        {
          // shortest note is 1/32th
          fraction = 4;
          break;
        }
        default:
        {
          // shortest note is 1/8th => no change to interval
          fraction = 1;
          break;
        }
      }
      break;
    }
    case 16:
    {
      // beat is 1/16th
      switch(m_settings.m_shortest_note)
      {
        case 32:
        {
          // shortest note is 1/32th
          fraction = 2;
          break;
        }
        default:
        {
          // shortest note is 1/16th => no change to interval
          fraction = 1;
          break;
        }
      }
      break;
    }
    case 32:
    {
      // beat is 1/32th
      // shortest note is 1/32th => no change to interval
      fraction = 1;
      break;
    }
  }
  interval /= fraction; // interval for shortest note
  interval *= 1000; // Convert to milliseconds

  return interval;
}

/*! Restore the channels settings from a QStringList

  \param  chn_props QString with the channels settings
  \param  chn_ix    channel index
  \param  version   Version of the config file

  \return status of the operation

<b>History   :</b>	 26-09-2019mm		created by Michael Moser
*/
bool MainWindow::restoreChannelSettings(QString chn_props, qint32 chn_ix, QString version)
{
  QStringList chn_props_list;
  chn_props_list = chn_props.split(";", QString::SkipEmptyParts);
  if(version == "1.0")
  {
    if(chn_props_list.size() == m_channels->getPropLength())
    {
      if(chn_ix >= c_max_channel_count)
      {
        QMessageBox::critical(this, tr("Invalid config file"), tr("Too many channel entries"));
        return false;
      }
      else
      {
         m_channels->fromString(chn_ix, chn_props);
        return true;
      }
    }
    else
    {
      QMessageBox::critical(this, tr("Invalid config file"), QString(tr("Not enough data available for %1")).arg(m_channels->getPropID()));
      return false;
    }
  }
  else
  {
    QMessageBox::critical(this, tr("Invalid config file"), QString(tr("version: %1 not supported")).arg(version));
    return false;
  }
}

/*! Handle File -> Save Config


<b>History   :</b>	 26-09-2019mm		created by Michael Moser
*/
void MainWindow::on_actionSave_Config_triggered()
{
  if(m_last_config_file.isEmpty())
  {
     on_actionSave_Config_As_triggered();
  }
  else
  {
    saveConfigFile(m_last_config_file);
  }
}

/*! Handle File -> Save Config As


<b>History   :</b>
14-05-2020mm		created by Michael Moser
*/
void MainWindow::on_actionSave_Config_As_triggered()
{
  QString fileName;

  fileName = QFileDialog::getSaveFileName(this, tr("Configuration File"), m_last_config_path, tr("Configurations (*.ini)"));

  if(!fileName.isEmpty())
  {
    QFileInfo fi(fileName);
    m_last_config_path = fi.path();

    if(!fileName.endsWith(".ini"))
    {
      fileName.append(".ini");
    }

    QSettings settings;
    settings.setValue("last_config_file", fileName);

    saveConfigFile(fileName);
  }
}

/*! Save Config File


<b>History   :</b>
14-05-2020mm		created by Michael Moser
*/
void MainWindow::saveConfigFile(QString& fileName)
{
  QFile out;

  out.setFileName(fileName);
  if(out.open( QIODevice::WriteOnly | QIODevice::Text))
  {
    QTextStream os(&out);

    saveConfig(os);

    out.close();
  }
}

void MainWindow::on_actionNew_Config_triggered()
{
  QString fileName;

  fileName = QFileDialog::getOpenFileName(this, tr("Configuration File"), m_last_config_path, tr("Configurations (*.ini)"));

  if(!fileName.isEmpty())
  {
    QSettings settings;
    settings.setValue("last_config_file", fileName);

    m_channels->resetChannels();
    m_settings.resetSettings();
    on_actionSave_Config_triggered();
  }
}


/*! Handle File -> Open Config


<b>History   :</b>	 26-09-2019mm		created by Michael Moser
*/
void MainWindow::on_actionOpen_Config_triggered()
{
  QString fileName;

  fileName = QFileDialog::getOpenFileName(this, tr("Configuration File"), m_last_config_path, tr("Configurations (*.ini)"));

  if(!fileName.isEmpty())
  {
    QSettings settings;
    settings.setValue("last_config_file", fileName);

    loadConfig(fileName);
  }
}

/*! Load a config file

  \param  filename   filename of the config file

<b>History   :</b>
14-05-2020mm		created by Michael Moser
*/
void MainWindow::loadConfig(QString& fileName)
{
  QFile in;

  if(!fileName.isEmpty())
  {

    QFileInfo fi(fileName);
    m_last_config_path = fi.path();

    in.setFileName(fileName);

    if(in.open( QIODevice::ReadOnly | QIODevice::Text))
    {

      restoreConfig(in);

      info_0_1->setNum(m_settings.m_BPM);
      info_0_3->setText(tr("1/%1").arg(m_settings.m_shortest_note));
      info_1_1->setText(tr("%1/%2").arg(m_settings.m_bar_numerator)
                                   .arg(m_settings.m_bar_denominator));
      info_1_3->setNum(m_settings.m_max_segments);

      in.close();
    }
  }
}


/*! Handle Extras -> Settings

  Initialize settings dialog with current values
  Execute settings dialog
  Fetch new settings from settings dialog class

<b>History   :</b>	 26-09-2019mm		created by Michael Moser
*/
void MainWindow::on_actionSettings_triggered()
{
  CSettingsDialog *dlg = new CSettingsDialog(this);


  if(m_bits_to_bytes->isBitFileOpen())
  {
    dlg->setFileSize(m_bits_to_bytes->getFileSize());
  }
  else
  {
    dlg->setFileSize(0);
  }

//  dlg->setMaxChannels(c_max_channel_count);
  qint32  last_max_channels = m_settings.m_current_max_channels;
  qint64  last_FirstSegment = m_settings.m_FirstSegment;
  dlg->setSettings(m_settings);

  if(dlg->exec() == QDialog::Accepted)
  {
    dlg->getSettings(m_settings);
    show_hide_channels();

    m_segmentRenderArea->setChannelCount(m_settings.m_current_max_channels);
    m_segmentRenderArea->setMaxSegments(m_settings.m_max_segments);
    qint32 render_width = m_segmentRenderArea->geometry().x()+m_segmentRenderArea->geometry().width();
    qint32 render_height = m_channels->size().height() + m_channels->geometry().y();

#ifndef QT_NO_DEBUG
    qDebug("render width=%d render height=%d", render_width, render_height);
#endif
    scrollAreaWidgetContents->setGeometry(0,0, render_width, render_height);

    closeFile();
    openFile();

    if((last_max_channels != m_settings.m_current_max_channels) ||
       (last_FirstSegment != m_settings.m_FirstSegment))
    {
      last_max_channels = m_settings.m_current_max_channels;
      last_FirstSegment = m_settings.m_FirstSegment;
      position_segment(m_settings.m_FirstSegment);
    }
    double interval = calculate_interval();

#ifndef QT_NO_DEBUG
      qDebug("Interval for shortest note = %fms", interval);
#endif

    m_midi_clock_interval = static_cast<int>(interval);

    if(m_midi_clock->isActive())
    {
      m_midi_clock->stop();

#ifdef WITH_MIDI_TIMER_INTERVAL_TEST
      qDebug("midi timer interval test: nom=%lld avg=%lld",
             m_interval_test.nominal_interval, (m_interval_test.avg_sum/m_interval_test.avg_counter));

      m_interval_test.avg_counter = 0;
      m_interval_test.avg_sum = 0;
      m_interval_test.nominal_interval = m_midi_clock_interval;
      m_interval_test.start_interval_time = QDateTime::currentMSecsSinceEpoch();
#endif
      m_midi_clock->start(m_midi_clock_interval);
    }

    info_0_1->setNum(m_settings.m_BPM);
    info_0_3->setText(tr("1/%1").arg(m_settings.m_shortest_note));
    info_1_1->setText(tr("%1/%2").arg(m_settings.m_bar_numerator)
                                 .arg(m_settings.m_bar_denominator));
    info_1_3->setNum(m_settings.m_max_segments);

  }
}

/*! Handle Extras -> MIDI Instruments

  Initialize MIDI instruments dialog with current values
  Execute settings dialog
  Fetch new settings from MIDI instruments dialog class

<b>History   :</b>	 26-09-2019mm		created by Michael Moser
*/
void MainWindow::on_actionMIDI_Instruments_triggered()
{
  CMIDIInstrumentsDialog *dlg = new CMIDIInstrumentsDialog(this);

  dlg->setMIDI_Instruments(m_midi_instruments, c_max_midi_voices);
  if(dlg->exec() == QDialog::Accepted)
  {
    dlg->getMIDI_Instruments(m_midi_instruments, c_max_midi_voices);
  }
}

/*! Start audio recording

  Ask user for output filename
  If filename has not extension ".wav" append ".wav"
  Setup audio interface with values from Extras -> Settings dialog
  Start recording

<b>History   :</b>	 26-09-2019mm		created by Michael Moser
*/
void MainWindow::start_audio_recording()
{
  if (m_audioRecorder->state() == QMediaRecorder::StoppedState)
  {
    QString fileName = QFileDialog::getSaveFileName(this, tr("WAV Output File"), ".", tr("WAV Files (*.wav)"));

    if(!fileName.isEmpty())
    {
      if(!fileName.endsWith(".wav"))
      {
        fileName.append(".wav");
      }

      if(m_settings.m_audio_interface.isEmpty())
      {
        QStringList in = m_audioRecorder->audioInputs();
        QStringList container = m_audioRecorder->supportedContainers();
        QStringList codec = m_audioRecorder->supportedAudioCodecs();

        m_settings.m_audio_interface = in[0];
        m_settings.m_audio_codec = codec[0];
        m_settings.m_audio_container = container[0];
        m_settings.m_audio_sample_rate = 48000;
      }

      m_audioRecorder->setOutputLocation(QUrl::fromLocalFile(fileName));

      m_status_bar_label_recording->setText(tr("Record to: ") + fileName );

      m_audioRecorder->setAudioInput(m_settings.m_audio_interface);

      QAudioEncoderSettings settings;
      settings.setCodec(m_settings.m_audio_codec);
      settings.setSampleRate(m_settings.m_audio_sample_rate);
      settings.setChannelCount(1);
      settings.setQuality(QMultimedia::NormalQuality);
      settings.setEncodingMode(QMultimedia::ConstantQualityEncoding);
      m_audioRecorder->setEncodingSettings(settings, QVideoEncoderSettings(), m_settings.m_audio_container);
      m_audioRecorder->record();
    }
  }
  else
  {
    m_audioRecorder->stop();
  }
}

/*! Pause audio recording

<b>History   :</b>	 26-09-2019mm		created by Michael Moser
*/
void MainWindow::pause_audio_recording()
{

  if (m_audioRecorder->state() != QMediaRecorder::PausedState)
  {
    m_audioRecorder->pause();
  }
}

/*! Resume audio recording

<b>History   :</b>	 26-09-2019mm		created by Michael Moser
*/
void MainWindow::resume_audio_recording()
{
  if (m_audioRecorder->state() == QMediaRecorder::PausedState)
  {
    m_audioRecorder->record();
  }
}

/*! Stop audio recording

<b>History   :</b>	 26-09-2019mm		created by Michael Moser
*/
void MainWindow::stop_audio_recording()
{
  if (m_audioRecorder->state() == QMediaRecorder::RecordingState ||
      m_audioRecorder->state() == QMediaRecorder::PausedState)
  {
    m_status_bar_label_recording->setText(tr("Record to: "));

    m_audioRecorder->stop();
  }
}

/*! Display audio recording error message at status bar


<b>History   :</b>	 26-09-2019mm		created by Michael Moser
*/
void MainWindow::displayErrorMessage()
{
  m_statusbar->showMessage(m_audioRecorder->errorString());
}

/*! Display audio recording progress message at status bar


<b>History   :</b>	 26-09-2019mm		created by Michael Moser
*/
void MainWindow::updateProgress(qint64 duration)
{
    if (m_audioRecorder->error() != QMediaRecorder::NoError || duration < 2000)
        return;

    m_statusbar->showMessage(tr("Recorded %1 sec").arg(duration / 1000));
}

/*! Display audio recording status message at status bar


<b>History   :</b>	 26-09-2019mm		created by Michael Moser
*/
void MainWindow::updateStatus(QMediaRecorder::Status status)
{
  QString statusMessage;

  switch (status)
  {
    case QMediaRecorder::RecordingStatus:
    {
      statusMessage = tr("Recording to %1").arg(m_audioRecorder->actualLocation().toString());
      break;
    }
    case QMediaRecorder::PausedStatus:
    {
      statusMessage = tr("Paused");
      break;
    }
    case QMediaRecorder::UnloadedStatus:
    case QMediaRecorder::LoadedStatus:
    {
      statusMessage = tr("Stopped");
      break;
    }
    default:
    {
      break;
    }
  }

  if (m_audioRecorder->error() == QMediaRecorder::NoError)
  {
    m_statusbar->showMessage(statusMessage);
  }
}



