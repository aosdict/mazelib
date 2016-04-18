#include "Maze.h"
#include "RecursiveBacktracker.h"
#include <map>

int main(int argc, char* argv[]) {
  Maze::Maze myMaze(10,10,2);
  std::map<unsigned short, char> structmap;
  myMaze.RenderAsText(0, structmap);

  Maze::RecursiveBacktracker rb(0);

  myMaze.GenerateMaze(&rb);

  myMaze.RenderAsText(0, structmap);
}
