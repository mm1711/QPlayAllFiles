/*! \file  channelproperties.h

Widget code for handling the channel properties

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

#ifndef CHANNELPROPERTIES_H
#define CHANNELPROPERTIES_H

#include <QWidget>
#include <QComboBox>
#include <QLineEdit>
#include <QSpinBox>
#include <QStringList>

namespace Ui {
class CChannelProperties;
}

class CChannelProperties : public QWidget
{
  Q_OBJECT

public:
  explicit CChannelProperties(QWidget *parent = nullptr);
  ~CChannelProperties();
  QString getPropID() { return c_prop_id; }
  qint32  getPropLength() { return c_chn_props_v1_0_len; }
  qint32  getCurrentVoiceIndex();
  void    setVoiceIndex(qint32 index);
  qint32  getCurrentVelocityIndex();
  qint32  getCurrentVelocityValue();
  void    setVelocityIndex(qint32 index);
  qint32  getCurrentNoteIndex();
  QString getCurrentNoteText();
  void    setNoteIndex(qint32 index);
  qint32  getCurrentGroup();
  void    setGroup(qint32 group);
  bool    getChannelState() { return m_channel_state;}
  void    setChannelState(bool value) { m_channel_state = value;}
  QString toString();
  void    fromString(QString settings);

  //! Constants for MIDI volume (note: in MIDI spec 'volume' is called 'velocity')
  static const quint8 c_velocity_pppp = 8;
  static const quint8 c_velocity_ppp  = 20;
  static const quint8 c_velocity_pp   = 31;
  static const quint8 c_velocity_p    = 42;
  static const quint8 c_velocity_mp   = 53;
  static const quint8 c_velocity_mf   = 64;
  static const quint8 c_velocity_f    = 80;
  static const quint8 c_velocity_ff   = 96;
  static const quint8 c_velocity_fff  = 112;
  static const quint8 c_velocity_ffff = 127;



private:
  Ui::CChannelProperties *ui;

  bool    m_channel_state;   /*!< Channel state: true = note is currently played  false = note is not currently not played */

// constants
  const QString c_prop_id = "chn_props;";     /*!< identifier for channels settings in ini file */
  const qint32  c_chn_props_v1_0_len = 5;     /*!< V1.0 channels settings elements count */


  /*! Volume names for channels_velocity_comboBox
   */
  const QStringList c_velocity_names =
  {
    "pppp", "ppp", "pp", "p", "mp", "mf", "f", "ff", "fff", "ffff"
  } ;

  /*! Map volume names from channels_velocity_comboBox to velocity value
   */
  const QMap<QString /* key */, qint32 /* name */> c_velocity_map =
  {
    { c_velocity_names[0], c_velocity_pppp},
    { c_velocity_names[1], c_velocity_ppp},
    { c_velocity_names[2], c_velocity_pp},
    { c_velocity_names[3], c_velocity_p},
    { c_velocity_names[4], c_velocity_mp},
    { c_velocity_names[5], c_velocity_mf},
    { c_velocity_names[6], c_velocity_f},
    { c_velocity_names[7], c_velocity_ff},
    { c_velocity_names[8], c_velocity_fff},
    { c_velocity_names[9], c_velocity_ffff}
  };

  /*! Note names
   */
  const QStringList c_note_names =
  {
  // 0     1         2      3        4     5     6         7     8         9      10      11
    "C-1", "C#/Db-1", "D0-1", "D#/Eb-1", "E-1", "F-1", "F#/Gb-1", "G-1", "G#/Ab-1", "A-1", "A#/Bb-1", "B-1",
    "C0", "C#/Db0", "D0", "D#/Eb0", "E0", "F0", "F#/Gb0", "G0", "G#/Ab0", "A0", "A#/Bb0", "B0",
    "C1", "C#/Db1", "D1", "D#/Eb1", "E1", "F1", "F#/Gb1", "G1", "G#/Ab1", "A1", "A#/Bb1", "B1",
    "C2", "C#/Db2", "D2", "D#/Eb2", "E2", "F2", "F#/Gb2", "G2", "G#/Ab2", "A2", "A#/Bb2", "B2",
    "C3", "C#/Db3", "D3", "D#/Eb3", "E3", "F3", "F#/Gb3", "G3", "G#/Ab3", "A3", "A#/Bb3", "B3",
    "C4", "C#/Db4", "D4", "D#/Eb4", "E4", "F4", "F#/Gb4", "G4", "G#/Ab4", "A4", "A#/Bb4", "B4",
    "C5", "C#/Db5", "D5", "D#/Eb5", "E5", "F5", "F#/Gb5", "G5", "G#/Ab5", "A5", "A#/Bb5", "B5",
    "C6", "C#/Db6", "D6", "D#/Eb6", "E6", "F6", "F#/Gb6", "G6", "G#/Ab6", "A6", "A#/Bb6", "B6",
    "C7", "C#/Db7", "D7", "D#/Eb7", "E7", "F7", "F#/Gb7", "G6", "G#/Ab7", "A7", "A#/Bb7", "B7",
    "C8", "C#/Db8", "D8", "D#/Eb8", "E8", "F8", "F#/Gb8", "G8", "G#/Ab8", "A8", "A#/Bb8", "B8",
    "C9", "C#/Db9", "D9", "D#/Eb9", "E9", "F9", "F#/Gb9", "G9",
    "No Note"
  };

};

#endif // CHANNELPROPERTIES_H
