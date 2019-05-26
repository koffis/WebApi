#include "details.h"
#include "ui_details.h"

Details::Details(QString index,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Details)
{
    ui->setupUi(this);
    mID = index;

    QPixmap logo("logo.png");
    QSize logoSize(100, 100);
    logo = logo.scaled(logoSize,Qt::KeepAspectRatio);

    ui->mLogoDetails->setPixmap(logo);
    ui->mLogoDetails->repaint();
    ui->mLogoDetails->setPixmap(logo);

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
    netwMan = new QNetworkAccessManager(this);
    connect(netwMan,SIGNAL(finished(QNetworkReply*)),this,SLOT(slot_netwMan(QNetworkReply*)));

    QString url = "http://api.openweathermap.org/data/2.5/forecast?id=" + mID+"&APPID=4b18a4c9cfae7c4328275a70a1a25d49";
    request.setUrl(url);
    sendReq();
}

Details::~Details()
{
    delete netwMan;
    delete ui;
}

void Details::sendReq()
{
    qDebug()<<"OK";
    netwMan->get(request);
}

void Details::slot_netwMan(QNetworkReply *rep)
{
 rep->waitForReadyRead(1000);

 doc = QJsonDocument::fromJson(rep->readAll(), &docEr);
 if (docEr.errorString()=="no error occurred")
 {
   // temp = doc.object().value("dt_txt").toObject();
 }
 QJsonValue value = doc.object().value("list");
 QJsonArray array = value.toArray();
 QVector<QVector<QString>> data;
 int cnt = 0;
 foreach (const QJsonValue & v, array)
 {
     if(cnt == 6)
         break;
     cnt++;
     QJsonObject obj = v.toObject();
     temp = obj.value("main").toObject();

     double temper =  temp.value("temp").toDouble()-273;
     double pres = temp.value("pressure").toDouble();
     double hum = temp.value("humidity").toDouble();


     QJsonObject obj2 = v.toObject();
     temp = obj.value("wind").toObject();

     double wind = temp.value("speed"). toDouble();

     QString date = v.toObject().value("dt_txt").toString();
     QVector<QString> tempDate;
     tempDate.push_back(QString::number(temper) + " °C");
     tempDate.push_back(QString::number(pres) + " hPa");
     tempDate.push_back(QString::number(hum) + " %");
     tempDate.push_back(QString::number(wind) + " m/s");
     tempDate.push_back(date);

     data.push_back(tempDate);

 }

// for(auto a : data)
// {
//     for(auto b : a)
//     {
//         qDebug()<<b;
//     }
// }

 ui->mDetailsTemp1Lable->setText(data[0][0]);
 ui->mPreassure1InfoLable->setText(data[0][1]);
 ui->mHumidity1InfoLable->setText(data[0][2]);
 ui->mWind1InfoLable->setText(data[0][3]);
 ui->mDetailsTime1Lable->setText(data[0][4]);

 ui->mDetailsTemp2Lable->setText(data[1][0]);
 ui->mPreassure2InfoLable->setText(data[1][1]);
 ui->mHumidity2InfoLable->setText(data[1][2]);
 ui->mWind2InfoLable->setText(data[1][3]);
 ui->mDetailsTime2Lable->setText(data[1][4]);

 ui->mDetailsTemp3Lable->setText(data[2][0]);
 ui->mPreassure3InfoLable->setText(data[2][1]);
 ui->mHumidity3InfoLable->setText(data[2][2]);
 ui->mWind3InfoLable->setText(data[2][3]);
 ui->mDetailsTime3Lable->setText(data[2][4]);

 ui->mDetailsTemp4Lable->setText(data[3][0]);
 ui->mPreassure4InfoLable->setText(data[3][1]);
 ui->mHumidity4InfoLable->setText(data[3][2]);
 ui->mWind4InfoLable->setText(data[3][3]);
 ui->mDetailsTime4Lable->setText(data[3][4]);

 ui->mDetailsTemp5Lable->setText(data[4][0]);
 ui->mPreassure5InfoLable->setText(data[4][1]);
 ui->mHumidity5InfoLable->setText(data[4][2]);
 ui->mWind5InfoLable->setText(data[4][3]);
 ui->mDetailsTime5Lable->setText(data[4][4]);

 ui->mDetailsTemp6Lable->setText(data[5][0]);
 ui->mPreassure6InfoLable->setText(data[5][1]);
 ui->mHumidity6InfoLable->setText(data[5][2]);
 ui->mWind6InfoLable->setText(data[5][3]);
 ui->mDetailsTime6Lable->setText(data[5][4]);


 rep->deleteLater();


}





