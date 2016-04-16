#ifndef MAZEFLOOR_H
#define MAZEFLOOR_H

/* MazeFloor.h - defines the MazeFloor class, which represents a single level
   of a maze. */

#include "MazeSpace.h"
#include <map>

namespace Maze {

  class Floor {
  private:
    typedef unsigned short ushort;
    std::vector<std::vector<Space> > floor;

  public:
    Floor(ushort width, ushort height);

    RenderAsText(uchar spacing, std::map<ushort,char> structviews);
    // Staircases always generate downwards, and the lowest level will be
    // prevented from generating any.

  };

}

#endif
