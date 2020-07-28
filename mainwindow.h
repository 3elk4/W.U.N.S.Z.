#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QkeyEvent>
#include <QTimer>
#include <vector>
#include <iostream>
#include <QRadioButton>
#include <map>
#include "point.h"
#include "constants.h"
#include "barrier.h"
#include "boxsize.h"
#include "snake.h"
#include "prizeAndScore.h"
#include "frameandbarrier.h"
#include "collisionmanager.h"
#include "simpleautomatic.h"
#include "astar.h"
#include "BFS.h"
#include "DFS.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

	//mainwindow
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent* event);
    void init();

	//score 
	void showScore();

    //get BoardSize
    static BoxSize getBoardSize() {
        return boardSize;
    }

	//getSquareSize
    static BoxSize getSquareSize() {
        return squareSize;
    }

	//getStartingPoint
	static Point getStartingPoint() {
		return startingPoint;
	}

private:
    Ui::MainWindow *ui;
	void setRadioButtons(bool value);	
	QTimer* algTimer;

	Snake snake;
	PrizeAndScore prizeAndScore;
	Obstacles frameAndbarrier;
	
	SimpleAutomatic simpleAutomatic;
	AStar astar;
	BFS bfs;
	DFS dfs;
	
    vector <vector<int>> board;

    int posY = 0, posX = 0;
    
    motionMode mode = isHuman;

    //size
    static BoxSize squareSize;
    static BoxSize boardSize;

    static Point startingPoint;

private slots:
	void empty_loop();
    void loop();
    void loopAutoSnakeOne();
    void loopTheShortestOne();
	void loopBFS();
	void loopDFS();
    void loopPrize();

    void on_automat_clicked();
    void on_human_clicked();
    void on_startButton_clicked();
    void on_theShortest_clicked();
	void on_BFS_clicked();
	void on_DFS_clicked();
};

#endif // MAINWINDOW_H
