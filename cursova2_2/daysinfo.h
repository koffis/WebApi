#ifndef DAYSINFO_H
#define DAYSINFO_H

#include <QDialog>

namespace Ui {
class DaysInfo;
}

class DaysInfo : public QDialog
{
    Q_OBJECT

public:
    explicit DaysInfo(QWidget *parent = nullptr);
    ~DaysInfo();

private:
    Ui::DaysInfo *ui;
};

#endif // DAYSINFO_H
