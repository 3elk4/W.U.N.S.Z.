#ifndef DFS_H
#define DFS_H

#include <iostream>
#include "snake.h"
#include "prizeAndScore.h"
#include "frameandbarrier.h"
#include "collisionmanager.h"
#include <list>

using namespace std;

class DFS
{
public:
	DFS();
	~DFS();

	vector<Point> getPath();
	void clearPath();
	void dfs(Snake &snake, PrizeAndScore &prizeAndScore, Obstacles &frameAndBarrier);
	vector<Point> reconstruct_path(const Point current_state);
	void clear();

private:
	map <Point, Point> came_from;
	vector <Point> path;
	vector<Point> visited;
	list<Point> stack;
};

#endif //DFS_H