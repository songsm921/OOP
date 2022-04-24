#ifndef _8_H
#define _8_H

#include <istream>
#include <ostream>
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "extra.h"
#include <string>

namespace Ui{
class municipality;
}
namespace Sumin
{

class Municipality : public QWidget {
    Q_OBJECT
public:
    explicit Municipality(std::string,QWidget* parent = nullptr);
    ~Municipality(){
    }
private slots:
    void Tab_1_checkbox(int arg);
    void Tab_2_checkbox(int arg);
    void Tab_3_checkbox(int arg);
    void Tab_4_checkbox(int arg);

    void Tab_1_checkbox_2(int arg1);
    void Tab_2_checkbox_2(int arg1);
    void Tab_3_checkbox_2(int arg1);
    void Tab_4_checkbox_2(int arg1);

    void Tab_1_Apply();
    void Tab_2_Apply();
    void Tab_3_Apply();
    void Tab_4_Apply();

    void Tab_1_Save();
    void load();

private:
    QFont font1;
    Ui::municipality *ui;
    Sumin::ExtraCourse *ptr[8];
    Sumin::ExtraCourse *ptr_2[8];
    Sumin::ExtraCourse *ptr_3[8];
    Sumin::ExtraCourse *ptr_4[8];
    std::string name;
    int sem1,sem2;
    int sem2_1,sem2_2,sem3_1,sem3_2,sem4_1,sem4_2;
    int index1;
    int index2;
    int index3;
    int index2_1;
    int index2_2;
    int index2_3;
    int index3_1;
    int index3_2;
    int index3_3;
    int index4_1;
    int index4_2;
    int index4_3;
};
}

#endif
