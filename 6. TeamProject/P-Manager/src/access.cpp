#include "access.h"
#include "ui_access.h"

namespace Minho{
Access::Access(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Access)
{
    ui->setupUi(this);
	QPixmap ready(":/image/image/ready.jpg");
	QGraphicsScene *scene = new QGraphicsScene();
	QGraphicsPixmapItem* item = new QGraphicsPixmapItem(ready);
	scene->addItem(item);
	graphicsView = new QGraphicsView(scene, this);
    graphicsView->setGeometry(QRect(250, 120, 520, 380));
	graphicsView->show();

}

Access::~Access()
{
    delete ui;
}

void Access::on_pushButton_clicked()
{
    emit open_1();
}

void Minho::Access::on_pushButton_2_clicked()
{
	emit open_2();
}

void Minho::Access::on_pushButton_3_clicked()
{
	emit open_3();
}

void Minho::Access::on_pushButton_4_clicked()
{
	emit open_4();
}

void Minho::Access::on_pushButton_5_clicked()
{
	emit open_5();
}

void Minho::Access::on_pushButton_6_clicked()
{
	emit open_6();
}

void Access::on_pushButton_8_clicked()
{
    mc.Unsubscribe(name,mc.get_logged_in_member()->get_pw());
    this->close();
}

void Access::open_access(string _name) {
    name = _name;
    ui->label_2->setText(QString::fromStdString(name));
    this->show();
    emit main_window(name);
}
}
