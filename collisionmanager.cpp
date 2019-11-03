#include "mainwindow.h"
#include "collisionmanager.h"

CollisionManager::CollisionManager() {
}

#pragma region PRIZE

void CollisionManager::initPrizePosition(Snake &snake, FrameAndBarrier &frameAndBarrier, PrizeAndScore &prizeAndscore) {
	vector<Point> emptyFields;

	set<Point> frame = frameAndBarrier.getFrame();
	vector<Point> barrierBody = frameAndBarrier.getBarrier()->getBarrierShape();
	vector<Point> snakeBody = snake.getSnakeBody();

	for (int i = MainWindow::getStartingPoint().x; i < MainWindow::getBoardSize().boxWidth; i += MainWindow::getSquareSize().boxWidth) {
		for (int j = MainWindow::getStartingPoint().y; j < MainWindow::getBoardSize().boxHeight; j += MainWindow::getSquareSize().boxHeight) {
			if (frame.find(Point(i, j)) == frame.end() && find(snakeBody.begin(), snakeBody.end(), Point(i, j)) == snakeBody.end() &&
				find(barrierBody.begin(), barrierBody.end(), Point(i,j)) == barrierBody.end())
				emptyFields.push_back(Point(i, j));
		}
	}

	prizeAndscore.setPrizePosition(emptyFields.at(qrand() % emptyFields.size()));
}

bool CollisionManager::isPrizeGained(Snake &snake, FrameAndBarrier &frameAndBarrier, PrizeAndScore &prizeAndScore) {
	Point head = snake.getHeadPosition();
	Point prize = prizeAndScore.getPrizePosition();
	
	if (head == prize) {
		snake.setPrizeGained(true);
		prizeAndScore.getTimer()->start(speed::prize);
		initPrizePosition(snake, frameAndBarrier, prizeAndScore);
		prizeAndScore.increaseScore();
		return true;
	}
	snake.setPrizeGained(false);
	return false;
}

#pragma endregion PRIZE

#pragma region SNAKE

bool CollisionManager::checkSnakeCollisionAbility(Snake &snake, FrameAndBarrier &frameAndBarrier) {
	Point head = snake.getHeadPosition();
	set<Point> frame = frameAndBarrier.getFrame();
	vector<Point> barrierBody = frameAndBarrier.getBarrier()->getBarrierShape();
	vector<Point> body = snake.getSnakeBody();

	if (frame.find(head) != frame.end()) {
		return true;
	}
	else if (find(barrierBody.begin(), barrierBody.end(), head) != barrierBody.end()) {
		return true;
	}
	else if (body.size() > 1) {
		if (find(body.begin() + 1, body.end(), head) != body.end())
			return true;
	}

	return false;
}

#pragma endregion SNAKE

#pragma region BARRIER
//barrier - set a position as second thing - easier
void CollisionManager::initBarrierPosition(FrameAndBarrier &frameAndBarrier) {
	vector<Point> emptyFields;
	set<Point> frame = frameAndBarrier.getFrame();

	for (int i = MainWindow::getStartingPoint().x; i < MainWindow::getBoardSize().boxWidth; i += MainWindow::getSquareSize().boxWidth) {
		for (int j = MainWindow::getStartingPoint().y; j < MainWindow::getBoardSize().boxHeight; j += MainWindow::getSquareSize().boxHeight) {
			if (frame.find(Point(i, j)) == frame.end()) {
				Point temp = Point(i, j) + Point(frameAndBarrier.getBarrier()->getBarrierSize().boxWidth * MainWindow::getSquareSize().boxWidth, frameAndBarrier.getBarrier()->getBarrierSize().boxHeight * MainWindow::getSquareSize().boxHeight);
				if (temp.x < MainWindow::getBoardSize().boxWidth && temp.y < MainWindow::getBoardSize().boxHeight) {
					emptyFields.push_back(Point(i, j));
				}
			}	
		}
	}
	
	frameAndBarrier.getBarrier()->setBarrierStartingPoint(emptyFields.at(qrand() % emptyFields.size()));
}

#pragma endregion BARRIER

#pragma region ASTAR
//astar
int CollisionManager::collisionPossibility(Point probPoint, Snake &snake, FrameAndBarrier &frameAndBarrier) {
	for (auto point : snake.getSnakeBody()) {
		if (probPoint == point) return cost::hightCost;
	}

	for (auto point : frameAndBarrier.getFrame()) {
		if (probPoint == point) return cost::hightCost;
	}

	for (auto point : frameAndBarrier.getBarrier()->getBarrierShape()) {
		if (probPoint == point) return cost::hightCost;
	}

	return cost::lowCost;
}

#pragma endregion ASTAR

CollisionManager::~CollisionManager() {
}