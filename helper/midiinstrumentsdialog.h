/*! \file  midiinstrumentsdialog.h

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

#ifndef MIDIINSTRUMENTSDIALOG_H
#define MIDIINSTRUMENTSDIALOG_H

#include <QDialog>
#include <QComboBox>
#include <QDialogButtonBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>



class CMIDIInstrumentsDialog : public QDialog
{
  Q_OBJECT

public:
  explicit CMIDIInstrumentsDialog(QWidget *parent = nullptr);
  ~CMIDIInstrumentsDialog();
  void setMIDI_Instruments(qint32 *midi_instruments, qint32 size);
  void getMIDI_Instruments(qint32 *midi_instruments, qint32 size);

private:

  // constants
  static const quint8 c_max_midi_voices = 16;         /*!< maximum MIDI voices defined by MIDI spec */

//  QComboBox   *m_midi_instruments[c_max_midi_voices]; /*!< QComboBox for each MIDI voice */

  QDialogButtonBox *buttonBox;
  QLabel *header1;
  QLabel *header2;
  QHBoxLayout *horizontalLayout1;
  QLabel *m_midi_instruments_label[c_max_midi_voices];
  QComboBox *m_midi_instruments[c_max_midi_voices];     /*!< QComboBox for each MIDI voice */
  QHBoxLayout *horizontalLayout[c_max_midi_voices];

  /*! General MIDI instrument names
   */
  const QStringList c_general_midi =
  {
    "AcousticGrandPiano",
    "BrightAcousticPiano",
    "ElectricGrandPiano",
    "HonkyTonkPiano",
    "ElectricPiano1",
    "ElectricPiano2",
    "Harpsichord",
    "Clavinet",
    "Celesta",
    "Glockenspiel",
    "MusicBox",
    "Vibraphone",
    "Marimba",
    "Xylophone",
    "TubularBells",
    "Dulcimer",
    "DrawbarOrgan",
    "PercussiveOrgan",
    "RockOrgan",
    "ChurchOrgan",
    "ReedOrgan",
    "Accordion",
    "Harmonica",
    "TangoAccordion",
    "AcousticGuitarNylon",
    "AcousticGuitarSteel",
    "ElectricGuitarJazz",
    "ElectricGuitarClean",
    "ElectricGuitarMuted",
    "OverdrivenGuitar",
    "DistortionGuitar",
    "GuitarHarmonics",
    "AcousticBass",
    "ElectricBassFinger",
    "ElectricBassPick",
    "FretlessBass",
    "SlapBass1",
    "SlapBass2",
    "SynthBass1",
    "SynthBass2",
    "Violin",
    "Viola",
    "Cello",
    "Contrabass",
    "TremoloStrings",
    "PizzicatoStrings",
    "OrchestralHarp",
    "Timpani",
    "StringEnsemble1",
    "StringEnsemble2",
    "SynthStrings1",
    "SynthStrings2",
    "ChoirAahs",
    "VoiceOohs",
    "SynthVoice",
    "OrchestraHit",
    "Trumpet",
    "Trombone",
    "Tuba",
    "MutedTrumpet",
    "FrenchHorn",
    "BrassSection",
    "SynthBrass1",
    "SynthBrass2",
    "SopranoSax",
    "AltoSax",
    "TenorSax",
    "BaritoneSax",
    "Oboe",
    "EnglishHorn",
    "Bassoon",
    "Clarinet",
    "Piccolo",
    "Flute",
    "Recorder",
    "PanFlute",
    "BlownBottle",
    "Shakuhachi",
    "Whistle",
    "Ocarina",
    "Lead1Square",
    "Lead2Sawtooth",
    "Lead3Calliope",
    "Lead4Chiff",
    "Lead5Charang",
    "Lead6Voice",
    "Lead7Fifths",
    "Lead8BassAndLead",
    "Pad1NewAge",
    "Pad2Warm",
    "Pad3Polysynth",
    "Pad4Choir",
    "Pad5Bowed",
    "Pad6Metallic",
    "Pad7Halo",
    "Pad8Sweep",
    "Fx1Rain",
    "Fx2Soundtrack",
    "Fx3Crystal",
    "Fx4Atmosphere",
    "Fx5Brightness",
    "Fx6Goblins",
    "Fx7Echoes",
    "Fx8SciFi",
    "Sitar",
    "Banjo",
    "Shamisen",
    "Koto",
    "Kalimba",
    "BagPipe",
    "Fiddle",
    "Shanai",
    "TinkleBell",
    "Agogo",
    "SteelDrums",
    "Woodblock",
    "TaikoDrum",
    "MelodicTom",
    "SynthDrum",
    "ReverseCymbal",
    "GuitarFretNoise",
    "BreathNoise",
    "Seashore",
    "BirdTweet",
    "TelephoneRing",
    "Helicopter",
    "Applause",
    "Gunshot"
  };

};


#endif // MIDIINSTRUMENTSDIALOG_H
