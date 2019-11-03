#include "mainwindow.h"
#include "mainwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

using namespace std;

Barrier::Barrier(BoxSize ptk) {
	size = BoxSize(ptk.boxWidth, ptk.boxHeight);
}

/*bool barrier::checkIfCanDoBarrier(){
    if(size.x >= (MainWindow::getBoardSize().boxWidth / MainWindow::getSquareSize().boxWidth) - 2 || size.x < 1 || size.y >= (MainWindow::getBoardSize().boxHeight / MainWindow::getSquareSize().boxHeight) - 2 || size.y < 1) return false;
    int a = size.x * MainWindow::getSquareSize().boxWidth + startBarrier.x;
    int b = size.y * MainWindow::getSquareSize().boxHeight + startBarrier.y;
    if(a >= MainWindow::getBoardSize().boxWidth || b >= MainWindow::getBoardSize().boxHeight) return false;

    return true;
}*/

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

/*void swasticaBarrier::initBarrier() {
    for(int b = barrierStartingPoint.y; b < size.y * MainWindow::getSquareSize().boxHeight + barrierStartingPoint.y; b += MainWindow::getSquareSize().boxHeight){
        for(int a = barrierStartingPoint.x; a < size.x * MainWindow::getSquareSize().boxWidth + barrierStartingPoint.x; a += MainWindow::getSquareSize().boxWidth){
            if(a == (size.x/2) * MainWindow::getSquareSize().boxWidth + barrierStartingPoint.x || b == (size.y/2) * MainWindow::getSquareSize().boxHeight + barrierStartingPoint.y){
				barrierBody.push_back(Point(a, b));
            }
            if(b == barrierStartingPoint.y && (a > (size.x/2) * MainWindow::getSquareSize().boxWidth + barrierStartingPoint.x)){
				barrierBody.push_back(Point(a, b));
            }
            if(b == (size.y * MainWindow::getSquareSize().boxHeight + barrierStartingPoint.y) - MainWindow::getSquareSize().boxHeight && (a < (size.x/2) * MainWindow::getSquareSize().boxWidth + barrierStartingPoint.x)){
				barrierBody.push_back(Point(a, b));
            }
            if(a == barrierStartingPoint.x && (b < (size.y/2) * MainWindow::getSquareSize().boxHeight + barrierStartingPoint.y)){
				barrierBody.push_back(Point(a, b));
            }
            if(a == (size.x * MainWindow::getSquareSize().boxWidth + barrierStartingPoint.x) - MainWindow::getSquareSize().boxWidth && (b >  (size.y/2) * MainWindow::getSquareSize().boxHeight + barrierStartingPoint.y)){
				barrierBody.push_back(Point(a, b));
            }
        }
     }
}*/

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
