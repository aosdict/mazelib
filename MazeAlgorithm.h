/* Abstract base class for various maze-generating algorithmic classes to
   inherit from. */

#ifndef MAZEALGORITHM_H
#define MAZEALGORITHM_H

#include "MazeFloor.h"

/* Algorithms for the generation of the maze, selectable by the user.
   Recursive Backtracker: pretty simple depth-first path carving algorithm
   Recursive Backtracker Mod: a variant of RB optimized for a square grid that
     enables twistier paths and doesn't require that every fourth square
     is necessarily a path.
   Prim's: minimum spanning tree algorithm based on random edge carving
   Kruskal's: forest-based minimum spanning tree path carving algorithm
   Connected Rooms: wall-building algorithm based on roguelike dungeon design
     http://www.roguebasin.com/index.php?title=Abstract_Dungeons that makes the
     maze into a network of rooms (a recursive division algorithm)
   Connected Rooms with Tunnels: same as connected rooms, but some of the rooms
     will use a tunnel/maze painter instead of generating a room
   Eller's: possibly infinite in one direction along one axis
   Eller Variant: attempt to make Eller's work while removing the strict
     path-wall-path format of these algorithms. Not designed yet.
   Hunt and Kill: random stepping
   Growing Tree: very versatile and flexible algorithm that can behave
     identically to Recursive Backtracker, Prim's, a breadth-first search, or
     any combination thereof.
   Recursive Division Variant: http://weblog.jamisbuck.org/2015/1/15/better-recursive-division-algorithm.html
     Recursive division that is more computationally expensive, but generates
     much more interesting mazes than the normal recursive division algorithm,
     and can be modified to generate organic rooms integrated with the maze.

   Algorithms that may be added at a later date:
   Binary Space Partitioning: http://www.roguebasin.com/index.php?title=Basic_BSP_Dungeon_generation
   Cellular Automata: http://www.roguebasin.com/index.php?title=Cellular_Automata_Method_for_Generating_Random_Cave-Like_Levels
   
   The following algorithms are not going to be implemented because they are
   extremely inefficient:
   Wilson's algorithm
   Aldous-Broder algorithm
*/


class MazeAlgorithm {
 private:
  typedef unsigned short ushort;

 protected:
  // Parameters that all algorithms must implement
  ushort staircase_attempts;
  
 public:
  virtual void GenerateMaze(MazeFloor& floor) = 0;
};

#endif
