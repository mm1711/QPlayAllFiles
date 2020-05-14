/*! \file  settings.h

Class for application settings

<b>Copyright   :</b> (C) 2019 Michael Moser

<b>Last edit	:</b>

<b>History   :</b>
04-11-2019mm		creation by Michael Moser
13-05-2020mm    New members: m_bar_numerator, m_bar_denominator
                m_shortest_note and m_bar_accent
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

#ifndef CSETTINGS_H
#define CSETTINGS_H
#include <QtCore>

class CSettings
{
public:
  CSettings();

  qint32  m_current_max_channels = 13;  /*!< Channel count */
  qint32  m_BPM = 120;                  /*!< Beats Per Minute */
  bool    m_Staccato = 0;               /*!< Defines whether a note is turned off after each beat */
  bool    m_Loop = 0;                   /*!< Play segments in loop mode */
  qint64  m_FirstSegment = 0;           /*!< First segment to play */
  qint64  m_LastSegment = 0;            /*!< Last segment to play */
  QString m_audio_interface;            /*!< Audio interface for recording */
  QString m_audio_codec;                /*!< Audio codec for recording */
  QString m_audio_container;            /*!< Audio container format for recording */
  qint32  m_audio_sample_rate;          /*!< Audio sample rate for recording */
  QString m_midi_out_name;              /*!< MIDI interface name */
  qint32  m_bar_numerator = 4;          /*!< Bar Numerator */
  qint32  m_bar_denominator = 4;        /*!< Bar Denominator */
  qint32  m_bar_accent = 1;             /*!< Accent in Bar  */
  qint32  m_shortest_note = 4;          /*!< Shortest Note  */
  bool    m_with_interval_variation = 1; /*!< With variation of MIDI clock interval  */
  qint32  m_min_interval_variation = 5; /*!< Minimum variation of MIDI clock interval  */
  qint32  m_max_interval_variation = 20; /*!< Maximum variation of MIDI clock interval  */
  bool    m_with_metronome = 1;         /*!< With metronome channel  */
  qint32  m_metronome_note = 35;        /*!< Metronome note (= instrument)  */
};

#endif // CSETTINGS_H
