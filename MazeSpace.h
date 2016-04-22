#ifndef MAZESPACE_H
#define MAZESPACE_H

/* MazeSpace.h - defines MazeSpace, a class which should be customized by the
   programmer for the behavior they want in their maze. */

#include "MazeDefs.h"

namespace Maze {

  class Space {
  private:

    // Actual representation of the maze data. Everything has to be regarded
    // either as a path or as a wall by the maze generator. Structures
    // must therefore always define one of the two.
    maze_type path_type;

    // If the space is part of a structure, this will represent what kind of
    // custom space it is. A value of 0 represents "not a structure" and will
    // be a normal wall or path usable by the maze algorithm.
    ushort structure_id;

    // If the space is valid for traveling up or down a floor.
    bool can_go_up;
    bool can_go_down;


  public:
    // default is a non-structure wall
    Space(): path_type(M_WALL), structure_id(0), can_go_up(false),
      can_go_down(false) {}
    // can be extended for any values though
    Space(maze_type m_type, ushort st_type):
      path_type(m_type), structure_id(st_type), can_go_up(false),
      can_go_down(false) {}

    ushort struct_id() const { return structure_id; }
    maze_type type() const { return path_type; }

    //friend class Floor;

  };

}

#endif
