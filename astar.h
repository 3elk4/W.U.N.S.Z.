#ifndef ASTAR_H
#define ASTAR_H

#include <iostream>
#include <QTimer>
#include "point.h"
#include "constants.h"

using namespace std;

class AStar {
public:
	AStar();
	~AStar();

	QTimer* getTimer();
	void setTimer(QMainWindow *window);

	vector<Point> getPath();
	
	void clearAll();
	
	int heuristic(Point first, Point second);
	void astar(Snake &snake, PrizeAndScore &prizeAndScore, FrameAndBarrier &frameAndBarrier);
	vector<Point> recontructPath(map <Point, Point> &cameFrom, const Point &current);

private:
	QTimer *aStarTimer = nullptr;

	vector <Point> path;

	vector <Point> openSet;
	vector <Point> closedSet;
	map <Point, Point> cameFrom;

	map <Point, int> gScore;
	map <Point, int> fScore;
};

#endif // ASTAR_H