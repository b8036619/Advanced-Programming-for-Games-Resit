using namespace std;
#include "Maze.h"
#include "Player.h"

#include <iostream>
#include <conio.h>

int main() {

	Maze* maze = new Maze();
	Player* player = new Player(16, 39);

	bool finished = false;

	char keyPressed;
	while (true) {

		maze->printMaze(player);

		keyPressed = _getch();

		switch (keyPressed)
		{
		case 'a':
			player->MoveLeft(maze->getChar(player->GetPosition()[0], (player->GetPosition()[1] - 1)));
			break;
		case 'd':
			player->MoveRight(maze->getChar(player->GetPosition()[0], (player->GetPosition()[1] + 1)));
			if ((maze->getChar(player->GetPosition()[0], (player->GetPosition()[1] + 1))) == 'f') {
				finished = true;
			}
			break;
		case 'w':
			player->MoveUp(maze->getChar((player->GetPosition()[0] - 1), player->GetPosition()[1]));
			break;
		case 's':
			player->MoveDown(maze->getChar((player->GetPosition()[0] + 1), player->GetPosition()[1]));
			break;
		default:
			break;
		}
		keyPressed = ' ';

		maze->update(player);

		if (finished) { break; }

	}

}