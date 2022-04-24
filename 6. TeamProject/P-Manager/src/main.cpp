#include <QApplication>

#include "widgets/mainwindow.h"
#include "committee.h"
#include "coursewindow.h"
#include "municipality.h"
#include "extra.h"
#include "login.h"
#include "extra_widget.h"
#include "club.h"


// Entry point of our application
int main(int argc, char **argv)
{
    QApplication app(argc, argv);


    MainWindowWidget mainWindow;
    Minho::Login login;
    Minho::Access access;
    QObject::connect(&login,SIGNAL(send_id(string)),&access,SLOT(open_access(string)));
    QObject::connect(&access,SIGNAL(main_window(string)), &mainWindow,SLOT(setting(string)));
    QObject::connect(&access,SIGNAL(open_1()), &mainWindow,SLOT(open1()));
    QObject::connect(&access,SIGNAL(open_2()), &mainWindow,SLOT(open2()));
    QObject::connect(&access,SIGNAL(open_3()), &mainWindow,SLOT(open3()));
    QObject::connect(&access,SIGNAL(open_4()), &mainWindow,SLOT(open4()));
    QObject::connect(&access,SIGNAL(open_5()), &mainWindow,SLOT(open5()));
    QObject::connect(&access,SIGNAL(open_6()), &mainWindow,SLOT(open6()));
    login.show();

    return app.exec();
}
