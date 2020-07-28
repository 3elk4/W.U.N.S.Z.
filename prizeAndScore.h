#ifndef PRIZE_H
#define PRIZE_H

#include <iostream>
#include <QTimer>
#include <QMainWindow>
#include "point.h"
#include "constants.h"

class PrizeAndScore {
public:
	PrizeAndScore();
	~PrizeAndScore();

	//get & set 
	QTimer* getTimer();
	void setTimer(QMainWindow *window);

	Point getPrizePosition();
	void setPrizePosition(Point ptk);

	int getScore();
	void increaseScore();
	void setZeroScore();

private:
	QTimer *prizeTimer = nullptr;
	Point prizePosition;
	int score;
};

#endif // PRIZE_H
