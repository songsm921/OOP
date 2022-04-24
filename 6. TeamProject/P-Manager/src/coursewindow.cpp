#include "ui_course.h"
#include<iostream>
#include "coursewindow.h"
#include <QDebug>
namespace Minho
{

CourseWindow:: CourseWindow(QWidget* parent) :
    QWidget(parent), ui(new Ui::course) {
    ui->setupUi(this);
    ui->tableWidget9->setFont(font1);
    ui->tableWidget10->setFont(font1);
    ui->tableWidget1->setColumnWidth(0, 300);
    ui->tableWidget1->setColumnWidth(1, 30);
    ui->tableWidget1->setColumnWidth(2, 30);
    ui->tableWidget1->setColumnWidth(3, 300);
    ui->tableWidget2->setColumnWidth(0, 300);
    ui->tableWidget2->setColumnWidth(1, 30);
    ui->tableWidget2->setColumnWidth(2, 30);
    ui->tableWidget2->setColumnWidth(3, 300);
    ui->tableWidget3->setColumnWidth(0, 300);
    ui->tableWidget3->setColumnWidth(1, 30);
    ui->tableWidget3->setColumnWidth(2, 30);
    ui->tableWidget3->setColumnWidth(3, 300);
    ui->tableWidget4->setColumnWidth(0, 300);
    ui->tableWidget4->setColumnWidth(1, 30);
    ui->tableWidget4->setColumnWidth(2, 30);
    ui->tableWidget4->setColumnWidth(3, 300);
    ui->tableWidget5->setColumnWidth(0, 300);
    ui->tableWidget5->setColumnWidth(1, 30);
    ui->tableWidget5->setColumnWidth(2, 30);
    ui->tableWidget5->setColumnWidth(3, 300);
    ui->tableWidget6->setColumnWidth(0, 300);
    ui->tableWidget6->setColumnWidth(1, 30);
    ui->tableWidget6->setColumnWidth(2, 30);
    ui->tableWidget6->setColumnWidth(3, 300);
    ui->tableWidget7->setColumnWidth(0, 300);
    ui->tableWidget7->setColumnWidth(1, 30);
    ui->tableWidget7->setColumnWidth(2, 30);
    ui->tableWidget7->setColumnWidth(3, 300);
    ui->tableWidget8->setColumnWidth(0, 300);
    ui->tableWidget8->setColumnWidth(1, 30);
    ui->tableWidget8->setColumnWidth(2, 30);
    ui->tableWidget8->setColumnWidth(3, 300);
    ui->tableWidget9->setColumnWidth(0, 300);
    ui->tableWidget9->setColumnWidth(1, 100);
    ui->tableWidget9->setColumnWidth(2, 100);


    mc.get_logged_in_member()->get_courses()->sort();
    mc.get_logged_in_member()->get_courses()->read_data(mc.get_logged_in_member()->get_id());

    font1.setFamily(QString::fromUtf8("1\355\233\210\354\240\220\353\263\264\353\247\230\353\263\264 B"));
    font1.setPointSize(10);
    font1.setBold(false);
    font1.setWeight(50);
    ui->tableWidget1->setFont(font1);
    ui->tableWidget2->setFont(font1);
    ui->tableWidget3->setFont(font1);
    ui->tableWidget4->setFont(font1);
    ui->tableWidget5->setFont(font1);
    ui->tableWidget6->setFont(font1);
    ui->tableWidget7->setFont(font1);
    ui->tableWidget8->setFont(font1);
    ui->tableWidget9->setFont(font1);
    ui->tableWidget10->setFont(font1);

    for(int row=0; row<10; row++)
        for(int col = 0 ; col< 4 ; col++)
        {
        QTableWidgetItem *item_;
        item_ = new QTableWidgetItem;
        QString qs = QString::fromStdString(mc.get_logged_in_member()->get_courses()->get_inf(0,row,col));
        item_->setText(qs);
        ui->tableWidget1->setItem(row, col, item_);
        }
    for(int row=0; row<10; row++)
        for(int col = 0 ; col< 4 ; col++)
        {
        QTableWidgetItem *item_;
        item_ = new QTableWidgetItem;
        QString qs = QString::fromStdString(mc.get_logged_in_member()->get_courses()->get_inf(1,row,col));
        item_->setText(qs);
        ui->tableWidget2->setItem(row, col, item_);
        }
    for(int row=0; row<10; row++)
        for(int col = 0 ; col< 4 ; col++)
        {
        QTableWidgetItem *item_;
        item_ = new QTableWidgetItem;
        QString qs = QString::fromStdString(mc.get_logged_in_member()->get_courses()->get_inf(2,row,col));
        item_->setText(qs);
        ui->tableWidget3->setItem(row, col, item_);
        }
    for(int row=0; row<10; row++)
        for(int col = 0 ; col< 4 ; col++)
        {
        QTableWidgetItem *item_;
        item_ = new QTableWidgetItem;
        QString qs = QString::fromStdString(mc.get_logged_in_member()->get_courses()->get_inf(3,row,col));
        item_->setText(qs);
        ui->tableWidget4->setItem(row, col, item_);
        }
    for(int row=0; row<10; row++)
        for(int col = 0 ; col< 4 ; col++)
        {
        QTableWidgetItem *item_;
        item_ = new QTableWidgetItem;
        QString qs = QString::fromStdString(mc.get_logged_in_member()->get_courses()->get_inf(4,row,col));
        item_->setText(qs);
        ui->tableWidget5->setItem(row, col, item_);
        }
    for(int row=0; row<10; row++)
        for(int col = 0 ; col< 4 ; col++)
        {
        QTableWidgetItem *item_;
        item_ = new QTableWidgetItem;
        QString qs = QString::fromStdString(mc.get_logged_in_member()->get_courses()->get_inf(5,row,col));
        item_->setText(qs);
        ui->tableWidget6->setItem(row, col, item_);
        }
    for(int row=0; row<10; row++)
        for(int col = 0 ; col< 4 ; col++)
        {
        QTableWidgetItem *item_;
        item_ = new QTableWidgetItem;
        QString qs = QString::fromStdString(mc.get_logged_in_member()->get_courses()->get_inf(6,row,col));
        item_->setText(qs);
        ui->tableWidget7->setItem(row, col, item_);
        }
    for(int row=0; row<10; row++)
        for(int col = 0 ; col< 4 ; col++)
        {
        QTableWidgetItem *item_;
        item_ = new QTableWidgetItem;
        QString qs = QString::fromStdString(mc.get_logged_in_member()->get_courses()->get_inf(7,row,col));
        item_->setText(qs);
        ui->tableWidget8->setItem(row, col, item_);
        }
    if(mc.get_logged_in_member()->get_courses()->get_dual_major() == 0){
        ui->tableWidget10->hide();
        ui->checkBox->setChecked(false);
    }
    else{
        ui->tableWidget10->show();
        ui->checkBox->setChecked(true);
    }

    // 학과 구현하면 학과 미리 써놓기

    const QString d;
    d.fromStdString(mc.get_logged_in_member()->get_dept());
    ui->lineEdit->setText(d);

    int *sum = mc.get_logged_in_member()->get_courses()->sum_category();
    int *arr = new int[7]; std::string _dept;
    mc.get_logged_in_member()->get_courses()->get_requirements(arr, _dept);

    ui->label_66->setText(QString::fromStdString(_dept));
    ui->tableWidget9->setFont(font1);
    for (int row = 0; row < 7; row++) // 계열
    {
        QTableWidgetItem* item_ = new QTableWidgetItem;
        QString item_text = QString::number(sum[row]);
        item_->setText(item_text);
        ui->tableWidget9->setItem(row, 1, item_); // 이수
        QTableWidgetItem* item_s = new QTableWidgetItem;
        QString item_stext = QString::number(arr[row]);
        item_s->setText(item_stext);
        ui->tableWidget9->setItem(row, 2, item_s);
        // 총
    }
    QTableWidgetItem* item_ = new QTableWidgetItem;
    QString item_text = QString::number(sum[7]);
    item_->setText(item_text);
    ui->tableWidget10->setItem(0,1, item_); // 0,1: 복전 테이블의 이수


    QTableWidgetItem* item_d = new QTableWidgetItem;
    std::string dd = mc.get_logged_in_member()->get_dual_dept();
    int dual_req = mc.get_logged_in_member()->get_courses()->get_dual_req(dd);
    QString item_dtext = QString::number(dual_req); //0,2: 복전 테이블의 총
    item_d->setText(item_dtext);
    ui->tableWidget10->setItem(0,2, item_d);

    ui->tableWidget10->setSpan(1,0,1,3);

    QString item_ddtext = QString::fromStdString(dd);
    QTableWidgetItem* item_dd = new QTableWidgetItem;
    item_dd->setText(item_ddtext);
    ui->tableWidget10->setItem(1,0, item_dd);

    QObject::connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked1()));


    delete[] arr;
}

void CourseWindow::on_pushButton_clicked1()
{
    mc.get_logged_in_member()->get_courses()->sort();
    int i = 0;
    // 표의 내용 읽고 데이터에 저장
    for(int sem = 0; sem < 8 ; sem++)
        for(int row=0; row<10; row++){
            for(int column = 0 ; column< 4 ; column++)
            {
                QTableWidgetItem *item_;
                QString item_text;
                switch (sem) {
                case 0:{
                    item_ = ui->tableWidget1->item(row,column);
                    item_text = item_->text();
                    break;
                }
                case 1:{
                    item_ = ui->tableWidget2->item(row,column);
                    item_text = item_->text();
                    break;
                }
                case 2:{
                    item_ = ui->tableWidget3->item(row,column);
                    item_text = item_->text();
                    break;
                }
                case 3:{
                    item_ = ui->tableWidget4->item(row,column);
                    item_text = item_->text();
                    break;
                }
                case 4:{
                    item_ = ui->tableWidget5->item(row,column);
                    item_text = item_->text();
                    break;
                }
                case 5:{
                    item_ = ui->tableWidget6->item(row,column);
                    item_text = item_->text();
                    break;
                }
                case 6:{
                    item_ = ui->tableWidget7->item(row,column);
                    item_text = item_->text();
                    break;
                }
                case 7:{
                    item_ = ui->tableWidget8->item(row,column);
                    item_text = item_->text();
                    break;
                }
                }
                if(item_text.isEmpty() == false)
                    i++;
                mc.get_logged_in_member()->get_courses()->set_inf(item_text.toStdString(),sem,row,column);
            }
            if(i == 4)
                mc.get_logged_in_member()->get_courses()->increment_size(sem);
            i = 0;
        }

    int* sum = mc.get_logged_in_member()->get_courses()->sum_category();
    ui->tableWidget9->setFont(font1);
    for (int row = 0; row < 7; row++) // 계열
    {
        QTableWidgetItem* item_ = new QTableWidgetItem;
        QString item_text = QString::number(sum[row]);
        item_->setText(item_text);
        ui->tableWidget9->setItem(row, 1, item_); // 이수
    }

    if(ui->checkBox->isChecked()) // 복수전공 체크되있으면
    {
    QTableWidgetItem* item_ = new QTableWidgetItem;
    QString item_text = QString::number(sum[7]);
    item_->setText(item_text);
    ui->tableWidget10->setItem(0,1, item_); // 0,1: 복전 테이블의 이수

    QTableWidgetItem *dditem_;
    QString dditem_text;
    dditem_ = ui->tableWidget10->item(1,0);
    dditem_text = dditem_->text();
    std::string dualdept_ =dditem_text.toStdString();
    mc.get_logged_in_member()->get_dual_dept()=dualdept_;

    QTableWidgetItem* item_d = new QTableWidgetItem;
    std::string dd = mc.get_logged_in_member()->get_dual_dept();
    int dual_req = mc.get_logged_in_member()->get_courses()->get_dual_req(dd);
    QString item_dtext = QString::number(dual_req); //0,2: 복전 테이블의 총
    item_d->setText(item_dtext);
    ui->tableWidget10->setItem(0,2, item_d);

    QString item_ddtext = QString::fromStdString(dd);
    QTableWidgetItem* item_dd = new QTableWidgetItem;
    item_dd->setText(item_ddtext);
    ui->tableWidget10->setItem(1,0, item_dd);
    }


    // 데이터를 로그에 쓰기
    mc.get_logged_in_member()->get_courses()->write_data(mc.get_logged_in_member()->get_id());
}

void CourseWindow::on_checkBox_stateChanged(int arg1)
{
    if(arg1 == 0){
        ui->tableWidget10->hide();
        mc.get_logged_in_member()->get_courses()->get_dual_major() = 0;
    }
    else{
        ui->tableWidget10->show();
        mc.get_logged_in_member()->get_courses()->get_dual_major() = 1;
    }
}





}
