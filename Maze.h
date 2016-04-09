#ifndef MAZELIB_H
#define MAZELIB_H

/* Overarching Maze class; controls all features of generating a maze. */

#include "MazeSpace.h"
#include "MazeFloor.h"
#include "MazeAlgorithm.h"

class Maze {
private:
  typedef unsigned short ushort;
  // Floors will be regarded as descending (level 0 goes down to level 1, etc)
  vector<MazeFloor> floors;
  
  
public:
  // There will be no concept of predefined edge spaces, i.e. walls or
  // something, by default. The maze spans the entire area.
  
  Maze(ushort width, ushort height, ushort floors);

  
  void GenerateMaze(ushort staircase_attempts, const MazeAlgorithm& alg);
  void GenerateMaze(const vector<ushort>& staircase_attempts,
                    const vector<MazeAlgorithm>& algs);
  
};


#endif
