/*! \file  playallfileslist.h

Play All Files list class

<b>Copyright   :</b> (C) 2019 Michael Moser

<b>Last edit	:</b>

<b>History   :</b>	22-11-2019mm		creation by Michael Moser

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

#include "playallfilelist.h"

CPlayAllFileList::CPlayAllFileList()
{
  x = 0;
  y = 0;
  list = new QList<CListItem>;
}

void CPlayAllFileList::addListItem(CListItem &item)
{
  list->append(item);
}
