#ifndef WIDGETS_MAINWINDOW_H
#define WIDGETS_MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include "committee.h"
#include "municipality.h"
#include "extra.h"
#include "coursewindow.h"
#include "login.h"
#include "member.h"
#include "portfolio.h"
#include "extra_widget.h"
#include "club.h"
#include <QMenu>
#include <QMenuBar>
#include <QMouseEvent>
#include <QAction>
#include <QActionEvent>

namespace Ui{
class MainWindow;
}

class MainWindowWidget : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindowWidget(QMainWindow* parent =nullptr);
    ~MainWindowWidget();
private:
    string name;
    Ui::MainWindow *ui;
    Junhyeong::Committee* committee;
    Sumin::Municipality* municipality;
    Sumin::EXTRA* extra;
    Sumin::CLUB* club;
    Sumin::Portfolio* portfolio;
    Minho::CourseWindow* course;

public slots:
    void setting(string _name);
    void open1();
    void open2();
    void open3();
    void open4();
    void open5();
    void open6();


};


#endif
