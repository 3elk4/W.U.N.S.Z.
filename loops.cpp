#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

using namespace std;

//TODO: posprawdzać czy aby na pewno taki boardsize ma być
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
	/*
	if(snake.getHead() == 1){
            //w gore
            posWy = (posWy - 10) % boardSize.boxHeight;
        }
        else if(head == 2){
            //w prawo
            posWx = (posWx + 10) % boardSize.boxWidth;
        }
        else if(head == 3){
            // w dol
            posWy = (posWy + 10) % boardSize.boxHeight;
        }
        else{
            posWx = (posWx - 10) % boardSize.boxWidth;
        }
	*/
        
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
    //doBoard();
    astar.astar(snake, prizeAndScore, frameAndbarrier);
}

void MainWindow::loopPrize(){
	CollisionManager::initPrizePosition(snake, frameAndbarrier, prizeAndScore);
}
