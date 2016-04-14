#ifndef MAZEDEFS_H
#define MAZEDEFS_H

/* File to define various things globally in the Maze namespace, like
   typedefs. Pretty much everything should include this before other Maze
   includes.
*/

#include <climits>

namespace Maze {
  // For programming conciseness
  typedef unsigned short ushort;

  // Representation of whether a given Space is walkable or not, and how it
  // should be treated by the generation algorithms.
  typedef enum {M_WALL, M_PATH} maze_type;

}

#endif
