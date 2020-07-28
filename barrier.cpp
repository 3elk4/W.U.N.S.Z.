#include "mainwindow.h"
#include "mainwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

using namespace std;

Barrier::Barrier(BoxSize ptk) {
	size = BoxSize(ptk.boxWidth, ptk.boxHeight);
}

void lShapeBarrier::initBarrier(){
        for(int b = barrierStartingPoint.y; b < size.boxHeight * MainWindow::getSquareSize().boxHeight + barrierStartingPoint.y; b += MainWindow::getSquareSize().boxHeight){
            for(int a = barrierStartingPoint.x; a < size.boxWidth * MainWindow::getSquareSize().boxWidth + barrierStartingPoint.x; a += MainWindow::getSquareSize().boxWidth){
                if(a == barrierStartingPoint.x || b == (size.boxHeight * MainWindow::getSquareSize().boxHeight + barrierStartingPoint.y) - MainWindow::getSquareSize().boxHeight){
                    barrierBody.push_back(Point(a, b));
                }
            }
        }
}

void cShapeBarrier::initBarrier() {
    for(int b = barrierStartingPoint.y; b < size.boxHeight * MainWindow::getSquareSize().boxHeight + barrierStartingPoint.y; b += MainWindow::getSquareSize().boxHeight){
        for(int a = barrierStartingPoint.x; a < size.boxWidth * MainWindow::getSquareSize().boxWidth + barrierStartingPoint.x; a += MainWindow::getSquareSize().boxWidth){
            if(a == barrierStartingPoint.x || b == barrierStartingPoint.y || b == (size.boxHeight * MainWindow::getSquareSize().boxHeight + barrierStartingPoint.y) - MainWindow::getSquareSize().boxHeight){
				barrierBody.push_back(Point(a, b));
            }
        }
    }
}

void lineBarrier::initBarrier() {
    for(int b = barrierStartingPoint.y; b < size.boxHeight * MainWindow::getSquareSize().boxHeight + barrierStartingPoint.y; b += MainWindow::getSquareSize().boxHeight){
        for(int a = barrierStartingPoint.x; a < size.boxWidth * MainWindow::getSquareSize().boxWidth + barrierStartingPoint.x; a += MainWindow::getSquareSize().boxWidth){
			barrierBody.push_back(Point(a, b));
        }
    }
}

void snailBarrier::initBarrier() {
    for(int b = barrierStartingPoint.y; b < size.boxHeight * MainWindow::getSquareSize().boxHeight + barrierStartingPoint.y; b += MainWindow::getSquareSize().boxHeight){
        for(int a = barrierStartingPoint.x; a < size.boxWidth * MainWindow::getSquareSize().boxWidth + barrierStartingPoint.x; a += MainWindow::getSquareSize().boxWidth){
            if(a == barrierStartingPoint.x || b == barrierStartingPoint.y || b == (size.boxHeight * MainWindow::getSquareSize().boxHeight + barrierStartingPoint.y) - MainWindow::getSquareSize().boxHeight || (a == (size.boxWidth * MainWindow::getSquareSize().boxWidth + barrierStartingPoint.x) - MainWindow::getSquareSize().boxWidth && b > barrierStartingPoint.y + 2 * MainWindow::getSquareSize().boxHeight)) {
				barrierBody.push_back(Point(a, b));
            }
        }
    }
}

snailBarrier::~snailBarrier() {
	barrierBody.clear();
}


Barrier::~Barrier(){
    barrierBody.clear();
}
