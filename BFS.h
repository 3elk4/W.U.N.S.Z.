#pragma once

#include <iostream>
#include "snake.h"
#include "prizeAndScore.h"
#include "frameandbarrier.h"
#include "collisionmanager.h"

using namespace std;

class BFS
{
public:
	BFS();
	~BFS();

	vector<Point> getPath();
	void clearPath();
	void bfs(Snake &snake, PrizeAndScore &prizeAndScore, Obstacles &frameAndBarrier);
	vector<Point> reconstruct_path(const Point current_state);
	void clear();

private:
	map <Point, Point> came_from;
	vector <Point> path;
	vector<Point> visited;
	list<Point> queue;
	bool done;
};

