/*! \file  channelproperties.cpp

Widget code for handling the channel properties

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

#include "channelproperties.h"
#include "ui_channelproperties.h"

CChannelProperties::CChannelProperties(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::CChannelProperties)
{
  ui->setupUi(this);
  ui->channel_voice_spinBox->setValue(0);
  ui->channel_note_comboBox->addItems(c_note_names);
  ui->channel_velocity_comboBox->addItems(c_velocity_names);
  ui->channel_velocity_comboBox->setCurrentIndex(ui->channel_velocity_comboBox->findText(c_velocity_names[6]));
  ui->channel_group_lineEdit->setText("0");

}

CChannelProperties::~CChannelProperties()
{
  delete ui;
}

/*! Return current voice index

  \return current voice index

<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
qint32 CChannelProperties::getCurrentVoiceIndex()
{
  return ui->channel_voice_spinBox->value();
}

/*! Set current voice index

    \param index  voice index

<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
void CChannelProperties::setVoiceIndex(qint32 index)
{
  ui->channel_voice_spinBox->setValue(index);
}

/*! Return current velocity index

  \return current velocity index

<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
qint32 CChannelProperties::getCurrentVelocityIndex()
{
  return ui->channel_velocity_comboBox->currentIndex();
}

/*! Return current velocity value

  \return current velocity value

<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
qint32 CChannelProperties::getCurrentVelocityValue()
{
  return c_velocity_map[ui->channel_velocity_comboBox->currentText()];
}

/*! Set current velocity index

    \param index  velocity index

<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
void  CChannelProperties::setVelocityIndex(qint32 index)
{
  ui->channel_velocity_comboBox->setCurrentIndex(index);
}

/*! Return current note index

  \return current note value

<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
qint32 CChannelProperties::getCurrentNoteIndex()
{
  return ui->channel_note_comboBox->currentIndex();
}

/*! Return current note text

  \return current note text

<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
QString CChannelProperties::getCurrentNoteText()
{
  return ui->channel_note_comboBox->currentText();
}

/*! Set current note index

    \param index  note index

<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
void CChannelProperties::setNoteIndex(qint32 index)
{
  if( index >= c_note_names.size() )
  {
    index = c_note_names.size()-1;
  }
  ui->channel_note_comboBox->setCurrentIndex(index);
}

/*! Return current group

  \return current group

<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
qint32 CChannelProperties::getCurrentGroup()
{
 return ui->channel_group_lineEdit->text().toInt();
}

/*! Set current group

    \param index  group

<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
void CChannelProperties::setGroup(qint32 index)
{
  ui->channel_group_lineEdit->setText(QString::number(index));
}


/*! Return channel settings as ";" separated QString


<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
QString CChannelProperties::toString()
{
  return  c_prop_id +
          QString::number(ui->channel_voice_spinBox->value()) + ";" +
          QString::number(ui->channel_note_comboBox->currentIndex()) + ";" +
          QString::number(ui->channel_velocity_comboBox->currentIndex()) + ";" +
          ui->channel_group_lineEdit->text() + ";";
}

/*! Set channel settings from ";" separated QString

    \param settings  ";" separated settings

<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
void CChannelProperties::fromString(QString settings)
{
  QStringList values = settings.split(";",QString::SkipEmptyParts);
  if(values.size() == c_chn_props_v1_0_len)
  {
    QString id = values.at(0) + ";";
    if(id == c_prop_id)
    {
      ui->channel_voice_spinBox->setValue(values.at(1).toInt());
      ui->channel_note_comboBox->setCurrentIndex(values.at(2).toInt());
      ui->channel_velocity_comboBox->setCurrentIndex(values.at(3).toInt());
      ui->channel_group_lineEdit->setText(values.at(4));
    }
  }
}
