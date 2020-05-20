/*! \file  settings.cpp

Class for application settings

<b>Copyright   :</b> (C) 2019 Michael Moser

<b>Last edit	:</b>

<b>History   :</b>	04-11-2019mm		creation by Michael Moser

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

#include "settings.h"

CSettings::CSettings()
{

}

void CSettings::resetSettings()
{
  m_current_max_channels = 13;
  m_BPM = 120;
  m_Staccato = 0;
  m_Loop = 0;
  m_FirstSegment = 0;
  m_LastSegment = 0;
  m_audio_interface;
  m_audio_codec;
  m_audio_container;
  m_audio_sample_rate;
  m_midi_out_name;
  m_bar_numerator = 4;
  m_bar_denominator = 4;
  m_bar_accent = 1;
  m_shortest_note = 4;
  m_with_interval_variation = 1;
  m_min_interval_variation = 5;
  m_max_interval_variation = 20;
  m_with_metronome = 1;
  m_metronome_note = 40;
}
