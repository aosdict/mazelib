#ifndef ALGO_NONLINEAR_RECURSIVE_DIVISION_MOD_H
#define ALGO_NONLINEAR_RECURSIVE_DIVISION_MOD_H

/* File that defines the Nonlinear Recursive Division Mod algorithm.
   A non-discrete-walled form of Nonlinear Recursive Division.
   Algorithm details:
*/

/*
Possible solution: build all walls and THEN break holes in them?
111111
1111WW
111WW2
11WW22
1WW222
1W2222
Can't determine whether to keep recursing based on size, you could get a single very long twisty passage

Problematic situation:
  ###
###.#
#...#
##..#
 ####

######
##...#
#....#
#...##
###.#
  ###
Taking it for granted that small rooms can't be eliminated with this algorithm.
Can't really do dimension-based limits on rooms because they can be irregular.

In situations like this, X can become a wall:
...1...
...1...
..11...
..1X...
..11...
...1...
...1...
So walls can clump together in this algorithm, and it can't be helped.

When walls are being built in a space with straight walls (a rectangular space),
it is not possible for there to be no place to break it in a single space.
When they are diagonal, that can happen:
..1...
.11...
11..22
....2.
*/

#include "MazeAlgorithm.h"

namespace Maze {

class RecursiveBacktrackerMod : public Algorithm {
private:

public:

};

}



#endif
