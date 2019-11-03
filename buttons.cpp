#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

using namespace std;

void MainWindow::on_automat_clicked() {
    mode = isAuto;
}

void MainWindow::on_human_clicked() {
    mode = isHuman;
}

void MainWindow::on_theShortest_clicked(){
    mode = isShortest;
}

//tu poprawic dla the shortest + napisać oddzielnego loopa
void MainWindow::on_startButton_clicked() {
    if(ui->startButton->text().toStdString() == "STOP"){
		ui->automat->setEnabled(true);
		ui->human->setEnabled(true);
		ui->theShortest->setEnabled(true);

		simpleAutomatic.getTimer()->stop();
		astar.getTimer()->stop();
		snake.getTimer()->stop();

		ui->startButton->setText("START");
    }
    else {
		ui->automat->setEnabled(false);
		ui->human->setEnabled(false);
		ui->theShortest->setEnabled(false);

		if (mode == isAuto) {
			simpleAutomatic.getTimer()->start(speed::simpleAutomatic);
			astar.getTimer()->stop();
		}
		else if (mode == isShortest) {
			astar.getTimer()->start(speed::astar);
			simpleAutomatic.getTimer()->stop();
		}
		snake.getTimer()->start(speed::snake);
		ui->startButton->setText("STOP");
    }

}
