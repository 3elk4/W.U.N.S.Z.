#include "BFS.h"



BFS::BFS()
{
}


BFS::~BFS()
{

}

vector<Point> BFS::getPath()
{
	return this->path;
}

void BFS::clearPath()
{
	this->path.clear();
}

void BFS::bfs(Snake & snake, PrizeAndScore & prizeAndScore, Obstacles & frameAndBarrier)
{
	clear();
	Point headPos = snake.getHeadPosition();
	Point prize = prizeAndScore.getPrizePosition();

	this->visited.push_back(headPos);
	this->queue.push_back(headPos);
	while (!this->done){
		Point current_state = this->queue.front();
		this->queue.pop_front();
		vector <Point> neighbours = { current_state + Point(0, -tileSize::h),
									current_state + Point(0, tileSize::h),
									current_state + Point(-tileSize::w, 0),
									current_state + Point(tileSize::w, 0)
		};

		for (const auto & neighbour : neighbours) {
			if (CollisionManager::checkSnakeCollisionAbility(neighbour, snake, frameAndBarrier)) {
				continue;
			}
			else if (neighbour == prize) {
				this->came_from[neighbour] = current_state;
				this->done = true;
				break;
			}
			else if (find(this->visited.begin(), this->visited.end(), neighbour) == this->visited.end()) {
				this->visited.push_back(neighbour);
				this->queue.push_back(neighbour);
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

vector<Point> BFS::reconstruct_path(const Point current_state)
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

void BFS::clear()
{
	this->came_from.clear();
	this->visited.clear();
	this->path.clear();
	this->queue.clear();
	this->done = false;
}
