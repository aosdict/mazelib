#include "Maze.h"

/* Calling this constructor will NOT generate a maze. It will allocate the
   data in the correct sizes accordingly, and nothing else.
*/
Maze::Maze(ushort width, ushort height, ushort floors) {
  // Make the default floor populated with default MazeSpaces and put a copy on
  // every floor
  floors = vector<MazeFloor>(floors, MazeFloor(width, height));
}

/* Generates the maze with the same parameters on each floor. */
void Maze::GenerateMaze(const MazeAlgorithm& alg) {
  for(int i=0; i<floors.size(); ++i) {
    alg.GenerateMaze(floors[i]);
  }
}

/* Generates the maze with a different algorithm for each floor.
   If algs is shorter than floors, the last valid element of algs will be
   applied to all remaining floors.
   If algs is longer than floors, the extra algorithms will be disregarded.
*/
void GenerateMaze(const vector<MazeAlgorithm>& algs) {
  const MazeAlgorithm& current; 
  for(int i=0; i<floors.size(); ++i) {
    if(i < algs.size()) {
      current = algs[i];
    }
    current.GenerateMaze(floors[i]);
  }
}
