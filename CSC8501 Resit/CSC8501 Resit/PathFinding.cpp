#include "PathFinding.h"

PathFinding::PathFinding() {

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

	bool shortPathFound = false;
	while (shortPathFound == false) {

		int numOfPaths = 0;
		bool pathFound = false;
		while (pathFound == false) {

			while (true)
			{

			}

		}

	}

}

char PathFinding::FindNext(int pathNo) {

	char previous = 'E';
	int pathSize = paths[pathNo].size();

	if (paths[pathNo].size() < 1) { previous = ' '; }
	else { previous = paths[pathNo][pathSize]; }

	vector<char> options;

	if ((mazeCopy[posCopy[0]][posCopy[1] - 1] == ' ' || mazeCopy[posCopy[0]][posCopy[1] + 1] == '\x9C') && previous != 'R') { //Left

		if (mazeCopy[posCopy[0]][posCopy[1] + 1] == '\x9C'){ options.emplace_back('F'); }
		else { options.emplace_back('L'); }

	}
	if ((mazeCopy[posCopy[0]][posCopy[1] + 1] == ' ' || mazeCopy[posCopy[0]][posCopy[1] + 1] == '\x9C') && previous != 'L') { //Right

		if (mazeCopy[posCopy[0]][posCopy[1] + 1] == '\x9C') { options.emplace_back('F'); }
		else { options.emplace_back('R'); }

		options.emplace_back('R');

	}
	if ((mazeCopy[posCopy[0] - 1][posCopy[1]] == ' ' || mazeCopy[posCopy[0]][posCopy[1] + 1] == '\x9C') && previous != 'D') { //Up

		if (mazeCopy[posCopy[0]][posCopy[1] + 1] == '\x9C') { options.emplace_back('F'); }
		else { options.emplace_back('U'); }

	}
	if ((mazeCopy[posCopy[0] + 1][posCopy[1]] == ' ' || mazeCopy[posCopy[0]][posCopy[1] + 1] == '\x9C') && previous != 'U') { //Down

		if (mazeCopy[posCopy[0]][posCopy[1] + 1] == '\x9C') { options.emplace_back('F'); }
		else { options.emplace_back('D'); }

	}

	if (options.size() == 0) { return '#'; }
	else if (options.size() > 1){
		
		for (int i = 0; i < options.size(); i++) {
			//create branch points
		}

		return options[0];
	}
	else { return options[0]; }

}