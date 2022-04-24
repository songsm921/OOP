#ifndef _5_H
#define _5_H

#include <istream>
#include <ostream>
#include <QWidget>
#include <qstring.h>
#include "member.h"
#include <QObject>

namespace Ui{
class course;
}
namespace Minho
{

class CourseWindow : public QWidget{
    Q_OBJECT
public:
    explicit CourseWindow(QWidget* parent = nullptr);
    ~CourseWindow(){}

private slots:
    void on_pushButton_clicked1();

    void on_checkBox_stateChanged(int arg1);


private:
    Ui::course* ui;
    QFont font1;
};

}

#endif
