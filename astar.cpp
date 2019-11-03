#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "astar.h"
#include <iostream>


AStar::AStar() {
}

AStar::~AStar() {
	if(this->aStarTimer != nullptr)
		delete this->aStarTimer;
}



QTimer* AStar::getTimer() {
	return this->aStarTimer;
}

void AStar::setTimer(QMainWindow *window) {
	this->aStarTimer = new QTimer(window);
}

vector<Point> AStar::getPath() {
	return this->path;
}


// heuristic function. estimates the cost to reach goal(second) from node first.
int AStar::heuristic(Point first, Point second) {
	return abs(first.x - second.x) + abs(first.y - second.y);
}

//This method creates the shortest path to the goal, based on map of points and current position
vector <Point> AStar::recontructPath(map <Point, Point> &cameFrom, const Point &current) {
	Point temp = current;
	vector <Point> buff;
	map <Point, Point>::iterator i;
	while (true) {
		i = cameFrom.find(temp);
		if (i != cameFrom.end()) {
			temp = cameFrom[temp];
			buff.push_back(temp);
		}
		else break;
	}
	return buff;
}

void AStar::clearAll() {
	openSet.clear();
	gScore.clear();
	fScore.clear();
	// For node n, cameFrom[n] is the node immediately preceding it on the cheapest path from start to n currently known.
	cameFrom.clear();
	closedSet.clear();
	path.clear();
}


void AStar::astar(Snake &snake, PrizeAndScore &prizeAndScore, FrameAndBarrier &frameAndBarrier) {
	//preparing to 
	clearAll();

	//a* finds the way from start (headPos) to goal(prize)
	Point headPos = snake.getHeadPosition();
	Point prize = prizeAndScore.getPrizePosition();

	//for what check path if there is no there?
	if (headPos == prize) {
		return;
	}

	// The set of discovered nodes that may need to be (re-)expanded.
	// Initially, only the start node is known.
	openSet.push_back(headPos);

	// For node n, gScore[n] is the cost of the cheapest path from start to n currently known.
	gScore[headPos] = 0;
	// For node n, fScore[n] := gScore[n] + h(n).
	fScore[headPos] = heuristic(headPos, prize);

	while (!openSet.empty()) {
		//has the lowest score
		Point current = openSet[0];
		int value = fScore[openSet[0]];

		//the node in openSet having the lowest fScore[] value
		for (auto i = openSet.begin(); i != openSet.end(); ++i) {
			if (fScore[*i] < value) {
				value = fScore[*i];
				current = *i;
			}
		}

		//current == goal
		if (current == prize) {
			path = recontructPath(cameFrom, current);
			if (path.size() >= 2) {
				int deltaX = path[path.size() - 2].x - path[path.size() - 1].x;
				int deltaY = path[path.size() - 2].y - path[path.size() - 1].y;

				if (deltaX > 0 && deltaY == 0) snake.setHead(rightDir);
				else if (deltaX < 0 && deltaY == 0) snake.setHead(leftDir);
				else if (deltaX == 0 && deltaY > 0) snake.setHead(down);
				else if (deltaX == 0 && deltaY < 0) snake.setHead(up);
			}
			return;
		}

	
		//remove current
		for (auto j = openSet.begin(); j != openSet.end(); ++j) {
			if (*j == current) {
				openSet.erase(j);
				break;
			}
		}

		//here are added all checked points
		closedSet.push_back(current);

		//now check neighbours
		vector <Point> neighbours = {	current + Point(0, -tileSize::h), 
										current + Point(0, tileSize::h),
										current + Point(-tileSize::w, 0),
										current + Point(tileSize::w, 0)
									};
	
		for (const auto &n : neighbours) {
			//continue if neighbour was already checked
			if (find(closedSet.begin(), closedSet.end(), n) != closedSet.end())
				continue;

			// heuristic(current, n) + CollisionManager::collisionPossibility(n, snake, frameAndBarrier)
			// is the weight of the edge from current to neighbor
		   // tentative_gScore is the distance from start to the neighbor through current
			int tentative_gScore = gScore[current] + heuristic(current, n) + CollisionManager::collisionPossibility(n, snake, frameAndBarrier);

			//add if neighbour is not in open set
			if (find(openSet.begin(), openSet.end(), n) == openSet.end())
				openSet.push_back(n);
			else if (tentative_gScore >= gScore[n])
				continue;

			// This path to neighbor is better than any previous one. Record it!
			cameFrom[n] = current;
			gScore[n] = tentative_gScore;
			fScore[n] = tentative_gScore + heuristic(n, prize);

		}

	}
}