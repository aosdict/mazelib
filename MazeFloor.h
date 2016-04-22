#ifndef MAZEFLOOR_H
#define MAZEFLOOR_H

/* MazeFloor.h - defines the MazeFloor class, which represents a single level
   of a maze. */

#include "MazeSpace.h"
#include <vector>
#include <map>

namespace Maze {

  class Floor {
  private:
    typedef unsigned short ushort;
    std::vector<std::vector<Space> > floor;

  public:
    Floor(ushort width, ushort height);

    ushort height() const { return floor.size(); }
    ushort width() const { return (floor.size() ? floor[0].size() : 0); }

    Space& operator() (ushort x, ushort y);
    Space& operator() (std::pair<ushort, ushort> coord);

    void RenderAsText(uchar spacing, std::map<ushort,char> structviews) const;

    // Staircases always generate downwards, and the lowest level will be
    // prevented from generating any.

  };

}

#endif
