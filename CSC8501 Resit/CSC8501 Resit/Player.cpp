#include "Player.h"

Player::Player(int y, int x) {
	position = { y, x };
	health = 150;
}

void Player::MoveDown(char c) {
	if (CheckMove(c)) {
		position[0]++;
		health--;
	}
}

void Player::MoveUp(char c) {
	if (CheckMove(c)) {
		position[0]--;
		health--;
	}
}

void Player::MoveLeft(char c) {
	if (CheckMove(c)) {
		position[1]--;
		health--;
	}
}

void Player::MoveRight(char c) {
	if (CheckMove(c)) {
		position[1]++;
		health--;
	}
}

bool Player::CheckMove(char c) {
	if (c == ' ') { return true; }
	else if (c == '\x9C') {
		health = health + 11;
		return true; 
	}
	else { return false; }
}
