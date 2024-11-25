#ifndef CLOCKINTERFACE_H
#define CLOCKINTERFACE_H

#include <QDialog>
#include "interface.h"

class interface;

QT_BEGIN_NAMESPACE
namespace Ui {
class clockInterface;
}
QT_END_NAMESPACE

class clockInterface : public QDialog
{
    Q_OBJECT

public:
    explicit clockInterface(QWidget *parent = nullptr);
    ~clockInterface();


private slots:
    void on_pushButton_2_clicked();
    void updateTime();

private:
    Ui::clockInterface *ui;
    interface *mainwindow;
};

#endif // CLOCKINTERFACE_H
