#ifndef PLAYER_H
#define PLAYER_H
#include <QObject>
#include<QTimer>
#include <QVector>
#include"../../include/model/seq.h"
#include"../../include/model/time.h"
#include <QMediaPlayer>

namespace app::source{
class Player:public QObject{
    Q_OBJECT
  public:
    virtual ~Player() =default;
    virtual void Start() = 0;
    virtual void Init() = 0;
    virtual void Play(int pitch_m,int octave_m)=0;
    virtual void GetInfo(const as4::model::ISeq &source) = 0;//Player는 MelodyPlayer와 DrumPlayer의 Base Class이면 추상클래스입니다.
};
class MelodyPlayer:public Player{
    Q_OBJECT
public:
    MelodyPlayer();
  ~MelodyPlayer() override;
  void Start() override;//재생, 정지의 과정을 시작하는 method입니다.
  void Init() override;//timer를 시작하는 함수입니다. 여기서 start에서는 처리할 수 없는 0에서 바로 시작하는 노트를 처리합니다.
  void GetInfo(const as4::model::ISeq &source) override;//ISeq로 부터 재생에 필요한 음원에 대한 정보를 받아옵니다.
  void Play(int pitch_m,int octave_m) override;//Octave, Pitch를 받아 음원을 처리합니다.
public slots:
  void Check();//타이머에 따라 시간축을 담당하는 LineX의 Index를 증가시킵니다.
private:
  int size;
  int index;
  QMediaPlayer *player;
  QTimer *interval;//음원의 재생,정지를 위해 timeout의 시그널을 보내주는 timer입니다.
  QVector<int> pitch_m;
  QVector<int> octave_m;
  QVector<int> LineStart;
  QVector<int> LineStop;//위 벡터부터 차례로, pitch를 담고 있는, octave를 담고있는,음원의 시작 unit을 담고있는, 음원의 시작 unit과 음원의 지속 unit을 담고 있는 벡터입니다.
  QVector<int> LineX;//시간축을 담당하는 벡터입니다. 1unit이 0.125sec이므로 0.125초 마다 다음 unit의 시작 index로 증가합니다.
  bool first;//음원이 처음 재생되고, 또 한번 재생될 때, 음원의 정보를 담고 있는 Vector와 index를 초기화 하기 위한 변수입니다.
};
class DrumPlayer:public Player{
    Q_OBJECT
public:
    DrumPlayer();
  ~DrumPlayer() override;
  void Start() override;
  void Init() override;
  void GetInfo(const as4::model::ISeq &source) override;
  void Play(int pitch_m,int octave_m) override;
public slots:
  void Check();
private:
  int size;
  int index;
  QMediaPlayer *player;
  QTimer *interval;
  QVector<int> pitch_m;
  QVector<int> octave_m;
  QVector<int> LineStart;
  QVector<int> LineStop;
  QVector<int> LineX;
  bool first;//전체적인 Concept은 MelodyPlayer와 같습니다. 다른 부분은 Melody와 다르게 정지가 없다는 점과, 음원 소스파일이 drum이라는 것입니다.
};
}
#endif // PLAYER_H
