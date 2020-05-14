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
#include "ui_settingsdialog.h"

CSettingsDialog::CSettingsDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::CSettingsDialog)
{
  ui->setupUi(this);

  setWindowTitle(tr("Settings"));

  m_file_size = 0;
  m_midi_out = new QMidiOut();
  m_max_channels = 99;

  QStringList denominators;
  denominators << "4" << "8" << "16" << "32" ;
  ui->Denominator_comboBox->addItems(denominators);
  ui->shortestNote_comboBox->addItems(denominators);
  ui->Accent_spinBox->setValue(1);

  QMap<QString /* key */, QString /* name */> midimap = m_midi_out->devices();
  for(int ix = 0; ix < midimap.size(); ix++)
  {
    ui->MIDI_Interface_comboBox->addItem(midimap[QString::number(ix)]);
  }

  QAudioRecorder *audioRecorder = new QAudioRecorder(this);

  ui->audio_Interface_comboBox->addItems(audioRecorder->audioInputs());
  ui->audio_codec_comboBox->addItems(audioRecorder->supportedAudioCodecs());
  ui->audio_container_comboBox->addItems(audioRecorder->supportedContainers());

  QList<int> sample_rates = audioRecorder->supportedAudioSampleRates();

  for (int kk = 0; kk < sample_rates.size(); kk++)
  {
    ui->audio_sampling_rate_comboBox->addItem(QString::number(sample_rates.at(kk)));
  }
}

CSettingsDialog::~CSettingsDialog()
{
  delete ui;
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
  ui->channels_spinBox->setMaximum(m_max_channels);
  ui->channels_spinBox->setValue(settings.m_current_max_channels);
  ui->BPM_lineEdit->setText(QString::number(settings.m_BPM));
  ui->Numerator_spinBox->setValue(settings.m_bar_numerator);

  ui->Denominator_comboBox->setCurrentText(QString::number(settings.m_bar_denominator));

  ui->Accent_spinBox->setValue(settings.m_bar_accent);
  ui->Accent_spinBox->setMaximum(settings.m_bar_numerator);

  initialize_shortestNote_comboBox(settings.m_bar_denominator);
  ui->shortestNote_comboBox->setCurrentText(QString::number(settings.m_shortest_note));

  ui->intervalVariation_checkBox->setChecked(settings.m_with_interval_variation);
  ui->minIntervalVariation_spinBox->setValue(settings.m_min_interval_variation);
  ui->maxIntervalVariation_spinBox->setValue(settings.m_max_interval_variation);
  ui->metronome_checkBox->setChecked(settings.m_with_metronome);
  ui->metronom_spinBox->setValue(settings.m_metronome_note);

  ui->staccato_checkBox->setChecked(settings.m_Staccato);
  ui->loop_checkBox->setChecked(settings.m_Loop);
  ui->firstSegment_lineEdit->setText(QString::number(settings.m_FirstSegment));
  ui->lastSegment_lineEdit->setText(QString::number(settings.m_LastSegment));

  if(!settings.m_audio_interface.isEmpty())
  {
    ui->audio_Interface_comboBox->setCurrentIndex(
          ui->audio_Interface_comboBox->findText(settings.m_audio_interface));
  }

  if(!settings.m_audio_codec.isEmpty())
  {
    ui->audio_codec_comboBox->setCurrentIndex(
          ui->audio_codec_comboBox->findText(settings.m_audio_codec));
  }

  if(!settings.m_audio_container.isEmpty())
  {
    ui->audio_container_comboBox->setCurrentIndex(
          ui->audio_container_comboBox->findText(settings.m_audio_container));
  }

  ui->audio_sampling_rate_comboBox->setCurrentIndex(
        ui->audio_sampling_rate_comboBox->findText(QString::number(settings.m_audio_sample_rate)));

  if(!settings.m_midi_out_name.isEmpty())
  {
    ui->MIDI_Interface_comboBox->setCurrentIndex(
          ui->MIDI_Interface_comboBox->findText(settings.m_midi_out_name));
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
  ui->shortestNote_comboBox->clear();
  ui->shortestNote_comboBox->addItems(denominators);
}


/*! Return dialog controls values in 'settings'


<b>History   :</b>
26-09-2019mm  created by Michael Moser
13-05-2020mm  get values from m_bar_numerator, m_bar_denominator,
              m_shortest_note and m_bar_accent
*/
void CSettingsDialog::getSettings(CSettings& settings)
{
  settings.m_current_max_channels = ui->channels_spinBox->value();
  settings.m_BPM = ui->BPM_lineEdit->text().toInt();
  settings.m_bar_numerator = ui->Numerator_spinBox->value();
  settings.m_bar_denominator = (ui->Denominator_comboBox->currentText()).toInt();
  settings.m_bar_accent = ui->Accent_spinBox->value();
  settings.m_shortest_note = (ui->shortestNote_comboBox->currentText()).toInt();
  settings.m_Staccato = ui->staccato_checkBox->isChecked();
  settings.m_Loop = ui->loop_checkBox->isChecked();
  settings.m_FirstSegment = ui->firstSegment_lineEdit->text().toLongLong();
  settings.m_LastSegment = ui->lastSegment_lineEdit->text().toLongLong();
  settings.m_audio_interface = ui->audio_Interface_comboBox->currentText();
  settings.m_audio_codec = ui->audio_codec_comboBox->currentText();
  settings.m_audio_container = ui->audio_container_comboBox->currentText();
  settings.m_audio_sample_rate = ui->audio_sampling_rate_comboBox->currentText().toInt();
  settings.m_midi_out_name = ui->MIDI_Interface_comboBox->currentText();
  settings.m_with_interval_variation = ui->intervalVariation_checkBox->isChecked();
  settings.m_min_interval_variation = ui->minIntervalVariation_spinBox->value();
  settings.m_max_interval_variation = ui->maxIntervalVariation_spinBox->value();
  settings.m_with_metronome = ui->metronome_checkBox->isChecked();
  settings.m_metronome_note = ui->metronom_spinBox->value();
}

/*! Event handler for "First" button

  Set firstSegment_lineEdit to 0

<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
void CSettingsDialog::on_set_first_segment_Btn_clicked()
{
  ui->firstSegment_lineEdit->setText("0");
}

/*! Event handler for "Last" button

  Set lastSegment_lineEdit to last available segment

<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
void CSettingsDialog::on_set_last_segment_Btn_clicked()
{
  if(ui->channels_spinBox->value() > 0)
  {
    ui->lastSegment_lineEdit->setText(QString::number((m_file_size / ui->channels_spinBox->value())));
  }
}

/*! Event handler for channels_spinBox changed value

  When the channel count is changed, update lastSegment_lineEdit value

<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
void CSettingsDialog::on_channels_spinBox_valueChanged(int )
{
  on_set_last_segment_Btn_clicked();
}

/*! Event handler for Numerator_spinBox changed value

  When the bar numerator is changed, update maximum value of Accent_spinBox

<b>History   :</b>
13-05-2020mm created by Michael Moser
*/
void CSettingsDialog::on_Numerator_spinBox_valueChanged(int arg1)
{
  ui->Accent_spinBox->setMaximum(arg1);
}

/*! Event handler for Denominator_comboBox changed value

  When the bar denominator is changed, update values in shortestNote_comboBox

<b>History   :</b>
13-05-2020mm created by Michael Moser
*/
void CSettingsDialog::on_Denominator_comboBox_currentIndexChanged(const QString &arg1)
{
  int denominator = arg1.toInt();

  QString current =  ui->shortestNote_comboBox->currentText();

  if(current.isEmpty())
  {
    return;
  }

  int current_shortest = current.toInt();


//  if( current_shortest < denominator)
  {
    initialize_shortestNote_comboBox(denominator);
    ui->shortestNote_comboBox->setCurrentText(current);
  }
}

