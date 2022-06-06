#ifndef PATHFINDING_H
#define PATHFINDING_H

#include <vector>

using namespace std;

class PathFinding {
public:

	PathFinding();
	~PathFinding();

	vector<char> FindPath(vector<int> pos, vector<vector<char>> maze);

	void FindEnd() { findEndPath = true; }

private:

	char FindNext(int pathNo, bool findEnd);

	void CreateBranch(int pathNo, char direction);

	vector<vector<char>> paths;

	vector<vector<char>> branchPaths;

	vector<int> posCopy;
	vector<vector<char>> mazeCopy;

	bool findEndPath;

	bool endPath;

	vector<char> empty = { 'E','M','P','T','Y' };

};

#endif
