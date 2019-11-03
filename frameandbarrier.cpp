#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "frameandbarrier.h"

FrameAndBarrier::FrameAndBarrier() {
	frameSize = BoxSize(MainWindow::getBoardSize());
	frameStartingPoint = Point(MainWindow::getStartingPoint());
	initFrame();
}

set<Point> FrameAndBarrier::getFrame() {
	return frame;
}

void FrameAndBarrier::initFrame() {
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


BoxSize FrameAndBarrier::getFrameSize() {
	return this->frameSize;
}

void FrameAndBarrier::setFrameSize(BoxSize fs) {
	this->frameSize = BoxSize(fs.boxWidth, fs.boxHeight);
}

Point FrameAndBarrier::getFrameStaringPoint() {
	return this->frameStartingPoint;
}
void FrameAndBarrier::setFrameStartingPoint(Point p) {
	this->frameStartingPoint = Point(p.x, p.y);
}

Barrier* FrameAndBarrier::getBarrier() {
	return obstacle;
}

void FrameAndBarrier::setBarrier(Barrier *barrier) {
	this->obstacle = barrier;
}

FrameAndBarrier::~FrameAndBarrier() {
	frame.clear();
	//if(this->obstacle != nullptr) delete obstacle;
}

