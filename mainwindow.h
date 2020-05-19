/*! \file  mainwindow.h

Definition of QMainWindow GUI class.

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



#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QSpinBox>
#include <QLabel>
#include <QStringList>
#include <QGridLayout>
#include <QScrollArea>
#include <QFileDialog>
#include <QTextStream>
#include <QFile>
#include <QPainter>
#include <QTimer>
#include <QAudioRecorder>
#include <QAudioDeviceInfo>
#include <QAudioProbe>
#include <QSettings>
#include <QRandomGenerator>

#include "./helper/segmentrenderarea.h"
#include "./helper/bitstobytes.h"
#include "./helper/channelproperties.h"
#include "./helper/settings.h"
#include "./helper/settingsdialog.h"
#include "./helper/midiinstrumentsdialog.h"
#include "./QMidi/src/QMidiOut.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void midi_clock_timeout();
  void on_btnSetNotes_clicked();
  void on_playBtn_clicked();
  void on_stopBtn_clicked();
  void on_actionOpen_triggered();
  void on_actionClose_triggered();
  void on_actionOpen_Config_triggered();
  void on_actionSave_Config_triggered();
  void on_actionSave_Config_As_triggered();
  void on_actionSettings_triggered();
  void on_actionMIDI_Instruments_triggered();

  void updateStatus(QMediaRecorder::Status);
  void updateProgress(qint64 pos);
  void displayErrorMessage();




private:
  Ui::MainWindow *ui;

  // constants
  const QString version = "0.3";                                  /*!< Application version string */
  const QString c_settings_version = "version;1.0;";              /*!< identifier for version of ini file */
  static const qint32 c_max_channel_count = 88;                   /*!< maximum channels */
  static const qint32 c_max_visible_segments = 156;               /*!< maximum visible segments */
  static const qint32 c_max_segments = 2*c_max_visible_segments;  /*!< maximum segments in data buffer */
  static const quint8 c_max_midi_voices = 16;                     /*!< maximum MIDI voices defined by MIDI spec */
  static const qint32 c_max_midi_instruments = 128;               /*!< maximum MIDI instruments defined by MIDI spec */
  static const qint32 c_max_scales = 15;                          /*!< maximum scale count */
  static const qint32 c_max_pattern = 7;                          /*!< maximum elements in halftone mode formulas */
  static const qint32 c_BMP = 180;                                /*!< default beats per minute */
  static const qint32 c_audio_sample_rate = 48000;                /*!< default audio sample rate for recording */
  static const bool   c_Staccato = false;                         /*!< default staccato setting */
  static const bool   c_Loop = false;                             /*!< default loop setting */
  static const quint8 c_invalid_note = 255;                       /*!< Marker for invalid/unused notes */
  static const qint32 c_input_buffer_size = 4096;                 /*!< Buffer size for file input */

  QString app_caption;                                  /*!< Window titel of application */

  // settings
  CSettings m_settings;                                 /*!< Application settings container */
  QString   m_last_config_path;                         /*!< Last path for config files */
  QString   m_last_data_path;                           /*!< Last path for data files */
  QString   m_last_config_file;                         /*!< Last path for config file name */


  QString m_filename;                                   /*!< Filename for data input file */
  CBitsToBytes *m_bits_to_bytes;                        /*!< Helper class for converting the bit stream from file to a byte array */
  CChannelProperties *m_channels[c_max_channel_count] = { nullptr }; /*!< Properties of the defined channels */
  QAudioRecorder *m_audioRecorder = nullptr;            /*!< Instance of QAudioRecorder for recording the played segments */
  QMidiOut *m_midi_out;                                 /*!< Instance of QMidiOut for playing the segments */
  int    m_midi_clock_interval;                         /*!< MIDI timer interval calculated from BPM (beats per minute) setting */
  QTimer *m_midi_clock;                                 /*!< MIDI timer for playing the segments */
  CSegmentRenderArea *m_segmentRenderArea;              /*!< Widget for painting the segments */

  QLabel  *m_status_bar_label_recording;                /*!< Status bar widget for displaying recording status information */
  QLabel  *m_status_bar_label;                          /*!< Status bar widget for displaying current played segment number */
  qint32  m_midi_instruments[c_max_midi_voices] = {0};  /*!< Defined MIDI instruments per MIDI voice defined in File -> Settings dialog */

  qint32 m_buffer_read_size;                            /*!< Read buffer size depending on max channels and constant c_max_segments */
  char  m_buffer[c_max_segments*c_max_channel_count];   /*!< Buffer for input data */

  bool   m_playing;                                     /*!< Flag for playing state */
  bool   m_init_play;                                   /*!< Flag for initializing play settings. False for transition PAUSE -> PLAY */

  qint64 m_current_segment;                             /*!< Currently played segment */
  qint32 m_current_scale = 0;                           /*!< Current selected scale (C,D,E,..) */
  qint32 m_current_mode = 0;                            /*!< Current selected mode (Major, Minor, Dorian, ...) */
  qint32 m_current_count_time;                          /*!< Current count time in bar 4/4 => 0 1 2 3, 0 1 2 3 ... */
  qint64 m_current_played_note;                         /*!< Currently played note from start of playing */

  QRandomGenerator m_prng;


  void resizeEvent(QResizeEvent* event);
  void setupControls();
  void setupChannels(QWidget* parent);
  void setupMIDI_Instruments();
  bool openFile();
  void closeFile();
  bool openMIDI();
  void closeMIDI();
  void start_audio_recording();
  void stop_audio_recording();
  void pause_audio_recording();
  void resume_audio_recording();
  int play_segment(char *segment);
  void init_MIDI_instruments();
  void all_notes_off();
  void clear_tone_state();
  void position_segment(qint64 segment);
  void saveConfigFile(QString& fileName);
  void saveConfig(QTextStream& os);
  void restoreConfig(QFile& in);
  void loadConfig(QString& fileName);
  QString saveMIDI_Instruments();
  bool restoreMIDI_Instruments(QStringList instruments_list, QString version);
  QString saveAudioSettings();
  bool restoreAudioSettings(QStringList audio_settings_list, QString version);
  QString saveScaleSettings();
  bool restoreScaleSettings(QStringList scales_list, QString version);
  QString saveGeneralSettings();
  bool restoreGeneralSettings(QStringList general_list, QString version);
  bool restoreChannelSettings(QString chn_props, qint32 chn_ix, QString version);
  void show_hide_channels();
  double calculate_interval();

  // constant data items
  const QString c_general_settings = "general_settings;"; /*!< identifier for general settings in ini file */
  const qint32  c_general_settings_v1_0_len = 9;          /*!< V1.0 general settings elements count */
  const QString c_midi_instruments = "midi_instruments;"; /*!< identifier for midi instruments in ini file */
  const qint32  c_midi_instruments_len = 17;              /*!< V1.0 midi instruments elements count */
  const QString c_audio_settings = "audio_settings;";     /*!< identifier for audio settings in ini file */
  const qint32  c_audio_settings_v1_0_len = 5;            /*!< V1.0 audio settings elements count */
  const QString c_scale_settings = "scale_settings;";     /*!< identifier for scale settings in ini file */
  const qint32  c_scale_settings_v1_0_len = 5;            /*!< V1.0 scale settings elements count */
  const qint32  c_channels_y_pos_start = 70;              /*!< Y start position for channels */
  /*! Start notes for different scales
   */
  const int c_start_notes[14] =
  {
    0, // for "Chromatic" setting
    0, // C Dur
    7, 2, 9, 4, 11, 6,
    5, 10, 3, 8, 1, 6
  };

  /*! Octave names for octave_comboBox
   */
  const QStringList c_octaves =
  {
    "C-1", "C0", "C1", "C2", "C3", "C4", "C5", "C6"
  };

  /*! Scale names for scale_comboBox
   */
  const QStringList c_scale_Names =
  {
    "Chromatic",
    "C",
    "G",
    "D",
    "A",
    "E",
    "B",
    "F#",
    "F",
    "Bb",
    "Eb",
    "Ab",
    "Db",
    "Gb"
  };

  /*! Mode names for mode_comboBox
   */
  const QStringList c_scale_Modes =
  {
    "Major",
    "Major roma",
    "Minor natural",
    "Minor harmonic",
    "Minor melodic",
    "Minor roma",
    "Dorian",
    "Phrygian",
    "Lydian",
    "Mixolydian",
    "Aeolian",
    "Lokrian",
    "Purvi",
    "Marava",
    "Todi"
  };

  /*! Halftone mode formulas
   */
  const int c_scale_pattern[c_max_scales][c_max_pattern] =
  {
    { 2, 2, 1, 2, 2, 2, 1 }, // Dur
    { 1, 3, 1, 2, 1, 3, 1 }, // Dur roma
    { 2, 1, 2, 2, 1, 2, 2 }, // Moll natural
    { 2, 1, 2, 2, 1, 3, 1 }, // Moll harmonic
    { 2, 1, 2, 2, 2, 2, 1 }, // Moll melodic
    { 2, 1, 3, 1, 1, 3, 1 }, // Moll roma
    { 2, 1, 2, 2, 2, 1, 2 }, // Dorian
    { 1, 2, 2, 2, 1, 2, 2 }, // Phrygian
    { 2, 2, 2, 1, 2, 2, 1 }, // Lydian
    { 2, 2, 1, 2, 2, 1, 2 }, // Mixolydian
    { 2, 1, 2, 2, 1, 2, 2 }, // Aeolian
    { 1, 2, 2, 1, 2, 2, 2 }, // Lokrian
    { 1, 3, 2, 1, 1, 3, 1 }, // Purvi
    { 1, 3, 2, 1, 2, 2, 1 }, // Marava
    { 1, 2, 3, 1, 1, 3, 1 }  // Todi
  };

  /*! List with prim numbers 2 ... 2003
   */
  const QVector<int> primeList =
  {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
    31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
    73, 79, 83, 89, 97, 101, 103, 107, 109, 113,
    127,131,137,139,149,151,157,163,167,173,
    179,181,191,193,197,199,211,223,227,229,
    233,239,241,251,257,263,269,271,277,281,
    283,293,307,311,313,317,331,337,347,349,
    353,359,367,373,379,383,389,397,401,409,
    419,421,431,433,439,443,449,457,461,463,
    467,479,487,491,499,503,509,521,523,541,
    547,557,563,569,571,577,587,593,599,601,
    607,613,617,619,631,641,643,647,653,659,
    661,673,677,683,691,701,709,719,727,733,
    739,743,751,757,761,769,773,787,797,809,
    811,821,823,827,829,839,853,857,859,863,
    877,881,883,887,907,911,919,929,937,941,
    947,953,967,971,977,983,991,997,1009,1013,
    1019,1021,1031,1033,1039,1049,1051,1061,1063,1069,
    1087,1091,1093,1097,1103,1109,1117,1123,1129,1151,
    1153,1163,1171,1181,1187,1193,1201,1213,1217,1223,
    1229,1231,1237,1249,1259,1277,1279,1283,1289,1291,
    1297,1301,1303,1307,1319,1321,1327,1361,1367,1373,
    1381,1399,1409,1423,1427,1429,1433,1439,1447,1451,
    1453,1459,1471,1481,1483,1487,1489,1493,1499,1511,
    1523,1531,1543,1549,1553,1559,1567,1571,1579,1583,
    1597,1601,1607,1609,1613,1619,1621,1627,1637,1657,
    1663,1667,1669,1693,1697,1699,1709,1721,1723,1733,
    1741,1747,1753,1759,1777,1783,1787,1789,1801,1811,
    1823,1831,1847,1861,1867,1871,1873,1877,1879,1889,
    1901,1907,1913,1931,1933,1949,1951,1973,1979,1987,
    1993,1997,1999,2003
  };
 };
#endif // MAINWINDOW_H
