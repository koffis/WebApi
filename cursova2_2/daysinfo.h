#ifndef DAYSINFO_H
#define DAYSINFO_H

#include <QDialog>
#include <QString>

namespace Ui {
class DaysInfo;
}

class DaysInfo : public QDialog
{
    Q_OBJECT

public:

    explicit DaysInfo(const QString &index,QWidget *parent = nullptr);
    ~DaysInfo();

private:
    Ui::DaysInfo *ui;
    QString mIndex;
};

#endif // DAYSINFO_H
