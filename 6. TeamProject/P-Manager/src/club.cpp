#include "club.h"
#include <QDebug>
#include "ui_club.h"
#include <string>
#include <fstream>
#include <sstream>
namespace Sumin {
CLUB::CLUB(std::string _name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::club)
{
    name = _name;
    ui->setupUi(this);
    ui->tableWidget->setColumnWidth(0,485);
    ui->tableWidget->setColumnWidth(1,485);
    ui->tableWidget_2->setColumnWidth(0,485);
    ui->tableWidget_2->setColumnWidth(1,485);
    ui->table2_1->setColumnWidth(0,485);
    ui->table2_1->setColumnWidth(1,485);
    ui->table2_2->setColumnWidth(0,485);
    ui->table2_2->setColumnWidth(1,485);
    ui->table3_1->setColumnWidth(0,485);
    ui->table3_1->setColumnWidth(1,485);
    ui->table3_2->setColumnWidth(0,485);
    ui->table3_2->setColumnWidth(1,485);
    ui->table4_1->setColumnWidth(0,485);
    ui->table4_1->setColumnWidth(1,485);
    ui->table4_2->setColumnWidth(0,485);
    ui->table4_2->setColumnWidth(1,485);

    font1.setFamily(QString::fromUtf8("1\355\233\210\354\240\220\353\263\264\353\247\230\353\263\264 B"));
    font1.setPointSize(10);
    font1.setBold(false);
    font1.setWeight(50);
    ui->tableWidget->setFont(font1);
    ui->tableWidget_2->setFont(font1);
    ui->table2_1->setFont(font1);
    ui->table2_2->setFont(font1);
    ui->table3_1->setFont(font1);
    ui->table3_2->setFont(font1);
    ui->table4_1->setFont(font1);
    ui->table4_2->setFont(font1);

    for(int i=0; i<8; i++) {
        ptr[i] = new Sumin::Club;
        ptr_2[i]= new Sumin::Club;
        ptr_3[i] = new Sumin::Club;
        ptr_4[i] = new Sumin::Club;
    }
    sem1=0;
    sem2=0;
    sem2_1=0;
    sem2_2=0;
    sem3_1=0;
    sem3_2=0;
    sem4_1=0;
    sem4_2=0;
    index1 = 0;
    index2 = 0;
    index3 = 0;
    index2_1=0;
    index2_2=0;
    index2_3=0;
    index3_1=0;
    index3_2=0;
    index3_3=0;
    index4_1=0;
    index4_2=0;
    index4_3=0;
    QObject::connect(ui->checkBox,SIGNAL(stateChanged(int)),this,SLOT(Tab_1_checkbox(int)));
    QObject::connect(ui->checkBox_2,SIGNAL(stateChanged(int)),this,SLOT(Tab_1_checkbox_2(int)));
    QObject::connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(Tab_1_Apply()));
    QObject::connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(Tab_1_Save()));
    QObject::connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(Tab_1_Save()));
    QObject::connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(Tab_1_Save()));
    QObject::connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(Tab_1_Save()));
    /*******************************************/
    QObject::connect(ui->check2_1,SIGNAL(stateChanged(int)),this,SLOT(Tab_2_checkbox(int)));
    QObject::connect(ui->check2_2,SIGNAL(stateChanged(int)),this,SLOT(Tab_2_checkbox_2(int)));
    QObject::connect(ui->apply2,SIGNAL(clicked()),this,SLOT(Tab_2_Apply()));
    /*******************************************/
    QObject::connect(ui->check3_1,SIGNAL(stateChanged(int)),this,SLOT(Tab_3_checkbox(int)));
    QObject::connect(ui->check3_2,SIGNAL(stateChanged(int)),this,SLOT(Tab_3_checkbox_2(int)));
    QObject::connect(ui->apply3,SIGNAL(clicked()),this,SLOT(Tab_3_Apply()));
    /*******************************************/
    QObject::connect(ui->check4_1,SIGNAL(stateChanged(int)),this,SLOT(Tab_4_checkbox(int)));
    QObject::connect(ui->check4_2,SIGNAL(stateChanged(int)),this,SLOT(Tab_4_checkbox_2(int)));
    QObject::connect(ui->apply4,SIGNAL(clicked()),this,SLOT(Tab_4_Apply()));
    load();
    /*******************************************/
}

CLUB::~CLUB()
{
    delete ui;
}
void CLUB::Tab_1_checkbox(int arg)
{
    if(sem1==0)
        sem1=1;
    else if(sem1==1)
        sem1=0;
    qDebug()<<"is"<<sem1;
}
void CLUB::Tab_2_checkbox(int arg)
{
    if(sem2_1==0)
        sem2_1=1;
    else if(sem2_1==1)
        sem2_1=0;
    qDebug()<<"is"<<sem2_1;
}
void CLUB::Tab_3_checkbox(int arg)
{
    if(sem3_1==0)
        sem3_1=1;
    else if(sem3_1==1)
        sem3_1=0;
    qDebug()<<"is"<<sem3_1;
}
void CLUB::Tab_4_checkbox(int arg)
{
    if(sem4_1==0)
        sem4_1=1;
    else if(sem4_1==1)
        sem4_1=0;
    qDebug()<<"is"<<sem4_1;
}

void CLUB::Tab_1_checkbox_2(int arg1)
{
    if(sem2==0)
        sem2=1;
    else if(sem2==1)
        sem2=0;
}
void CLUB::Tab_2_checkbox_2(int arg1)
{
    if(sem2_2==0)
        sem2_2=1;
    else if(sem2_2==1)
        sem2_2=0;
}
void CLUB::Tab_3_checkbox_2(int arg1)
{
    if(sem3_2==0)
        sem3_2=1;
    else if(sem3_2==1)
        sem3_2=0;
}
void CLUB::Tab_4_checkbox_2(int arg1)
{
    if(sem4_2==0)
        sem4_2=1;
    else if(sem4_2==1)
        sem4_2=0;
}

void CLUB::Tab_1_Apply()
{
    qDebug()<<"here";
    if(index2>=4&&sem1==1)
       {
        qDebug()<<"OVERFLOW";
        return;
    }

    else if(index3>=4&&sem2==1)
    {
     qDebug()<<"OVERFLOW";
     return;
 }
    ptr[index1]->setInfo(1,sem1,sem2,ui->lineEdit->text(),ui->lineEdit_2->text());
    QTableWidgetItem *item1 = new QTableWidgetItem(ui->lineEdit->text(),1);
    QTableWidgetItem *item2 = new QTableWidgetItem(ui->lineEdit_2->text(),1);
    if(sem1==1&&sem2==0)
    {
    ui->tableWidget->setItem(index2,0,item1);
    ui->tableWidget->setItem(index2,1,item2);
    index2++;
    index1++;
    }
    else if(sem1==0&&sem2==1)
    {
        ui->tableWidget_2->setItem(index3,0,item1);
        ui->tableWidget_2->setItem(index3,1,item2);
        index3++;
        index1++;
    }
    else if(sem1==1&&sem2==1)
    {
        QTableWidgetItem *item3 = new QTableWidgetItem(ui->lineEdit->text(),1);
        QTableWidgetItem *item4 = new QTableWidgetItem(ui->lineEdit_2->text(),1);
        ui->tableWidget->setItem(index2,0,item1);
        ui->tableWidget->setItem(index2,1,item2);
        ui->tableWidget_2->setItem(index3,0,item3);
        ui->tableWidget_2->setItem(index3,1,item4);
        index2++;
        index3++;
        index1++;
    }
    return;
}
void CLUB::Tab_2_Apply()
{
    qDebug()<<"here";
    if(index2_2>=4&&sem2_1==1)
       {
        qDebug()<<"OVERFLOW";
        return;
    }

    else if(index2_3>=4&&sem2_2==1)
    {
     qDebug()<<"OVERFLOW";
     return;
 }
    ptr_2[index2_1]->setInfo(2,sem2_1,sem2_2,ui->name2->text(),ui->role2->text());
    QTableWidgetItem *item1 = new QTableWidgetItem(ui->name2->text(),1);
    QTableWidgetItem *item2 = new QTableWidgetItem(ui->role2->text(),1);
    if(sem2_1==1&&sem2_2==0)
    {
    ui->table2_1->setItem(index2_2,0,item1);
    ui->table2_1->setItem(index2_2,1,item2);
    index2_2++;
    index2_1++;
    }
    else if(sem2_1==0&&sem2_2==1)
    {
        ui->table2_2->setItem(index2_3,0,item1);
        ui->table2_2->setItem(index2_3,1,item2);
        index2_3++;
        index2_1++;
    }
    else if(sem2_1==1&&sem2_2==1)
    {
        QTableWidgetItem *item3 = new QTableWidgetItem(ui->name2->text(),1);
        QTableWidgetItem *item4 = new QTableWidgetItem(ui->role2->text(),1);
        ui->table2_1->setItem(index2_2,0,item1);
        ui->table2_1->setItem(index2_2,1,item2);
        ui->table2_2->setItem(index2_3,0,item3);
        ui->table2_2->setItem(index2_3,1,item4);
        index2_2++;
        index2_3++;
        index2_1++;
    }
    return;
}
void CLUB::Tab_3_Apply()
{
    qDebug()<<"here";
    if(index3_2>=4&&sem3_1==1)
       {
        qDebug()<<"OVERFLOW";
        return;
    }

    else if(index3_3>=4&&sem3_2==1)
    {
     qDebug()<<"OVERFLOW";
     return;
 }
    ptr_3[index3_1]->setInfo(3,sem3_1,sem3_2,ui->name3->text(),ui->role3->text());
    QTableWidgetItem *item1 = new QTableWidgetItem(ui->name3->text(),1);
    QTableWidgetItem *item2 = new QTableWidgetItem(ui->role3->text(),1);
    if(sem3_1==1&&sem3_2==0)
    {
    ui->table3_1->setItem(index3_2,0,item1);
    ui->table3_1->setItem(index3_2,1,item2);
    index3_2++;
    index3_1++;
    }
    else if(sem3_1==0&&sem3_2==1)
    {
        ui->table3_2->setItem(index3_3,0,item1);
        ui->table3_2->setItem(index3_3,1,item2);
        index3_3++;
        index3_1++;
    }
    else if(sem3_1==1&&sem3_2==1)
    {
        QTableWidgetItem *item3 = new QTableWidgetItem(ui->name3->text(),1);
        QTableWidgetItem *item4 = new QTableWidgetItem(ui->role3->text(),1);
        ui->table3_1->setItem(index3_2,0,item1);
        ui->table3_1->setItem(index3_2,1,item2);
        ui->table3_2->setItem(index3_3,0,item3);
        ui->table3_2->setItem(index3_3,1,item4);
        index3_2++;
        index3_3++;
        index3_1++;
    }
    return;
}
void CLUB::Tab_4_Apply()
{
    qDebug()<<"here";
    if(index4_2>=4&&sem4_1==1)
       {
        qDebug()<<"OVERFLOW";
        return;
    }

    else if(index4_3>=4&&sem4_2==1)
    {
     qDebug()<<"OVERFLOW";
     return;
 }
    ptr_4[index4_1]->setInfo(4,sem4_1,sem4_2,ui->name4->text(),ui->role4->text());
    QTableWidgetItem *item1 = new QTableWidgetItem(ui->name4->text(),1);
    QTableWidgetItem *item2 = new QTableWidgetItem(ui->role4->text(),1);
    if(sem4_1==1&&sem4_2==0)
    {
    ui->table4_1->setItem(index4_2,0,item1);
    ui->table4_1->setItem(index4_2,1,item2);
    index4_2++;
    index4_1++;
    }
    else if(sem4_1==0&&sem4_2==1)
    {
        ui->table4_2->setItem(index4_3,0,item1);
        ui->table4_2->setItem(index4_3,1,item2);
        index4_3++;
        index4_1++;
    }
    else if(sem4_1==1&&sem4_2==1)
    {
        QTableWidgetItem *item3 = new QTableWidgetItem(ui->name4->text(),1);
        QTableWidgetItem *item4 = new QTableWidgetItem(ui->role4->text(),1);
        ui->table4_1->setItem(index4_2,0,item1);
        ui->table4_1->setItem(index4_2,1,item2);
        ui->table4_2->setItem(index4_3,0,item3);
        ui->table4_2->setItem(index4_3,1,item4);
        index4_2++;
        index4_3++;
        index4_1++;
    }
    return;
}


void CLUB::Tab_1_Save()
{
    std::string file_path = "commandLog_Club";
    file_path.append("_"+name+".txt");
    std::ofstream inLogWrite;
    inLogWrite.open(file_path,std::ios::out);
    if(index1==0)
        ;
    else
        for(int i=0;i<index1;i++)
        {
            inLogWrite<<"1"<<" "<<ptr[i]->semester1()<<" "<<ptr[i]->semester2()<<std::endl<<ptr[i]->GetName().toStdString()<<std::endl<<ptr[i]->GetRole().toStdString()<<std::endl;
        }
    if(index2_1==0)
        ;
    else
        for(int i=0;i<index2_1;i++)
        {
            inLogWrite<<"2"<<" "<<ptr_2[i]->semester1()<<" "<<ptr_2[i]->semester2()<<std::endl<<ptr_2[i]->GetName().toStdString()<<std::endl<<ptr_2[i]->GetRole().toStdString()<<std::endl;
        }
    if(index3_1==0)
        ;
    else
        for(int i=0;i<index3_1;i++)
        {
            inLogWrite<<"3"<<" "<<ptr_3[i]->semester1()<<" "<<ptr_3[i]->semester2()<<std::endl<<ptr_3[i]->GetName().toStdString()<<std::endl<<ptr_3[i]->GetRole().toStdString()<<std::endl;
        }
    if(index4_1==0)
        ;
    else
        for(int i=0;i<index4_1;i++)
        {
            inLogWrite<<"4"<<" "<<ptr_4[i]->semester1()<<" "<<ptr_4[i]->semester2()<<std::endl<<ptr_4[i]->GetName().toStdString()<<std::endl<<ptr_4[i]->GetRole().toStdString()<<std::endl;
        }
    inLogWrite.close();
}
void CLUB::load()
{
    std::string tokens[5],line;
    std::stringstream stream;
    int nTokens;
    int check =1;
    int count =0;
    int val1,val2,val3;
    std::string val4,val5;
    std::string file_path = "commandLog_Club";
    file_path.append("_"+name+".txt");
    std::ifstream inLogRead;
    inLogRead.open(file_path,std::ios::in);
    while(check)
    {
        getline(inLogRead,line);
        if(line=="")
        {
            if(inLogRead.eof())
                for(int i = 0; i<index1;i++)
                    qDebug()<<ptr[i]->semester1()<<ptr[i]->semester2();
                check=0;
        }
        else {
            stream.str(line);
            nTokens = 0;
            while(stream>>tokens[nTokens])
                nTokens++;
            stream.clear();
            /*********************/
            if(count==0)
            {
               val1 = atoi(tokens[0].c_str());
               val2 = atoi(tokens[1].c_str());
               val3 = atoi(tokens[2].c_str());
               count++;
               continue;
            }
            else if(count==1)
            {
                for(int i = 0; i<nTokens;i++)
                {
                    val4+=" ";
                    val4+=tokens[i].c_str();
                }
                count++;
                continue;
            }
            else if(count == 2)
            {
                for(int i = 0; i<nTokens;i++)
                {
                    val5+=" ";
                    val5+=tokens[i].c_str();
                }
                count++;
            }
            if(count==3)
            {
            if(val1==1)
            {
            ptr[index1]->setInfo(val1,val2,val3,QString::fromStdString(val4),QString::fromStdString(val5));
            QTableWidgetItem *item1 = new QTableWidgetItem(QString::fromStdString(val4),1);
            QTableWidgetItem *item2 = new QTableWidgetItem(QString::fromStdString(val5),1);
            if(val2==1&&val3==0)
            {
            ui->tableWidget->setItem(index2,0,item1);
            ui->tableWidget->setItem(index2,1,item2);
            index2++;
            index1++;
            }
            else if(val2==0&&val3==1)
            {
                ui->tableWidget_2->setItem(index3,0,item1);
                ui->tableWidget_2->setItem(index3,1,item2);
                index3++;
                index1++;
            }
            else if(val2==1&&val3==1)
            {
                QTableWidgetItem *item3 = new QTableWidgetItem(QString::fromStdString(val4),1);
                QTableWidgetItem *item4 = new QTableWidgetItem(QString::fromStdString(val5),1);
                ui->tableWidget->setItem(index2,0,item1);
                ui->tableWidget->setItem(index2,1,item2);
                ui->tableWidget_2->setItem(index3,0,item3);
                ui->tableWidget_2->setItem(index3,1,item4);
                index2++;
                index3++;
                index1++;
            }
            }
            else if(val1==2)
            {
            ptr_2[index2_1]->setInfo(val1,val2,val3,QString::fromStdString(val4),QString::fromStdString(val5));
            QTableWidgetItem *item1 = new QTableWidgetItem(QString::fromStdString(val4),1);
            QTableWidgetItem *item2 = new QTableWidgetItem(QString::fromStdString(val5),1);
            if(val2==1&&val3==0)
            {
            ui->table2_1->setItem(index2_2,0,item1);
            ui->table2_1->setItem(index2_2,1,item2);
            index2_2++;
            index2_1++;
            }
            else if(val2==0&&val3==1)
            {
                ui->table2_2->setItem(index2_3,0,item1);
                ui->table2_2->setItem(index2_3,1,item2);
                index2_3++;
                index2_1++;
            }
            else if(val2==1&&val3==1)
            {
                QTableWidgetItem *item3 = new QTableWidgetItem(QString::fromStdString(val4),1);
                QTableWidgetItem *item4 = new QTableWidgetItem(QString::fromStdString(val5),1);
                ui->table2_1->setItem(index2_2,0,item1);
                ui->table2_1->setItem(index2_2,1,item2);
                ui->table2_2->setItem(index2_3,0,item3);
                ui->table2_2->setItem(index2_3,1,item4);
                index2_2++;
                index2_3++;
                index2_1++;
            }
            }
            else if(val1==3)
            {
            ptr_3[index3_1]->setInfo(val1,val2,val3,QString::fromStdString(val4),QString::fromStdString(val5));
            QTableWidgetItem *item1 = new QTableWidgetItem(QString::fromStdString(val4),1);
            QTableWidgetItem *item2 = new QTableWidgetItem(QString::fromStdString(val5),1);
            if(val2==1&&val3==0)
            {
            ui->table3_1->setItem(index3_2,0,item1);
            ui->table3_1->setItem(index3_2,1,item2);
            index3_2++;
            index3_1++;
            }
            else if(val2==0&&val3==1)
            {
                ui->table3_2->setItem(index3_3,0,item1);
                ui->table3_2->setItem(index3_3,1,item2);
                index3_3++;
                index3_1++;
            }
            else if(val2==1&&val3==1)
            {
                QTableWidgetItem *item3 = new QTableWidgetItem(QString::fromStdString(val4),1);
                QTableWidgetItem *item4 = new QTableWidgetItem(QString::fromStdString(val5),1);
                ui->table3_1->setItem(index3_2,0,item1);
                ui->table3_1->setItem(index3_2,1,item2);
                ui->table3_2->setItem(index3_3,0,item3);
                ui->table3_2->setItem(index3_3,1,item4);
                index3_2++;
                index3_3++;
                index3_1++;
            }
            }
            else if(val1==4)
            {
            ptr_4[index4_1]->setInfo(val1,val2,val3,QString::fromStdString(val4),QString::fromStdString(val5));
            QTableWidgetItem *item1 = new QTableWidgetItem(QString::fromStdString(val4),1);
            QTableWidgetItem *item2 = new QTableWidgetItem(QString::fromStdString(val5),1);
            if(val2==1&&val3==0)
            {
            ui->table4_1->setItem(index4_2,0,item1);
            ui->table4_1->setItem(index4_2,1,item2);
            index4_2++;
            index4_1++;
            }
            else if(val2==0&&val3==1)
            {
                ui->table4_2->setItem(index4_3,0,item1);
                ui->table4_2->setItem(index4_3,1,item2);
                index4_3++;
                index4_1++;
            }
            else if(val2==1&&val3==1)
            {
                QTableWidgetItem *item3 = new QTableWidgetItem(QString::fromStdString(val4),1);
                QTableWidgetItem *item4 = new QTableWidgetItem(QString::fromStdString(val5),1);
                ui->table4_1->setItem(index4_2,0,item1);
                ui->table4_1->setItem(index4_2,1,item2);
                ui->table4_2->setItem(index4_3,0,item3);
                ui->table4_2->setItem(index4_3,1,item4);
                index4_2++;
                index4_3++;
                index4_1++;
            }
            }
            count = 0;
            val4.clear();
            val5.clear();
            continue;
            }

        }
    }

}
}
