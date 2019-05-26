#include "daysinfo.h"
#include "ui_daysinfo.h"

DaysInfo::DaysInfo(const QString &index,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DaysInfo)
{

    ui->setupUi(this);

    QPixmap logo("logo.png");
    QSize logoSize(100, 100);
    logo = logo.scaled(logoSize,Qt::KeepAspectRatio);

    ui->mLogoDaysInfo->setPixmap(logo);
    ui->mLogoDaysInfo->repaint();
    ui->mLogoDaysInfo->setPixmap(logo);

    QPixmap pix("001-snow.png");
    QSize PicSize(50, 50);
    pix = pix.scaled(PicSize,Qt::KeepAspectRatio);
    ui->mDay1ImageLable->setPixmap(pix);
    ui->mDay1ImageLable->repaint();
    ui->mDay1ImageLable->setPixmap(pix);

    QPixmap pix2("016-sunrise.png");
    QSize PicSize2(50, 50);
    pix2 = pix2.scaled(PicSize2,Qt::KeepAspectRatio);
    ui->mDay2ImageLable->setPixmap(pix2);
    ui->mDay2ImageLable->repaint();
    ui->mDay2ImageLable->setPixmap(pix2);

    QPixmap pix3("013-raining.png");
    QSize PicSize3(50, 50);
    pix3 = pix3.scaled(PicSize3,Qt::KeepAspectRatio);
    ui->mDay3ImageLable->setPixmap(pix3);
    ui->mDay3ImageLable->repaint();
    ui->mDay3ImageLable->setPixmap(pix3);

    QPixmap pix4("009-lighting.png");
    QSize PicSize4(50, 50);
    pix4 = pix4.scaled(PicSize4,Qt::KeepAspectRatio);
    ui->mDay4ImageLable->setPixmap(pix4);
    ui->mDay4ImageLable->repaint();
    ui->mDay4ImageLable->setPixmap(pix4);

    QPixmap pix5("039-wind.png");
    QSize PicSize5(50, 50);
    pix5 = pix5.scaled(PicSize5,Qt::KeepAspectRatio);
    ui->mDay5ImageLable->setPixmap(pix5);
    ui->mDay5ImageLable->repaint();
    ui->mDay5ImageLable->setPixmap(pix5);




}

DaysInfo::~DaysInfo()
{
    delete ui;
}
