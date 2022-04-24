#include "extra.h"


namespace Sumin
{
ExtraCourse::ExtraCourse()
{
}
ExtraCourse::~ExtraCourse(){}
void ExtraCourse::setInfo(int grade,int sem_1,int sem_2,QString name,QString Role)
{
    Yourgrade =grade;
    semester[0] = sem_1;
    semester[1]= sem_2;
    ActivityName = name;
    YourSector = Role;
}
QString ExtraCourse::GetRole()
{
    return YourSector;
}
Club::Club()
{
}
QString ExtraCourse::GetName()
{
    return ActivityName;
}
int ExtraCourse::semester1()
{
    return semester[0];
}
int ExtraCourse::semester2()
{
    return semester[1];
}
void Club::setInfo(int grade,int sem_1,int sem_2,QString name,QString Role)
{
    Yourgrade =grade;
    semester[0] = sem_1;
    semester[1]= sem_2;
    ActivityName = name;
    YourRole = Role;
}
QString Club::GetRole()
{
    return YourRole;
}

Committee:: Committee() {

}
void Committee::setInfo(int grade,int sem_1,int sem_2,QString name,QString Role)
{
    Yourgrade =grade;
    semester[0] = sem_1;
    semester[1]= sem_2;
    ActivityName = name;
    YourRole = Role;
}
QString Committee::GetRole()
{
    return YourRole;
}
}

