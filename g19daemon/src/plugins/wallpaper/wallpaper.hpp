/*
 * <one line to give the program's name and a brief idea of what it does.>
 * Copyright (C) 2014  <copyright holder> <email>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef WALLPAPER_H
#define WALLPAPER_H 

#include "../../gscreen.hpp"
#include "../../plugininterface.hpp"
#include <QtCore>
#include <QtPlugin>
#include <chrono>

class Wallpaper: public QObject, public PluginInterface {
  Q_OBJECT
  Q_INTERFACES(PluginInterface)

  Q_PLUGIN_METADATA(IID "wallpaper")

public:
  Wallpaper();
  ~Wallpaper();
  void lKeys(int keys);
  QString getName();
  QImage getIcon();
  void setActive(bool active);
  bool isPopup();
  QObject *getQObject();
  void mKeys(int keys);

private:
  Gscreen *screen;
  QImage image;
  std::chrono::time_point<std::chrono::system_clock> last_read;
  bool isActive;
  void paint();

signals:
  void doAction(gAction action, void *data); // Signal to draw img on screen
};

#endif // WALLPAPER_H 
