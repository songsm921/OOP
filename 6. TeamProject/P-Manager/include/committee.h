#ifndef COMMITTEE_H
#define COMMITTEE_H

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QObject>
#include <QPushButton>
#include <QFrame>
#include <string>
#include <QString>
#include <fstream>
#include <istream>
#include <ostream>
#include <iostream>
#include <sstream>
#include <QDebug>


using namespace std;

namespace Ui{
class committee;
}

namespace Junhyeong
{
class Committee : public QWidget {
    Q_OBJECT
public:
    explicit Committee(string, QWidget* parent=nullptr);
    ~Committee();
    void role(QWidget* widget, QTextEdit* textEdit, QLineEdit* lineEdit, QPushButton* pushButton);
    void DoTask();
private slots:
    void hide();
    void save_str1();
    void role11();
    void role12();
    void role13();
    void role14();
    void role15();
    void role16();
    void role17();
    void role18();
    void role21();
    void role22();
    void role23();
    void role24();
    void role25();
    void role26();
    void role27();
    void role28();
    void role31();
    void role32();
    void role33();
    void role34();
    void role35();
    void role36();
    void role37();
    void role38();
    void role41();
    void role42();
    void role43();
    void role44();
    void role45();
    void role46();
    void role47();
    void role48();

    void on_pushButton_7_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_32_clicked();

    void on_pushButton_50_clicked();

    void on_pushButton_51_clicked();

    void on_pushButton_52_clicked();

    void on_pushButton_53_clicked();

    void on_checkBox_11_stateChanged(int arg1);

    void on_checkBox_12_stateChanged(int arg1);

    void on_checkBox_13_stateChanged(int arg1);

    void on_checkBox_14_stateChanged(int arg1);

    void on_checkBox_15_stateChanged(int arg1);

    void on_checkBox_16_stateChanged(int arg1);

    void on_checkBox_17_stateChanged(int arg1);

    void on_checkBox_18_stateChanged(int arg1);

    void on_checkBox_21_stateChanged(int arg1);

    void on_checkBox_22_stateChanged(int arg1);

    void on_checkBox_23_stateChanged(int arg1);

    void on_checkBox_24_stateChanged(int arg1);

    void on_checkBox_25_stateChanged(int arg1);

    void on_checkBox_26_stateChanged(int arg1);

    void on_checkBox_27_stateChanged(int arg1);

    void on_checkBox_28_stateChanged(int arg1);

    void on_checkBox_31_stateChanged(int arg1);

    void on_checkBox_32_stateChanged(int arg1);

    void on_checkBox_33_stateChanged(int arg1);

    void on_checkBox_38_stateChanged(int arg1);

    void on_checkBox_37_stateChanged(int arg1);

    void on_checkBox_36_stateChanged(int arg1);

    void on_checkBox_34_stateChanged(int arg1);

    void on_checkBox_35_stateChanged(int arg1);

    void on_checkBox_41_stateChanged(int arg1);

    void on_checkBox_42_stateChanged(int arg1);

    void on_checkBox_43_stateChanged(int arg1);

    void on_checkBox_44_stateChanged(int arg1);

    void on_checkBox_45_stateChanged(int arg1);

    void on_checkBox_46_stateChanged(int arg1);

    void on_checkBox_47_stateChanged(int arg1);

    void on_checkBox_48_stateChanged(int arg1);
signals:
    void role_widget11();
    void role_widget12();
    void role_widget13();
    void role_widget14();
    void role_widget15();
    void role_widget16();
    void role_widget17();
    void role_widget18();
    void role_widget21();
    void role_widget22();
    void role_widget23();
    void role_widget24();
    void role_widget25();
    void role_widget26();
    void role_widget27();
    void role_widget28();
    void role_widget31();
    void role_widget32();
    void role_widget33();
    void role_widget34();
    void role_widget35();
    void role_widget36();
    void role_widget37();
    void role_widget38();
    void role_widget41();
    void role_widget42();
    void role_widget43();
    void role_widget44();
    void role_widget45();
    void role_widget46();
    void role_widget47();
    void role_widget48();
    void save1();
    void save2();
    void save3();
    void save4();
private:
    Ui::committee* ui;
    string str1[8], str2[8],str3[8],str4[8];
    string chk1[8], chk2[8],chk3[8],chk4[8];
    QWidget *widget1[8], *widget2[8], *widget3[8], *widget4[8];
    QTextEdit *textEdit1[8], *textEdit2[8], *textEdit3[8], *textEdit4[8];
    QLineEdit *lineEdit1[8], *lineEdit2[8], *lineEdit3[8], *lineEdit4[8];
    QPushButton *pushButton1[8], *pushButton2[8], *pushButton3[8], *pushButton4[8];
    int n;
    ofstream output;
    ifstream input;
    string test;
    stringstream ss;
    string tokens[4];
    string enter;
    string name;

};

}

#endif
