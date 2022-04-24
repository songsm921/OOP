#include "widgets/mainwindow.h"
#include "ui_mainwindow.h"


MainWindowWidget::MainWindowWidget(QMainWindow* parent) :
    QMainWindow(parent), ui(new Ui::MainWindow())

{
    ui->setupUi(this);
    this->takeCentralWidget();
}

MainWindowWidget::~MainWindowWidget() {
    delete committee;
    delete municipality;
    delete extra;
    delete club;
    delete portfolio;
    delete course;
}

void MainWindowWidget::setting(string _name) {
    name = _name;
}

void MainWindowWidget::open1() {
    course = new Minho::CourseWindow();
    this->hide();
    this->takeCentralWidget();
    this->setCentralWidget(course);
    this->show();
}

void MainWindowWidget::open2() {
    this->hide();
    municipality = new Sumin::Municipality(name);
    this->takeCentralWidget();
    this->setCentralWidget(municipality);
    this->show();
}

void MainWindowWidget::open3() {
    this->hide();
    club= new Sumin::CLUB(name);
    this->takeCentralWidget();
    this->setCentralWidget(club);
    this->show();
}

void MainWindowWidget::open4() {
    this->hide();
    extra = new Sumin::EXTRA(name);
    this->takeCentralWidget();
    this->setCentralWidget(extra);
    this->show();
}

void MainWindowWidget::open5() {
    this->hide();
    committee = new Junhyeong::Committee(name);
    this->takeCentralWidget();
    this->setCentralWidget(committee);
    this->show();
}


void MainWindowWidget::open6() {
    this->hide();
    portfolio = new Sumin::Portfolio(name);
    this->takeCentralWidget();
    this->setCentralWidget(portfolio);
    this->show();
}
