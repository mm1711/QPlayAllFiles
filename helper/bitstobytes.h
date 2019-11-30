/*! \file  bitstobytes.h

The class CBitsToBytes() handles the logic of converting a
bit stream from file into a byte array.

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

#ifndef CBITSTOBYTES_H
#define CBITSTOBYTES_H

#include <QFile>
#include <QString>


class CBitsToBytes
{
public:
  CBitsToBytes( quint32 byte_buffer_size );
  ~CBitsToBytes();

  bool openBitFile(QString& path);
  void closeBitFile();
  bool isBitFileOpen() { return (m_in != nullptr); }
  quint32 readBitsAsBytes(char *buf, quint32 bits_to_read);
  qint64  getFileSize();
  void    set_bit_position(qint64 bit_position);

protected:
  QFile *m_in;                /*!< QFile instance for input data file */

  quint32 m_byte_buffer_size; /*!< Max. size for input buffer set in ctor */
  quint32 m_available_bytes;  /*!< Currently available bytes in input buffer */
  quint32 m_curr_byte_ix;     /*!< Current byte index in input buffer */
  quint8  m_curr_bit_ix;      /*!< Current bit index in input buffer */
  char  *m_byte_buffer;       /*!< Dynamically allocated input buffer */


};

#endif // CBITSTOBYTES_H
