#include "DFS.h"

DFS::DFS()
{
}

DFS::~DFS()
{
}

vector<Point> DFS::getPath()
{
	return this->path;
}

void DFS::clearPath()
{
	this->path.clear();
}

void DFS::dfs(Snake & snake, PrizeAndScore & prizeAndScore, Obstacles & frameAndBarrier)
{
	clear();
	Point headPos = snake.getHeadPosition();
	Point prize = prizeAndScore.getPrizePosition();

	this->stack.push_back(headPos);
	while (!this->stack.empty()) {
		Point current_state = this->stack.back();
		if (current_state == prize) break;
		if (find(this->visited.begin(), this->visited.end(), current_state) != this->visited.end() ||
			CollisionManager::checkSnakeCollisionAbility(current_state, snake, frameAndBarrier)) continue;

		this->visited.push_back(current_state);
		vector <Point> neighbours = { current_state + Point(0, -tileSize::h),
								current_state + Point(0, tileSize::h),
								current_state + Point(-tileSize::w, 0),
								current_state + Point(tileSize::w, 0)
		};

		for (const auto & neighbour : neighbours) {
			if (find(this->visited.begin(), this->visited.end(), neighbour) == this->visited.end()) {
				stack.push_back(neighbour);
				this->came_from[neighbour] = current_state;
			}
		}
	}

	this->path = reconstruct_path(prize);
	if (path.size() >= 2) {
		int deltaX = path[path.size() - 2].x - path[path.size() - 1].x;
		int deltaY = path[path.size() - 2].y - path[path.size() - 1].y;

		if (deltaX > 0 && deltaY == 0) snake.setHead(rightDir);
		else if (deltaX < 0 && deltaY == 0) snake.setHead(leftDir);
		else if (deltaX == 0 && deltaY > 0) snake.setHead(down);
		else if (deltaX == 0 && deltaY < 0) snake.setHead(up);
	}
}

vector<Point> DFS::reconstruct_path(const Point current_state)
{
	Point temp = current_state;
	this->path.clear();
	map <Point, Point>::iterator i;
	while (true) {
		i = this->came_from.find(temp);
		if (i != this->came_from.end()) {
			temp = this->came_from[temp];
			this->path.push_back(temp);
		}
		else break;
	}
	return this->path;
}

void DFS::clear()
{
	this->came_from.clear();
	this->visited.clear();
	this->path.clear();
	this->stack.clear();
}
