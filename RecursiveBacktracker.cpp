#include "RecursiveBacktracker.h"
#include "MazeSpace.h"
#include <iostream>

/* Behavior regarding structures:
   If the space being passed over or the space being passed into is a
   structure wall, do not move there or recurse.
   If the space being passed over is a normal path, do not move there or
   recurse.
   If the space being passed into is any path and a loop_prob check passes,
   convert the space being passed over into a normal path ONLY IF it is a normal
   wall, and do not move there or recurse.
   */


/* All possible permutations of the bits 00, 01, 10, and 11
  Each value corresponds to a direction.
  This is the most efficient way to generate a random ordering of the four
  directions, by simply selecting a number at random from this array. */
static const unsigned char bitperms[24] = {
 0x1B, 0x1E, 0x27, 0x2D, 0x36, 0x39,
 0x4B, 0x4E, 0x63, 0x6C, 0x72, 0x78,
 0x87, 0x8D, 0x93, 0x9C, 0xB1, 0xB4,
 0xC6, 0xC9, 0xD2, 0xD8, 0xE1, 0xE4
};

namespace Maze {

// Assumes that the space it is being called on has already been converted to
// a path
void RecursiveBacktracker::recurse(ushort x, ushort y, Floor& floor) const {
  // create an instance of the path space we want to carve
  const Space path(M_PATH, 0);

  // randomize order of directions to try
  unsigned char dirs = bitperms[rand() % 24];

  // iterate through directions
  for(int i=0; i<8; i+=2) {
    unsigned char currdir = (dirs >> i) & 0x3;
    // 0 = left, 1 = up, 2 = right, 3 = down
    if(currdir == 0) {
      if(x > 1 && floor(x-2, y).type() == M_WALL) {
        floor(x-2, y) = path;
        floor(x-1, y) = path;
        recurse(x-2, y, floor);
      }
    }
    else if(currdir == 1) {
      if(y > 1 && floor(x, y-2).type() == M_WALL) {
        floor(x, y-1) = path;
        floor(x, y-2) = path;
        recurse(x, y-2, floor);
      }
    }
    else if(currdir == 2) {
      if(x < floor.width()-2 && floor(x+2, y).type() == M_WALL) {
        floor(x+1, y) = path;
        floor(x+2, y) = path;
        recurse(x+2, y, floor);
      }
    }
    else if(currdir == 3) {
      if(y < floor.height()-2 && floor(x, y+2).type() == M_WALL) {
        floor(x, y+1) = path;
        floor(x, y+2) = path;
        recurse(x, y+2, floor);
      }
    }
  }
}

void RecursiveBacktracker::GenerateMaze(Floor& floor) const {

  const ushort fw = floor.width();
  const ushort fh = floor.height();

  // pick a random starting point
  ushort start_x = rand() % fw;
  ushort start_y = rand() % fh;

  // turn it into a path
  floor(start_x, start_y) = Space(M_PATH, 0);

  // start the recursion
  recurse(start_x, start_y, floor);

}

}
