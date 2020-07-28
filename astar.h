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

	vector<Point> getPath();
	void clearPath();
	
	void clearAll();
	
	int heuristic(Point first, Point second);
	void astar(Snake &snake, PrizeAndScore &prizeAndScore, Obstacles &frameAndBarrier);
	vector<Point> recontructPath(map <Point, Point> &cameFrom, const Point &current);

private:
	vector <Point> path;

	vector <Point> openSet;
	vector <Point> closedSet;
	map <Point, Point> cameFrom;

	map <Point, int> gScore;
	map <Point, int> fScore;
};

#endif // ASTAR_H