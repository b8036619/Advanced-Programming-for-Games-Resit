#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

using namespace std;

class Player {
public:

	Player(int y, int x);
	~Player();

	vector<int> GetPosition() { return position; }

	void MoveUp(char c);
	void MoveDown(char c);
	void MoveLeft(char c);
	void MoveRight(char c);

	bool CheckMove(char c);

	int GetHealth() { return health; }

private:

	vector<int> position;

	int health;

};

#endif
