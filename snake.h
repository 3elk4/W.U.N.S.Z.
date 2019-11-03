#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <QTimer>
#include <set>
#include "point.h"
#include "constants.h"

using namespace std;

class Snake {
public:
	Snake();
	~Snake();

	//snake
	void initBody();
	void speed();

	//get & set
	vector<Point> getSnakeBody();
	void addToSnakeBody(Point point);
	void clearSnakeBody() {
		this->snakeBody.clear();
	}

	Point getHeadPosition();
	void setHeadPosition(Point ptk);

	direction getHead();
	void setHead(direction dir);

	QTimer* getTimer();
	void setTimer(QMainWindow *window); 

	void setPrizeGained(bool value);

private:
	QTimer *snakeSpeed = nullptr;
	vector<Point> snakeBody;
	Point headPosition;
	direction head;

	bool isPrizeGained;
};

#endif // SNAKE_H
