/*! \file  midiinstrumentsdialog.cpp

GUI class for MIDI instruments setup dialog

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

#include "midiinstrumentsdialog.h"
#include "ui_midiinstrumentsdialog.h"

CMIDIInstrumentsDialog::CMIDIInstrumentsDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::CMIDIInstrumentsDialog)
{
  ui->setupUi(this);

  setupMIDI_Instruments();
}

CMIDIInstrumentsDialog::~CMIDIInstrumentsDialog()
{
  delete ui;
}

/*! Set MIDI instruments QComboBoxes


<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
void CMIDIInstrumentsDialog::setMIDI_Instruments(qint32 *midi_instruments, qint32 size)
{
  for(int ix = 0; ix < size && ix < c_max_midi_voices; ix++)
  {
    m_midi_instruments[ix]->setCurrentIndex(midi_instruments[ix]);
  }
}

/*! Get MIDI instruments QComboBoxes values


<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
void CMIDIInstrumentsDialog::getMIDI_Instruments(qint32 *midi_instruments, qint32 size)
{
  for(int ix = 0; ix < size && ix < c_max_midi_voices; ix++)
  {
    midi_instruments[ix] = m_midi_instruments[ix]->currentIndex();
  }
}

/*! Setup MIDI instruments QComboBoxes


<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
void  CMIDIInstrumentsDialog::setupMIDI_Instruments()
{
  ui->midi_voice_comboBox_0->addItems(c_general_midi);
  m_midi_instruments[0] = ui->midi_voice_comboBox_0;
  ui->midi_voice_comboBox_1->addItems(c_general_midi);
  m_midi_instruments[1] = ui->midi_voice_comboBox_1;
  ui->midi_voice_comboBox_2->addItems(c_general_midi);
  m_midi_instruments[2] = ui->midi_voice_comboBox_2;
  ui->midi_voice_comboBox_3->addItems(c_general_midi);
  m_midi_instruments[3] = ui->midi_voice_comboBox_3;
  ui->midi_voice_comboBox_4->addItems(c_general_midi);
  m_midi_instruments[4] = ui->midi_voice_comboBox_4;
  ui->midi_voice_comboBox_5->addItems(c_general_midi);
  m_midi_instruments[5] = ui->midi_voice_comboBox_5;
  ui->midi_voice_comboBox_6->addItems(c_general_midi);
  m_midi_instruments[6] = ui->midi_voice_comboBox_6;
  ui->midi_voice_comboBox_7->addItems(c_general_midi);
  m_midi_instruments[7] = ui->midi_voice_comboBox_7;
  ui->midi_voice_comboBox_8->addItems(c_general_midi);
  m_midi_instruments[8] = ui->midi_voice_comboBox_8;
  ui->midi_voice_comboBox_9->addItems(c_general_midi);
  m_midi_instruments[9] = ui->midi_voice_comboBox_9;
  ui->midi_voice_comboBox_10->addItems(c_general_midi);
  m_midi_instruments[10] = ui->midi_voice_comboBox_10;
  ui->midi_voice_comboBox_11->addItems(c_general_midi);
  m_midi_instruments[11] = ui->midi_voice_comboBox_11;
  ui->midi_voice_comboBox_12->addItems(c_general_midi);
  m_midi_instruments[12] = ui->midi_voice_comboBox_12;
  ui->midi_voice_comboBox_13->addItems(c_general_midi);
  m_midi_instruments[13] = ui->midi_voice_comboBox_13;
  ui->midi_voice_comboBox_14->addItems(c_general_midi);
  m_midi_instruments[14] = ui->midi_voice_comboBox_14;
  ui->midi_voice_comboBox_15->addItems(c_general_midi);
  m_midi_instruments[15] = ui->midi_voice_comboBox_15;
}
