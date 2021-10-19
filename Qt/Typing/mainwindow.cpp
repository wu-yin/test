#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    switch(event->key()){
        case Qt::Key_A:
        qDebug("aa");
        break;
    }
}



MainWindow::~MainWindow()
{
    delete ui;
}

