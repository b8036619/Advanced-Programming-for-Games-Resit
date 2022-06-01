#ifndef PRIZE_H
#define PRIZE_H

#include <vector>

using namespace std;

class Prize {
public:

	Prize(int y, int x);
	~Prize();

	vector<int> GetPosition() { return position; }

	bool isCollected() { return collected; }

	void playerCollected() { collected = true; }

private:

	vector<int> position;
	bool collected;

};

#endif
