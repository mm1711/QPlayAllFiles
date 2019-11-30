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
#include "../helper/settings.h"
#include "../QMidi/src/QMidiOut.h"

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

private:

  Ui::CSettingsDialog *ui;

  QMidiOut *m_midi_out;
  QString m_midi_name;
  qint64  m_file_size;
  qint32  m_max_channels;
};

#endif // SETTINGSDIALOG_H
