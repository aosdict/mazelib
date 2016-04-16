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
void Maze::GenerateMaze(const vector<MazeAlgorithm>& algs) {
  const MazeAlgorithm& current;
  for(int i=0; i<floors.size(); ++i) {
    if(i < algs.size()) {
      current = algs[i];
    }
    current.GenerateMaze(floors[i]);
  }
}

/* Displays the maze as output printed to the terminal. By default, paths will
   print as '.', walls will print as '#', and structure spaces will print as
   the value looked up in the map. If it's not there, it will just print the
   structure ID. The number of characters between each Space is controlled by
   the spacing parameter. */
void Maze::RenderAsText(uchar spacing, std::map<ushort,char> structviews) {
  for(ushort i=0; i<floors.size(); ++i) {
    std::cout << "Floor " << i << std::endl;
    floors[i].RenderAsText(spacing, structviews);
    std::cout << std::endl;
  }
}
