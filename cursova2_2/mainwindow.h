#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QTimer>
#include <QDebug>
namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    void addCountry();
private slots :

    void sendReq();
    void slot_netwMan(QNetworkReply*);
    void addAllCities(const QString &text);
    void cityChanged(const QString &text);
    void showDaysInfo();
    void showDetailsInfo();

private:
    Ui::MainWindow *ui;
    QString mCountry;
    QString mCity;
    QString mCurrentCityID;
    QJsonDocument doc;
    QJsonObject temp;
    QJsonParseError docEr;

    QNetworkAccessManager* netwMan;
    QNetworkRequest request;

};

#endif // MAINWINDOW_H
