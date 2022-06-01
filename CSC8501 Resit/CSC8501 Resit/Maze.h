#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include "Player.h"
#include "Prize.h"

using namespace std;

class Maze {
public:

	Maze();
	~Maze();

	void printMaze(Player* p);
	void update(Player* p);

	char getChar(int y, int x);

private:

	vector<vector<char>> maze;

	vector<Prize*> prizes;

};

#endif