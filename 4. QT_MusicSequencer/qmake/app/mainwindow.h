#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>
#include <QDebug>
#include "player.h"
#include "../../include/model/note.h"
namespace Ui {
class MainWindow;
}

class customscene : public QGraphicsScene{
Q_OBJECT
protected:
    QGraphicsScene* scene;
public:
    customscene() : x(0),y(0),LR(0){}
    void mousePressEvent(QGraphicsSceneMouseEvent *event);//Mouse 좌표 및 Event Method
signals:
    void clicked(int x_m, int y_m, int LR_m);//좌표 정보를 보내는 Signal
private:
    int x,y;
    int LR;//L=1 R=2
};//MouseEvent와 그 event에 따른 scene을 출력하기 위해 Custom Scene Class를 하나 작성하였으며, 이는 QGraphicsScene을 상속받습니다. 그렇기 때문에 QGraphicsScene에서 Protected Method를 사용할 수 있습니다.

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void Play_Melody();//melody play버튼을 눌렀을 때의 Slot
    void Play_Drum();//Drum play버튼을 눌렀을 때의 Slot
public slots:
    void slot1(int x, int y, int LR);//Melody Tab에서의 좌표 정보를 받는 Slot
    void slot2(int x, int y, int LR);//Drum Tab에서의 좌표 정보를 받는 Slot

private:
    Ui::MainWindow *ui;
   app::source::Player *player_m;//Melody Player
   app::source::Player *player_d;//Drum Player
   as4::model::ISeq *melody;//Melody Track
   as4::model::ISeq *drum;//Drum Track
   customscene *scene;//Melody Tab의 scene pointer
   customscene *scene2;//Drum Tab의 scene pointer
   std::vector<QGraphicsRectItem*> items;//mouse로 클릭하여 생성된 사각형의 정보를 담아두는 Vector
   std::vector<QPointF> coordinates;//item을 삭제할 때 발생하는 문제를 해결하기 위해 Scene에서의 Item의 좌표정보를 담아두는 Vector
   std::vector<QGraphicsRectItem*> items_drum;//mouse로 클릭하여 생성된 사각형의 정보를 담아두는 Vector
   std::vector<QPointF> coordinates_drum;//item을 삭제할 때 발생하는 문제를 해결하기 위해 Scene에서의 Item의 좌표정보를 담아두는 Vector
   int finalX,finalY;//좌표를 받아 처리하는 과정 중 필요한 변수



};

#endif // MAINWINDOW_H
