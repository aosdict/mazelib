#include "MazeFloor.h"
#include <iostream>

namespace Maze {

Floor::Floor(ushort width, ushort height) {
  if(width == 0 || height == 0) {
    std::cerr << "WARNING: Generating a floor with 0 width or height"
              << std::endl;
  }
  floor = std::vector<std::vector<Space> >(height, std::vector<Space>(width, Space()));
}

Space& Floor::operator() (ushort x, ushort y) {
  return floor[y][x];
}

/* Same as the other operator() but this takes a pair instead. */
Space& operator() (std::pair<ushort, ushort> coord) {
  return floor[coord.second][coord.first];
}

void Floor::RenderAsText(uchar spacing, std::map<ushort,char> structviews) const
{
  // For now, spacing will be ignored and there will be no spacing.
  for(int i=0; i<floor.size(); ++i) {
    for(int j=0; j<floor[i].size(); ++j) {
      ushort sid = floor[i][j].struct_id();
      if(sid) {
        // structure, use its preferred character if possible
        std::map<ushort,char>::iterator itr = structviews.find(sid);
        if(itr != structviews.end()) {
          std::cout << itr->second;
        }
        else {
          // else give up and print the id
          std::cout << sid;
        }
      }
      else {
        // normal wall or path
        if(floor[i][j].type() == M_WALL) {
          std::cout << '#';
        }
        else {
          std::cout << '.';
        }
      }
    }
    std::cout << std::endl;
  }
}

}
