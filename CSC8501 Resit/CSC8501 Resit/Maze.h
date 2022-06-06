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

	void PrintMaze(Player* p);
	void Update(Player* p);

	char GetChar(int y, int x);

	vector<vector<char>> GetMaze() { return maze; }

	bool GetIsAllCollected() { return allCollected; }

private:

	vector<vector<char>> maze;

	vector<Prize*> prizes;

	bool allCollected;

};

#endif