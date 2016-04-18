all: main

DFLAGS = -g
mzlib_obj = Maze.o MazeFloor.o MazeStructure.o
algo_obj = RecursiveBacktracker.o	

main: main.o $(mzlib_obj) $(algo_obj)
	g++ main.o $(mzlib_obj) $(algo_obj) -o main $(DFLAGS)

main.o: main.cpp
	g++ -c main.cpp $(DFLAGS)

Maze.o: Maze.cpp
	g++ -c Maze.cpp $(DFLAGS)

MazeFloor.o: MazeFloor.cpp
	g++ -c MazeFloor.cpp $(DFLAGS)

MazeStructure.o: MazeStructure.cpp
	g++ -c MazeStructure.cpp $(DFLAGS)

RecursiveBacktracker.o: RecursiveBacktracker.cpp
	g++ -c RecursiveBacktracker.cpp $(DFLAGS)

clean:
	rm *.o
