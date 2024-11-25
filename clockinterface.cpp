#include "clockinterface.h"
#include "ui_clockinterface.h"
#include "interface.h"
#include <QPixmap>
#include <QTimer>
#include <QDateTime>

clockInterface::clockInterface(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::clockInterface)
{
    ui->setupUi(this);
    ui->label_2->setStyleSheet("font-size: 81px; color: green; font-weight: bold; font-family: Arial;");
    QPixmap pixmap(":/img/clock.png");
    ui->label->setPixmap(pixmap);
    ui->label->setScaledContents(true);
    QTimer *timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, &clockInterface::updateTime);

    timer->start(1000);

    updateTime();
}

clockInterface::~clockInterface()
{
    delete ui;
}

void clockInterface::on_pushButton_2_clicked()
{
    hide();
    mainwindow = new interface(this);
    mainwindow->show();
}

void clockInterface::updateTime()
{
    QString currentTime = QDateTime::currentDateTime().toString("HH:mm");

    ui->label_2->setText(currentTime);
}

