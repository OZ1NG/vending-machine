#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setControl();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int coin){
    money += coin;
    ui->lcdNumber->display(money);
    setControl();
}

void Widget::setControl(){

    ui->pbCoffee->setEnabled(money >= 200);
    ui->pbTea->setEnabled(money >= 150);
    ui->pbMilk->setEnabled(money >= 100);
}

int Widget::remainCoin(int coin_type)
{
    int result = 0;

    for(money; money >= coin_type; money = money-coin_type){
        result++;
    }

    return result;
}

void Widget::on_pbReset_clicked()
{
    int total = money;
    int coin500_count = remainCoin(500);
    int coin100_count = remainCoin(100);
    int coin50_count = remainCoin(50);
    int coin10_count = remainCoin(10);
    int coin_total_count = coin500_count+coin100_count+coin50_count+coin10_count;

    QString msg_Money = QString("Money : ") + QString::number(total) + QString("\n");
    QString msg500    = QString("500   : ") + QString::number(coin500_count) + QString("\n");
    QString msg100    = QString("100   : ") + QString::number(coin100_count) + QString("\n");
    QString msg50     = QString("50    : ") + QString::number(coin50_count) + QString("\n");
    QString msg10     = QString("10    : ") + QString::number(coin10_count) + QString("\n");
    QString msg_total = QString("Total : ") + QString::number(coin_total_count) + QString("\n");

    QMessageBox::information(this, "Return Changes", msg_Money+msg500+msg100+msg50+msg10+msg_total);
    ui->lcdNumber->display(money);
    setControl();
}

void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}


void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}


void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-100);
}



