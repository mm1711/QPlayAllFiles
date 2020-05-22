/*! \file  segmentrenderarea.h

GUI class displaying the bit stream graphically

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

#ifndef SEGMENTRENDERAREA_H
#define SEGMENTRENDERAREA_H

#include <QWidget>
#include <QBrush>
#include <QPen>
#include <QPainter>
#include <QByteArray>

class CSegmentRenderArea : public QWidget
{
  Q_OBJECT

public:
  explicit CSegmentRenderArea(QWidget *parent = nullptr, qint32 max_segments = 250,  qint32 _channels = 127);
  ~CSegmentRenderArea() override;

  QSize minimumSizeHint() const override;
  QSize sizeHint() const override;
  QSize maximumSize() const;
  void setPen(const QPen &pen);
  void setBrush(const QBrush &brush);
  void setChannelCount(qint32 _channels);
  void setData(const char *_data, qint32 _segments);
  bool moveWindow(qint32 step);
  void setChannelHeight(qint8 height);
  void setMaxSegments(qint32 max_segments);

protected:
  void paintEvent(QPaintEvent *event) override;

private:
  const char *m_segment_buffer;                         /*!< Pointer to input data with 1 byte per channel */
  QPen pen;                                             /*!< QPen for drawing the channel outline */
  QBrush brush;                                         /*!< QBrush for drawing the channel outline */

  qint32  m_max_visible_segments;                       /*!< Maximum visible segments determined by widget 'width' and constant c_channel_width */
  qint32  m_channel_count;                              /*!< Current channel count set by parent */
  qint32  m_start_segment;                              /*!< Start segment for rendering the input data */
  qint32  m_end_segment;                                /*!< End segment for rendering the input data */
  qint32  m_max_segment;                                /*!< Maximum segments to render */
  qint8   m_channel_height = c_channel_height;          /*!< Channel height */
  qint32  m_max_segment_render_width;                   /*!< Maximum widget width */
  qint32  m_max_segment_render_height;                  /*!< Maximum widget height */

  //constants
  const qint8 c_channel_width = 4;                      /*!< Width of one channel */
  const qint8 c_channel_height = 26;                    /*!< Height of one channel */

};

#endif // SEGMENTRENDERAREA_H
