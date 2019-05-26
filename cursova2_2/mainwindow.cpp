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


    connect(ui->mButtonToShow5DayInfo, &QPushButton::clicked
            , this,&MainWindow::showDaysInfo);

    connect(ui->mButtonToShowDetails, &QPushButton::clicked
            , this,&MainWindow::showDetailsInfo);

    QPixmap pix("001-snow.png");
    QSize PicSize(50, 50);
    pix = pix.scaled(PicSize,Qt::KeepAspectRatio);

    ui->SkyInfo_MainForm_3->setPixmap(pix);
    ui->SkyInfo_MainForm_3->repaint();
    ui->SkyInfo_MainForm_3->setPixmap(pix);

    QPixmap logo("logo.png");
    QSize logoSize(200, 200);
    logo = logo.scaled(logoSize,Qt::KeepAspectRatio);

    ui->mLogoImage->setPixmap(logo);
    ui->mLogoImage->repaint();
    ui->mLogoImage->setPixmap(logo);
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
