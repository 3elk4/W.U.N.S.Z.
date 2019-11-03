#ifndef SIMPLEAUTOMATIC_H
#define SIMPLEAUTOMATIC_H

#include <iostream>
#include "point.h"
#include "constants.h"
#include "snake.h"
#include <map>

using namespace std;

class SimpleAutomatic {
public:
	SimpleAutomatic();
	~SimpleAutomatic();

	QTimer* getTimer();
	void setTimer(QMainWindow *window);

	direction chooseDirection(Snake &snake, PrizeAndScore &prizeAndScore);
	direction checkDirection(direction chosen, direction head);

private:
	QTimer *simpleAutomaticTimer = nullptr;
	Point delta;
};

#endif // SIMPLEAUTOMATIC_H