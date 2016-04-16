#include "MazeStructure.h"
#include <sstream>

namespace Maze {

ushort Structure::width() const {
  if(spaces.size() == 0) return 0;
  else return spaces[0].size();
}

ushort Structure::height() const {
  return spaces.size();
}

/* Format for input:

   First line must be "structure" and then the structure name, width and height
    (as they appear in the grid with no transformations):
   structure intersectionRoom 5 5

   Then is the section of character mappings, which let the user define what
    a specific character represents on the map of the structure. There must
    always be at least 1 mapping. Each line must have the following format:
    mapping <char> <id_1> <type> <prob> <id_2> <type> <prob> ... <id_n> <type>
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
    Here is an example line that will always generate data type 3 as a walkable
    space when a '%' is found in the map:
      mapping % 3 path
    Here is another example line that will generate data type 7 half of the time
    and nothing (keeping the normal wall that can get carved up for normal maze
    generation) the other half of the time when a '#' is found in the map:
      mapping # 7 32768 path 0 wall

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

/* Operator to read in the data from standard input or a file. I am NOT
   concerned with validating it at this time. */
std::istream& operator>>(std::istream& instr, Structure& structure) {

  // reset anything relevant
  structure.spaces.clear();
  structure.name = "";

  // read initial info
  std::string tmp;
  unsigned short width, height;
  instr >> tmp >> structure.name >> width >> height;

  // read mappings
  char curChar;
  std::string line_type, linestr;
  std::map<char, std::map<ushort, Space> > char_mappings;
  instr >> line_type;
  while(line_type == "mapping") {
    instr >> curChar;
    // read in the rest of the line
    std::getline(instr, linestr);
    std::stringstream ss(linestr);

    ushort sid;
    std::string typestr;
    ushort prob;
    ushort currentProbSum = 0;
    maze_type ty;
    ss >> sid >> typestr;
    while(ss >> prob) {
      if((unsigned int) currentProbSum + prob > USHRT_MAX) {
        currentProbSum == USHRT_MAX;
      }
      else {
        currentProbSum += prob;
      }
      if(typestr == "path") ty = M_PATH;
      else ty = M_WALL;
      char_mappings[curChar][currentProbSum] = Space(ty, sid);
      ss >> sid >> typestr;
    }
    char_mappings[curChar][USHRT_MAX] = Space(ty, sid);

    // get next line_type
    instr >> line_type;
  }

  //line_type should now be "grid"
  //read the grid
  std::getline(instr, linestr);
  while (linestr != "end structure") {
    // Note that this assumes the grid is a rectangle.
    // There is no checking that it isn't.
    std::vector<std::map<ushort, Space> > temp;
    for(int i=0; i<linestr.length(); ++i) {
      temp.push_back(char_mappings[linestr[i]]);
    }
    structure.spaces.push_back(temp);

    std::getline(instr, linestr);
  }

}

Space Structure::resolve_space(ushort x, ushort y) {
  ushort rnd = (unsigned int) rand() & 0xFFFF;
  std::map<ushort, Space>::iterator itr;
  for(itr = spaces[y][x].begin(); itr != spaces[y][x].end(); ++itr) {
    if(rnd < itr->first) {
      return itr->second;
    }
  }
  // if it actually manages not to hit anything in the map, just take the
  // last "default" element
  itr = spaces[y][x].end()--;
  return itr->second;
}

/* Make appropriate transformations and resolve all choices of spaces,
   generating a section of a maze. */
std::vector<std::vector<Space> > Structure::generate
  (ushort rotation, bool flipx, bool flipy) {
  std::vector<std::vector<Space> > out;
  /* Take the source x and source y in the structure. Apply any flips, then
     apply a rotation.
     Rotate 90 clockwise = flip horizontally then transpose.
     Rotate 90 counterclockwise = flip vertically then transpose.
     Rotate 180 = flip horizontally and vertically. */
  if(spaces.size() == 0 || spaces[0].size() == 0) {
    std::cerr << "WARNING: trying to generate a structure \"" << name <<
                 "\" with a zero dimension" << std::endl;
    return out;
  }

  ushort maxx = spaces[0].size()-1;
  ushort maxy = spaces.size()-1;

  for(int i=0; i<=maxy; ++i) {
    out.push_back(std::vector<Space>());
    for(int j=0; j<=maxx; ++j) {
      ushort srcx = i;
      ushort srcy = j;

      // Resolve any flips
      if(flipx) {
        srcx = maxx - srcx;
      }
      if(flipy) {
        srcy = maxy - srcy;
      }

      // Resolve any rotations
      if(rotation == 90) {
        srcx = maxx - srcx;
        std::swap(srcx, srcy);
      }
      else if(rotation == 180) {
        srcx = maxx - srcx;
        srcy = maxy - srcy;
      }
      else if(rotation == 270) {
        srcy = maxy - srcy;
        std::swap(srcx, srcy);
      }
      // Rotation of 0 or indeed any other value will not rotate the structure.

      // Resolve the spaces
      out[i].push_back(resolve_space(srcx, srcy));
    }
  }
  return out;
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
}
