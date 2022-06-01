#include "Maze.h"
#include <iostream>
#include <fstream>

Maze::Maze() {
	/*
	maze.resize(41, vector<char>(25));

	FILE * txtFile;
	errno_t err;
	err = fopen_s(&txtFile,"PrizeMaze.txt", "r");

	if (txtFile == nullptr) {
		cout << "Text File cannot be opened! \n";
	}
	else {
		vector<char> bytes;

		int x = 0;
		int y = 0;
		int count = 0;
		char tempChar;
		while (!feof(txtFile)) {

			if (count == 1025) { break; }

			tempChar = getc(txtFile);

			if (tempChar != 'x' && ' ' && 'p' && '\n') {
				tempChar = '\x9C';
				maze[x][y] = tempChar;
			}
			else {
				maze[x][y] = tempChar;
			}

			if (x == 40) {
				x = 0;
				y++;
			}
			else { x++; }
			
			count++;
		}
		cout << count << "\n";
	}
	*/

	maze = { {'x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x'},
		{'x',' ','\x9C',' ', ' ',' ',' ',' ', ' ',' ','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x'},
		{'x','x','x','x','x','x',' ','x','x',' ','x','x','x','x','x','x',' ','\x9C',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\x9C',' ','x','x','x','x'},
		{'x','x','x','x','x','x',' ','x','x',' ','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x',' ','x','x','x','x','x','x','x','x','x','x','x','x'},
		{'x','x','x','x','x','x',' ','x','x',' ','x','x','x','x','x','x','x','\x9C','x','x','x','x','x','x','x','x','x',' ','x','x','x','x','x','x','x','x','x','x','x','x'},
		{'x','x','x','x','x','x',' ','x','x',' ','x','x','x','x','x','x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x','x','x','x','x','x','x','x','x','x','x','x'},
		{'x','x','x','x','x','x',' ','x','x',' ','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x',' ','x','x','x','x','x','x','x','x','x','x','x','x'},
		{'x','x','x','x','x','x',' ','x','x',' ',' ',' ',' ',' ',' ',' ',' ',' ','\x9C',' ',' ',' ',' ',' ',' ',' ',' ',' ','x','x','x','x','x','x','x','x','x','x','x','x'},
		{'x','x','x','x','x','x',' ','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x',' ','x','x','x','x','x','x','x','x','x','x','x','x','x','x'},
		{'x','x','x','x','x','x',' ','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x',' ','x','x','x','x','x','x','x','x','x','x','x','x','x','x'},
		{'x','x','x','x','x','x',' ','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x',' ',' ',' ',' ',' ',' ',' ','\x9C',' ','x','x','x','x','x','x'},
		{'x','x','x','x','x','x',' ','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x',' ','x','x','x','x','x','x','x','x','x','x','x','x','x','x'},
		{'x','x','x','x','x','x',' ','x','x','x','x','x','x','x',' ','\x9C',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x','x','x','x','x','x','x','x','x','x','x','x','x','x'},
		{'x','x','x','x','x','x',' ','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x',' ',' ',' ',' ',' ',' ',' ',' ','\x9C',' ','x','x','x','x','x'},
		{'x','x','x','x','x','x',' ','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x',' ','x','x','x','x','x','x','x','x','x','x','x','x','x','x'},
		{'x','x','x','x','x','x',' ','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x',' ','x','x','x','x','x','x','x','x','x','x','x','x','x','x'},
		{'x','x','x','x','x',' ','\x9C',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','P'},
		{'x','x','x','x','x','x',' ','x','x','x','x','x','x',' ','x','x','x','x','x','x','x','x','x','x','x',' ','x','x','x','x','x','x','x','x','x','x','x','x','x','x'},
		{'x','x','x','x','x','x',' ','x','x','x','x','x','x',' ','x','x','x','x','x','x','x','x','x','x','x','\x9C','x','x','x','x','x','x','x','x','x','x','x','x','x','x'},
		{'x','x','x','x','x','x',' ',' ',' ','\x9C',' ','x','x',' ','x','x','x','x','x','x',' ','x','x','x','x',' ','x','x','x','x','x','x','x','x','x','x','x','x','x','x'},
		{'x','x','x','x','x','x',' ','x','x','x','x','x','x',' ','x','x','x','x','x','x','\x9C','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x'},
		{'x',' ','\x9C',' ',' ',' ',' ','x','x','x','x','x','x',' ','x','x','x','x','x','x',' ','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x'},
		{'x','x','x','x','x','x',' ','x','x','x','x','x','x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\x9C',' ','x','x','x','x','x','x','x','x','x','x','x','x','x','x'},
		{'x','x','x','x','x','x',' ',' ',' ','\x9C',' ','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x'},
		{'x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x'}};

	prizes = {new Prize(1,2), new Prize(2,17), new Prize(2,34), new Prize(4,17), new Prize(7,18), new Prize(10,32), new Prize(12,15), new Prize(13,33), new Prize(16,6),
		new Prize(18,25), new Prize(19,9), new Prize(20,20), new Prize(21,2), new Prize(22,24), new Prize(23,9)};

}
Maze::~Maze() {
	delete &maze;
}

void Maze::printMaze(Player* p) {

	cout << "--------------------------------------------" << "\n";

	int x = 0;
	int y = 0;
	for (int i = 0; i < 1000; i++) {
		
		if (maze[y][x] == 'P' && (y != p->GetPosition()[0] || x != p->GetPosition()[1])) {
			maze[y][x] = ' ';
		}

		cout << maze[y][x];

		if (x == 39) {
			x = 0;
			y++;
			cout << "\n";
		}
		else { x++; }

	}

	cout << "\n        Health: " << p->GetHealth() << "\n\n" ;

}

void Maze::update(Player* p) {

	for (int i = 0; i < prizes.size(); i++) {

		if (p->GetPosition() == prizes[i]->GetPosition()) {
			prizes[i]->playerCollected();
		}

		if (!prizes[i]->isCollected()) {
			maze[prizes[i]->GetPosition()[0]][prizes[i]->GetPosition()[1]] = '\x9C';
		}
		else {
			maze[prizes[i]->GetPosition()[0]][prizes[i]->GetPosition()[1]] = ' ';
		}

	}

	maze[p->GetPosition()[0]][p->GetPosition()[1]] = 'P';

}

char Maze::getChar(int y, int x) {

	if (x > 39) { return 'f'; }
	else { return maze[y][x]; }

}
