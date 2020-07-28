#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

SimpleAutomatic::SimpleAutomatic() {
	delta = Point(0, 0);
}

direction SimpleAutomatic::chooseDirection(Snake &snake, PrizeAndScore &prizeAndScore) {
	delta = Point(prizeAndScore.getPrizePosition().x - snake.getHeadPosition().x, prizeAndScore.getPrizePosition().y - snake.getHeadPosition().y);
	direction chosen;

	if (delta.x <= 0 && delta.y < 0) {
		if (abs(delta.x) >= abs(delta.y)) chosen = direction::leftDir;
		else chosen = direction::up;
	}
	else if (delta.x > 0 && delta.y <= 0) {
		if (abs(delta.x) >= abs(delta.y)) chosen = direction::rightDir;
		else chosen = direction::up;
	}
	else if(delta.x < 0 && delta.y >= 0) {
		if (abs(delta.x) >= abs(delta.y)) chosen = direction::leftDir;
		else chosen = direction::down;
	}
	else if (delta.x >= 0 && delta.y > 0) {
		if (abs(delta.x) >= abs(delta.y)) chosen = direction::rightDir;
		else chosen = direction::down;
	}

	return checkDirection(chosen, snake.getHead());
}

direction SimpleAutomatic::checkDirection(direction chosen, direction head) {
	switch (chosen) {
		case direction::leftDir:
			if (head != direction::rightDir) return direction::leftDir;
			else if (delta.y > 0) return direction::down;
			else return direction::up;
			break;
		case direction::rightDir:
			if (head != direction::leftDir) return direction::rightDir;
			else if (delta.y > 0) return direction::down;
			else return direction::up;
			break;
		case direction::up:
			if (head != direction::down) return direction::up;
			else if (delta.x > 0) return direction::rightDir;
			else return direction::leftDir;
			break;
		case direction::down:
			if (head != direction::up) return direction::down;
			else if (delta.x > 0) return direction::rightDir;
			else return direction::leftDir;
			break;
	}
}

SimpleAutomatic::~SimpleAutomatic() {
}
