#include "PathFinding.h"
#include <stdlib.h>
#include <time.h>

PathFinding::PathFinding() {
	findEndPath = false;
}

PathFinding::~PathFinding() {

}

vector<char> PathFinding::FindPath(vector<int> pos, vector<vector<char>> maze) {

	if (pos.size() < 2) {
		//error
	}
	if (maze.size() < 1000) {
		//error
	}

	posCopy = pos;
	mazeCopy = maze;

	endPath = false;

	int numOfPaths = 0;
	while (true) { //Create paths

		if (branchPaths.size() > 0){
			paths.emplace_back(branchPaths[0]); // Moves branch to paths
			branchPaths.erase(branchPaths.begin());

			posCopy[0] = paths[paths.size() - 1][paths[paths.size() - 1].size() - 2];// Update position
			posCopy[1] = paths[paths.size() - 1][paths[paths.size() - 1].size() - 1];

			paths[paths.size() - 1].erase(paths[paths.size() - 1].begin() + paths[paths.size() - 1].size() - 2, paths[paths.size() - 1].end());

		}
		else {
			paths.emplace_back(empty);
		}
					
		char tempChar = ' ';
		srand(time(NULL));
		while (true) //Create a path
		{
			tempChar = FindNext(numOfPaths, findEndPath);
			paths[numOfPaths].emplace_back(tempChar);

			if (endPath == true) {
				endPath = false;
				break;
			}

			switch (tempChar) // Update Position on path
			{
			case 'L':
				posCopy[1] = posCopy[1] - 1;
				break;
			case 'R':
				posCopy[1] = posCopy[1] + 1;
				break;
			case 'U':
				posCopy[0] = posCopy[0] - 1;
				break;
			case 'D':
				posCopy[0] = posCopy[0] + 1;
				break;
			case '#':
				paths[numOfPaths] = empty;
				posCopy = pos;
				break;

			default:
				break;
			}
		}
		

		numOfPaths++;

		if (paths.size() > 10) { // Done enough paths
			break;
		}

	}

	vector<char> tempVec = paths[0];

	for (int i = 1; i < paths.size(); i++) { // Find smallest path

		if (tempVec.size() > paths[i].size()) {
			tempVec = paths[i];
		}
	}
	

	paths = {};
	branchPaths = {};
	posCopy = {};

	return tempVec;
	
}

char PathFinding::FindNext(int pathNo, bool findEnd) {

	char previous = 'E';

	int pathSize = 0;

	if (paths[pathNo] != empty) {
		pathSize = paths[pathNo].size();
	}
	else {
		paths[pathNo] = {};
	}


	if (paths[pathNo].size() < 1) { previous = ' '; }
	else { previous = paths[pathNo][pathSize - 1]; }

	vector<char> options = {};

	if (!findEnd) {
		if (posCopy[0] == 16 && posCopy[1] == 39) { options.emplace_back('L'); } // If at start
		else {

			if ((mazeCopy[posCopy[0]][posCopy[1] - 1] == ' ' || mazeCopy[posCopy[0]][posCopy[1] - 1] == '\x9C') && previous != 'R') { //Left

				options.emplace_back('L');
				if (mazeCopy[posCopy[0]][posCopy[1] - 1] == '\x9C') { options.emplace_back('F'); }

			}
			if ((mazeCopy[posCopy[0]][posCopy[1] + 1] == ' ' || mazeCopy[posCopy[0]][posCopy[1] + 1] == '\x9C') && previous != 'L') { //Right

				options.emplace_back('R');
				if (mazeCopy[posCopy[0]][posCopy[1] + 1] == '\x9C') { options.emplace_back('F'); }

			}
			if ((mazeCopy[posCopy[0] - 1][posCopy[1]] == ' ' || mazeCopy[posCopy[0] - 1][posCopy[1]] == '\x9C') && previous != 'D') { //Up

				options.emplace_back('U');
				if (mazeCopy[posCopy[0] - 1][posCopy[1]] == '\x9C') { options.emplace_back('F'); }

			}
			if ((mazeCopy[posCopy[0] + 1][posCopy[1]] == ' ' || mazeCopy[posCopy[0] + 1][posCopy[1]] == '\x9C') && previous != 'U') { //Down

				options.emplace_back('D');
				if (mazeCopy[posCopy[0] + 1][posCopy[1]] == '\x9C') { options.emplace_back('F'); }

			}
		}
	}
	else { // Finding exit
		if ((mazeCopy[posCopy[0]][posCopy[1] - 1] == ' ') && previous != 'R') { //Left

			options.emplace_back('L');

		}
		if ((mazeCopy[posCopy[0]][posCopy[1] + 1] == ' ') && previous != 'L') { //Right

			options.emplace_back('R');
			if (posCopy[0] == 16 && (posCopy[1] + 1) == 39) { options.emplace_back('F'); }

		}
		if ((mazeCopy[posCopy[0] - 1][posCopy[1]] == ' ') && previous != 'D') { //Up

			options.emplace_back('U');

		}
		if ((mazeCopy[posCopy[0] + 1][posCopy[1]] == ' ') && previous != 'U') { //Down

			options.emplace_back('D');

		}
	}

	if (options.size() == 0) { return '#'; } // Hit dead end

	else if (options.size() > 1){ // Multiple options

		int randomDirection = rand() % options.size(); // Pick path

		for (int i = 0; i < options.size(); i++) { // Check if £ or exit found
			if (options[i] == 'F') {
				endPath = true;
				return options[i - 1];
			}

			if (i != randomDirection) {
				CreateBranch(pathNo, options[i]); // Create new paths for the other directions
			}

		}

		return options[randomDirection];
	}

	else { return options[0]; }

}

void PathFinding::CreateBranch(int pathNo, char direction) {// Creates a new path to be used later

	vector<char> tempVec = paths[pathNo];
	tempVec.emplace_back(direction);

	switch (direction)
	{
	case 'L':
		tempVec.emplace_back(static_cast<char>(posCopy[0]));
		tempVec.emplace_back(static_cast<char>(posCopy[1] - 1));
		break;
	case 'R':
		tempVec.emplace_back(static_cast<char>(posCopy[0]));
		tempVec.emplace_back(static_cast<char>(posCopy[1] + 1));
		break;
	case 'U':
		tempVec.emplace_back(static_cast<char>(posCopy[0] - 1));
		tempVec.emplace_back(static_cast<char>(posCopy[1]));
		break;
	case 'D':
		tempVec.emplace_back(static_cast<char>(posCopy[0] + 1));
		tempVec.emplace_back(static_cast<char>(posCopy[1]));
		break;
	}

	branchPaths.emplace_back(tempVec);

}