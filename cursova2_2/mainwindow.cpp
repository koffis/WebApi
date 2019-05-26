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
#include <QSet>
#include <QVector>
#include <algorithm>

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

    QPixmap logo("logo.jpg");
    QSize logoSize(200, 200);
    logo = logo.scaled(logoSize,Qt::KeepAspectRatio);

    ui->mLogoImage->setPixmap(logo);
    ui->mLogoImage->repaint();
    ui->mLogoImage->setPixmap(logo);

    addCountry();

    connect(ui->mChooseCountryComboBx, &QComboBox::currentTextChanged,this,&MainWindow::addAllCities);
    connect(ui->mChooseCityComboBox, &QComboBox::currentTextChanged,this,&MainWindow::cityChanged);

    netwMan = new QNetworkAccessManager(this);
        connect(netwMan,SIGNAL(finished(QNetworkReply*)),this,SLOT(slot_netwMan(QNetworkReply*)));

       request.setUrl(QUrl("http://api.openweathermap.org/data/2.5/weather?id=2172797&APPID=4b18a4c9cfae7c4328275a70a1a25d49"));

        connect(ui->mChooseCityComboBox, &QComboBox::currentTextChanged,this,&MainWindow::sendReq);
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

    QVector<QString> temp;

    for(auto element : lCountry)
       temp.push_back(element);

    std::sort(temp.begin(),temp.end());

    for(auto element : temp)
        ui->mChooseCountryComboBx->addItem(element);
}

void MainWindow::sendReq()
{
    qDebug()<<"OK";
    netwMan->get(request);
}

void MainWindow::slot_netwMan(QNetworkReply *rep)
{
    rep->waitForReadyRead(1000);

    doc = QJsonDocument::fromJson(rep->readAll(), &docEr);
    if (docEr.errorString()=="no error occurred")
    {
    temp = doc.object().value("main").toObject();

    qDebug() << "Temp: " << temp.value("temp"). toDouble()-273;
    qDebug()<<"Data: " <<QDateTime::currentDateTime().date();
    qDebug()<<"Time: "<<QDateTime::currentDateTime().time().toString();
    }

    rep->deleteLater();
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

    QVector<QString> lCity;
    QJsonValue value = object.value("cities");
    QJsonArray array = value.toArray();
    foreach (const QJsonValue & v, array)
    {
        if(mCountry == v.toObject().value("country").toString())
        {
            lCity.push_back(v.toObject().value("name").toString());
        }
    }
        std::sort(lCity.begin(),lCity.end());

    for(auto element : lCity)
        ui->mChooseCityComboBox->addItem(element);
}

void MainWindow::cityChanged(const QString &text)
{
    qDebug()<<text;
    mCity = text;
    QFile file("city.list.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(jsonData);
    QJsonObject object = document.object();

    QJsonValue value = object.value("cities");
    QJsonArray array = value.toArray();
    foreach (const QJsonValue & v, array)
    {
        if(mCity == v.toObject().value("name").toString())
        {
            int temp = v.toObject().value("id").toInt();
            mCurrentCityID = QString::number(temp);
            break;
        }
    }

    qDebug()<<mCurrentCityID;


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
