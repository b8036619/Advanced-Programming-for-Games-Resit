#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

using namespace std;

class Player {
public:

	Player();
	~Player();

	vector<int> GetPosition() { return position; }

	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();

private:

	vector<int> position;

};

#endif
