/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *frame;
    QLabel *label;
    QLCDNumber *lcdNumber;
    QGroupBox *groupBox;
    QRadioButton *human;
    QRadioButton *automat;
    QRadioButton *theShortest;
    QPushButton *startButton;
    QFrame *line;
    QWidget *board;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(890, 430);
        MainWindow->setFocusPolicy(Qt::ClickFocus);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setAnimated(true);
        MainWindow->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks|QMainWindow::ForceTabbedDocks);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(670, 10, 211, 371));
        frame->setAutoFillBackground(false);
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 71, 20));
        label->setFocusPolicy(Qt::NoFocus);
        label->setAutoFillBackground(false);
        label->setAlignment(Qt::AlignCenter);
        lcdNumber = new QLCDNumber(frame);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(80, 10, 121, 21));
        lcdNumber->setLayoutDirection(Qt::LeftToRight);
        lcdNumber->setFrameShape(QFrame::WinPanel);
        lcdNumber->setFrameShadow(QFrame::Sunken);
        lcdNumber->setSmallDecimalPoint(false);
        lcdNumber->setDigitCount(12);
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);
        groupBox = new QGroupBox(frame);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 60, 191, 261));
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        human = new QRadioButton(groupBox);
        human->setObjectName(QString::fromUtf8("human"));
        human->setEnabled(false);
        human->setGeometry(QRect(10, 30, 131, 17));
        human->setFocusPolicy(Qt::ClickFocus);
        human->setChecked(true);
        automat = new QRadioButton(groupBox);
        automat->setObjectName(QString::fromUtf8("automat"));
        automat->setEnabled(false);
        automat->setGeometry(QRect(10, 50, 161, 17));
        automat->setFocusPolicy(Qt::ClickFocus);
        automat->setCheckable(true);
        theShortest = new QRadioButton(groupBox);
        theShortest->setObjectName(QString::fromUtf8("theShortest"));
        theShortest->setEnabled(false);
        theShortest->setGeometry(QRect(10, 70, 151, 17));
        theShortest->setFocusPolicy(Qt::ClickFocus);
        startButton = new QPushButton(frame);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setEnabled(true);
        startButton->setGeometry(QRect(10, 330, 111, 31));
        startButton->setFocusPolicy(Qt::NoFocus);
        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 30, 191, 20));
        line->setFrameShadow(QFrame::Sunken);
        line->setFrameShape(QFrame::HLine);
        board = new QWidget(centralWidget);
        board->setObjectName(QString::fromUtf8("board"));
        board->setGeometry(QRect(10, 10, 650, 370));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 890, 21));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "POINTS:", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "W.U.N.S.Z motion mode", nullptr));
        human->setText(QApplication::translate("MainWindow", "Human W.U.N.S.Z", nullptr));
        automat->setText(QApplication::translate("MainWindow", "Simple automatic W.U.N.S.Z", nullptr));
        theShortest->setText(QApplication::translate("MainWindow", "A-star W.U.N.S.Z", nullptr));
        startButton->setText(QApplication::translate("MainWindow", "STOP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
