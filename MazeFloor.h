#ifndef MAZEFLOOR_H
#define MAZEFLOOR_H

/* MazeFloor.h - defines the MazeFloor class, which represents a single level
   of a maze. */

#include "MazeSpace.h"

class MazeFloor {
private:
  typedef unsigned short ushort;
  vector<vector<MazeSpace> > maze;

public:
  MazeFloor(ushort width, ushort height);
  
  // Staircases always generate downwards, and the lowest level will be
  // prevented from generating any.
  
};

#endif
