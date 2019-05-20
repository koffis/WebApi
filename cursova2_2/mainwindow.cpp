#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "daysinfo.h"
#include "details.h"
#include <QAction>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setStyleSheet("background-image:url(fon_svet_polosy_pyatna_odnotonnyy_43981_2560x1440.jpg)");

    connect(ui->ButtonToShow5DayInfo, &QPushButton::clicked
            , this,&MainWindow::showDaysInfo);

    connect(ui->ButtonToShowDetails, &QPushButton::clicked
            , this,&MainWindow::showDetailsInfo);

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

void MainWindow::showDetailsInfo()
{
  Details lDetailsInfo;
  lDetailsInfo.setModal(true);
  lDetailsInfo.exec();
}
