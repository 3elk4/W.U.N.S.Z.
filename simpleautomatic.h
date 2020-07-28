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

	direction chooseDirection(Snake &snake, PrizeAndScore &prizeAndScore);
	direction checkDirection(direction chosen, direction head);

private:
	Point delta;
};

#endif // SIMPLEAUTOMATIC_H