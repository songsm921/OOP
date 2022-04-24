#include "login.h"
#include "ui_login.h"
#include <QDebug>

namespace Minho {

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    QPixmap ready(":/image/image/ponix.jpg");
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(ready);
    scene->addItem(item);

    QPixmap ready2(":/image/image/main.jpg");
    scene2 = new QGraphicsScene(this);
    ui->graphicsView_2->setScene(scene2);
    QGraphicsPixmapItem* item2 = new QGraphicsPixmapItem(ready2);
    scene2->addItem(item2);

    mc.read_log();

    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    ui->label_6->hide();
    ui->label_10->hide();
    ui->label_11->hide();
}

Login::~Login()
{
    mc.write_log();
    delete ui;
}

void Login::on_pushButton_clicked() // login
{
    QString _id, pwd;
    bool success;
    _id = ui->textEdit->toPlainText();
    id=_id.toStdString();
    pwd = ui->textEdit_2->toPlainText();
    success = mc.Login(_id.toStdString(), pwd.toStdString());
    if(success == true){
        ui->label_3->show();
        ui->label_5->hide();
        ui->label_10->hide();
        ui->label_4->hide();
        ui->label_6->hide();
        ui->label_11->hide();
    }
    else {
        ui->label_5->show();
        ui->label_3->hide();
        ui->label_10->hide();
        ui->label_4->hide();
        ui->label_6->hide();
        ui->label_11->hide();
    }
}

void Login::on_pushButton_2_clicked()  // register
{
    QString id, pwd, dept;
    bool success;
    id = ui->textEdit_3->toPlainText();
    pwd = ui->textEdit_4->toPlainText();
    dept = ui->textEdit_5->toPlainText();
    success = mc.Register(id.toStdString(), pwd.toStdString(), dept.toStdString());
    if(success == true){
        ui->label_4->show();
        ui->label_6->hide();
        ui->label_10->hide();
        ui->label_11->hide();
    }
    else{
        ui->label_6->show();
        ui->label_4->hide();
        ui->label_10->hide();
        ui->label_11->hide();
    }
}

void Login::on_toolBox_currentChanged(int index) // register/login window change
{
    if(index == 0){
        ui->label_3->hide();
        ui->label_5->hide();
        ui->label_10->hide();
        ui->label_4->hide();
        ui->label_6->hide();
        ui->label_11->hide();
    }
    else{
        ui->label_3->hide();
        ui->label_5->hide();
        ui->label_10->hide();
        ui->label_4->hide();
        ui->label_6->hide();
        ui->label_11->hide();
    }
}


}

void Minho::Login::on_pushButton_3_clicked() // logout
{
    mc.Logout();
    ui->label_3->hide();
    ui->label_5->hide();
    ui->label_10->show();
    ui->label_4->hide();
    ui->label_6->hide();
    ui->label_11->hide();
}

void Minho::Login::on_pushButton_4_clicked()
{
    if(mc.is_logged_in()){
        emit send_id(id);
        this->hide();
    //로그인 중이면 access창 띄우기
    }
    else{
        ui->label_11->show();
    }
}
