#include "player.h"
#include <QDebug>

namespace app::source{
MelodyPlayer::MelodyPlayer()
{
    for(int i=0;i<41;i++)
   {
        LineX.push_back(i);
    }//unit은 0과 양의 정수로 표현되므로, 현재 구현하여야 하는 총 unit은 40 unit이므로 41까지 x축을 설정하였습니다.
    player = new QMediaPlayer[16];//음원을 재생하는 player객체, QSoundEffect는 play가 작동하지 않아 QMediaPlayer를 사용하였습니다.
    interval = new QTimer;
    QObject::connect(interval,SIGNAL(timeout()),this,SLOT(Check()));//설정한 interval마다 timeout 시그널을 보냅니다.
    interval->setInterval(125);//0.125=1unit설정
    size = 0;
    first =true;
}
MelodyPlayer::~MelodyPlayer()
{
    delete interval;
}
void MelodyPlayer::GetInfo(const as4::model::ISeq &source)
{
    //qDebug()<<"info";
   if(first==true)
        first=false;
    else if(first==false)
    {
        LineStart.clear();
        LineStop.clear();
        pitch_m.clear();
        octave_m.clear();
        index=0;
    }//Header File에서 설명한 초기화 과정.
    size = source.Getsize();//0unit에서 시작하는 음원을 처리하기 위해 미리 size를 받아놓습니다. 이를 처리하는 과정은 Init()에 있습니다.
    for(int k=0;k<source.Getsize();k++)
    {
        LineStart.push_back(source.Enter1(k));
        LineStop.push_back(source.Enter1(k)+source.Enter2(k));
        pitch_m.push_back(source.Enter3(k));
        octave_m.push_back(source.Enter4(k));
    }//음원 정보 입력.
}
void MelodyPlayer::Check()
{
    index++;//결국 이 함수는 1unit 부터 시작하는 음원 밖에 재생 및 정지 할 수 있습니다.
    if(index>=41)
        interval->stop();//41unit 부터는 구현하고자 하는 범위를 벗어나므로, 재생을 담당하는 타이머를 정지합니다.
    else
        Start();
}
void MelodyPlayer::Init()
{
    if(first==true)
        interval->start();
    else if(first==false)
    {
       //qDebug()<<"restart";
        interval->stop();
        interval->start();
    }
    for(int j = 0;j<size;j++)
    {
        if(LineStart[j]==0)
        {
            Play(pitch_m[j],octave_m[j]);
        }
    }//이곳에서 0unit 시작 음원을 처리합니다.

}
void MelodyPlayer::Start()
{
    for(int count=0;count<size;count++)
    {
        if(LineStart[count]==LineX[index])
        {
            Play(pitch_m[count],octave_m[count]);
        }
        if(LineStop[count]==LineX[index])
        {
          if(pitch_m[count]==0)
          {
              switch(octave_m[count])
              {case 4:
                  player[0].stop();
                  break;
              case 5:
                  player[1].stop();
              }
          }
          else if(pitch_m[count]==1)
          {
              switch(octave_m[count])
              {
              case 4:
                  player[2].stop();
                  break;
              case 5:
                  player[3].stop();
              }
          }
          else if(pitch_m[count]==2)
          {
              switch(octave_m[count])
              {
              case 4:
                  player[4].stop();
                  break;
              case 5:
                  player[5].stop();
              }
          }
         else if(pitch_m[count]==3)
          {
              switch(octave_m[count])
              {case 4:
                  player[6].stop();
                  break;
              case 5:
                  player[7].stop();
              }
          }
         else if(pitch_m[count]==4)
          {
              player[8].stop();
          }
          else if(pitch_m[count]==5)
           {
               player[9].stop();
           }
          else if(pitch_m[count]==6)
           {
               player[10].stop();
           }
          else if(pitch_m[count]==7)
           {
               player[11].stop();
           }
          else if(pitch_m[count]==8)
           {
               player[12].stop();
           }
          else if(pitch_m[count]==9)
           {
               player[13].stop();
           }
          else if(pitch_m[count]==10)
           {
               player[14].stop();
           }
          else if(pitch_m[count]==11)
           {
               player[15].stop();
           }
        }
    }
}//음원을 재생하는 방법은 아래와 같습니다.
//1. For문을 사용하여 현재 LineX에 음원의 시작이 일치하면 그 음원을 재생, 마찬가지로 종료하고자 음원이 존재한다면 그 음원 정지.
//2. For문의 연산속도가 상당히 빨라 이는 화음처리까지 가능한 상태입니다.
void MelodyPlayer::Play(int pitch_m, int octave_m)
{
   //qDebug()<<"playstart";
    int pitch=pitch_m;
    int octave=octave_m;
    if(pitch==0)
    {

        switch(octave)
        {
        case 4:
        {
            player[0].setMedia(QUrl("qrc:/melody/audio/melody/0_4.wav"));
            player[0].play();
            break;
        }
        case 5:
        {
            player[1].setMedia(QUrl("qrc:/melody/audio/melody/0_5.wav"));
            player[1].play();
            break;
        }
        }
    }
    else if(pitch==1)
    {
        switch(octave)
        {
        case 4:
        {
            player[2].setMedia(QUrl("qrc:/melody/audio/melody1_4.wav"));
            player[2].play();
            break;
        }
        case 5:
        {
            player[3].setMedia(QUrl("qrc:/melody/audio/melody/1_5.wav"));
            player[3].play();
        }
        }
    }
    else if(pitch==2)
    {
        switch(octave)
       {
        case 4:
        {
            player[4].setMedia(QUrl("qrc:/melody/audio/melody/2_4.wav"));
            player[4].play();
            break;
        }
        case 5:
        {
            player[5].setMedia(QUrl("qrc:/melody/audio/melody/2_5.wav"));
            player[5].play();
            break;
        }
        }
    }
    else if(pitch==3)
    {
        switch(octave)
       {
        case 4:
        {
            player[6].setMedia(QUrl("qrc:/melody/audio/melody/3_4.wav"));
            player[6].play();
            break;
        }
        case 5:
        {
            player[7].setMedia(QUrl("qrc:/melody/audio/melody/3_5.wav"));
            player[7].play();
        }
        }
    }
    else if(pitch==4)
    {
        player[8].setMedia(QUrl("qrc:/melody/audio/melody/4_4.wav"));
        player[8].play();
    }
    else if(pitch==5)
    {
        player[9].setMedia(QUrl("qrc:/melody/audio/melody/5_4.wav"));
        player[9].play();
    }
    else if(pitch==6)
    {
        player[10].setMedia(QUrl("qrc:/melody/audio/melody/6_4.wav"));
        player[10].play();
    }
    else if(pitch==7)
    {
        player[11].setMedia(QUrl("qrc:/melody/audio/melody/7_4.wav"));
        player[11].play();
    }
    else if(pitch==8)
    {
        player[12].setMedia(QUrl("qrc:/melody/audio/melody/8_4.wav"));
        player[12].play();

    }
    else if(pitch==9)
    {
        player[13].setMedia(QUrl("qrc:/melody/audio/melody/9_4.wav"));
        player[13].play();
    }
    else if(pitch==10)
    {
        player[14].setMedia(QUrl("qrc:/melody/audio/melody/10_4.wav"));
        player[14].play();
    }
    else if(pitch==11)
    {
        player[15].setMedia(QUrl("qrc:/melody/audio/melody/11_4.wav"));
        player[15].play();
    }
}//Start()에서 받아온 정보로 음원을 재생합니다.
/***************************************************************************/
DrumPlayer::DrumPlayer()
{
    for(int i=0;i<41;i++)
   {
        LineX.push_back(i);
    }
    player = new QMediaPlayer[16];
    interval = new QTimer;
    QObject::connect(interval,SIGNAL(timeout()),this,SLOT(Check()));
    interval->setInterval(125);
    index=0;
    size = 0;
}
DrumPlayer::~DrumPlayer()
{
    delete interval;
}
void DrumPlayer::GetInfo(const as4::model::ISeq &source)
{
    if(first==true)
         first=false;
     else if(first==false)
     {
         LineStart.clear();
         LineStop.clear();
         pitch_m.clear();
         octave_m.clear();
         index=0;
     }
    size = source.Getsize();
    for(int k=0;k<source.Getsize();k++)
    {
        LineStart.push_back(source.Enter1(k));
        LineStop.push_back(source.Enter1(k)+source.Enter2(k));
        pitch_m.push_back(source.Enter3(k));
        octave_m.push_back(source.Enter4(k));
    }
}
void DrumPlayer::Check()
{
    index++;
    if(index>=41)
        interval->stop();
    else
        Start();
}
void DrumPlayer::Init()
{
    if(first==true)
        interval->start();
    else if(first==false)
    {
        qDebug()<<"restart";
        interval->stop();
        interval->start();
    }
    for(int j = 0;j<size;j++)
    {
        if(LineStart[j]==0)
        {
            Play(pitch_m[j],octave_m[j]);
        }
    }
}
void DrumPlayer::Start()
{
    for(int count=0;count<size;count++)
    {
        if(LineStart[count]==LineX[index])
        {
            Play(pitch_m[count],octave_m[count]);
        }
    }
}//Drum은 정지 부분이 존재하지 않습니다.
void DrumPlayer::Play(int pitch_m, int octave_m)
{
    qDebug()<<"playstart";
    int pitch=pitch_m;
    int octave=octave_m;
    if(pitch==0)
    {
        switch(octave)
        {
        case 4:
        {
            player[0].setMedia(QUrl("qrc:/melody/audio/drum/0_4.wav"));
            player[0].play();
            break;
        }
        case 5:
        {
            player[1].setMedia(QUrl("qrc:/melody/audio/drum/0_5.wav"));
            player[1].play();
            break;
        }
        }
    }
    else if(pitch==1)
    {
        switch(octave)
        {
        case 4:
        {
            player[2].setMedia(QUrl("qrc:/melody/audio/drum/1_4.wav"));
            player[2].play();
            break;
        }
        case 5:
        {
            player[3].setMedia(QUrl("qrc:/melody/audio/drum/1_5.wav"));
            player[3].play();
        }
        }
    }
    else if(pitch==2)
    {
        switch(octave)
       {
        case 4:
        {
            player[4].setMedia(QUrl("qrc:/melody/audio/drum/2_4.wav"));
            player[4].play();
            break;
        }
        case 5:
        {
            player[5].setMedia(QUrl("qrc:/melody/audio/drum/2_5.wav"));
            player[5].play();
            break;
        }
        }
    }
    else if(pitch==3)
    {
        switch(octave)
       {
        case 4:
        {
            player[6].setMedia(QUrl("qrc:/melody/audio/drum/3_4.wav"));
            player[6].play();
            break;
        }
        case 5:
        {
            player[7].setMedia(QUrl("qrc:/melody/audio/drum/3_5.wav"));
            player[7].play();
        }
        }
    }
    else if(pitch==4)
    {
        player[8].setMedia(QUrl("qrc:/melody/audio/drum/4_4.wav"));
        player[8].play();
    }
    else if(pitch==5)
    {
        player[9].setMedia(QUrl("qrc:/melody/audio/drum/5_4.wav"));
        player[9].play();
    }
    else if(pitch==6)
    {
        player[10].setMedia(QUrl("qrc:/melody/audio/drum/6_4.wav"));
        player[10].play();
    }
    else if(pitch==7)
    {
        player[11].setMedia(QUrl("qrc:/melody/audio/drum/7_4.wav"));
        player[11].play();
    }
    else if(pitch==8)
    {
        player[12].setMedia(QUrl("qrc:/melody/audio/drum/8_4.wav"));
        player[12].play();
    }
    else if(pitch==9)
    {
        player[13].setMedia(QUrl("qrc:/melody/audio/drum/9_4.wav"));
        player[13].play();
    }
    else if(pitch==10)
    {
        player[14].setMedia(QUrl("qrc:/melody/audio/drum/10_4.wav"));
        player[14].play();
    }
    else if(pitch==11)
    {
        player[15].setMedia(QUrl("qrc:/melody/audio/drum/11_4.wav"));
        player[15].play();
    }

}
//DrumPlayer 또한 MelodyPlayer의 코드 Concept은 동일합니다.





}
