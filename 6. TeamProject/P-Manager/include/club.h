#ifndef FORM6_H
#define FORM6_H

#include <QWidget>
#include "extra.h"
#include <QObject>
#include <QTableWidgetItem>
#include <QCheckBox>

namespace Ui {
class club;
}
namespace Sumin {
class CLUB : public QWidget
{
    Q_OBJECT

public:
    explicit CLUB(std::string, QWidget *parent = nullptr);
    ~CLUB();
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
   std::string name;
    Ui::club *ui;
    Sumin::ExtraCourse *ptr[8];
    Sumin::ExtraCourse *ptr_2[8];
    Sumin::ExtraCourse *ptr_3[8];
    Sumin::ExtraCourse *ptr_4[8];
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
#endif // FORM3_H
