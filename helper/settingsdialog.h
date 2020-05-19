/*! \file  settingsdialog.h

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

#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QComboBox>
#include <QAudioRecorder>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

#include "../helper/settings.h"
#include "../QMidi/src/QMidiOut.h"
#include "../helper/channelproperties.h"

namespace Ui {
class CSettingsDialog;
}

class CSettingsDialog : public QDialog
{
  Q_OBJECT

public:
  explicit CSettingsDialog(QWidget *parent = nullptr);
  ~CSettingsDialog();
  void    setSettings(CSettings settings);
  void    getSettings(CSettings& settings);
  void    setFileSize(qint64 file_size) { m_file_size = file_size; }
  void    setMaxChannels(qint32 max_channels) { m_max_channels = max_channels; }

private slots:
  void on_set_last_segment_Btn_clicked();
  void on_set_first_segment_Btn_clicked();
  void on_channels_spinBox_valueChanged(int );
  void on_Numerator_spinBox_valueChanged(int arg1);
  void on_Denominator_comboBox_currentIndexChanged(const QString &arg1);

private:
  void initialize_shortestNote_comboBox(int denominator);

  Ui::CSettingsDialog *ui;

  QLabel *label_channel;
  QSpinBox *channels_spinBox;
  QLabel *label_BPM;
  QLineEdit *BPM_lineEdit;
  QLabel *label_numerator;
  QSpinBox *Numerator_spinBox;
  QComboBox *Denominator_comboBox;
  QLabel *label_accent;
  QSpinBox *Accent_spinBox;
  QLabel *label_shortest;
  QComboBox *shortestNote_comboBox;
  QCheckBox *intervalVariation_checkBox;
  QLabel *label_min_interval;
  QSpinBox *minIntervalVariation_spinBox;
  QLabel *label_max_interval;
  QSpinBox *maxIntervalVariation_spinBox;
  QLabel *label_ms;
  QCheckBox *metronome_checkBox;
  QComboBox *metronomInstrument_comboBox;
  QCheckBox *staccato_checkBox;
  QCheckBox *loop_checkBox;
  QLabel *label_firstSegment;
  QLineEdit *firstSegment_lineEdit;
  QPushButton *set_first_segment_Btn;
  QLabel *label_lastSegment;
  QLineEdit *lastSegment_lineEdit;
  QPushButton *set_last_segment_Btn;
  QLabel *label_audio_interface;
  QComboBox *audio_Interface_comboBox;
  QLabel *label_audio_codec;
  QComboBox *audio_codec_comboBox;
  QLabel *label_audio_sampling_rate;
  QComboBox *audio_sampling_rate_comboBox;
  QLabel *label_audio_container;
  QComboBox *audio_container_comboBox;
  QLabel *label_midi_interface;
  QComboBox *MIDI_Interface_comboBox;
  QDialogButtonBox *buttonBox;



  QMidiOut *m_midi_out;
  QString m_midi_name;
  qint64  m_file_size;
  qint32  m_max_channels;
};

#endif // SETTINGSDIALOG_H
