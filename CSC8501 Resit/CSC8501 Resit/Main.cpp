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
	

	vector<char> moves = {};
	char currentMove = ' ';
	bool finished = false;
	while (true) {

		if (maze->GetIsAllCollected()) {
			pathFinding->FindEnd();
		}

		moves = pathFinding->FindPath(player->GetPosition(), maze->GetMaze());

		for (int i = 0; i < moves.size(); i++) {

			currentMove = moves[i];

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

			if (player->GetPosition() == vector<int>{16,39}) {
				finished = true;
			}

		}

		if (finished) { break; }

	}

	cout << '\n' << "       ---------------------";
	cout << '\n' << "       | Final Health: " << player->GetHealth() << " |";
	cout << '\n' << "       ---------------------";

	cout << '\n' << '\n' << "       Press any key to exit";
	_getch();

}