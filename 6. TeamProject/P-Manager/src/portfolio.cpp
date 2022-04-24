#include "portfolio.h"
#include "ui_portfolio.h"
#include "courses.h"
#include <QPen>
#include "extra.h"
#include <fstream>
#include <sstream>
#include <QDebug>
namespace Sumin{
Portfolio::Portfolio(std::string _name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Portfolio)
{
    name=_name;
    ui->setupUi(this);

    QPixmap ready(":/image/image/port.jpg");
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView_2->setScene(scene);
    ui->graphicsView_3->setScene(scene);
    ui->graphicsView_4->setScene(scene);
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(ready);
    scene->addItem(item);




    ptr[0] =ui->course_1;
    ptr[1] =ui->course_2;
    ptr[2] = ui->course_3;
    ptr[3] =ui->course_4;
    ptr[4] =ui->course_5;
    ptr[5] = ui->course_6;
    ptr[6] =ui->course_7;
    ptr[7] =ui->course_8;
    ptr[8] = ui->course_9;
    ptr[9] =ui->course_10;
    ptr[10] =ui->course_11;
    ptr[11] = ui->course_12;
    ptr[12] =ui->course_13;
    ptr[13] =ui->course_14;
    ptr[14] = ui->course_15;
    ptr[15] =ui->course_16;
    ptr[16] =ui->course_17;
    ptr[17] = ui->course_18;
    ptr[18] =ui->course_19;
    ptr[19] =ui->course_20;
    /******************/
    course2[0] =ui->course_21;
    course2[1] =ui->course_22;
    course2[2] = ui->course_23;
    course2[3] =ui->course_24;
    course2[4] =ui->course_25;
    course2[5] = ui->course_26;
    course2[6] =ui->course_27;
    course2[7] =ui->course_28;
    course2[8] = ui->course_29;
    course2[9] =ui->course_30;
    course2[10] =ui->course_31;
    course2[11] = ui->course_32;
    course2[12] =ui->course_33;
    course2[13] =ui->course_34;
    course2[14] = ui->course_35;
    course2[15] =ui->course_36;
    course2[16] =ui->course_37;
    course2[17] = ui->course_38;
    course2[18] =ui->course_39;
    course2[19] =ui->course_40;
     /******************/
    course3[0] =ui->course_41;
    course3[1] =ui->course_42;
    course3[2] = ui->course_43;
    course3[3] =ui->course_44;
    course3[4] =ui->course_45;
    course3[5] = ui->course_46;
    course3[6] =ui->course_47;
    course3[7] =ui->course_48;
    course3[8] = ui->course_49;
    course3[9] =ui->course_50;
    course3[10] =ui->course_51;
    course3[11] = ui->course_52;
    course3[12] =ui->course_53;
    course3[13] =ui->course_54;
    course3[14] = ui->course_55;
    course3[15] =ui->course_56;
    course3[16] =ui->course_57;
    course3[17] = ui->course_58;
    course3[18] =ui->course_59;
    course3[19] =ui->course_60;
     /******************/
    course4[0] =ui->course_61;
    course4[1] =ui->course_62;
    course4[2] = ui->course_63;
    course4[3] =ui->course_64;
    course4[4] =ui->course_65;
    course4[5] = ui->course_66;
    course4[6] =ui->course_67;
    course4[7] =ui->course_68;
    course4[8] = ui->course_69;
    course4[9] =ui->course_70;
    course4[10] =ui->course_71;
    course4[11] = ui->course_72;
    course4[12] =ui->course_73;
    course4[13] =ui->course_74;
    course4[14] = ui->course_75;
    course4[15] =ui->course_76;
    course4[16] =ui->course_77;
    course4[17] = ui->course_78;
    course4[18] =ui->course_79;
    course4[19] =ui->course_80;
    /****************/
    ptr_2[0] =ui->Club1;
    ptr_2[1] =ui->Club2;
    club2[0] =ui->Club1_2;
    club2[1] =ui->Club2_2;
    club3[0] =ui->Club1_3;
    club3[1] =ui->Club2_3;
    club4[0] =ui->Club1_4;
    club4[1] =ui->Club2_4;
    mani1[0] =ui->Committee1;
    mani1[1] =ui->Committee2;
    mani2[0] =ui->Committee1_2;
    mani2[1] =ui->Committee2_2;
    mani3[0] =ui->Committee1_3;
    mani3[1] =ui->Committee2_3;
    mani4[0] =ui->Committee1_4;
    mani4[1] =ui->Committee2_4;
    extra1[0] =ui->Extra1;
    extra1[1] =ui->Extra2;
    extra1[2] =ui->Extra3;
    extra1[3] =ui->Extra4;
    extra2[0] =ui->Extra1_2;
    extra2[1] =ui->Extra2_2;
    extra2[2] =ui->Extra3_2;
    extra2[3] =ui->Extra4_2;
    extra3[0] =ui->Extra1_3;
    extra3[1] =ui->Extra2_3;
    extra3[2] =ui->Extra3_3;
    extra3[3] =ui->Extra4_3;
    extra4[0] =ui->Extra1_4;
    extra4[1] =ui->Extra2_4;
    extra4[2] =ui->Extra3_4;
    extra4[3] =ui->Extra4_4;
    /*************************/
    ready1[0] =ui->Ready1;
    ready1[1] =ui->Ready2;
    ready1[2] =ui->Ready3;
    ready1[3] =ui->Ready4;
    ready2[0] =ui->Ready1_2;
    ready2[1] =ui->Ready2_2;
    ready2[2] =ui->Ready3_2;
    ready2[3] =ui->Ready4_2;
    ready3[0] =ui->Ready1_3;
    ready3[1] =ui->Ready2_3;
    ready3[2] =ui->Ready3_3;
    ready3[3] =ui->Ready4_3;
    ready4[0] =ui->Ready1_4;
    ready4[1] =ui->Ready2_4;
    ready4[2] =ui->Ready3_4;
    ready4[3] =ui->Ready4_4;
    for(int i = 0; i<4;i++)
        linecount[i] = 0;
    addCourse();
    addClub();
    addCommittee();
    addExtra();
    addReady();

    //ui->lineEdit->setStyleSheet("border: 4px solid red");
}
void Portfolio::addCourse()
{
    std::string file_path = "courseslog";
    std::string line;
    std::stringstream stream;
    int nTokens = 0;
    int check =1;
    int mode =0;
    int semester;
    std::string tokens[10];
    file_path.append("_"+name+".txt");
    QString coursename,level;
    std::ifstream inLogRead;
    inLogRead.open(file_path,std::ios::in);
    if(inLogRead.fail())
        return;
    while(check)
    {
        getline(inLogRead,line);
        if(line=="")
        {
            if(inLogRead.eof())
               { check=0;
            break;
            }
        }
        else {
            stream.str(line);
            nTokens = 0;
            while(stream>>tokens[nTokens])
                nTokens++;
            stream.clear();
            /*********************/
        }
        qDebug()<<QString::fromStdString(tokens[0]);
        if(nTokens!=0)
        qDebug()<<(QString::fromStdString(tokens[nTokens-1]));
       if(QString::fromStdString(tokens[0])=="dm")
       {
           nTokens = 0;
           continue;
       }
       if(mode==0)
       {
           semester = atoi(tokens[0].c_str());
           mode++;
           continue;
       }
       else if(mode==1)
       {
           for(int i=0;i<nTokens;i++)
           {
               coursename+=QString::fromStdString(tokens[i]);
                coursename+=" ";
           }
           mode++;
           continue;
       }
       else if(mode==2||mode==3)
       {
           mode++;
           continue;
       }
       else if(mode==4)
       {
           level = QString::fromStdString(tokens[0]);
           mode++;
       }
       if((mode==5&&level=="기초필수") || (mode==5&&level=="기필") || (mode==5&&level=="기초 필수"))
        {
            if(semester==0)
            {
                ptr[linecount[0]]->setText(coursename);
                ptr[linecount[0]]->setStyleSheet("border: 4px solid navy");
                linecount[0]++;
            }
            else if(semester==1)
            {
                ptr[linecount[0]]->setText(coursename);
                ptr[linecount[0]]->setStyleSheet("border: 4px solid navy");
                linecount[0]++;
            }
           else if(semester==2)
            {
                course2[linecount[1]]->setText(coursename);
                course2[linecount[1]]->setStyleSheet("border: 4px solid navy");
                linecount[1]++;
            }
           else if(semester==3)
             {
                 course2[linecount[1]]->setText(coursename);
                 course2[linecount[1]]->setStyleSheet("border: 4px solid navy");
                 linecount[1]++;
             }
           else if(semester==4)
              {
                  course3[linecount[2]]->setText(coursename);
                  course3[linecount[2]]->setStyleSheet("border: 4px solid navy");
                  linecount[2]++;
              }
            else if(semester==5)
              {
                  course3[linecount[2]]->setText(coursename);
                  course3[linecount[2]]->setStyleSheet("border: 4px solid navy");
                  linecount[2]++;
              }
            else if(semester==6)
              {
                  course4[linecount[3]]->setText(coursename);
                  course4[linecount[3]]->setStyleSheet("border: 4px solid navy");
                  linecount[3]++;
              }
            else if(semester==7)
              {
                  course4[linecount[3]]->setText(coursename);
                  course4[linecount[3]]->setStyleSheet("border: 4px solid navy");
                  linecount[3]++;
              }


        }
       if(mode==5)
          {
           mode =0;
           coursename.clear();
           line.clear();
       }

    }
    inLogRead.close();
    inLogRead.open(file_path,std::ios::in);
    mode = 0;
    check =1;
    while(check)
    {
        getline(inLogRead,line);
        if(line=="")
        {
            if(inLogRead.eof())
               { check=0;
            break;
            }
        }
        else {
            stream.str(line);
            nTokens = 0;
            while(stream>>tokens[nTokens])
                nTokens++;
            stream.clear();
            /*********************/
        }
        qDebug()<<QString::fromStdString(tokens[0]);
        if(nTokens!=0)
        qDebug()<<(QString::fromStdString(tokens[nTokens-1]));
       if(QString::fromStdString(tokens[0])=="dm")
       {
           nTokens = 0;
           continue;
       }
       if(mode==0)
       {
           semester = atoi(tokens[0].c_str());
           mode++;
           continue;
       }
       else if(mode==1)
       {
           for(int i=0;i<nTokens;i++)
           {
               coursename+=QString::fromStdString(tokens[i]);
                coursename+=" ";
           }
           mode++;
           continue;
       }
       else if(mode==2||mode==3)
       {
           mode++;
           continue;
       }
       else if(mode==4)
       {
           level = QString::fromStdString(tokens[0]);
           mode++;
       }
       if((mode==5&&level=="기초선택") || (mode==5&&level=="기선") || (mode==5&&level=="기초 선택"))
        {
            if(semester==0)
            {
                ptr[linecount[0]]->setText(coursename);
                ptr[linecount[0]]->setStyleSheet("border: 4px solid purple");
                linecount[0]++;
            }
            else if(semester==1)
            {
                ptr[linecount[0]]->setText(coursename);
                ptr[linecount[0]]->setStyleSheet("border: 4px solid purple");
                linecount[0]++;
            }
           else if(semester==2)
            {
                course2[linecount[1]]->setText(coursename);
                course2[linecount[1]]->setStyleSheet("border: 4px solid purple");
                linecount[1]++;
            }
           else if(semester==3)
             {
                 course2[linecount[1]]->setText(coursename);
                 course2[linecount[1]]->setStyleSheet("border: 4px solid purple");
                 linecount[1]++;
             }
           else if(semester==4)
              {
                  course3[linecount[2]]->setText(coursename);
                  course3[linecount[2]]->setStyleSheet("border: 4px solid purple");
                  linecount[2]++;
              }
            else if(semester==5)
              {
                  course3[linecount[2]]->setText(coursename);
                  course3[linecount[2]]->setStyleSheet("border: 4px solid purple");
                  linecount[2]++;
              }
            else if(semester==6)
              {
                  course4[linecount[3]]->setText(coursename);
                  course4[linecount[3]]->setStyleSheet("border: 4px solid purple");
                  linecount[3]++;
              }
            else if(semester==7)
              {
                  course4[linecount[3]]->setText(coursename);
                  course4[linecount[3]]->setStyleSheet("border: 4px solid purple");
                  linecount[3]++;
              }


        }
       if(mode==5)
       {
        mode =0;
        coursename.clear();
        line.clear();
    }

    }
    inLogRead.close();
    inLogRead.open(file_path,std::ios::in);
    mode = 0;
    check =1;
    while(check)
    {
        getline(inLogRead,line);
        if(line=="")
        {
            if(inLogRead.eof())
               { check=0;
            break;
            }
        }
        else {
            stream.str(line);
            nTokens = 0;
            while(stream>>tokens[nTokens])
                nTokens++;
            stream.clear();
            /*********************/
        }
        qDebug()<<QString::fromStdString(tokens[0]);
        if(nTokens!=0)
        qDebug()<<(QString::fromStdString(tokens[nTokens-1]));
       if(QString::fromStdString(tokens[0])=="dm")
       {
           nTokens = 0;
           continue;
       }
       if(mode==0)
       {
           semester = atoi(tokens[0].c_str());
           mode++;
           continue;
       }
       else if(mode==1)
       {
           for(int i=0;i<nTokens;i++)
           {
               coursename+=QString::fromStdString(tokens[i]);
                coursename+=" ";
           }
           mode++;
           continue;
       }
       else if(mode==2||mode==3)
       {
           mode++;
           continue;
       }
       else if(mode==4)
       {
           level = QString::fromStdString(tokens[0]);
           mode++;
       }
       if((mode==5&&level=="전공필수") || (mode==5&&level=="전필") || (mode==5&&level=="전공 필수"))
        {
            if(semester==0)
            {
                ptr[linecount[0]]->setText(coursename);
                ptr[linecount[0]]->setStyleSheet("border: 4px solid red");
                linecount[0]++;
            }
            else if(semester==1)
            {
                ptr[linecount[0]]->setText(coursename);
                ptr[linecount[0]]->setStyleSheet("border: 4px solid red");
                linecount[0]++;
            }
           else if(semester==2)
            {
                course2[linecount[1]]->setText(coursename);
                course2[linecount[1]]->setStyleSheet("border: 4px solid red");
                linecount[1]++;
            }
           else if(semester==3)
             {
                 course2[linecount[1]]->setText(coursename);
                 course2[linecount[1]]->setStyleSheet("border: 4px solid red");
                 linecount[1]++;
             }
           else if(semester==4)
              {
                  course3[linecount[2]]->setText(coursename);
                  course3[linecount[2]]->setStyleSheet("border: 4px solid red");
                  linecount[2]++;
              }
            else if(semester==5)
              {
                  course3[linecount[2]]->setText(coursename);
                  course3[linecount[2]]->setStyleSheet("border: 4px solid red");
                  linecount[2]++;
              }
            else if(semester==6)
              {
                  course4[linecount[3]]->setText(coursename);
                  course4[linecount[3]]->setStyleSheet("border: 4px solid red");
                  linecount[3]++;
              }
            else if(semester==7)
              {
                  course4[linecount[3]]->setText(coursename);
                  course4[linecount[3]]->setStyleSheet("border: 4px solid red");
                  linecount[3]++;
              }


        }
       if(mode==5)
       {
        mode =0;
        coursename.clear();
        line.clear();
    }
    }
    inLogRead.close();
    inLogRead.open(file_path,std::ios::in);
    mode = 0;
    check =1;
    while(check)
    {
        getline(inLogRead,line);
        if(line=="")
        {
            if(inLogRead.eof())
               {
                check=0;
                break;
            }
        }
        else {
            stream.str(line);
            nTokens = 0;
            while(stream>>tokens[nTokens])
                nTokens++;
            stream.clear();
            /*********************/
        }
        qDebug()<<QString::fromStdString(tokens[0]);
        if(nTokens!=0)
        qDebug()<<(QString::fromStdString(tokens[nTokens-1]));
       if(QString::fromStdString(tokens[0])=="dm")
       {
           nTokens = 0;
           continue;
       }
       if(mode==0)
       {
           semester = atoi(tokens[0].c_str());
           mode++;
           continue;
       }
       else if(mode==1)
       {
           for(int i=0;i<nTokens;i++)
           {
               coursename+=QString::fromStdString(tokens[i]);
                coursename+=" ";
           }
           mode++;
           continue;
       }
       else if(mode==2||mode==3)
       {
           mode++;
           continue;
       }
       else if(mode==4)
       {
           level = QString::fromStdString(tokens[0]);
           mode++;
       }
       if((mode==5&&level=="전공선택") || (mode==5&&level=="전선") || (mode==5&&level=="전공 선택"))
        {
            if(semester==0)
            {
                ptr[linecount[0]]->setText(coursename);
                ptr[linecount[0]]->setStyleSheet("border: 4px solid darkGreen");
                linecount[0]++;
            }
            else if(semester==1)
            {
                ptr[linecount[0]]->setText(coursename);
                ptr[linecount[0]]->setStyleSheet("border: 4px solid darkGreen");
                linecount[0]++;
            }
           else if(semester==2)
            {
                course2[linecount[1]]->setText(coursename);
                course2[linecount[1]]->setStyleSheet("border: 4px solid darkGreen");
                linecount[1]++;
            }
           else if(semester==3)
             {
                 course2[linecount[1]]->setText(coursename);
                 course2[linecount[1]]->setStyleSheet("border: 4px solid darkGreen");
                 linecount[1]++;
             }
           else if(semester==4)
              {
                  course3[linecount[2]]->setText(coursename);
                  course3[linecount[2]]->setStyleSheet("border: 4px solid darkGreen");
                  linecount[2]++;
              }
            else if(semester==5)
              {
                  course3[linecount[2]]->setText(coursename);
                  course3[linecount[2]]->setStyleSheet("border: 4px solid darkGreen");
                  linecount[2]++;
              }
            else if(semester==6)
              {
                  course4[linecount[3]]->setText(coursename);
                  course4[linecount[3]]->setStyleSheet("border: 4px solid darkGreen");
                  linecount[3]++;
              }
            else if(semester==7)
              {
                  course4[linecount[3]]->setText(coursename);
                  course4[linecount[3]]->setStyleSheet("border: 4px solid darkGreen");
                  linecount[3]++;
              }

        }
       if(mode==5)
       {
        mode =0;
        coursename.clear();
        line.clear();
    }
    }
    inLogRead.close();
    inLogRead.open(file_path,std::ios::in);
    mode = 0;
    check =1;
    while(check)
    {
        getline(inLogRead,line);
        if(line=="")
        {
            if(inLogRead.eof())
               { check=0;
            break;
            }
        }
        else {
            stream.str(line);
            nTokens = 0;
            while(stream>>tokens[nTokens])
                nTokens++;
            stream.clear();
            /*********************/
        }
        qDebug()<<QString::fromStdString(tokens[0]);
        if(nTokens!=0)
        qDebug()<<(QString::fromStdString(tokens[nTokens-1]));
       if(QString::fromStdString(tokens[0])=="dm")
       {
           nTokens = 0;
           continue;
       }
       if(mode==0)
       {
           semester = atoi(tokens[0].c_str());
           mode++;
           continue;
       }
       else if(mode==1)
       {
           for(int i=0;i<nTokens;i++)
           {
               coursename+=QString::fromStdString(tokens[i]);
                coursename+=" ";
           }
           mode++;
           continue;
       }
       else if(mode==2||mode==3)
       {
           mode++;
           continue;
       }
       else if(mode==4)
       {
           level = QString::fromStdString(tokens[0]);
           mode++;
       }
       if((mode==5&&level=="교양필수") || (mode==5&&level=="교필") || (mode==5&&level=="교양 필수"))
        {
            if(semester==0)
            {
                ptr[linecount[0]]->setText(coursename);
                ptr[linecount[0]]->setStyleSheet("border: 4px solid magenta");
                linecount[0]++;
            }
            else if(semester==1)
            {
                ptr[linecount[0]]->setText(coursename);
                ptr[linecount[0]]->setStyleSheet("border: 4px solid magenta");
                linecount[0]++;
            }
           else if(semester==2)
            {
                course2[linecount[1]]->setText(coursename);
                course2[linecount[1]]->setStyleSheet("border: 4px solid magenta");
                linecount[1]++;
            }
           else if(semester==3)
             {
                 course2[linecount[1]]->setText(coursename);
                 course2[linecount[1]]->setStyleSheet("border: 4px solid magenta");
                 linecount[1]++;
             }
           else if(semester==4)
              {
                  course3[linecount[2]]->setText(coursename);
                  course3[linecount[2]]->setStyleSheet("border: 4px solid magenta");
                  linecount[2]++;
              }
            else if(semester==5)
              {
                  course3[linecount[2]]->setText(coursename);
                  course3[linecount[2]]->setStyleSheet("border: 4px solid magenta");
                  linecount[2]++;
              }
            else if(semester==6)
              {
                  course4[linecount[3]]->setText(coursename);
                  course4[linecount[3]]->setStyleSheet("border: 4px solid magenta");
                  linecount[3]++;
              }
            else if(semester==7)
              {
                  course4[linecount[3]]->setText(coursename);
                  course4[linecount[3]]->setStyleSheet("border: 4px solid magenta");
                  linecount[3]++;
              }


        }
       if(mode==5)
       {
        mode =0;
        coursename.clear();
        line.clear();
    }
    }
    inLogRead.close();
    inLogRead.open(file_path,std::ios::in);
    mode = 0;
    check =1;
    while(check)
    {
        getline(inLogRead,line);
        if(line=="")
        {
            if(inLogRead.eof())
               { check=0;
            break;
            }
        }
        else {
            stream.str(line);
            nTokens = 0;
            while(stream>>tokens[nTokens])
                nTokens++;
            stream.clear();
            /*********************/
        }
        qDebug()<<QString::fromStdString(tokens[0]);
        if(nTokens!=0)
        qDebug()<<(QString::fromStdString(tokens[nTokens-1]));
       if(QString::fromStdString(tokens[0])=="dm")
       {
           nTokens = 0;
           continue;
       }
       if(mode==0)
       {
           semester = atoi(tokens[0].c_str());
           mode++;
           continue;
       }
       else if(mode==1)
       {
           for(int i=0;i<nTokens;i++)
           {
               coursename+=QString::fromStdString(tokens[i]);
                coursename+=" ";
           }
           mode++;
           continue;
       }
       else if(mode==2||mode==3)
       {
            mode++;
           continue;
       }
       else if(mode==4)
       {
           level = QString::fromStdString(tokens[0]);
           mode++;
       }
       if((mode==5&&level=="교양선택") || (mode==5&&level=="교선") || (mode==5&&level=="교양 선택"))
        {
            if(semester==0)
            {
                ptr[linecount[0]]->setText(coursename);
                ptr[linecount[0]]->setStyleSheet("border: 4px solid blue");
                linecount[0]++;
            }
            else if(semester==1)
            {
                ptr[linecount[0]]->setText(coursename);
                ptr[linecount[0]]->setStyleSheet("border: 4px solid blue");
                linecount[0]++;
            }
           else if(semester==2)
            {
                course2[linecount[1]]->setText(coursename);
                course2[linecount[1]]->setStyleSheet("border: 4px solid blue");
                linecount[1]++;
            }
           else if(semester==3)
             {
                 course2[linecount[1]]->setText(coursename);
                 course2[linecount[1]]->setStyleSheet("border: 4px solid blue");
                 linecount[1]++;
             }
           else if(semester==4)
              {
                  course3[linecount[2]]->setText(coursename);
                  course3[linecount[2]]->setStyleSheet("border: 4px solid blue");
                  linecount[2]++;
              }
            else if(semester==5)
              {
                  course3[linecount[2]]->setText(coursename);
                  course3[linecount[2]]->setStyleSheet("border: 4px solid blue");
                  linecount[2]++;
              }
            else if(semester==6)
              {
                  course4[linecount[3]]->setText(coursename);
                  course4[linecount[3]]->setStyleSheet("border: 4px solid blue");
                  linecount[3]++;
              }
            else if(semester==7)
              {
                  course4[linecount[3]]->setText(coursename);
                  course4[linecount[3]]->setStyleSheet("border: 4px solid blue");
                  linecount[3]++;
              }


        }
       if(mode==5)
       {
        mode =0;
        coursename.clear();
        line.clear();
    }
    }
    inLogRead.close();
    inLogRead.open(file_path,std::ios::in);
    check =1;
    mode = 0;
    while(check)
    {
        getline(inLogRead,line);
        if(line=="")
        {
            if(inLogRead.eof())
               { check=0;
            break;
            }
        }
        else {
            stream.str(line);
            nTokens = 0;
            while(stream>>tokens[nTokens])
                nTokens++;
            stream.clear();
            /*********************/
        }
        qDebug()<<QString::fromStdString(tokens[0]);
        if(nTokens!=0)
        qDebug()<<(QString::fromStdString(tokens[nTokens-1]));
       if(QString::fromStdString(tokens[0])=="dm")
       {
           nTokens = 0;
           continue;
       }
       if(mode==0)
       {
           semester = atoi(tokens[0].c_str());
           mode++;
           continue;
       }
       else if(mode==1)
       {
           for(int i=0;i<nTokens;i++)
           {
               coursename+=QString::fromStdString(tokens[i]);
                coursename+=" ";
           }
           mode++;
           continue;
       }
       else if(mode==2||mode==3)
       {
            mode++;
           continue;
       }
       else if(mode==4)
       {
           level = QString::fromStdString(tokens[0]);
           mode++;
       }
       if((mode==5&&level=="자유선택") || (mode==5&&level=="자선") || (mode==5&&level=="자유 선택"))
        {
            if(semester==0)
            {
                ptr[linecount[0]]->setText(coursename);
                ptr[linecount[0]]->setStyleSheet("border: 4px solid orange");
                linecount[0]++;
            }
            else if(semester==1)
            {
                ptr[linecount[0]]->setText(coursename);
                ptr[linecount[0]]->setStyleSheet("border: 4px solid orange");
                linecount[0]++;
            }
           else if(semester==2)
            {
                course2[linecount[1]]->setText(coursename);
                course2[linecount[1]]->setStyleSheet("border: 4px solid orange");
                linecount[1]++;
            }
           else if(semester==3)
             {
                 course2[linecount[1]]->setText(coursename);
                 course2[linecount[1]]->setStyleSheet("border: 4px solid orange");
                 linecount[1]++;
             }
           else if(semester==4)
              {
                  course3[linecount[2]]->setText(coursename);
                  course3[linecount[2]]->setStyleSheet("border: 4px solid orange");
                  linecount[2]++;
              }
            else if(semester==5)
              {
                  course3[linecount[2]]->setText(coursename);
                  course3[linecount[2]]->setStyleSheet("border: 4px solid orange");
                  linecount[2]++;
              }
            else if(semester==6)
              {
                  course4[linecount[3]]->setText(coursename);
                  course4[linecount[3]]->setStyleSheet("border: 4px solid orange");
                  linecount[3]++;
              }
            else if(semester==7)
              {
                  course4[linecount[3]]->setText(coursename);
                  course4[linecount[3]]->setStyleSheet("border: 4px solid orange");
                  linecount[3]++;
              }

        }
       if(mode==5)
       {
        mode =0;
        coursename.clear();
        line.clear();
    }
    }
    inLogRead.close();
    inLogRead.open(file_path,std::ios::in);
    check =1;
    mode = 0;
    while(check)
    {
        getline(inLogRead,line);
        if(line=="")
        {
            if(inLogRead.eof())
               { check=0;
            break;
            }
        }
        else {
            stream.str(line);
            nTokens = 0;
            while(stream>>tokens[nTokens])
                nTokens++;
            stream.clear();
            /*********************/
        }
        qDebug()<<QString::fromStdString(tokens[0]);
        if(nTokens!=0)
        qDebug()<<(QString::fromStdString(tokens[nTokens-1]));
       if(QString::fromStdString(tokens[0])=="dm")
       {
           nTokens = 0;
           continue;
       }
       if(mode==0)
       {
           semester = atoi(tokens[0].c_str());
           mode++;
           continue;
       }
       else if(mode==1)
       {
           for(int i=0;i<nTokens;i++)
           {
               coursename+=QString::fromStdString(tokens[i]);
               coursename+=" ";
           }
           mode++;
           continue;
       }
       else if(mode==2||mode==3)
       {
            mode++;
           continue;
       }
       else if(mode==4)
       {
           level = QString::fromStdString(tokens[0]);
           mode++;
       }
       if((mode==5&&level=="복수전공") || (mode==5&&level=="복전"))
        {
            if(semester==0)
            {
                ptr[linecount[0]]->setText(coursename);
                ptr[linecount[0]]->setStyleSheet("border: 4px solid green");
                linecount[0]++;
            }
            else if(semester==1)
            {
                ptr[linecount[0]]->setText(coursename);
                ptr[linecount[0]]->setStyleSheet("border: 4px solid green");
                linecount[0]++;
            }
           else if(semester==2)
            {
                course2[linecount[1]]->setText(coursename);
                course2[linecount[1]]->setStyleSheet("border: 4px solid green");
                linecount[1]++;
            }
           else if(semester==3)
             {
                 course2[linecount[1]]->setText(coursename);
                 course2[linecount[1]]->setStyleSheet("border: 4px solid green");
                 linecount[1]++;
             }
           else if(semester==4)
              {
                  course3[linecount[2]]->setText(coursename);
                  course3[linecount[2]]->setStyleSheet("border: 4px solid green");
                  linecount[2]++;
              }
            else if(semester==5)
              {
                  course3[linecount[2]]->setText(coursename);
                  course3[linecount[2]]->setStyleSheet("border: 4px solid green");
                  linecount[2]++;
              }
            else if(semester==6)
              {
                  course4[linecount[3]]->setText(coursename);
                  course4[linecount[3]]->setStyleSheet("border: 4px solid green");
                  linecount[3]++;
              }
            else if(semester==7)
              {
                  course4[linecount[3]]->setText(coursename);
                  course4[linecount[3]]->setStyleSheet("border: 4px solid green");
                  linecount[3]++;
              }

        }
       if(mode==5)
       {
        mode =0;
        coursename.clear();
        line.clear();
    }
    }
    inLogRead.close();
}
void Portfolio::addClub()
{
    std::string file_path = "commandLog_Club";
    std::string line;
    std::stringstream stream;
    int nTokens = 0;
    int check =1;
    std::string tokens[5];
    file_path.append("_"+name+".txt");
    std::ifstream inLogRead;
    inLogRead.open(file_path,std::ios::in);
    if(inLogRead.fail())
        return;
    int count =0;
    while(check)
    {

        getline(inLogRead,line);
        if(line=="")
        {
            if(inLogRead.eof())
               { check=0;
            break;
            }
        }
        else {
            stream.str(line);
            while(stream>>tokens[nTokens])
                nTokens++;
            stream.clear();
            /*********************/
        }
        if(nTokens==5&&QString::fromStdString(tokens[0])=="1")
        {
            ptr_2[count]->setText(QString::fromStdString(tokens[3]));
            count++;
        }
        if(count==2)
        {
            nTokens=0;
            break;
        }
        if(nTokens==5)
            nTokens=0;
    }
    inLogRead.close();
    inLogRead.open(file_path,std::ios::in);
    check=1;
    count =0;
    while(check)
    {

        getline(inLogRead,line);
        if(line=="")
        {
            if(inLogRead.eof())
               { check=0;
            break;
            }
        }
        else {
            stream.str(line);
            while(stream>>tokens[nTokens])
                nTokens++;
            stream.clear();
            /*********************/
        }
        if(nTokens==5&&QString::fromStdString(tokens[0])=="2")
        {
            club2[count]->setText(QString::fromStdString(tokens[3]));
            count++;
        }
        if(count==2)
        {
            nTokens=0;
            break;
        }
        if(nTokens==5)
            nTokens=0;
    }
    inLogRead.close();
    inLogRead.open(file_path,std::ios::in);
    check=1;
    count = 0;
    while(check)
    {

        getline(inLogRead,line);
        if(line=="")
        {
            if(inLogRead.eof())
               { check=0;
            break;
            }
        }
        else {
            stream.str(line);
            while(stream>>tokens[nTokens])
                nTokens++;
            stream.clear();
            /*********************/
        }
        if(nTokens==5&&QString::fromStdString(tokens[0])=="3")
        {
            club3[count]->setText(QString::fromStdString(tokens[3]));
            count++;
        }
        if(count==2)
        {
            nTokens=0;
            break;
        }
        if(nTokens==5)
            nTokens=0;
    }
    inLogRead.close();
    inLogRead.open(file_path,std::ios::in);
    check=1;
    count = 0;
    while(check)
    {

        getline(inLogRead,line);
        if(line=="")
        {
            if(inLogRead.eof())
               { check=0;
            break;
            }
        }
        else {
            stream.str(line);
            while(stream>>tokens[nTokens])
                nTokens++;
            stream.clear();
            /*********************/
        }
        if(nTokens==5&&QString::fromStdString(tokens[0])=="4")
        {
            club4[count]->setText(QString::fromStdString(tokens[3]));
            count++;
        }
        if(count==2)
        {
            nTokens=0;
            break;
        }
        if(nTokens==5)
            nTokens=0;
    }

}
void Portfolio::addCommittee()
{
    std::string file_path = "commandLog_Municipality";
    std::string line;
    std::stringstream stream;
    int nTokens = 0;
    int check =1;
    std::string tokens[5];
    file_path.append("_"+name+".txt");
    std::ifstream inLogRead;
    inLogRead.open(file_path,std::ios::in);
    if(inLogRead.fail())
        return;
    int count =0;
    while(check)
    {

        getline(inLogRead,line);
        if(line=="")
        {
            if(inLogRead.eof())
               { check=0;
            break;
            }
        }
        else {
            stream.str(line);
            while(stream>>tokens[nTokens])
                nTokens++;
            stream.clear();
            /*********************/
        }
        if(nTokens==5&&QString::fromStdString(tokens[0])=="1")
        {
            mani1[count]->setText(QString::fromStdString(tokens[3]));
            count++;
        }
        if(count==2)
        {
            nTokens=0;
            break;
        }
        if(nTokens==5)
            nTokens=0;
    }
    inLogRead.close();
    inLogRead.open(file_path,std::ios::in);
    check=1;
    count =0;
    while(check)
    {

        getline(inLogRead,line);
        if(line=="")
        {
            if(inLogRead.eof())
               { check=0;
            break;
            }
        }
        else {
            stream.str(line);
            while(stream>>tokens[nTokens])
                nTokens++;
            stream.clear();
            /*********************/
        }
        if(nTokens==5&&QString::fromStdString(tokens[0])=="2")
        {
            mani2[count]->setText(QString::fromStdString(tokens[3]));
            count++;
        }
        if(count==2)
        {
            nTokens=0;
            break;
        }
        if(nTokens==5)
            nTokens=0;
    }
    inLogRead.close();
    inLogRead.open(file_path,std::ios::in);
    check=1;
    count =0;
    while(check)
    {

        getline(inLogRead,line);
        if(line=="")
        {
            if(inLogRead.eof())
               { check=0;
            break;
            }
        }
        else {
            stream.str(line);
            while(stream>>tokens[nTokens])
                nTokens++;
            stream.clear();
            /*********************/
        }
        if(nTokens==5&&QString::fromStdString(tokens[0])=="3")
        {
            mani3[count]->setText(QString::fromStdString(tokens[3]));
            count++;
        }
        if(count==2)
        {
            nTokens=0;
            break;
        }
        if(nTokens==5)
            nTokens=0;
    }
    inLogRead.close();
    inLogRead.open(file_path,std::ios::in);
    check=1;
    count =0;
    while(check)
    {
        getline(inLogRead,line);
        if(line=="")
        {
            if(inLogRead.eof())
               { check=0;
            break;
            }
        }
        else {
            stream.str(line);
            while(stream>>tokens[nTokens])
                nTokens++;
            stream.clear();
            /*********************/
        }
        if(nTokens==5&&QString::fromStdString(tokens[0])=="4")
        {
            mani4[count]->setText(QString::fromStdString(tokens[3]));
            count++;
        }
        if(count==2)
        {
            nTokens=0;
            break;
        }
        if(nTokens==5)
            nTokens=0;
    }

}
void Portfolio::addExtra()
{
    std::string file_path = "commandLog_ExtraCourse";
    std::string line;
    std::stringstream stream;
    int nTokens = 0;
    int check =1;
    std::string tokens[5];
    file_path.append("_"+name+".txt");
    std::ifstream inLogRead;
    inLogRead.open(file_path,std::ios::in);
    if(inLogRead.fail())
        return;
    int count =0;
    while(check)
    {

        getline(inLogRead,line);
        if(line=="")
        {
            if(inLogRead.eof())
               { check=0;
            break;
            }
        }
        else {
            stream.str(line);
            while(stream>>tokens[nTokens])
                nTokens++;
            stream.clear();
            /*********************/
        }
        if(nTokens==5&&QString::fromStdString(tokens[0])=="1")
        {
            extra1[count]->setText(QString::fromStdString(tokens[3]));
            count++;
        }
        if(count==4)
        {
            nTokens=0;
            break;
        }
        if(nTokens==5)
            nTokens=0;
    }
    inLogRead.close();
    inLogRead.open(file_path,std::ios::in);
    check=1;
    count =0;
    while(check)
    {

        getline(inLogRead,line);
        if(line=="")
        {
            if(inLogRead.eof())
               { check=0;
            break;
            }
        }
        else {
            stream.str(line);
            while(stream>>tokens[nTokens])
                nTokens++;
            stream.clear();
            /*********************/
        }
        if(nTokens==5&&QString::fromStdString(tokens[0])=="2")
        {
            extra2[count]->setText(QString::fromStdString(tokens[3]));
            count++;
        }
        if(count==4)
        {
            nTokens=0;
            break;
        }
        if(nTokens==5)
            nTokens=0;
    }
    inLogRead.close();
    inLogRead.open(file_path,std::ios::in);
    check=1;
    count =0;
    while(check)
    {

        getline(inLogRead,line);
        if(line=="")
        {
            if(inLogRead.eof())
               { check=0;
            break;
            }
        }
        else {
            stream.str(line);
            while(stream>>tokens[nTokens])
                nTokens++;
            stream.clear();
            /*********************/
        }
        if(nTokens==5&&QString::fromStdString(tokens[0])=="3")
        {
            extra3[count]->setText(QString::fromStdString(tokens[3]));
            count++;
        }
        if(count==4)
        {
            nTokens=0;
            break;
        }
        if(nTokens==5)
            nTokens=0;
    }
    inLogRead.close();
    inLogRead.open(file_path,std::ios::in);
    check=1;
    count =0;
    while(check)
    {
        getline(inLogRead,line);
        if(line=="")
        {
            if(inLogRead.eof())
               { check=0;
            break;
            }
        }
        else {
            stream.str(line);
            while(stream>>tokens[nTokens])
                nTokens++;
            stream.clear();
            /*********************/
        }
        if(nTokens==5&&QString::fromStdString(tokens[0])=="4")
        {
            extra4[count]->setText(QString::fromStdString(tokens[3]));
            count++;
        }
        if(count==4)
        {
            nTokens=0;
            break;
        }
        if(nTokens==5)
            nTokens=0;
    }

}
void Portfolio::addReady()
{
    std::string file_path = "commandLog_Committee";
    std::string line;
    std::stringstream stream;
    int nTokens = 0;
    int check =1;
    std::string tokens[4];
    file_path.append("_"+name+".txt");
    std::ifstream inLogRead;
    inLogRead.open(file_path,std::ios::in);
    if(inLogRead.fail())
        return;
    int count =0;
    while(check)
    {

        getline(inLogRead,line);
        if(line=="")
        {
            if(inLogRead.eof())
               { check=0;
            break;
            }
        }
        else {
            stream.str(line);
            while(stream>>tokens[nTokens])
                nTokens++;
            stream.clear();
            /*********************/
        }
        if(QString::fromStdString(tokens[3])=="1")
        {
            if(QString::fromStdString(tokens[0])=="1")
            {
                switch(atoi(tokens[1].c_str())){
                     case 0:
                       ready1[count]->setText("축준위");
                       count++;
                    break;
                case 1:
                  ready1[count]->setText("엠준위");
                  count++;
               break;
                case 2:
                  ready1[count]->setText("생준위");
                  count++;
               break;
                case 3:
                  ready1[count]->setText("포준위");
                  count++;
               break;
                case 4:
                  ready1[count]->setText("새준위");
                  count++;
               break;
                case 5:
                  ready1[count]->setText("졸준위");
                  count++;
               break;
                case 6:
                  ready1[count]->setText("엠준위");
                  count++;
               break;
                case 7:
                  ready1[count]->setText("생준위");
                  count++;
               break;

            }
            }

        }
        else {
            nTokens = 0;
            continue;
        }
        if(count==4)
        {
            nTokens=0;
            break;
        }
        nTokens = 0;

    }
    inLogRead.close();
    inLogRead.open(file_path,std::ios::in);
    check=1;
    count =0;
    while(check)
    {

        getline(inLogRead,line);
        if(line=="")
        {
            if(inLogRead.eof())
               { check=0;
            break;
            }
        }
        else {
            stream.str(line);
            while(stream>>tokens[nTokens])
                nTokens++;
            stream.clear();
            /*********************/
        }
        if(QString::fromStdString(tokens[3])=="1")
        {
            if(QString::fromStdString(tokens[0])=="2")
            {
                switch(atoi(tokens[1].c_str())){
                     case 0:
                       ready2[count]->setText("축준위");
                       count++;
                    break;
                case 1:
                  ready2[count]->setText("엠준위");
                  count++;
               break;
                case 2:
                  ready2[count]->setText("생준위");
                  count++;
               break;
                case 3:
                  ready2[count]->setText("포준위");
                  count++;
               break;
                case 4:
                  ready2[count]->setText("새준위");
                  count++;
               break;
                case 5:
                  ready2[count]->setText("졸준위");
                  count++;
               break;
                case 6:
                  ready2[count]->setText("엠준위");
                  count++;
               break;
                case 7:
                  ready2[count]->setText("생준위");
                  count++;
               break;

            }
            }

        }
        else {
            nTokens = 0;
            continue;
        }
        if(count==4)
        {
            nTokens=0;
            break;
        }
         nTokens = 0;
    }
    inLogRead.close();
    inLogRead.open(file_path,std::ios::in);
    check=1;
    count =0;
    while(check)
    {

        getline(inLogRead,line);
        if(line=="")
        {
            if(inLogRead.eof())
               { check=0;
            break;
            }
        }
        else {
            stream.str(line);
            while(stream>>tokens[nTokens])
                nTokens++;
            stream.clear();
            /*********************/
        }
        if(QString::fromStdString(tokens[3])=="1")
        {
            if(QString::fromStdString(tokens[0])=="3")
            {
                switch(atoi(tokens[1].c_str())){
                     case 0:
                       ready3[count]->setText("축준위");
                       count++;
                    break;
                case 1:
                  ready3[count]->setText("엠준위");
                  count++;
               break;
                case 2:
                  ready3[count]->setText("생준위");
                  count++;
               break;
                case 3:
                  ready3[count]->setText("포준위");
                  count++;
               break;
                case 4:
                  ready3[count]->setText("새준위");
                  count++;
               break;
                case 5:
                  ready3[count]->setText("졸준위");
                  count++;
               break;
                case 6:
                  ready3[count]->setText("엠준위");
                  count++;
               break;
                case 7:
                  ready3[count]->setText("생준위");
                  count++;
               break;

            }
            }

        }
        else {
            nTokens = 0;
            continue;
        }
        if(count==4)
        {
            nTokens=0;
            break;
        }
         nTokens = 0;
    }
    inLogRead.close();
    inLogRead.open(file_path,std::ios::in);
    check=1;
    count =0;
    while(check)
    {
        getline(inLogRead,line);
        if(line=="")
        {
            if(inLogRead.eof())
               { check=0;
            break;
            }
        }
        else {
            stream.str(line);
            while(stream>>tokens[nTokens])
                nTokens++;
            stream.clear();
            /*********************/
        }
        if(QString::fromStdString(tokens[3])=="1")
        {
            if(QString::fromStdString(tokens[0])=="4")
            {
                switch(atoi(tokens[1].c_str())){
                     case 0:
                       ready4[count]->setText("축준위");
                       count++;
                    break;
                case 1:
                  ready4[count]->setText("엠준위");
                  count++;
               break;
                case 2:
                  ready4[count]->setText("생준위");
                  count++;
               break;
                case 3:
                  ready4[count]->setText("포준위");
                  count++;
               break;
                case 4:
                  ready4[count]->setText("새준위");
                  count++;
               break;
                case 5:
                  ready4[count]->setText("졸준위");
                  count++;
               break;
                case 6:
                  ready4[count]->setText("엠준위");
                  count++;
               break;
                case 7:
                  ready4[count]->setText("생준위");
                  count++;
               break;

            }
            }

        }
        else {
            nTokens = 0;
            continue;
        }
        if(count==4)
        {
            nTokens=0;
            break;
        }
         nTokens = 0;
    }


}

Portfolio::~Portfolio()
{
    delete ui;
}

}
