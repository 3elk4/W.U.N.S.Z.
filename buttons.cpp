#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

using namespace std;

//todo: disconnect
void MainWindow::on_automat_clicked() {
    //mode = isAuto;
	disconnect(algTimer, SIGNAL(timeout()), 0, 0);
	connect(algTimer, SIGNAL(timeout()), this, SLOT(loopAutoSnakeOne()));
}

void MainWindow::on_human_clicked() {
    //mode = isHuman;
	disconnect(algTimer, SIGNAL(timeout()), 0, 0);
	connect(algTimer, SIGNAL(timeout()), this, SLOT(empty_loop()));
}

void MainWindow::on_theShortest_clicked(){
    //mode = isShortest;
	disconnect(algTimer, SIGNAL(timeout()), 0, 0);
	connect(algTimer, SIGNAL(timeout()), this, SLOT(loopTheShortestOne()));
}

void MainWindow::on_BFS_clicked() {
	//mode = isBFS;
	disconnect(algTimer, SIGNAL(timeout()), 0, 0);
	connect(algTimer, SIGNAL(timeout()), this, SLOT(loopBFS()));
}

void MainWindow::on_DFS_clicked() {
	//mode = isDFS;
	disconnect(algTimer, SIGNAL(timeout()), 0, 0);
	connect(algTimer, SIGNAL(timeout()), this, SLOT(loopDFS()));
}

void MainWindow::setRadioButtons(bool value) {
	ui->automat->setEnabled(value);
	ui->human->setEnabled(value);
	ui->theShortest->setEnabled(value);
	ui->BFS->setEnabled(value);
	ui->DFS->setEnabled(value);
}

void MainWindow::on_startButton_clicked() {
    if(ui->startButton->text().toStdString() == "STOP"){
		setRadioButtons(true);
		snake.getTimer()->stop();
		algTimer->stop();
		ui->startButton->setText("START");
    }
    else {
		setRadioButtons(false);
		algTimer->start(speed::alg);
		snake.getTimer()->start(speed::snake);
		ui->startButton->setText("STOP");
    }

}
