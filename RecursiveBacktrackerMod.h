#ifndef ALGO_RECURSIVE_BACKTRACKER_MOD_H
#define ALGO_RECURSIVE_BACKTRACKER_MOD_H

/* File that defines the Recursive Backtracker Mod algorithm.
   Conceptually this is the same algorithm as the original RB, but this
   version is not discrete-walled. As a result, paths can turn and twist in
   tighter spaces.
   Algorithm details:
    - Very intuitive (slightly more complex than normal RB though)
    - Depth-first search that creates a spanning tree
    - Can reliably produce perfect or looped mazes with high control over the
      amount of looping
    - Does not reliably produce a full maze. In particular, diagonally running
      corridors occasionally block off an area of the map, which may be
      considered a blemish
    - Can use any start point
    - Very high river factor
    - NOT discrete-walled
*/

#include "MazeAlgorithm.h"

namespace Maze {

class RecursiveBacktrackerMod : public Algorithm {
private:
  unsigned int loop_prob;

  void recurse(ushort x, ushort y, Floor& floor) const;

public:
  RecursiveBacktrackerMod(unsigned int loop_chance) : loop_prob(loop_chance) {}

  void GenerateMaze(Floor& floor) const;

};

}



#endif
