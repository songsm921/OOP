#ifndef ACCESS_H
#define ACCESS_H

#include <QWidget>
#include "coursewindow.h"
#include <QPixmap>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

namespace Ui {
class Access;
}

namespace Minho{
class Access : public QWidget
{
    Q_OBJECT

public:
    explicit Access(QWidget *parent = nullptr);
    ~Access();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_8_clicked();
    void open_access(string _name);

signals:
    void open_1();
    void open_2();
    void open_3();
    void open_4();
    void open_5();
    void open_6();
    void main_window(string _name);


private:
    string name;
    QGraphicsView* graphicsView;
    Ui::Access *ui;
    Minho::CourseWindow *cw;
};
}
#endif // ACCESS_H
