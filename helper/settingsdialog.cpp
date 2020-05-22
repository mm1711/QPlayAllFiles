/*! \file  settingsdialog.cpp

GUI class for application settings dialog

<b>Copyright   :</b> (C) 2019 Michael Moser

<b>Last edit	:</b>

<b>History   :</b>	26-09-2019mm		creation by Michael Moser
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

#include "settingsdialog.h"

CSettingsDialog::CSettingsDialog(QWidget *parent) :
  QDialog(parent)
{

  setWindowTitle(tr("Settings"));

  m_file_size = 0;
  m_midi_out = new QMidiOut();
  m_max_channels = 127;

  QVBoxLayout *mainLayout = new QVBoxLayout;
  mainLayout->setContentsMargins(6, 6, 6, 6);


  QHBoxLayout *horizontalLayout1 = new QHBoxLayout();
  horizontalLayout1->setContentsMargins(6, 6, 6, 6);
  horizontalLayout1->setSpacing(10);

  label_channel = new QLabel();
  label_channel->setText(tr("Channels"));
  horizontalLayout1->addWidget(label_channel);

  channels_spinBox = new QSpinBox();
  channels_spinBox->setMinimum(1);
  channels_spinBox->setMaximum(m_max_channels-1);
  channels_spinBox->setValue(13);
  horizontalLayout1->addWidget(channels_spinBox);
  QSpacerItem *horizontalSpacer1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
  horizontalLayout1->addItem(horizontalSpacer1);

  mainLayout->addItem(horizontalLayout1);

  QHBoxLayout *horizontalLayout2 = new QHBoxLayout();
  horizontalLayout2->setContentsMargins(6, 6, 6, 6);
  horizontalLayout2->setSpacing(10);

  label_BPM = new QLabel();
  label_BPM->setText(tr("Beats/Minute"));
  horizontalLayout2->addWidget(label_BPM);
  BPM_lineEdit = new QLineEdit();
  BPM_lineEdit->setMaxLength(4);
  horizontalLayout2->addWidget(BPM_lineEdit);

  label_numerator = new QLabel();
  label_numerator->setText(tr("Measure"));
  horizontalLayout2->addWidget(label_numerator);
  Numerator_spinBox= new QSpinBox();
  Numerator_spinBox->setMinimum(1);
  Numerator_spinBox->setMaximum(16);
  Numerator_spinBox->setValue(4);
  horizontalLayout2->addWidget(Numerator_spinBox);

  Denominator_comboBox = new QComboBox();
  QStringList denominators;
  denominators << "4" << "8" << "16" << "32" ;
  Denominator_comboBox->addItems(denominators);
  horizontalLayout2->addWidget(Denominator_comboBox);

  label_accent = new QLabel();
  label_accent->setText(tr("Accent"));
  horizontalLayout2->addWidget(label_accent);

  Accent_spinBox = new QSpinBox();
  Accent_spinBox->setMinimum(1);
  Accent_spinBox->setMaximum(32);
  Accent_spinBox->setValue(1);
  horizontalLayout2->addWidget(Accent_spinBox);

  label_shortest = new QLabel();
  label_shortest->setText(tr("Shortest 1/"));
  horizontalLayout2->addWidget(label_shortest);

  shortestNote_comboBox = new QComboBox();
  shortestNote_comboBox->addItems(denominators);
  horizontalLayout2->addWidget(shortestNote_comboBox);

  QSpacerItem *horizontalSpacer2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
  horizontalLayout2->addItem(horizontalSpacer2);

  mainLayout->addItem(horizontalLayout2);

  QHBoxLayout *horizontalLayout3 = new QHBoxLayout();
  horizontalLayout3->setContentsMargins(6, 6, 6, 6);
  horizontalLayout3->setSpacing(10);

  intervalVariation_checkBox = new QCheckBox();
  intervalVariation_checkBox->setText(tr("Interval Variation"));
  intervalVariation_checkBox->setLayoutDirection(Qt::RightToLeft);
  intervalVariation_checkBox->setChecked(true);
  horizontalLayout3->addWidget(intervalVariation_checkBox);

  label_min_interval = new QLabel();
  label_min_interval->setText(tr("Min."));

  horizontalLayout3->addWidget(label_min_interval);

  minIntervalVariation_spinBox = new QSpinBox();
  minIntervalVariation_spinBox->setMaximum(10);
  minIntervalVariation_spinBox->setValue(5);

  horizontalLayout3->addWidget(minIntervalVariation_spinBox);

  label_max_interval = new QLabel();
  label_max_interval->setText(tr("Max."));
  horizontalLayout3->addWidget(label_max_interval);

  maxIntervalVariation_spinBox = new QSpinBox();
  maxIntervalVariation_spinBox->setMinimum(10);
  maxIntervalVariation_spinBox->setMaximum(100);
  maxIntervalVariation_spinBox->setValue(20);
  horizontalLayout3->addWidget(maxIntervalVariation_spinBox);

  label_ms = new QLabel();
  label_ms->setText(tr("ms"));
  horizontalLayout3->addWidget(label_ms);

  QSpacerItem *horizontalSpacer3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
  horizontalLayout3->addItem(horizontalSpacer3);

  metronome_checkBox = new QCheckBox();
  metronome_checkBox->setText(tr("Metronome"));
  metronome_checkBox->setLayoutDirection(Qt::RightToLeft);
  metronome_checkBox->setChecked(true);
  horizontalLayout3->addWidget(metronome_checkBox);

  metronomInstrument_comboBox = new QComboBox();
  CChannelProperties ccpr(nullptr);
  QStringList percussion_list = ccpr.getPercussionInstruments();
  metronomInstrument_comboBox->addItems(percussion_list);
  metronomInstrument_comboBox->adjustSize();
  horizontalLayout3->addWidget(metronomInstrument_comboBox);

  QSpacerItem *horizontalSpacer4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
  horizontalLayout3->addItem(horizontalSpacer4);

  mainLayout->addItem(horizontalLayout3);

  QHBoxLayout *horizontalLayout4 = new QHBoxLayout();
  horizontalLayout4->setContentsMargins(6, 6, 6, 6);
  horizontalLayout4->setSpacing(10);

  staccato_checkBox = new QCheckBox();
  staccato_checkBox->setText(tr("Staccato"));
  staccato_checkBox->setLayoutDirection(Qt::RightToLeft);
  horizontalLayout4->addWidget(staccato_checkBox);

  label_max_segments = new QLabel();
  label_max_segments->setText(tr("Max Segments"));
  horizontalLayout4->addWidget(label_max_segments);

  max_segments_spinBox = new QSpinBox();
  max_segments_spinBox->setMinimum(250);
  max_segments_spinBox->setMaximum(2000);
  max_segments_spinBox->setValue(250);
  horizontalLayout4->addWidget(max_segments_spinBox);


  QSpacerItem *horizontalSpacer5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
  horizontalLayout4->addItem(horizontalSpacer5);

  mainLayout->addItem(horizontalLayout4);

  QHBoxLayout *horizontalLayout5 = new QHBoxLayout();
  horizontalLayout5->setContentsMargins(6, 6, 6, 6);
  horizontalLayout5->setSpacing(10);

  loop_checkBox = new QCheckBox();
  loop_checkBox->setText(tr("Loop"));
  loop_checkBox->setLayoutDirection(Qt::RightToLeft);
  horizontalLayout5->addWidget(loop_checkBox);

  QSpacerItem *horizontalSpacer6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
  horizontalLayout5->addItem(horizontalSpacer6);

  mainLayout->addItem(horizontalLayout5);

  QHBoxLayout *horizontalLayout6 = new QHBoxLayout();
  horizontalLayout6->setContentsMargins(6, 6, 6, 6);
  horizontalLayout6->setSpacing(10);

  label_firstSegment = new QLabel();
  label_firstSegment->setText(tr("First Segment"));
  horizontalLayout6->addWidget(label_firstSegment);

  firstSegment_lineEdit = new QLineEdit();
  firstSegment_lineEdit->setMaxLength(10);
  horizontalLayout6->addWidget(firstSegment_lineEdit);

  set_first_segment_Btn = new QPushButton();
  set_first_segment_Btn->setText(tr("First"));
  horizontalLayout6->addWidget(set_first_segment_Btn);

  QSpacerItem *horizontalSpacer7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
  horizontalLayout6->addItem(horizontalSpacer7);

  mainLayout->addItem(horizontalLayout6);

  QHBoxLayout *horizontalLayout7 = new QHBoxLayout();
  horizontalLayout7->setContentsMargins(6, 6, 6, 6);
  horizontalLayout7->setSpacing(10);

  label_lastSegment = new QLabel();
  label_lastSegment->setText(tr("Last Segment"));
  horizontalLayout7->addWidget(label_lastSegment);

  lastSegment_lineEdit = new QLineEdit();
  lastSegment_lineEdit->setMaxLength(10);
  horizontalLayout7->addWidget(lastSegment_lineEdit);

  set_last_segment_Btn = new QPushButton();
  set_last_segment_Btn->setText(tr("Last"));
  horizontalLayout7->addWidget(set_last_segment_Btn);

  QSpacerItem *horizontalSpacer8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
  horizontalLayout7->addItem(horizontalSpacer8);

  mainLayout->addItem(horizontalLayout7);

  QAudioRecorder *audioRecorder = new QAudioRecorder(this);

  QHBoxLayout *horizontalLayout8 = new QHBoxLayout();
  horizontalLayout8->setContentsMargins(6, 6, 6, 6);
  horizontalLayout8->setSpacing(10);

  label_audio_interface = new QLabel();
  label_audio_interface->setText(tr("Audio Interface"));
  horizontalLayout8->addWidget(label_audio_interface);

  audio_Interface_comboBox = new QComboBox();
  audio_Interface_comboBox->addItems(audioRecorder->audioInputs());
  horizontalLayout8->addWidget(audio_Interface_comboBox);

  QSpacerItem *horizontalSpacer9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
  horizontalLayout8->addItem(horizontalSpacer9);

  mainLayout->addItem(horizontalLayout8);

  QHBoxLayout *horizontalLayout9 = new QHBoxLayout();
  horizontalLayout9->setContentsMargins(6, 6, 6, 6);
  horizontalLayout9->setSpacing(10);

  label_audio_codec = new QLabel();
  label_audio_codec->setText(tr("Audio Codec"));
  horizontalLayout9->addWidget(label_audio_codec);

  audio_codec_comboBox = new QComboBox();
  audio_codec_comboBox->addItems(audioRecorder->supportedAudioCodecs());
  horizontalLayout9->addWidget(audio_codec_comboBox);

  QSpacerItem *horizontalSpacer10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
  horizontalLayout9->addItem(horizontalSpacer10);

  mainLayout->addItem(horizontalLayout9);

  QHBoxLayout *horizontalLayout10 = new QHBoxLayout();
  horizontalLayout10->setContentsMargins(6, 6, 6, 6);
  horizontalLayout10->setSpacing(10);

  label_audio_sampling_rate = new QLabel();
  label_audio_sampling_rate->setText(tr("Audio Codec"));
  horizontalLayout10->addWidget(label_audio_sampling_rate);

  audio_sampling_rate_comboBox = new QComboBox();

  QList<int> sample_rates = audioRecorder->supportedAudioSampleRates();

  for (int kk = 0; kk < sample_rates.size(); kk++)
  {
    audio_sampling_rate_comboBox->addItem(QString::number(sample_rates.at(kk)));
  }

  horizontalLayout10->addWidget(audio_sampling_rate_comboBox);

  QSpacerItem *horizontalSpacer11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
  horizontalLayout10->addItem(horizontalSpacer11);

  mainLayout->addItem(horizontalLayout10);

  QHBoxLayout *horizontalLayout11 = new QHBoxLayout();
  horizontalLayout11->setContentsMargins(6, 6, 6, 6);
  horizontalLayout11->setSpacing(10);

  label_audio_container = new QLabel();
  label_audio_container->setText(tr("Audio Container"));
  horizontalLayout11->addWidget(label_audio_container);

  audio_container_comboBox = new QComboBox();
  audio_container_comboBox->addItems(audioRecorder->supportedContainers());
  horizontalLayout11->addWidget(audio_container_comboBox);

  QSpacerItem *horizontalSpacer12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
  horizontalLayout11->addItem(horizontalSpacer12);

  mainLayout->addItem(horizontalLayout11);

  QHBoxLayout *horizontalLayout12 = new QHBoxLayout();
  horizontalLayout12->setContentsMargins(6, 6, 6, 6);
  horizontalLayout12->setSpacing(10);

  label_midi_interface = new QLabel();
  label_midi_interface->setText(tr("MIDI Interface"));
  horizontalLayout12->addWidget(label_midi_interface);

  MIDI_Interface_comboBox = new QComboBox();

  QMap<QString /* key */, QString /* name */> midimap = m_midi_out->devices();
  for(int ix = 0; ix < midimap.size(); ix++)
  {
    MIDI_Interface_comboBox->addItem(midimap[QString::number(ix)]);
  }
  horizontalLayout12->addWidget(MIDI_Interface_comboBox);

  QSpacerItem *horizontalSpacer13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
  horizontalLayout12->addItem(horizontalSpacer13);

  mainLayout->addItem(horizontalLayout12);


  buttonBox = new QDialogButtonBox();
  buttonBox->setOrientation(Qt::Horizontal);
  buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
  buttonBox->setCenterButtons(true);

  mainLayout->addWidget(buttonBox);


  setLayout(mainLayout);

  connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
  connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
  connect(set_first_segment_Btn, SIGNAL(clicked()), this, SLOT(on_set_first_segment_Btn_clicked()));
  connect(set_last_segment_Btn, SIGNAL(clicked()), this, SLOT(on_set_last_segment_Btn_clicked()));

  connect(channels_spinBox, SIGNAL(valueChanged(int)), this, SLOT(on_channels_spinBox_valueChanged(int)));
  connect(Numerator_spinBox, SIGNAL(valueChanged(int)), this, SLOT(on_Numerator_spinBox_valueChanged(int)));
  connect(Denominator_comboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(on_Denominator_comboBox_currentIndexChanged(QString)));

  adjustSize();
}

CSettingsDialog::~CSettingsDialog()
{
  delete m_midi_out;
}

/*! Initialize dialog controls with values from 'settings'


<b>History   :</b>
26-09-2019mm  created by Michael Moser
13-05-2020mm  set values for m_bar_numerator, m_bar_denominator,
              m_shortest_note and m_bar_accent

*/
void CSettingsDialog::setSettings(CSettings settings)
{
  channels_spinBox->setMaximum(m_max_channels);
  channels_spinBox->setValue(settings.m_current_max_channels);
  BPM_lineEdit->setText(QString::number(settings.m_BPM));
  Numerator_spinBox->setValue(settings.m_bar_numerator);

  Denominator_comboBox->setCurrentText(QString::number(settings.m_bar_denominator));

  Accent_spinBox->setValue(settings.m_bar_accent);
  Accent_spinBox->setMaximum(settings.m_bar_numerator);

  initialize_shortestNote_comboBox(settings.m_bar_denominator);
  shortestNote_comboBox->setCurrentText(QString::number(settings.m_shortest_note));

  intervalVariation_checkBox->setChecked(settings.m_with_interval_variation);
  minIntervalVariation_spinBox->setValue(settings.m_min_interval_variation);
  maxIntervalVariation_spinBox->setValue(settings.m_max_interval_variation);
  metronome_checkBox->setChecked(settings.m_with_metronome);

  metronomInstrument_comboBox->setCurrentIndex(settings.m_metronome_note);

  staccato_checkBox->setChecked(settings.m_Staccato);
  max_segments_spinBox->setValue(settings.m_max_segments);
  loop_checkBox->setChecked(settings.m_Loop);
  firstSegment_lineEdit->setText(QString::number(settings.m_FirstSegment));
  lastSegment_lineEdit->setText(QString::number(settings.m_LastSegment));

  if(!settings.m_audio_interface.isEmpty())
  {
    audio_Interface_comboBox->setCurrentIndex(
          audio_Interface_comboBox->findText(settings.m_audio_interface));
  }

  if(!settings.m_audio_codec.isEmpty())
  {
    audio_codec_comboBox->setCurrentIndex(
          audio_codec_comboBox->findText(settings.m_audio_codec));
  }

  if(!settings.m_audio_container.isEmpty())
  {
    audio_container_comboBox->setCurrentIndex(
          audio_container_comboBox->findText(settings.m_audio_container));
  }

  audio_sampling_rate_comboBox->setCurrentIndex(
        audio_sampling_rate_comboBox->findText(QString::number(settings.m_audio_sample_rate)));

  if(!settings.m_midi_out_name.isEmpty())
  {
    MIDI_Interface_comboBox->setCurrentIndex(
          MIDI_Interface_comboBox->findText(settings.m_midi_out_name));
  }
}

/*! Initialize shortestNote_comboBox

  \param  denominator   denominator of bar

<b>History   :</b>
13-05-2020mm	created by Michael Moser
*/
void CSettingsDialog::initialize_shortestNote_comboBox(int denominator)
{
  QStringList denominators;
  switch (denominator)
  {
    case 4:
    {
      denominators << "4" << "8" << "16" << "32" ;
      break;
    }
    case 8:
    {
      denominators << "8" << "16" << "32" ;
      break;
    }
    case 16:
    {
      denominators << "16" << "32" ;
      break;
    }
    case 32:
    {
      denominators << "32" ;
      break;
    }
  }
  shortestNote_comboBox->clear();
  shortestNote_comboBox->addItems(denominators);
}


/*! Return dialog controls values in 'settings'


<b>History   :</b>
26-09-2019mm  created by Michael Moser
13-05-2020mm  get values from m_bar_numerator, m_bar_denominator,
              m_shortest_note and m_bar_accent
*/
void CSettingsDialog::getSettings(CSettings& settings)
{
  settings.m_current_max_channels = channels_spinBox->value();
  settings.m_BPM = BPM_lineEdit->text().toInt();
  settings.m_bar_numerator = Numerator_spinBox->value();
  settings.m_bar_denominator = (Denominator_comboBox->currentText()).toInt();
  settings.m_bar_accent = Accent_spinBox->value();
  settings.m_shortest_note = (shortestNote_comboBox->currentText()).toInt();
  settings.m_Staccato = staccato_checkBox->isChecked();
  settings.m_Loop = loop_checkBox->isChecked();
  settings.m_FirstSegment = firstSegment_lineEdit->text().toLongLong();
  settings.m_LastSegment = lastSegment_lineEdit->text().toLongLong();
  settings.m_audio_interface = audio_Interface_comboBox->currentText();
  settings.m_audio_codec = audio_codec_comboBox->currentText();
  settings.m_audio_container = audio_container_comboBox->currentText();
  settings.m_audio_sample_rate = audio_sampling_rate_comboBox->currentText().toInt();
  settings.m_midi_out_name = MIDI_Interface_comboBox->currentText();
  settings.m_with_interval_variation = intervalVariation_checkBox->isChecked();
  settings.m_min_interval_variation = minIntervalVariation_spinBox->value();
  settings.m_max_interval_variation = maxIntervalVariation_spinBox->value();
  settings.m_with_metronome = metronome_checkBox->isChecked();
  settings.m_metronome_note = metronomInstrument_comboBox->currentIndex();
  settings.m_max_segments = max_segments_spinBox->value();
}

/*! Event handler for "First" button

  Set firstSegment_lineEdit to 0

<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
void CSettingsDialog::on_set_first_segment_Btn_clicked()
{
  firstSegment_lineEdit->setText("0");
}

/*! Event handler for "Last" button

  Set lastSegment_lineEdit to last available segment

<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
void CSettingsDialog::on_set_last_segment_Btn_clicked()
{
  if(channels_spinBox->value() > 0)
  {
    lastSegment_lineEdit->setText(QString::number((m_file_size / channels_spinBox->value())));
  }
}

/*! Event handler for channels_spinBox changed value

  When the channel count is changed, update lastSegment_lineEdit value

<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
void CSettingsDialog::on_channels_spinBox_valueChanged(int chn_count)
{
  if(chn_count >= m_max_channels)
  {
    channels_spinBox->setValue(m_max_channels-1);
  }
  on_set_last_segment_Btn_clicked();
}

/*! Event handler for Numerator_spinBox changed value

  When the bar numerator is changed, update maximum value of Accent_spinBox

<b>History   :</b>
13-05-2020mm created by Michael Moser
*/
void CSettingsDialog::on_Numerator_spinBox_valueChanged(int arg1)
{
  Accent_spinBox->setMaximum(arg1);
}

/*! Event handler for Denominator_comboBox changed value

  When the bar denominator is changed, update values in shortestNote_comboBox

<b>History   :</b>
13-05-2020mm created by Michael Moser
*/
void CSettingsDialog::on_Denominator_comboBox_currentIndexChanged(const QString &arg1)
{
  int denominator = arg1.toInt();

  QString current =  shortestNote_comboBox->currentText();

  if(current.isEmpty())
  {
    return;
  }

//  int current_shortest = current.toInt();


//  if( current_shortest < denominator)
  {
    initialize_shortestNote_comboBox(denominator);
    shortestNote_comboBox->setCurrentText(current);
  }
}

