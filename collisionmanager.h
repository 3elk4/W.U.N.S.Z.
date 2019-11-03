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
	static void initPrizePosition(Snake &snake, FrameAndBarrier &frameAndBarrier, PrizeAndScore &prizeAndscore);
	static bool isPrizeGained(Snake &snake, FrameAndBarrier &frameAndBarrier, PrizeAndScore &prizeAndScore);

	//snake
	static bool checkSnakeCollisionAbility(Snake &snake, FrameAndBarrier &frameAndBarrier);
	
	//barrier
	static void initBarrierPosition(FrameAndBarrier &frameAndBarrier);

	//astar
	static int collisionPossibility(Point probPtk, Snake &snake, FrameAndBarrier &frameAndBarrier);

private:
};

#endif // COLLISIONMANAGER_H
