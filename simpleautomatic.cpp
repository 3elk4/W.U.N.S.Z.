#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

SimpleAutomatic::SimpleAutomatic() {
	delta = Point(0, 0);
}

direction SimpleAutomatic::chooseDirection(Snake &snake, PrizeAndScore &prizeAndScore) {
	delta = Point(prizeAndScore.getPrizePosition().x - snake.getHeadPosition().x, prizeAndScore.getPrizePosition().y - snake.getHeadPosition().y);
	direction chosen;
	
	//TODO: opisać to gdzieś sensownie
	if (delta.x <= 0 && delta.y < 0) {
		if (abs(delta.x) >= abs(delta.y)) chosen = direction::leftDir;
		else chosen = direction::up;
	}
	else if (delta.x > 0 && delta.y <= 0) {
		if (abs(delta.x) >= abs(delta.y)) chosen = direction::rightDir;
		else chosen = direction::up;
	}
	else if(delta.x < 0 && delta.y >= 0) {
		if (abs(delta.x) >= abs(delta.y)) chosen = direction::leftDir;
		else chosen = direction::down;
	}
	else if (delta.x >= 0 && delta.y > 0) {
		if (abs(delta.x) >= abs(delta.y)) chosen = direction::rightDir;
		else chosen = direction::down;
	}

	return checkDirection(chosen, snake.getHead());
}

direction SimpleAutomatic::checkDirection(direction chosen, direction head) {
	switch (chosen) {
		case direction::leftDir:
			if (head != direction::rightDir) return direction::leftDir;
			else if (delta.y > 0) return direction::down;
			else return direction::up;
			break;
		case direction::rightDir:
			if (head != direction::leftDir) return direction::rightDir;
			else if (delta.y > 0) return direction::down;
			else return direction::up;
			break;
		case direction::up:
			if (head != direction::down) return direction::up;
			else if (delta.x > 0) return direction::rightDir;
			else return direction::leftDir;
			break;
		case direction::down:
			if (head != direction::up) return direction::down;
			else if (delta.x > 0) return direction::rightDir;
			else return direction::leftDir;
			break;
	}
}


QTimer* SimpleAutomatic::getTimer() {
	return this->simpleAutomaticTimer;
}
void SimpleAutomatic::setTimer(QMainWindow *window) {
	this->simpleAutomaticTimer = new QTimer(window);
}


SimpleAutomatic::~SimpleAutomatic() {
	if(this->simpleAutomaticTimer != nullptr)
		delete this->simpleAutomaticTimer;
}





//auto chodzenie wunsza
/*
void MainWindow::goLeft(int deltaY){
	if(head != rightDir) head = leftDir;
	else{
		if(deltaY > 0) head = down;
		else head = up;
	}
}

void MainWindow::goRight(int deltaY){
	if(head != leftDir) head = rightDir;
	else{
		if(deltaY > 0) head = down;
		else head = up;
	}
}

void MainWindow::goUp(int deltaX){
	if(head != down) head = up;
	else {
		if(deltaX > 0) head = rightDir;
		else head = leftDir;
	}
}

void MainWindow::goDown(int deltaX){
	if(head != up) head = down;
	else {
		if(deltaX > 0) head = rightDir;
		else head = leftDir;
	}
}

*/


/*
void MainWindow::autoSnakeMove(){
	int deltaX = posPx - posSnake.x, deltaY = posPy - posSnake.y;
	if(deltaX <= 0 && deltaY < 0){
		if(abs(deltaX) >= abs(deltaY)){
			//idz w lewo
			goLeft(deltaY);
		}
		else if (deltaX == 0 && deltaY < 0) {
			//idz w gore
			goUp(deltaX);
		}
		else {
			//idz w gore
			goUp(deltaX);
		}
	}
	else if(deltaX > 0 && deltaY < 0){
		if(abs(deltaX) >= abs(deltaY)){
			//idz w prawo
			goRight(deltaY);
		}
		else if (deltaX > 0 && deltaY == 0) {
			//idź w prawo
			goRight(deltaY);
		}
		else{
			//idz w gore
			goUp(deltaX);
		}
	}
	else if(deltaX < 0 && deltaY >= 0){
		if(abs(deltaX) >= abs(deltaY)){
			//idz w lewo
			goLeft(deltaY);
		}
		else if (deltaX < 0 && deltaY == 0) {
			//idz w lewo
			goLeft(deltaY);
		}

		else{
			//idz w dol
			goDown(deltaX);
		}
	}
	else if(deltaX > 0 && deltaY >= 0){
		if(abs(deltaX) >= abs(deltaY)){
			//idz w prawo
			goRight(deltaY);
		}
		else if (deltaX == 0 && deltaY > 0) {
			//idz w dol
			goDown(deltaX);
		}
		else{
			//idz w dol
			goDown(deltaX);
		}
	}




}

*/
