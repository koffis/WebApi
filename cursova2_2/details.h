#ifndef DETAILS_H
#define DETAILS_H

#include <QDialog>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QtNetwork>
namespace Ui {
class Details;
}

class Details : public QDialog
{
    Q_OBJECT

public:
    explicit Details(QString index,QString cityName,QString countyName,QWidget *parent = nullptr);
    ~Details();

private:
    Ui::Details *ui;

    QString mID;
    QJsonDocument doc;
    QJsonObject temp;
    QJsonParseError docEr;

    QNetworkAccessManager* netwMan;
    QNetworkRequest request;
private slots :
    void sendReq();
    void slot_netwMan(QNetworkReply*);

};

#endif // DETAILS_H
