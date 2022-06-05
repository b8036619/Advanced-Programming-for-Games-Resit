using namespace std;
#include "Maze.h"
#include "Player.h"
#include "PathFinding.h"

#include <iostream>
#include <conio.h>

int main() {

	Maze* maze = new Maze();
	Player* player = new Player(16, 39);
	PathFinding* pathFinding = new PathFinding();
	

	bool finished = false;

	vector<char> moves = {};
	//char keyPressed;
	char currentMove = ' ';
	int counter = 0; //TEST
	while (true) { // find paths

		moves = pathFinding->FindPath(player->GetPosition(), maze->GetMaze());

		for (int i = 0; moves.size() > i; i++) {
			cout << '\n' << moves[i];
		}

		cout << '\n' << moves.size() << '\n';

		for (int i = 0; i < moves.size(); i++) {

			currentMove = moves[i];

			//cout << '\n' << currentMove << '\n';

			switch (currentMove)
			{
			case 'L':
				player->MoveLeft(maze->GetChar(player->GetPosition()[0], (player->GetPosition()[1] - 1)));
				break;
			case 'R':
				player->MoveRight(maze->GetChar(player->GetPosition()[0], (player->GetPosition()[1] + 1)));
				if ((maze->GetChar(player->GetPosition()[0], (player->GetPosition()[1] + 1))) == 'f') {
					finished = true;
				}
				break;
			case 'U':
				player->MoveUp(maze->GetChar((player->GetPosition()[0] - 1), player->GetPosition()[1]));
				break;
			case 'D':
				player->MoveDown(maze->GetChar((player->GetPosition()[0] + 1), player->GetPosition()[1]));
				break;
			default:
				break;
			}

			maze->Update(player);
			maze->PrintMaze(player);

		}

		/*
		if (counter == 20) { break; } // TEST
		counter++;
		*/
		/*
		while (true) { // follow path
			maze->PrintMaze(player);

			keyPressed = _getch();

			switch (keyPressed)
			{
			case 'a':
				player->MoveLeft(maze->GetChar(player->GetPosition()[0], (player->GetPosition()[1] - 1)));
				break;
			case 'd':
				player->MoveRight(maze->GetChar(player->GetPosition()[0], (player->GetPosition()[1] + 1)));
				if ((maze->GetChar(player->GetPosition()[0], (player->GetPosition()[1] + 1))) == 'f') {
					finished = true;
				}
				break;
			case 'w':
				player->MoveUp(maze->GetChar((player->GetPosition()[0] - 1), player->GetPosition()[1]));
				break;
			case 's':
				player->MoveDown(maze->GetChar((player->GetPosition()[0] + 1), player->GetPosition()[1]));
				break;
			default:
				break;
			}
			keyPressed = ' ';

			maze->Update(player);

			if (finished) { break; }

		}
		*/
		
	}

}