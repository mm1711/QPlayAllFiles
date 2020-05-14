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


CMIDIInstrumentsDialog::CMIDIInstrumentsDialog(QWidget *parent) :
  QDialog(parent)
{

  buttonBox = new QDialogButtonBox(this);
  buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
  buttonBox->setGeometry(QRect(20, 280, 511, 32));
  buttonBox->setOrientation(Qt::Horizontal);
  buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

  horizontalLayout1 = new QHBoxLayout;
  horizontalLayout1->setContentsMargins(0, 0, 0, 0);

  header1 = new QLabel;
  header1->setText(tr("Voice"));
  horizontalLayout1->addWidget(header1);

  header2 = new QLabel;
  header2->setText(tr("MIDI Instrument"));
  horizontalLayout1->addWidget(header2);

  QVBoxLayout *mainLayout = new QVBoxLayout;

  mainLayout->addLayout(horizontalLayout1);


  for(int ix = 0; ix < c_max_midi_voices; ix++)
  {
    horizontalLayout[ix] = new QHBoxLayout;
    horizontalLayout[ix]->setContentsMargins(0, 0, 0, 0);
    m_midi_instruments_label[ix] = new QLabel;
    m_midi_instruments_label[ix]->setNum(ix);
    horizontalLayout[ix]->addWidget(m_midi_instruments_label[ix]);
    m_midi_instruments[ix] = new QComboBox;
    m_midi_instruments[ix]->addItems(c_general_midi);
    horizontalLayout[ix]->addWidget(m_midi_instruments[ix] );
    mainLayout->addLayout(horizontalLayout[ix]);
  }

  mainLayout->addWidget(buttonBox);
  setLayout(mainLayout);

  connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
  connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

  adjustSize();
}

CMIDIInstrumentsDialog::~CMIDIInstrumentsDialog()
{
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

