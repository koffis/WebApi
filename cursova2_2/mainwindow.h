#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
private slots:

    void addAllCities(const QString &text);
    void showDaysInfo();
    void showDetailsInfo();

private:
    Ui::MainWindow *ui;
    QString mCountry;
    QString mCity;
};

#endif // MAINWINDOW_H
