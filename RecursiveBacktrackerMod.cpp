#include "RecursiveBacktrackerMod.h"
#include "MazeSpace.h"
#include <iostream>


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

void RecursiveBacktrackerMod::recurse(ushort x, ushort y, Floor& floor) const {
  /* How to determine if the space is suitable for recursing into: check if any
  of the 5 spaces surrounding that space in the direction of travel are paths.
  If they are, do not recurse there. If none are, then recurse there.
  Example approaching from the left:
  .!!
  .?!
  .!!
  ? = space being checked, ! = needs to be a wall
  */

  // randomize order of directions to try
  unsigned char dirs = bitperms[rand() % 24];

  // iterate through directions
  for(int i=0; i<8; i+=2) {
    unsigned char currdir = (dirs >> i) & 0x3;
    // 0 = left, 1 = up, 2 = right, 3 = down
    if(currdir == 0) {
      if(x > 0 && floor())
    }
  }

}

}
