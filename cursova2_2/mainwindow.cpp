#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "daysinfo.h"
#include "details.h"
#include <QAction>
#include <QFile>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

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

    addCountry();

    connect(ui->mChooseCountryComboBx, &QComboBox::currentTextChanged,this,&MainWindow::addAllCities);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addCountry()
{
    QFile file("city.list.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(jsonData);
    QJsonObject object = document.object();

    QSet<QString> lCountry;
    QJsonValue value = object.value("cities");
    QJsonArray array = value.toArray();
    foreach (const QJsonValue & v, array)
         lCountry.insert(v.toObject().value("country").toString());

    for(auto element : lCountry)
        ui->mChooseCountryComboBx->addItem(element);
}

void MainWindow::addAllCities(const QString &text)
{
    qDebug()<<text;
    mCountry = text;
    QFile file("city.list.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(jsonData);
    QJsonObject object = document.object();

    QSet<QString> lCity;
    QJsonValue value = object.value("cities");
    QJsonArray array = value.toArray();
    foreach (const QJsonValue & v, array)
    {
        if(mCountry == v.toObject().value("country").toString())
        {
            lCity.insert(v.toObject().value("name").toString());
        }
    }

    for(auto element : lCity)
        ui->mChooseCityComboBox->addItem(element);
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
