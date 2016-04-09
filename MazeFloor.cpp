#include "MazeFloor.h"

MazeFloor::MazeFloor(ushort width, ushort height) {
  //MazeSpace def;
  maze = vector<vector<MazeSpace> >(height, vector<MazeSpace>(width, MazeSpace()));
}
