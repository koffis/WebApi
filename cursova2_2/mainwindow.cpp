#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "daysinfo.h"
#include <QAction>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setStyleSheet("background-image:url(sky-2076868_960_720.jpg)");

    connect(ui->ButtonToShow5DayInfo, &QPushButton::clicked
            , this,&MainWindow::showDaysInfo);

    QPixmap pix("001-snow.png");
    QSize PicSize(50, 50);
    pix = pix.scaled(PicSize,Qt::KeepAspectRatio);

    ui->SkyInfo_MainForm_3->setPixmap(pix);
    ui->SkyInfo_MainForm_3->repaint();
    ui->SkyInfo_MainForm_3->setPixmap(pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showDaysInfo()
{
  DaysInfo lDaysInfo;
  lDaysInfo.setModal(true);
  lDaysInfo.exec();
}
