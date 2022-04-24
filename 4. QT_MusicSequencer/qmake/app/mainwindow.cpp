#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    finalX = 0;
    finalY = 0;
    melody = new as4::model::VectorSeq;
    drum = new as4::model::VectorSeq;
    player_m = new app::source::MelodyPlayer;
    player_d = new app::source::DrumPlayer;
    QObject::connect(ui->play_m,SIGNAL(clicked()),this,SLOT(Play_Melody()));//Melody Tab의 Play버튼을 눌렀을 때 처리를 위한 connect
    QObject::connect(ui->play_d,SIGNAL(clicked()),this,SLOT(Play_Drum()));//Drum Tab의 Play버튼을 눌렀을 때 처리를 위한 connect
    scene = new customscene;
    scene->setSceneRect(0,0,991,581);// scene과 ui에서 설정한 GraphicsView의 좌표 축이 서로 달라, Scene을 View에 맞춰주는 code
    ui->graphicsView->setScene(scene);//Melody Tab의 GraphicsView의 Scene 설정
    scene2 = new customscene;
    scene2->setSceneRect(0,0,991,581);
    ui->graphicsView_2->setScene(scene2);//Drum Tab의 GraphicsView의 Scene 설정
    QObject::connect(scene,SIGNAL(clicked(int,int,int)),this,SLOT(slot1(int,int,int)));//Melody Tab에서 Note를 찍었을 때 처리를 위한 connect
    QObject::connect(scene2,SIGNAL(clicked(int,int,int)),this,SLOT(slot2(int,int,int)));//Drum Tab에서 Note를 찍었을 때 처리를 위한 connect
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::Play_Melody()
{
   // qDebug()<<"here";
    player_m->GetInfo(*melody);//정보를 입력한 후,
    player_m->Init();//재생 과정 시작.
}
void MainWindow::Play_Drum()
{
   // qDebug()<<"here";
    player_d->GetInfo(*drum);
    player_d->Init();
}
void MainWindow::slot1(int x, int y, int LR)
{
   // qDebug()<<x<<y<<LR;
    int pitch=-1;
    int octave =-1;
    int x2 =-1;
    if (x >= 71 && x <= 93)
        {
            finalX = 0;
            x2 = 71;
        }
        else if (x >= 93 && x <= 117)
        {
            finalX = 1;
            x2 = 93;
        }
        else if (x >= 117 && x <= 140)
        {
            finalX = 2;
            x2 = 117;
        }
        else if (x >= 140 && x <= 163)
        {
            finalX = 3;
            x2 = 140;
        }
        else if (x >= 163 && x <= 186)
        {
            finalX = 4;
            x2 = 163;
        }
        else if (x >= 186 && x <= 209)
        {
            finalX = 5;
            x2 = 186;
        }
        else if (x >= 209 && x <= 232)
        {
            finalX = 6;
            x2 = 209;
        }
        else if (x >= 232 && x <= 254)
        {
            finalX = 7;
            x2 = 232;
        }
        else if (x >= 254 && x <= 278)
        {
            finalX = 8;
            x2 = 254;
        }
        else if (x >= 278 && x <= 301)
        {
            finalX = 9;
            x2 = 278;
        }
        else if (x >= 301 && x <= 323)
        {
            finalX = 10;
            x2 = 301;
        }
        else if (x >= 323 && x <= 346)
        {
            finalX = 11;
            x2 = 323;
        }
        else if (x >= 346 && x <= 369)
        {
            finalX = 12;
            x2 = 346;
        }
        else if (x >= 369 && x <= 392)
        {
            finalX = 13;
            x2 = 369;
        }
        else if (x >= 392 && x <= 415)
        {
            finalX = 14;
            x2 = 392;
        }
        else if (x >= 415 && x <= 438)
        {
            finalX = 15;
            x2 = 415;
        }
        else if (x >= 438 && x <= 461)
        {
            finalX = 16;
            x2 = 438;
        }
        else if (x >= 461 && x <= 485)
        {
            finalX = 17;
            x2 = 461;
        }
        else if (x >= 485 && x <= 507)
        {
            finalX = 18;
            x2 = 485;
        }
        else if (x >= 507 && x <= 530)
        {
            finalX = 19;
            x2 = 507;
        }
        else if (x >= 530 && x <= 554)
        {
            finalX = 20;
            x2 = 530;
        }
        else if (x >= 554 && x <= 576)
        {
            finalX = 21;
            x2 = 554;
        }
        else if (x >= 576 && x <= 599)
        {
            finalX = 22;
            x2 = 576;
        }
        else if (x >= 599 && x <= 624)
        {
            finalX = 23;
            x2 = 599;
        }
        else if (x >= 624 && x <= 646)
        {
            finalX = 24;
            x2 = 624;
        }
        else if (x >= 646 && x <= 668)
        {
            finalX = 25;
            x2 = 646;
        }
        else if (x >= 668 && x <= 691)
        {
            finalX = 26;
            x2 = 668;
        }
        else if (x >= 691 && x <= 714)
        {
            finalX = 27;
            x2 = 691;
        }
        else if (x >= 714 && x <= 737)
        {
            finalX = 28;
            x2 = 714;
        }
        else if (x >= 737 && x <= 760)
        {
            finalX = 29;
            x2 = 737;
        }
        else if (x >= 760 && x <= 783)
        {
            finalX = 30;
            x2 = 760;
        }
        else if (x >= 783 && x <= 806)
        {
            finalX = 31;
            x2 = 783;
        }
        else if (x >= 806 && x <= 830)
        {
            finalX = 32;
            x2 = 806;
        }
        else if (x >= 830 && x <= 853)
        {
            finalX = 33;
            x2 = 830;
        }
        else if (x >= 853 && x <= 875)
        {
            finalX = 34;
            x2 = 853;
        }
        else if (x >= 875 && x <= 898)
        {
            finalX = 35;
            x2 = 875;
        }
        else if (x >= 898 && x <= 922)
        {
            finalX = 36;
            x2 = 898;
        }
        else if (x >= 922 && x <= 945)
        {
            finalX = 37;
            x2 = 922;
        }
        else if (x >= 945 && x <= 967)
        {
            finalX = 38;
            x2 = 945;
        }
        else if (x >= 967 && x <= 982)
        {
            finalX = 39;
            x2 = 967;
        }
    /************************************************/
    if (y >= 0 && y <= 36)
        {
            finalY = 0;
            pitch = 11;
            octave = 4;
        }
        else if (y >= 36 && y <= 72)
        {
            finalY = 36;
            pitch = 10;
            octave = 4;
        }
        else if (y >= 72 && y <= 108)
        {
            finalY = 72;
            pitch = 9;
            octave = 4;
        }
        else if (y >= 108 && y <= 144)
        {
            finalY = 108;
            pitch = 8;
            octave = 4;
        }
        else if (y >= 144 && y <= 180)
        {
            finalY = 144;
            pitch = 7;
            octave = 4;
        }
        else if (y >= 180 && y <= 216)
        {
            finalY = 180;
            pitch = 6;
            octave = 4;
        }
        else if (y >= 216 && y <= 251)
        {
            finalY = 216;
            pitch = 5;
            octave = 4;
        }
        else if (y >= 251 && y <= 289)
        {
            finalY = 251;
            pitch = 4;
            octave = 4;
        }
        else if (y >= 289 && y <= 325)
        {
            finalY = 289;
            pitch = 3;
            octave = 5;
        }
        else if (y >= 325 && y <= 359)
        {
            finalY = 325;
            pitch = 3;
            octave = 4;
        }
        else if (y >= 359 && y <= 395)
        {
            finalY = 359;
            pitch = 2;
            octave = 5;
        }
        else if (y >= 395 && y <= 432)
        {
            finalY =395;
            pitch = 2;
            octave = 4;
        }
        else if (y >= 432 && y <= 467)
        {
            finalY = 432;
            pitch = 1;
            octave = 5;
        }
        else if (y >= 467 && y <= 504)
        {
            finalY = 467;
            pitch = 1;
            octave = 4;
        }
        else if (y >= 504 && y <= 540)
        {
            finalY = 504;
            pitch = 0;
            octave = 5;
        }
        else if (y >= 540 && y <= 575)
        {
            finalY = 540;
            pitch = 0;
            octave = 4;
        }//본래 excel파일에서 이미지를 만들어와서, 간격이 동일할 것이라고 생각하고, 수열의 점화식과 같은 일반항을 세워 진행하였으나,
    //예상외로 간격마다 좌표의 규칙성이 조금씩 깨져서 사각형이 생기는 부분이 정확하지 않아, 위와 같이 범위를 아예 설정하여 그 좌표값을 받으면
    //알맞는 위치의 x,y좌표를 강제로 설정하여 그 부분에 사각형이 생기게 설정하고, 해당하는 pitch와 octave, Start값을 아예 설정하였습니다.
    /*************************************************************/
    if(LR==1)//왼쪽 마우스를 눌렀을 때,
    {
       QGraphicsRectItem *item =new QGraphicsRectItem(x2,finalY,91,35);//x2는 각각의 unit의 시작 부분입니다.이는 좌표값입니다. finalY는 각 음계의 왼쪽 위 꼭짓점 좌표값입니다.
        item->setBrush(QBrush(Qt::green));
        scene->addItem(item);
        items.push_back(item);//item 정보 저장.->삭제 과정을 위한 처리
        coordinates.push_back(QPointF(x2,finalY));//Scene에서의 좌표값 저장 ->삭제 과정을 위한 처리.

       melody->Put({static_cast<as4::model::Timestamp>(finalX),4,{pitch,octave}});//finalX는 해당하는 좌표의 Unit값입니다.

    }
    else if(LR==2)
    {
        if(items.size()==0)
            return;
        for(unsigned i=0; i<items.size();i++)
        {
            //int check;
            int index =-1;
            //check = x2==static_cast<int>(items[i]->x())? 1: 0;
            //qDebug()<<check<<x2<<items[0]->x();
            if(x2==static_cast<int>(coordinates[i].x())&&finalY==static_cast<int>(coordinates[i].y()))
            {
                index =i;
                items[index]->setPos(coordinates[index].x(),coordinates[index].y());
                if(x2==static_cast<int>(items[i]->x())&&finalY==static_cast<int>(items[i]->y()))
                {
                    scene->removeItem(items[i]);
                    melody->Remove(melody->find(finalX,4,pitch,octave));
                }
                items.erase(items.begin()+index);
                coordinates.erase(coordinates.begin()+index);
            }
        }//위와 같은 과정을 거친 이유는, item과 scene이 사용하는 좌표축이 각각 다르기 때문입니다. 위에 주석처리된 code를 해제하여 debug되는 값을 보면,
        //item의 좌표값은 원래 찍었던 좌표에 의해 설정된 값과 다르게 항상 (0,0)이 나옵니다. 이를 생성부분에서 setPos를 통해 설정하고자 하였으나,
        //그리 할 경우 사각형이 원치 않은곳이 그려져, 삭제할 때, 삭제하고자 하는 아이템의 정보가 일치하면 그 아이템의 위치를 변경하여 거기서 삭제하는 것입니다.
        //이는 엄연히 다른 위치로 이동하였다가 삭제하는것이나, 연산속도로 인해 사용자의 눈에는 자신이 누른 곳이 삭제되는 것처럼 보이고, 원하는 결과가 처리되므로
        // 문제가 발생하지 않습니다.
    }
}
void MainWindow::slot2(int x, int y, int LR)
{
    //qDebug()<<x<<y<<LR;
    int pitch=-1;
    int octave =-1;
    int x2 =-1;
    if (x >= 71 && x <= 93)
        {
            finalX = 0;
            x2 = 71;
        }
        else if (x >= 93 && x <= 117)
        {
            finalX = 1;
            x2 = 93;
        }
        else if (x >= 117 && x <= 140)
        {
            finalX = 2;
            x2 = 117;
        }
        else if (x >= 140 && x <= 163)
        {
            finalX = 3;
            x2 = 140;
        }
        else if (x >= 163 && x <= 186)
        {
            finalX = 4;
            x2 = 163;
        }
        else if (x >= 186 && x <= 209)
        {
            finalX = 5;
            x2 = 186;
        }
        else if (x >= 209 && x <= 232)
        {
            finalX = 6;
            x2 = 209;
        }
        else if (x >= 232 && x <= 254)
        {
            finalX = 7;
            x2 = 232;
        }
        else if (x >= 254 && x <= 278)
        {
            finalX = 8;
            x2 = 254;
        }
        else if (x >= 278 && x <= 301)
        {
            finalX = 9;
            x2 = 278;
        }
        else if (x >= 301 && x <= 323)
        {
            finalX = 10;
            x2 = 301;
        }
        else if (x >= 323 && x <= 346)
        {
            finalX = 11;
            x2 = 323;
        }
        else if (x >= 346 && x <= 369)
        {
            finalX = 12;
            x2 = 346;
        }
        else if (x >= 369 && x <= 392)
        {
            finalX = 13;
            x2 = 369;
        }
        else if (x >= 392 && x <= 415)
        {
            finalX = 14;
            x2 = 392;
        }
        else if (x >= 415 && x <= 438)
        {
            finalX = 15;
            x2 = 415;
        }
        else if (x >= 438 && x <= 461)
        {
            finalX = 16;
            x2 = 438;
        }
        else if (x >= 461 && x <= 485)
        {
            finalX = 17;
            x2 = 461;
        }
        else if (x >= 485 && x <= 507)
        {
            finalX = 18;
            x2 = 485;
        }
        else if (x >= 507 && x <= 530)
        {
            finalX = 19;
            x2 = 507;
        }
        else if (x >= 530 && x <= 554)
        {
            finalX = 20;
            x2 = 530;
        }
        else if (x >= 554 && x <= 576)
        {
            finalX = 21;
            x2 = 554;
        }
        else if (x >= 576 && x <= 599)
        {
            finalX = 22;
            x2 = 576;
        }
        else if (x >= 599 && x <= 624)
        {
            finalX = 23;
            x2 = 599;
        }
        else if (x >= 624 && x <= 646)
        {
            finalX = 24;
            x2 = 624;
        }
        else if (x >= 646 && x <= 668)
        {
            finalX = 25;
            x2 = 646;
        }
        else if (x >= 668 && x <= 691)
        {
            finalX = 26;
            x2 = 668;
        }
        else if (x >= 691 && x <= 714)
        {
            finalX = 27;
            x2 = 691;
        }
        else if (x >= 714 && x <= 737)
        {
            finalX = 28;
            x2 = 714;
        }
        else if (x >= 737 && x <= 760)
        {
            finalX = 29;
            x2 = 737;
        }
        else if (x >= 760 && x <= 783)
        {
            finalX = 30;
            x2 = 760;
        }
        else if (x >= 783 && x <= 806)
        {
            finalX = 31;
            x2 = 783;
        }
        else if (x >= 806 && x <= 830)
        {
            finalX = 32;
            x2 = 806;
        }
        else if (x >= 830 && x <= 853)
        {
            finalX = 33;
            x2 = 830;
        }
        else if (x >= 853 && x <= 875)
        {
            finalX = 34;
            x2 = 853;
        }
        else if (x >= 875 && x <= 898)
        {
            finalX = 35;
            x2 = 875;
        }
        else if (x >= 898 && x <= 922)
        {
            finalX = 36;
            x2 = 898;
        }
        else if (x >= 922 && x <= 945)
        {
            finalX = 37;
            x2 = 922;
        }
        else if (x >= 945 && x <= 967)
        {
            finalX = 38;
            x2 = 945;
        }
        else if (x >= 967 && x <= 982)
        {
            finalX = 39;
            x2 = 967;
        }
    /************************************************/
    if (y >= 0 && y <= 36)
        {
            finalY = 0;
            pitch = 11;
            octave = 4;
        }
        else if (y >= 36 && y <= 72)
        {
            finalY = 36;
            pitch = 10;
            octave = 4;
        }
        else if (y >= 72 && y <= 108)
        {
            finalY = 72;
            pitch = 9;
            octave = 4;
        }
        else if (y >= 108 && y <= 144)
        {
            finalY = 108;
            pitch = 8;
            octave = 4;
        }
        else if (y >= 144 && y <= 180)
        {
            finalY = 144;
            pitch = 7;
            octave = 4;
        }
        else if (y >= 180 && y <= 216)
        {
            finalY = 180;
            pitch = 6;
            octave = 4;
        }
        else if (y >= 216 && y <= 251)
        {
            finalY = 216;
            pitch = 5;
            octave = 4;
        }
        else if (y >= 251 && y <= 289)
        {
            finalY = 251;
            pitch = 4;
            octave = 4;
        }
        else if (y >= 289 && y <= 325)
        {
            finalY = 289;
            pitch = 3;
            octave = 5;
        }
        else if (y >= 325 && y <= 359)
        {
            finalY = 325;
            pitch = 3;
            octave = 4;
        }
        else if (y >= 359 && y <= 395)
        {
            finalY = 359;
            pitch = 2;
            octave = 5;
        }
        else if (y >= 395 && y <= 432)
        {
            finalY =395;
            pitch = 2;
            octave = 4;
        }
        else if (y >= 432 && y <= 467)
        {
            finalY = 432;
            pitch = 1;
            octave = 5;
        }
        else if (y >= 467 && y <= 504)
        {
            finalY = 467;
            pitch = 1;
            octave = 4;
        }
        else if (y >= 504 && y <= 540)
        {
            finalY = 504;
            pitch = 0;
            octave = 5;
        }
        else if (y >= 540 && y <= 575)
        {
            finalY = 540;
            pitch = 0;
            octave = 4;
        }
    /*************************************************************/
    if(LR==1)
    {
       QGraphicsRectItem *item =new QGraphicsRectItem(x2,finalY,91,35);
        item->setBrush(QBrush(Qt::green));
        scene2->addItem(item);
        //item->setPos(x2,finalY);
        items_drum.push_back(item);
        coordinates_drum.push_back(QPointF(x2,finalY));

       drum->Put({static_cast<as4::model::Timestamp>(finalX),4,{pitch,octave}});

    }
    else if(LR==2)
    {
        if(items_drum.size()==0)
            return;
        for(unsigned i=0; i<items_drum.size();i++)
        {
           // int check;
            int index =-1;
           // check = x2==static_cast<int>(items[i]->x())? 1: 0;
           // qDebug()<<check<<x2<<items[0]->x();
            if(x2==static_cast<int>(coordinates_drum[i].x())&&finalY==static_cast<int>(coordinates_drum[i].y()))
            {
                index =i;
                items_drum[index]->setPos(coordinates_drum[index].x(),coordinates_drum[index].y());
                if(x2==static_cast<int>(items_drum[i]->x())&&finalY==static_cast<int>(items_drum[i]->y()))
                {
                    scene2->removeItem(items_drum[i]);
                    drum->Remove(drum->find(finalX,4,pitch,octave));
                }
                items_drum.erase(items_drum.begin()+index);
                coordinates_drum.erase(coordinates_drum.begin()+index);
            }
        }
    }
}
//Drum의 경우이며 Melody와 전체적인 과정은 동일합니다.
void customscene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
   // qDebug()<<"here";


       if(event->buttons()==Qt::LeftButton)
        {
        x=event->scenePos().x();
        y=event->scenePos().y();
        LR=1;
        }
       else if(event->buttons()==Qt::RightButton)
       {
           x=event->scenePos().x();
           y=event->scenePos().y();
           LR=2;
       }
     emit clicked(x,y,LR);//MouseEvent의 좌표값과 왼쪽 마우스인지, 오른쪽 마우스 버튼인지를 결정하여 이를 signal로 emit합니다.
}


