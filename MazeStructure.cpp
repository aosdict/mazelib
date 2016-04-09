#include "MazeStructure.h"
#include <map>

using namespace Maze;

/* Format for input:

   First line must be "structure" and then the structure name, width and height
    (as it is written in the file with no transformations):
   structure intersectionRoom 5 5

   Then is the section of character mappings, which let the user define what
    a specific character represents on the map of the structure. There must
    always be at least 1 mapping. Each line must have the following format:
    mapping <char> <id_1> <prob> <type> <id_2> <prob> <type> ... <id_n> <type>
    where the ids are unsigned shorts that represent user-defined space IDs,
    the types are either "wall" or "path",
    and the probs are unsigned shorts that represent its probability of being
    chosen out of 65536. Notes on these:
     - An ID of 0 is special in that that space will not be treated as part of
       the structure. It can be carved up by the maze algorithm normally.
     - The last id should not have a probability defined; it will be picked
       when none of the others are. It is essentially the else statement.
     - If using one id, a probability should not be specified.
     - Behavior is undefined if the probabilities add up to more than 65535.
    Here is an example line that will always generate data type 3 when a '%' is
    found in the map:
      mapping % 3
    Here is another example line that will generate data type 7 half of the time
    and nothing (keeping the normal wall that can get carved up for normal maze
    generation) the other half of the time when a '#' is found in the map:
      mapping # 7 32768 0

   After all mappings are entered, there must be a line containing only 'grid',
    and then the grid is defined. This is always a rectangle of characters that
    have defined mappings.
   grid
   #####
   #...#
   .....
   #...#
   #####

   Finally, there must be a line of "end structure" to signal that the structure
    is complete.
   end structure
*/

/* Operator to read in the data from standard input or a file. We are NOT
   concerned with validating it at this time. */
std::istream& operator>>(std::istream& instr, Structure& structure) {

  // read initial info
  std::string tmp;
  unsigned short width, height;
  instr >> tmp >> structure.name >> width >> height;
  structure.data = std::vector<vector<Space> >
    (height, std::vector<Space>(width, Space()));

  // read mappings
  std::string chstr, linestr;
  std::map<char, MazeSpace
  instr >> tmp >> chstr;
  std::getline(instr, linestr);
  stringstream ss(linestr);
                                              
}

/* Details on where and how the structure will be placed will be supplied in
   another place and handled by something else. The Structure class will handle
   only the actual structure information.

   

   Next, there will be lines controlling static placements (with a fixed
   coordinate and rotation). These look like:
     static <floor> <x> <y> <rotation> <flip>
     where floor is the single floor on which to place it, x and y are the top
     left coordinates of its placement (after rotating and flipping),
     rotate is any of 0, 90, 180, or 270, and flip is "horiz", "vert" or "none".
   static 2 150 100 90 none

   Next, there will be lines controlling random generation of the structure in
   the maze. These look like:
     random <floor> <numAttempts> <useRotations> <useFlips>
     where floor is the floor on which to place it, numAttempts is the number
     of times it will attempt to generate per floor, and useRotations and
     useFlips are both either "yes" or "no".
     Note that this will apply to all floors after this one, not just the floor
     specified, until another random statement is used on a deeper floor. These
     statements MUST be sorted in order of increasing floor.
   random 0 10 yes yes
   random 5 12 yes no
                                                  */
