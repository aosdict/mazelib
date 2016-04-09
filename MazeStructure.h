#ifndef MAZESTRUCTURE_H
#define MAZESTRUCTURE_H

#include "MazeSpace.h"
#include <vector>
#include <iostream>

/* Structure class - defines a structure of Spaces, which is intended
   to be pasted into a Floor.
   Certain spaces in rooms, defined by the user, can have probabilities of
   appearing as various kinds of spaces. These are resolved when a room gets
   put into a Floor. */
namespace Maze {

  // Class for generation probabilities resulting in different Spaces.
  
  class Structure {
  private:
    // Class that stores probabilities that can be resolved to Space data.
    // Does not actually store Spaces.
    class ChoiceSpace {
    public:
      std::vector<std::pair<ushort, std::pair<maze_type, ushort> > >
    };
    
    typedef unsigned short ushort;

    // Structure name
    std::string name;
  
  public:
    friend std::istream& operator>>(std::istream& instr, Structure& structure);

    // Return the grid as a double vector of Spaces, resolving any possible
    // choices of spaces and applying any transformations, ready to be copied
    // into a MazeFloor.
    //vector<vector<Space> > generate(); // random one
    
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
