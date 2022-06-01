#ifndef PRIZES_H
#define PRIZES_H

#include <vector>

using namespace std;

class Prizes {
public:

	Prizes();
	~Prizes();

	vector<int> GetPosition() { return position; }

private:

	vector<int> position;
	bool collected;

};

#endif