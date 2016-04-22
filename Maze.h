#ifndef MAZELIB_H
#define MAZELIB_H

/* Overarching Maze class; controls all features of generating a maze. */

#include "MazeSpace.h"
#include "MazeFloor.h"
#include "MazeAlgorithm.h"
#include <map>


namespace Maze {

  class Maze {
  private:
    typedef unsigned short ushort;
    // Floors will be regarded as descending (level 0 goes down to level 1, etc)
    std::vector<Floor> floors;
    

  public:
    // There will be no concept of predefined edge spaces, i.e. walls or
    // something, by default. The maze spans the entire area.

    Maze(ushort width, ushort height, ushort numFloors);


    void GenerateMaze(const Algorithm* alg);
    void GenerateMaze(const std::vector<Algorithm*> algs);

    // TODO: have a RenderAsText version that doesn't take the map, isn't
    // intended for structures, and will show any structures as * or something
    void RenderAsText(uchar spacing, std::map<ushort, char> structviews);

  };
}


#endif
