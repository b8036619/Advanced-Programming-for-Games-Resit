#ifndef MAZE_H
#define MAZE_H

#include <vector>

using namespace std;

class Maze {
public:

	Maze();
	~Maze();

	void printMaze();

private:

	vector<vector<char>> maze;

};

#endif