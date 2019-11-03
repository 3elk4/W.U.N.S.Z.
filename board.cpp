#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
/*
bool MainWindow::isWunsz(Point point){
	for (Point p : snake.getSnakeBody()) {
		if()
	}
	for(int i = 1; i < snake.getSnakeBody().size(); ++i){
		if(snakeBody[i].x == x && snakeBody[i].y == y){
			return true;
		}
	}
	return false;
}

bool MainWindow::isBarrier(int x, int y){
	vector <Point> temp = forcefield.getBarrierShape();
	for(int i = 0; i < temp.size(); ++i){
		if(temp[i].x == x && temp[i].y == y){
			return true;
		}
	}
	return false;
}

void MainWindow::doBoard(){
	board.clear();
	for(int i = 0; i < (boardSize.boxHeight/ squareSize.boxHeight); ++i){
		board.push_back(vector <int>(boardSize.boxWidth/squareSize.boxWidth ));
	}

	for(int i = 0; i < (boardSize.boxHeight/squareSize.boxHeight); ++i){
		for(int j = 0; j < (boardSize.boxWidth/squareSize.boxWidth); ++j){
			isBoard = motionScore::empty;
			if((i == 0 || i == (boardSize.boxHeight/squareSize.boxHeight) - 1) && (j == 0 || j == (boardSize.boxWidth/squareSize.boxWidth) - 1)){
				isBoard = wallorbarrier;
			}
			else if(isBarrier(i * squareSize.boxHeight , j * squareSize.boxWidth) == true){
				isBoard = wallorbarrier;
			}
			else if(i * squareSize.boxHeight  == snakeBody[0].x && j * squareSize.boxWidth == snakeBody[0].y){
				isBoard = headOfSnake;
			}
			else if(isWunsz(i * squareSize.boxHeight, j *squareSize.boxWidth) == true){
				isBoard = wunszyc;
			}
			else if(i * squareSize.boxHeight == posPy && j * squareSize.boxWidth == posPx){
				isBoard = food;
			}
			board[i][j] = isBoard;
		}
	}
}

*/
