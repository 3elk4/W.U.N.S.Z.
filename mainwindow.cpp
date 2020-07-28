#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <QPainter>

using namespace std;

Point MainWindow::startingPoint = Point();
BoxSize MainWindow::boardSize = BoxSize();
BoxSize MainWindow::squareSize = BoxSize();

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent), ui(new Ui::MainWindow)
{	
	qsrand(time(NULL));
    ui->setupUi(this);

    this->setWindowTitle("W.U.N.S.Z");
    this->setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);
    this->setMinimumSize(this->size());
    this->setMaximumSize(this->size());

	startingPoint = Point(ui->board->pos().x(), ui->board->pos().y());
	boardSize = BoxSize(ui->board->size().width(), ui->board->size().height());
	squareSize = BoxSize(tileSize::w, tileSize::h);

	snake = Snake();
	prizeAndScore = PrizeAndScore();

	frameAndbarrier = Obstacles();
	frameAndbarrier.setBarrier(new snailBarrier());
	CollisionManager::initBarrierPosition(frameAndbarrier);
	frameAndbarrier.getBarrier()->initBarrier();

	simpleAutomatic = SimpleAutomatic();
	astar = AStar();

	init();
	

    //timers

	//snake
	snake.setTimer(this);
    connect(snake.getTimer(), SIGNAL(timeout()), this, SLOT(loop()));
	snake.getTimer()->start(speed::snake);

	//prize
    prizeAndScore.setTimer(this);
    connect(prizeAndScore.getTimer(), SIGNAL(timeout()), this, SLOT(loopPrize()));
	prizeAndScore.getTimer()->start(speed::prize);

	//autosnake
	algTimer = new QTimer(this);
    connect(algTimer, SIGNAL(timeout()), this, SLOT(empty_loop()));
	algTimer->start(speed::alg);

	CollisionManager::initPrizePosition(snake, frameAndbarrier, prizeAndScore);
}

//init
void MainWindow::init()
{
	snake.setHeadPosition(Point(startPosition::x, startPosition::y));
	snake.clearSnakeBody();
	snake.addToSnakeBody(snake.getHeadPosition());

	prizeAndScore.setZeroScore();
}

//moving
void MainWindow::keyPressEvent(QKeyEvent *event){
    if(mode == isAuto){
        return;
    }
    switch(event->key()){
        case Qt::Key_Down: {
            if(snake.getHead() != up) snake.setHead(direction::down);
            break;
        }
        case Qt::Key_Up: {
            if(snake.getHead() != down) snake.setHead(direction::up);
            break;
        }
        case Qt::Key_Left: {
            if(snake.getHead() != rightDir) snake.setHead(direction::leftDir);
            break;
        }
        case Qt::Key_Right: {
            if(snake.getHead() != leftDir) snake.setHead(direction::rightDir);
            break;
        }
        default: {
            return;
        }
    }
}

//drawing
void MainWindow::paintEvent(QPaintEvent* event){
    QPainter paint(this);
	this->showScore();

    //game frame
    paint.setBrush(Qt::blue);
	for (Point ptk : frameAndbarrier.getFrame()) {
		paint.drawRect(ptk.x, ptk.y, squareSize.boxWidth, squareSize.boxHeight);
	}

	//obstacle
	paint.setBrush(Qt::blue);
	for (Point point : frameAndbarrier.getBarrier()->getBarrierShape()) {
		paint.drawRect(point.x, point.y, squareSize.boxWidth, squareSize.boxHeight);
	}
    
    //path - a star
	paint.setBrush(Qt::Dense4Pattern);
	for (Point pathField : astar.getPath()) {
		paint.drawRect(pathField.x, pathField.y, squareSize.boxWidth, squareSize.boxHeight);
	}
	astar.clearPath();

	//path - bfs
	paint.setBrush(Qt::Dense4Pattern);
	for (Point pathField : bfs.getPath()) {
		paint.drawRect(pathField.x, pathField.y, squareSize.boxWidth, squareSize.boxHeight);
	}
	bfs.clearPath();

	//path - dfs
	paint.setBrush(Qt::Dense4Pattern);
	for (Point pathField : dfs.getPath()) {
		paint.drawRect(pathField.x, pathField.y, squareSize.boxWidth, squareSize.boxHeight);
	}
	dfs.clearPath();

	//food
	paint.setBrush(Qt::green);
	paint.drawRect(prizeAndScore.getPrizePosition().x, prizeAndScore.getPrizePosition().y, squareSize.boxWidth, squareSize.boxHeight);

    //snake
	paint.setBrush(Qt::red);
    for(Point ptk : snake.getSnakeBody()){
		paint.drawRect(ptk.x, ptk.y, squareSize.boxWidth, squareSize.boxHeight);
    }

    return;
}

MainWindow::~MainWindow() {
    delete ui;
}




