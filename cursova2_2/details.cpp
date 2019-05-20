#include "details.h"
#include "ui_details.h"

Details::Details(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Details)
{
    ui->setupUi(this);

    QPixmap pix("001-snow.png");
    QSize PicSize(50, 50);
    pix = pix.scaled(PicSize,Qt::KeepAspectRatio);
    ui->mDetails1ImageLable->setPixmap(pix);
    ui->mDetails1ImageLable->repaint();
    ui->mDetails1ImageLable->setPixmap(pix);

    QPixmap pix2("016-sunrise.png");
    QSize PicSize2(50, 50);
    pix2 = pix2.scaled(PicSize2,Qt::KeepAspectRatio);
    ui->mDetails2ImageLable->setPixmap(pix2);
    ui->mDetails2ImageLable->repaint();
    ui->mDetails2ImageLable->setPixmap(pix2);

    QPixmap pix3("013-raining.png");
    QSize PicSize3(50, 50);
    pix3 = pix3.scaled(PicSize3,Qt::KeepAspectRatio);
    ui->mDetails3ImageLable->setPixmap(pix3);
    ui->mDetails3ImageLable->repaint();
    ui->mDetails3ImageLable->setPixmap(pix3);

    QPixmap pix4("009-lighting.png");
    QSize PicSize4(50, 50);
    pix4 = pix4.scaled(PicSize4,Qt::KeepAspectRatio);
    ui->mDetails4ImageLable->setPixmap(pix4);
    ui->mDetails4ImageLable->repaint();
    ui->mDetails4ImageLable->setPixmap(pix4);

    QPixmap pix5("039-wind.png");
    QSize PicSize5(50, 50);
    pix5 = pix5.scaled(PicSize5,Qt::KeepAspectRatio);
    ui->mDetails5ImageLable->setPixmap(pix5);
    ui->mDetails5ImageLable->repaint();
    ui->mDetails5ImageLable->setPixmap(pix5);

    QPixmap pix6("039-wind.png");
    QSize PicSize6(50, 50);
    pix6 = pix6.scaled(PicSize6,Qt::KeepAspectRatio);
    ui->mDetails6ImageLable->setPixmap(pix6);
    ui->mDetails6ImageLable->repaint();
    ui->mDetails6ImageLable->setPixmap(pix6);
}

Details::~Details()
{
    delete ui;
}
