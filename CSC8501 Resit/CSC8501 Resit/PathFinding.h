#ifndef PATHFINDING_H
#define PATHFINDING_H

#include <vector>

using namespace std;

class PathFinding {
public:

	PathFinding();
	~PathFinding();

	vector<char> FindPath(vector<int> pos, vector<vector<char>> maze);

	char FindNext(int pathNo);


private:

	vector<vector<char>> paths;

	vector<vector<char>> pathsToCheck;

	vector<vector<int>> branchPoints;

	vector<int> posCopy;
	vector<vector<char>> mazeCopy;

};

#endif
