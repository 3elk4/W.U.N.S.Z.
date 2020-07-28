#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include <iostream>
#include "snake.h"
#include "prizeAndScore.h"
#include "frameandbarrier.h"
#include <algorithm>
#include <set>
#include <QtGlobal>

using namespace std;

class CollisionManager {
public:
	CollisionManager();
	~CollisionManager();

	//prize
	static void initPrizePosition(Snake &snake, Obstacles &frameAndBarrier, PrizeAndScore &prizeAndscore);
	static bool isPrizeGained(Snake &snake, Obstacles &frameAndBarrier, PrizeAndScore &prizeAndScore);

	//snake
	static bool checkSnakeCollisionAbility(Snake &snake, Obstacles &frameAndBarrier);
	
	//barrier
	static void initBarrierPosition(Obstacles &frameAndBarrier);

	//astar
	static int collisionPossibility(Point probPtk, Snake &snake, Obstacles &frameAndBarrier);

	//dfs, bfs
	static bool checkSnakeCollisionAbility(const Point & snakeHead, Snake &snake, Obstacles &frameAndBarrier);

private:
};

#endif // COLLISIONMANAGER_H
