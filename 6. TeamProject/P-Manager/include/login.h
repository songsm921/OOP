#ifndef LOGIN_H
#define LOGIN_H

#include "member.h"
#include "access.h"
#include <QWidget>

namespace Ui {
class Login;
}

namespace Minho
{


class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    string get_id() {return id;}
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_toolBox_currentChanged(int index);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

signals:
    void send_id(string);

private:
    QGraphicsScene *scene, *scene2;
    QGraphicsView* graphicsView;
    Ui::Login *ui;
    Access* access;
    string id;
};

}

#endif // LOGIN_H
