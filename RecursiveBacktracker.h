#ifndef ALGO_RECURSIVE_BACKTRACKER_H
#define ALGO_RECURSIVE_BACKTRACKER_H

/* File that defines the Recursive Backtracker algorithm.
   Algorithm details:
    - Very simple and intuitive
    - Depth-first search that creates a spanning tree
    - Can reliably produce perfect or looped mazes with high control over the
      amount of looping
    - Reliably produces a full maze
    - Can use any start point
    - Very high (perhaps the highest) river factor
    - Discrete-walled
    - Will produce blemishes of a wall across the entire edge of the map if the
      dimensions or start point do not agree
*/

#include "MazeAlgorithm.h"

namespace Maze {

  class RecursiveBacktracker: public Algorithm {
  private:
    unsigned int loop_prob;

    void recurse(ushort x, ushort y, Floor& floor) const;

  public:
    RecursiveBacktracker(unsigned int loop_chance) : loop_prob(loop_chance) {}

    void GenerateMaze(Floor& floor) const;
  };

}

#endif
