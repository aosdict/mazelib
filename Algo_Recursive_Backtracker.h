#ifndef ALGO_RECURSIVE_BACKTRACKER_H
#define ALGO_RECURSIVE_BACKTRACKER_H

/* File that defines the Recursive Backtracker algorithm.
   Algorithm details:
    - Requires a concept of distinct walls and spaces; two adjacent path spaces
      that are considered by the algorithm must either have a wall in between
      them, or a path in between them. Of every four spaces in the grid, one is
      always guaranteed to be a wall, and one is always guaranteed to be a path.
    - Dimensions matter. If a dimension is even, there will be a guaranteed
      unbroken wall at one end of that dimension, which may be considered a
      blemish.
    - Can use a random or specific start point.
    - Cannot guarantee that a pre-specified end point is particularly far away.
      However, it can keep track of the distance and return the point as far
      away from the starting point as possible as a potential end point.
    - Can use a coefficient to have a probability of carving a path out to a
      space that is already carved out, creating a loop in the maze. If the
      coefficient is 0, the maze will be a "perfect maze", a complete spanning
      tree with no cycles.
*/

#include "MazeAlgorithm.h"

class RecursiveBacktracker: public MazeAlgorithm {
private:
  unsigned int loop_prob;
  
public:
  RecursiveBacktracker(unsigned int loop_chance);
  
  void GenerateMaze(MazeFloor& floor);
}

#endif
