#ifndef MAZESTRUCTURE_H
#define MAZESTRUCTURE_H

#include "MazeSpace.h"
#include <vector>
#include <map>
#include <iostream>

/* Structure class - defines a structure of Spaces, which is intended
   to be pasted into a Floor.
   Certain spaces in rooms, defined by the user, can have probabilities of
   appearing as various kinds of spaces. These are resolved when a room gets
   put into a Floor. */
namespace Maze {

  // Enum for rotation. Rotation can be none,

  // Class for generation probabilities resulting in different Spaces.

  class Structure {
  private:

    /* The base type to represent different possibilities in a space is a Map
    of unsigned shorts (the probabilities) to these pairs.
    Then, these are all placed in a double vector. */
    std::vector<std::vector<std::map<ushort, Space> > > spaces;

    // Randomly resolve a certain space from the array of probabilities.
    Space resolve_space(ushort x, ushort y);

    // Construct a space from the structure id and the type string.
    Space make_space(ushort id, std::string typestr);

    // Structure name
    std::string name;

  public:
    ushort width() const;
    ushort height() const;

    friend std::istream& operator>>(std::istream& instr, Structure& structure);

    // Return the grid as a double vector of Spaces, resolving any possible
    // choices of spaces and applying any transformations, ready to be copied
    // into a MazeFloor.
    vector<vector<Space> > generate(ushort rotation, bool flipx, bool flipy);

  };

  // Input data into the class (a constructor isn't very appropriate)
  std::istream& operator>>(std::istream& instr, Structure& structure);

}


/* MOVE THIS SOMEWHERE ELSE

  // Class for information about placing of structures
  class StructurePlacementInfo {
  private:
    ushort floor;
    ushort spawnx;
    ushort spawny;
    ushort rotation;
    bool flipx;
    bool flipy;
  public:
    StructurePlacementInfo(ushort fl, ushort x, ushort y, ushort rot, bool flpx,
                        bool flpy):
      floor(fl), spawnx(x), spawny(y), rotation(rot), flipx(flpx), flipy(flpy)
    {}
  };
*/
#endif
