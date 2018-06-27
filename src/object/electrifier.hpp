//  SuperTux
//  Copyright (C) 2006 Matthias Braun <matze@braunis.de>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef HEADER_SUPERTUX_OBJECT_ELECTRIFIER_HPP
#define HEADER_SUPERTUX_OBJECT_ELECTRIFIER_HPP

#include "supertux/game_object.hpp"
#include "supertux/timer.hpp"
#include <stdint.h>
#include <map>

//Changes all tiles with the given ID to a new one for a given amount of time, then removes itself
//Used by the Kugelblitz to electrify water - can be used for other effects, too
class Electrifier : public GameObject
{
public: 
  Electrifier(std::map<uint32_t, uint32_t> tilemap, float seconds);
  Electrifier(uint32_t oldtile, uint32_t newtile, float seconds);
  virtual bool is_saveable() const {
    return false;
  }

protected:
  virtual void update(float time);
  virtual void draw(DrawingContext& context);

private:
  std::map<uint32_t, uint32_t> changingtilemap;
  Timer duration;
};

#endif

/* EOF */
