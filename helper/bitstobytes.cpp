/*! \file  bitstobytes.cpp

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

#include "bitstobytes.h"


CBitsToBytes::CBitsToBytes( quint32 byte_buffer_size )
{
  m_in = nullptr;
  m_available_bytes = 0;
  m_curr_byte_ix = 0;
  m_curr_bit_ix = 0;
  m_byte_buffer_size = byte_buffer_size;
  m_byte_buffer = nullptr;

  m_byte_buffer = new char[byte_buffer_size];

  if(m_byte_buffer != nullptr)
  {
    memset(m_byte_buffer, '\0', m_byte_buffer_size);
  }
}

CBitsToBytes::~CBitsToBytes()
{
  closeBitFile();
  if(m_byte_buffer != nullptr)
  {
    delete [] m_byte_buffer;
  }

}


/*! open bit file and fill the buffer

  Check whether path is empty
      Return with false
  Check if there is already a file open
      Close the file and destroy QFile object
  Create new QFile object
  Open input file
  Read m_byte_buffer_size from the input file

<b>History   :</b>	26-09-2019mm created by Michael Moser
*/
bool CBitsToBytes::openBitFile(QString& path)
{
  if(path.isEmpty())
  {
    qDebug("openBitFile: path is empty!");
    return false;
  }

  if(m_in != nullptr)
  {
    m_in->close();
    delete m_in;
  }

  m_in = new QFile(path);
  if( m_in == nullptr)
  {
    qDebug("openBitFile: new QFile() failed");
    return false;
  }

  // open input file
  if(!m_in->open(QIODevice::ReadOnly))
  {
    qDebug("openBitFile: open file failed");
    return false;
  }

  m_curr_byte_ix = 0;
  m_curr_bit_ix = 0;
  if(m_byte_buffer != nullptr)
  {
    m_available_bytes = static_cast<quint32>(m_in->read(static_cast<char *>(m_byte_buffer), m_byte_buffer_size));
  }
  else
  {
    qDebug("openBitFile: no buffer available");
    m_available_bytes = 0;
  }

  return true;
}

/*! Close input file


<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
void CBitsToBytes::closeBitFile()
{
  if(m_in != nullptr)
  {
    m_in->close();
    delete m_in;
    m_in = nullptr;
  }
}

/*! Convert bits to bytes

  Create a byte for each bit in the bytes of the input buffer
  Example: Input byte   0x55 01010101b =>
           Output bytes 0x00 0x01 0x00 0x01 0x00 0x01 0x00 0x01

  Refill input buffer if necessary.
  Return the count of read bits.

  \param  buf           output byte buffer
  \param  bits_to_read  count of bits to read

<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
quint32 CBitsToBytes::readBitsAsBytes(char *buf, quint32 bits_to_read)
{
//  qDebug("readBitsAsBytes: bits_to_read=%d byte_ix=%d bit_ix=%d", bits_to_read, m_curr_byte_ix, m_curr_bit_ix);

  if((m_in != nullptr) && (m_byte_buffer != nullptr))
  {
    quint8 curr_byte = static_cast<quint8>(m_byte_buffer[m_curr_byte_ix]);

    for(quint32 ix = 0; ix < bits_to_read; ix++)
    {
      buf[ix] = ((curr_byte & (1 << m_curr_bit_ix)) != 0) ? 1 : 0;
      if (m_curr_bit_ix++ >= 7)
      {
        m_curr_bit_ix = 0;
        if(m_curr_byte_ix++ >= m_available_bytes)
        {
          // refill byte buffer from file
          m_available_bytes = static_cast<quint32>(m_in->read(m_byte_buffer, m_byte_buffer_size));
          m_curr_byte_ix = 0;
          if(m_available_bytes == 0)
          {
            // EOF reached
            return ix;
          }
        }
        curr_byte = static_cast<quint8>(m_byte_buffer[m_curr_byte_ix]);
      }
    }

    return bits_to_read;
  }
  else
  {
    return 0;
  }
}

/*! Set internal bit index to bit_position

  Calculate the byte position from bit_position
  Move the file position to the byte position
  Fill input buffer from this position

  \param bit_position  new bit position in input file

<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
void CBitsToBytes::set_bit_position(qint64 bit_position)
{
  qint64 byte_position = bit_position / 8;

  qDebug("set_bit_position(%d): byte_position=%d", bit_position, byte_position);

  if(!m_in->seek(byte_position))
  {
    qDebug("set_bit_position: seek(%d) failed!", byte_position);
  }

  m_curr_bit_ix = bit_position % 8;
  m_available_bytes = static_cast<quint32>(m_in->read(m_byte_buffer, m_byte_buffer_size));
  m_curr_byte_ix = 0;
}

/*! Return the size of the input file


<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
qint64  CBitsToBytes::getFileSize()
{
  if( m_in != nullptr)
  {
    return m_in->size();
  }
  else
  {
    return 0;
  }
}
