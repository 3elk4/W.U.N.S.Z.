#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "prizeAndScore.h"

using namespace std;

PrizeAndScore::PrizeAndScore() {
	this->prizePosition = Point(0, 0);
	this->score = 0;
	this->prizeTimer = NULL;
}

#pragma region GET&SET
QTimer* PrizeAndScore::getTimer() {
	return this->prizeTimer;
}

void PrizeAndScore::setTimer(QMainWindow *window) {
	this->prizeTimer = new QTimer(window);
}

Point PrizeAndScore::getPrizePosition() {
	return this->prizePosition;
}

void PrizeAndScore::setPrizePosition(Point ptk) {
	this->prizePosition = Point(ptk.x, ptk.y);
}

int PrizeAndScore::getScore() {
	return this->score;
}
void PrizeAndScore::increaseScore() {
	this->score++;
}

void PrizeAndScore::setZeroScore() {
	this->score = 0;
}
#pragma endregion GET&SET

PrizeAndScore::~PrizeAndScore(){
	if(this->prizeTimer != nullptr)
		delete prizeTimer;
}

void MainWindow::showScore() {
	ui->lcdNumber->display(prizeAndScore.getScore());
}