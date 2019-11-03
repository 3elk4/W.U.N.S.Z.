#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "snake.h"

using namespace std;

Snake::Snake() {
	this->headPosition = Point(startPosition::x, startPosition::y);
	this->head = direction::down;
	this->isPrizeGained = false;
	this->snakeSpeed = NULL;
}

void Snake::initBody(){
     Point headSnake = {headPosition.x, headPosition.y};
     snakeBody.insert(snakeBody.begin(), headSnake);
     
	 if(!isPrizeGained){
         snakeBody.pop_back();
     }
}

void Snake::speed(){
   /* if((points % 10) && points != 0){
      //cout << "start1" << endl;
        time->start(200 - points*5);
    }
    else if(points == 0){
        //cout << "start2" << endl;
        time->start(200);
    }
    else if(points >= 20){
        //cout << "start3" << endl;
        time->start(200);
    }*/
    snakeSpeed->start(speed::snake);
}

#pragma region GET&SET
vector<Point> Snake::getSnakeBody() {
	return this->snakeBody;
}

void Snake::addToSnakeBody(Point point) {
	this->snakeBody.push_back(point);
}

Point Snake::getHeadPosition() {
	return this->headPosition;
}

void Snake::setHeadPosition(Point ptk) {
	this->headPosition = Point(ptk.x, ptk.y);
}

direction Snake::getHead() {
	return this->head;
}

void Snake::setHead(direction dir) {
	this->head = dir;
}

QTimer* Snake::getTimer() {
	return this->snakeSpeed;
}

void Snake::setTimer(QMainWindow *window) {
	snakeSpeed = new QTimer(window);
}

void Snake::setPrizeGained(bool value) {
	this->isPrizeGained = value;
}
#pragma endregion GET&SET

Snake::~Snake() {
	if(this->snakeSpeed != nullptr)
		delete snakeSpeed;
}


