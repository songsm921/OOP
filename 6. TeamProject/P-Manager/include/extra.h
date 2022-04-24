#ifndef _7_H
#define _7_H

#include <istream>
#include <ostream>
#include <QString>
#include <QObject>
#include <string>


namespace Sumin
{
class ExtraCourse : public QObject{
    Q_OBJECT
public:
    ExtraCourse();
    virtual ~ExtraCourse();
    virtual void setInfo(int grade,int sem_1,int sem_2,QString name,QString Role);
    QString GetName();
    int semester1();
    int semester2();
    virtual QString GetRole();
    std::string get_user_name() {return name;}

protected:
    int Yourgrade;
    int semester[2];
    std::string name;
    QString ActivityName;
    QString YourSector;
};

class Club:public ExtraCourse{

public:
      Club();
      //~Club();
      void setInfo(int grade,int sem_1,int sem_2,QString name,QString Role) override;
      QString GetRole() override;
private:
    QString YourRole;
};

class Committee:public ExtraCourse{
public:
    Committee();
    void setInfo(int grade,int sem_1,int sem_2,QString name,QString Role) override;
    QString GetRole() override;
private:

    QString YourRole;
};

}

#endif
