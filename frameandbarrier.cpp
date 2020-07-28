#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "frameandbarrier.h"

Obstacles::Obstacles() {
	frameSize = BoxSize(MainWindow::getBoardSize());
	frameStartingPoint = Point(MainWindow::getStartingPoint());
	initFrame();
}

set<Point> Obstacles::getFrame() {
	return frame;
}

void Obstacles::initFrame() {
	frame.clear();
	for (int i = frameStartingPoint.y; i < frameSize.boxHeight; i += MainWindow::getSquareSize().boxHeight) {
		frame.insert(Point(frameStartingPoint.x, i));
		frame.insert(Point(frameSize.boxWidth, i));
	}

	for (int i = frameStartingPoint.x; i < frameSize.boxWidth; i += MainWindow::getSquareSize().boxWidth) {
		frame.insert(Point(i, frameStartingPoint.y));
		frame.insert(Point(i, frameSize.boxHeight));
	}
	frame.insert(Point(frameSize.boxWidth, frameSize.boxHeight));
}


BoxSize Obstacles::getFrameSize() {
	return this->frameSize;
}

void Obstacles::setFrameSize(BoxSize fs) {
	this->frameSize = BoxSize(fs.boxWidth, fs.boxHeight);
}

Point Obstacles::getFrameStaringPoint() {
	return this->frameStartingPoint;
}
void Obstacles::setFrameStartingPoint(Point p) {
	this->frameStartingPoint = Point(p.x, p.y);
}

Barrier* Obstacles::getBarrier() {
	return obstacle;
}

void Obstacles::setBarrier(Barrier *barrier) {
	this->obstacle = barrier;
}

Obstacles::~Obstacles() {
	frame.clear();
	//if(this->obstacle != nullptr) delete obstacle;
}

