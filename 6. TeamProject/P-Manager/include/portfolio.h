#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include <QWidget>
#include <QTextEdit>
#include <QLine>
#include <QPixmap>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

namespace Ui {
class Portfolio;
}

namespace Sumin{
class Portfolio : public QWidget
{
    Q_OBJECT

public:
    explicit Portfolio(std::string, QWidget *parent = nullptr);
    void addCourse();
    void addClub();
    void addCommittee();
    void addReady();
    void addExtra();
    ~Portfolio();


private:
    QGraphicsScene *scene;
    std::string name;
    Ui::Portfolio *ui;
    QTextEdit* ptr[20];
    QTextEdit *course2[20];
    QTextEdit *course3[20];
    QTextEdit *course4[20];
    QTextEdit* ptr_2[2];
    QTextEdit* club2[2];
    QTextEdit* club3[2];
    QTextEdit* club4[2];
    QTextEdit* mani1[2];
    QTextEdit* mani2[2];
    QTextEdit* mani3[2];
    QTextEdit* mani4[2];
    QTextEdit* extra1[4];
    QTextEdit* extra2[4];
    QTextEdit* extra3[4];
    QTextEdit* extra4[4];
    QTextEdit* ready1[4];
    QTextEdit* ready2[4];
    QTextEdit* ready3[4];
    QTextEdit* ready4[4];
    int linecount[4];

};
}
#endif // PORTFOLIO_H
