#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

using namespace std;

void MainWindow::empty_loop(){}

void MainWindow::loop() {
	switch (snake.getHead()) {
		case direction::up:
			snake.setHeadPosition(Point(snake.getHeadPosition().x, snake.getHeadPosition().y - squareSize.boxHeight));
			break;
		case direction::rightDir:
			snake.setHeadPosition(Point(snake.getHeadPosition().x + squareSize.boxWidth, snake.getHeadPosition().y));
			break;
		case direction::down:
			snake.setHeadPosition(Point(snake.getHeadPosition().x, snake.getHeadPosition().y + squareSize.boxHeight));
			break;
		case direction::leftDir:
			snake.setHeadPosition(Point(snake.getHeadPosition().x - squareSize.boxWidth, snake.getHeadPosition().y));
			break;
	}
        
    //funckje odnośnie snake'a jedzonka, punktów, kolizji
	snake.initBody();
	CollisionManager::isPrizeGained(snake, frameAndbarrier, prizeAndScore);
	if (CollisionManager::checkSnakeCollisionAbility(snake, frameAndbarrier)) {
		init();
		prizeAndScore.getTimer()->start(speed::prize);
	}
	snake.speed();
    update();
}

void MainWindow::loopAutoSnakeOne(){
    snake.setHead(simpleAutomatic.chooseDirection(snake, prizeAndScore));
}

void MainWindow::loopTheShortestOne(){
    astar.astar(snake, prizeAndScore, frameAndbarrier);
}

void MainWindow::loopBFS() {
	bfs.bfs(snake, prizeAndScore, frameAndbarrier);
}

void MainWindow::loopDFS() {
	dfs.dfs(snake, prizeAndScore, frameAndbarrier);
}

void MainWindow::loopPrize(){
	CollisionManager::initPrizePosition(snake, frameAndbarrier, prizeAndScore);
}
