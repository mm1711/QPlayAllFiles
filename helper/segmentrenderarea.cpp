/*! \file  segmentrenderarea.cpp

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

#include "segmentrenderarea.h"

CSegmentRenderArea::CSegmentRenderArea(QWidget *parent, qint32 max_segments, qint32 _channels) :
  QWidget(parent)
{
  QPalette palette;
  QBrush _brush(QColor(255, 255, 255, 255));
  _brush.setStyle(Qt::SolidPattern);
  palette.setBrush(QPalette::Active, QPalette::Base, _brush);
  QBrush brush1(QColor(255, 255, 200, 255));
  brush1.setStyle(Qt::SolidPattern);
  palette.setBrush(QPalette::Active, QPalette::Window, brush1);
  palette.setBrush(QPalette::Inactive, QPalette::Base, _brush);
  palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
  palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
  palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
  setPalette(palette);

  setAutoFillBackground(true);

  m_channel_count = _channels;
  m_max_visible_segments = max_segments;

  m_max_segment_render_width = m_max_visible_segments * c_channel_width;
  m_max_segment_render_height = c_channel_height* (m_channel_count + 1);

  setMinimumSize(QSize(m_max_segment_render_width, m_max_segment_render_height));
  setMaximumSize(QSize(m_max_segment_render_width, m_max_segment_render_height));


  m_start_segment = 0;
  m_end_segment = m_max_visible_segments;

  m_segment_buffer = nullptr;
}

CSegmentRenderArea::~CSegmentRenderArea()
{
}

void CSegmentRenderArea::setMaxSegments(qint32 max_segments)
{
  m_max_visible_segments = max_segments;

  m_max_segment_render_width = m_max_visible_segments * c_channel_width;

  setMinimumSize(QSize(m_max_segment_render_width, m_max_segment_render_height));
  setMaximumSize(QSize(m_max_segment_render_width, m_max_segment_render_height));

  m_end_segment = m_max_visible_segments;
  update();
}


/*! Return desired width x height of widget

  \return QSize object with desired width x height

<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
QSize CSegmentRenderArea::sizeHint() const
{
  return QSize(m_max_segment_render_width, m_max_segment_render_height);
}

/*! Return minimum width x height of widget

  \return QSize object with minimum width x height

<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
QSize CSegmentRenderArea::minimumSizeHint() const
{
  return QSize(m_max_segment_render_width, m_max_segment_render_height);
}

/*! Return maximum width x height of widget

  \return QSize object with maximum width x height

<b>History   :</b>	 14-11-2019mm created by Michael Moser
*/
QSize CSegmentRenderArea::maximumSize() const
{
  return QSize(m_max_segment_render_width, m_max_segment_render_height);
}


/*! Set height of channel

  \param height  channel heigth

<b>History   :</b>	 14-11-2019mm created by Michael Moser
*/
void CSegmentRenderArea::setChannelHeight(qint8 height)
{
  m_channel_height = height;
  m_max_segment_render_height = (m_channel_count + 1) * m_channel_height;

  setMinimumSize(QSize(m_max_segment_render_width, m_max_segment_render_height));
  setMaximumSize(QSize(m_max_segment_render_width, m_max_segment_render_height));
}

/*! Set QPen for channel outline drawing

  \param pen  QPen for channel outline drawing

<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
void CSegmentRenderArea::setPen(const QPen &pen)
{
  this->pen = pen;
  update();
}

/*! Set QBrush for channel fill drawing

  \param brush  QBrush for channel fill drawing

<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
void CSegmentRenderArea::setBrush(const QBrush &brush)
{
  this->brush = brush;
  update();
}

/*! Set channel count

  \param  _channels channel count to draw

<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
void CSegmentRenderArea::setChannelCount(qint32 _channels)
{
  m_channel_count = _channels;

  update();
}

/*! Set render data


<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
void CSegmentRenderArea::setData(const char *_data, qint32 _segments)
{
  m_segment_buffer = _data;
  m_max_segment = _segments;
  m_start_segment = 0;
  m_end_segment = m_max_visible_segments;
  update();
}

/*! Move drawing window

  \param step step size for moving

<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
bool CSegmentRenderArea::moveWindow(qint32 step)
{
  if((m_end_segment+step) < m_max_segment)
  {
    m_start_segment += step;
    m_end_segment += step;
    update();
    return true;
  }
  else
  {
    return false;
  }
}

/*! Paint event for widget

  Render the data from m_segment_buffer

<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
void CSegmentRenderArea::paintEvent(QPaintEvent * /* event */)
{
  QPainter painter(this);
  QBrush brush0(QColor(255, 255, 200,255));
  QBrush brush1(Qt::white);
  QBrush brush_black(Qt::black);
  painter.setPen(pen);
  painter.setRenderHint(QPainter::Antialiasing, true);

  if( m_segment_buffer != nullptr)
  {
    painter.save();

    qint32 x_pos = 0;
    qint32 y_pos = m_channel_height;

    for (qint32 segment = m_start_segment; segment < m_end_segment && segment < m_max_segment; segment++)
    {
      for (qint32 channel = 0; channel < m_channel_count; channel++)
      {
        qint32 ix = (segment * m_channel_count) + channel;
        char curr_Byte = m_segment_buffer[ix];

        painter.drawRect(x_pos, y_pos, c_channel_width, m_channel_height);
        if (curr_Byte != 0)
        {
          painter.fillRect(x_pos, y_pos, c_channel_width, m_channel_height, brush_black);
        }
        else
        {
          if((channel % 2) == 0)
          {
            painter.fillRect(x_pos, y_pos, c_channel_width, m_channel_height, brush0);
          }
          else
          {
            painter.fillRect(x_pos, y_pos, c_channel_width, m_channel_height, brush1);
          }
        }
        y_pos += m_channel_height;
      }
      x_pos += c_channel_width;
      y_pos = m_channel_height;
    }
/*
    QPen pen_frame(Qt::green, c_channel_width, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin);
    painter.setPen(pen_frame);
    painter.drawRect(0, 0, width(), height());
*/
    painter.restore();
  }
}

