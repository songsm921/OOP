#include "committee.h"
#include "ui_committee.h"

using namespace std;
namespace Junhyeong
{
    Committee::Committee(string _name, QWidget* parent) :
        QWidget(parent), ui(new Ui::committee())
    {
        name=_name;
        n=0;
        ui->setupUi(this);
        for(int i=0; i<8; i++) {
        widget1[i] = new QWidget(ui->tab);
        widget2[i] = new QWidget(ui->tab_2);
        widget3[i] = new QWidget(ui->tab_3);
        widget4[i] = new QWidget(ui->tab_4);
        }
        for(int i=0; i<8; i++) {
        textEdit1[i] = new QTextEdit(widget1[i]);
        textEdit2[i] = new QTextEdit(widget2[i]);
        textEdit3[i] = new QTextEdit(widget3[i]);
        textEdit4[i] = new QTextEdit(widget4[i]);
        }
        for(int i=0; i<8; i++) {
            lineEdit1[i] = new QLineEdit(widget1[i]);
            lineEdit2[i] = new QLineEdit(widget2[i]);
            lineEdit3[i] = new QLineEdit(widget3[i]);
            lineEdit4[i] = new QLineEdit(widget4[i]);
        }
        for(int i=0; i<8; i++) {
            lineEdit1[i]->setText("입력하세요");
            lineEdit2[i]->setText("입력하세요");
            lineEdit3[i]->setText("입력하세요");
            lineEdit4[i]->setText("입력하세요");
        }
        for(int i=0; i<8; i++) {
        pushButton1[i] = new QPushButton(widget1[i]);
        pushButton2[i] = new QPushButton(widget2[i]);
        pushButton3[i] = new QPushButton(widget3[i]);
        pushButton4[i] = new QPushButton(widget4[i]);
        }
        for(int i=0; i<8; i++) {
        chk1[i] = "0";
        chk2[i] = "0";
        chk3[i] = "0";
        chk4[i] = "0";
        }
        for(int i=0; i<8; i++) {
        QObject::connect(pushButton1[i],SIGNAL(clicked()), this, SLOT(hide()));
        QObject::connect(pushButton2[i],SIGNAL(clicked()), this, SLOT(hide()));
        QObject::connect(pushButton3[i],SIGNAL(clicked()), this, SLOT(hide()));
        QObject::connect(pushButton4[i],SIGNAL(clicked()), this, SLOT(hide()));
        }
        QObject::connect(this,SIGNAL(role_widget11()), this, SLOT(role11()));
        QObject::connect(this,SIGNAL(role_widget12()), this, SLOT(role12()));
        QObject::connect(this,SIGNAL(role_widget13()), this, SLOT(role13()));
        QObject::connect(this,SIGNAL(role_widget14()), this, SLOT(role14()));
        QObject::connect(this,SIGNAL(role_widget15()), this, SLOT(role15()));
        QObject::connect(this,SIGNAL(role_widget16()), this, SLOT(role16()));
        QObject::connect(this,SIGNAL(role_widget17()), this, SLOT(role17()));
        QObject::connect(this,SIGNAL(role_widget18()), this, SLOT(role18()));
        QObject::connect(this,SIGNAL(role_widget21()), this, SLOT(role21()));
        QObject::connect(this,SIGNAL(role_widget22()), this, SLOT(role22()));
        QObject::connect(this,SIGNAL(role_widget23()), this, SLOT(role23()));
        QObject::connect(this,SIGNAL(role_widget24()), this, SLOT(role24()));
        QObject::connect(this,SIGNAL(role_widget25()), this, SLOT(role25()));
        QObject::connect(this,SIGNAL(role_widget26()), this, SLOT(role26()));
        QObject::connect(this,SIGNAL(role_widget27()), this, SLOT(role27()));
        QObject::connect(this,SIGNAL(role_widget28()), this, SLOT(role28()));
        QObject::connect(this,SIGNAL(role_widget31()), this, SLOT(role31()));
        QObject::connect(this,SIGNAL(role_widget32()), this, SLOT(role32()));
        QObject::connect(this,SIGNAL(role_widget33()), this, SLOT(role33()));
        QObject::connect(this,SIGNAL(role_widget34()), this, SLOT(role34()));
        QObject::connect(this,SIGNAL(role_widget35()), this, SLOT(role35()));
        QObject::connect(this,SIGNAL(role_widget36()), this, SLOT(role36()));
        QObject::connect(this,SIGNAL(role_widget37()), this, SLOT(role37()));
        QObject::connect(this,SIGNAL(role_widget38()), this, SLOT(role38()));
        QObject::connect(this,SIGNAL(role_widget41()), this, SLOT(role41()));
        QObject::connect(this,SIGNAL(role_widget42()), this, SLOT(role42()));
        QObject::connect(this,SIGNAL(role_widget43()), this, SLOT(role43()));
        QObject::connect(this,SIGNAL(role_widget44()), this, SLOT(role44()));
        QObject::connect(this,SIGNAL(role_widget45()), this, SLOT(role45()));
        QObject::connect(this,SIGNAL(role_widget46()), this, SLOT(role46()));
        QObject::connect(this,SIGNAL(role_widget47()), this, SLOT(role47()));
        QObject::connect(this,SIGNAL(role_widget48()), this, SLOT(role48()));
        QObject::connect(this,SIGNAL(save1()), this, SLOT(save_str1()));
        QObject::connect(this,SIGNAL(save2()), this, SLOT(save_str1()));
        QObject::connect(this,SIGNAL(save3()), this, SLOT(save_str1()));
        QObject::connect(this,SIGNAL(save4()), this, SLOT(save_str1()));
        hide();

        string file_path = "commandLog_Committee";
        file_path.append("_"+name+".txt");
        input.open(file_path,ios::in);
        if(input.fail()) {
            ;
        }
        else {
        DoTask();
        input.close();
        }

    }

    Committee::~Committee(){
        for(int i=0; i<8; i++) {
            delete widget1[i];
            delete widget2[i];
            delete widget3[i];
            delete widget4[i];
            delete textEdit1[i];
            delete textEdit2[i];
            delete textEdit3[i];
            delete textEdit4[i];
            delete lineEdit1[i];
            delete lineEdit2[i];
            delete lineEdit3[i];
            delete lineEdit4[i];
            delete pushButton1[i];
            delete pushButton2[i];
            delete pushButton3[i];
            delete pushButton4[i];
        }
    }
}

void Junhyeong::Committee::DoTask() {
    while(!input.eof()) {
        for(int i=0; i<4; i++) {
        input >> tokens[i];
        cout << tokens[i] << " ";
        }
        cout << endl;
        if (tokens[0] == "") // 로그에서 빈 줄을 받는 경우.
            continue;
        if(tokens[0] == "1") {
            for(int j=0; j<8; j++) {
            if(tokens[1] == to_string(j)) {
                lineEdit1[j]->setText(QString::fromStdString(tokens[2]));
            }
            }
            if(tokens[1] == "0") {
            if(tokens[3]=="1")
               ui->checkBox_11->setChecked(true);
            else if(tokens[3]=="0")
                ui->checkBox_11->setChecked(false);
            }
            if(tokens[1] == "1") {
            if(tokens[3]=="1")
               ui->checkBox_12->setChecked(true);
            else if(tokens[3]=="0")
                ui->checkBox_12->setChecked(false);
            }
            if(tokens[1] == "2") {
            if(tokens[3]=="1")
               ui->checkBox_13->setChecked(true);
            else if(tokens[3]=="0")
                ui->checkBox_13->setChecked(false);
            }
            if(tokens[1] == "3") {
            if(tokens[3]=="1")
               ui->checkBox_14->setChecked(true);
            else if(tokens[3]=="0")
                ui->checkBox_14->setChecked(false);
            }
            if(tokens[1] == "4") {
            if(tokens[3]=="1")
               ui->checkBox_15->setChecked(true);
            else if(tokens[3]=="0")
                ui->checkBox_15->setChecked(false);
            }
            if(tokens[1] == "5") {
            if(tokens[3]=="1")
               ui->checkBox_16->setChecked(true);
            else if(tokens[3]=="0")
                ui->checkBox_16->setChecked(false);
            }
            if(tokens[1] == "6") {
            if(tokens[3]=="1")
               ui->checkBox_17->setChecked(true);
            else if(tokens[3]=="0")
                ui->checkBox_17->setChecked(false);
            }
            if(tokens[1] == "7") {
            if(tokens[3]=="1")
               ui->checkBox_18->setChecked(true);
            else if(tokens[3]=="0")
                ui->checkBox_18->setChecked(false);
            }
        }
        if(tokens[0] == "2") {
        for(int j=0; j<8; j++) {
            if(tokens[1] == to_string(j)) {
                lineEdit2[j]->setText(QString::fromStdString(tokens[2]));
                }
            }
        if(tokens[1] == "0") {
        if(tokens[3]=="1")
           ui->checkBox_21->setChecked(true);
        else if(tokens[3]=="0")
            ui->checkBox_21->setChecked(false);
        }
        if(tokens[1] == "1") {
        if(tokens[3]=="1")
           ui->checkBox_22->setChecked(true);
        else if(tokens[3]=="0")
            ui->checkBox_22->setChecked(false);
        }
        if(tokens[1] == "2") {
        if(tokens[3]=="1")
           ui->checkBox_23->setChecked(true);
        else if(tokens[3]=="0")
            ui->checkBox_23->setChecked(false);
        }
        if(tokens[1] == "3") {
        if(tokens[3]=="1")
           ui->checkBox_24->setChecked(true);
        else if(tokens[3]=="0")
            ui->checkBox_24->setChecked(false);
        }
        if(tokens[1] == "4") {
        if(tokens[3]=="1")
           ui->checkBox_25->setChecked(true);
        else if(tokens[3]=="0")
            ui->checkBox_25->setChecked(false);
        }
        if(tokens[1] == "5") {
        if(tokens[3]=="1")
           ui->checkBox_26->setChecked(true);
        else if(tokens[3]=="0")
            ui->checkBox_26->setChecked(false);
        }
        if(tokens[1] == "6") {
        if(tokens[3]=="1")
           ui->checkBox_27->setChecked(true);
        else if(tokens[3]=="0")
            ui->checkBox_27->setChecked(false);
        }
        if(tokens[1] == "7") {
        if(tokens[3]=="1")
           ui->checkBox_28->setChecked(true);
        else if(tokens[3]=="0")
            ui->checkBox_28->setChecked(false);
        }
        }
        if(tokens[0] == "3") {
        for(int j=0; j<8; j++) {
            if(tokens[1] == to_string(j)) {
                lineEdit3[j]->setText(QString::fromStdString(tokens[2]));
                }
            }
        if(tokens[1] == "0") {
        if(tokens[3]=="1")
           ui->checkBox_31->setChecked(true);
        else if(tokens[3]=="0")
            ui->checkBox_31->setChecked(false);
        }
        if(tokens[1] == "1") {
        if(tokens[3]=="1")
           ui->checkBox_32->setChecked(true);
        else if(tokens[3]=="0")
            ui->checkBox_32->setChecked(false);
        }
        if(tokens[1] == "2") {
        if(tokens[3]=="1")
           ui->checkBox_33->setChecked(true);
        else if(tokens[3]=="0")
            ui->checkBox_33->setChecked(false);
        }
        if(tokens[1] == "3") {
        if(tokens[3]=="1")
           ui->checkBox_34->setChecked(true);
        else if(tokens[3]=="0")
            ui->checkBox_34->setChecked(false);
        }
        if(tokens[1] == "4") {
        if(tokens[3]=="1")
           ui->checkBox_35->setChecked(true);
        else if(tokens[3]=="0")
            ui->checkBox_35->setChecked(false);
        }
        if(tokens[1] == "5") {
        if(tokens[3]=="1")
           ui->checkBox_36->setChecked(true);
        else if(tokens[3]=="0")
            ui->checkBox_36->setChecked(false);
        }
        if(tokens[1] == "6") {
        if(tokens[3]=="1")
           ui->checkBox_37->setChecked(true);
        else if(tokens[3]=="0")
            ui->checkBox_37->setChecked(false);
        }
        if(tokens[1] == "7") {
        if(tokens[3]=="1")
           ui->checkBox_38->setChecked(true);
        else if(tokens[3]=="0")
            ui->checkBox_38->setChecked(false);
        }
        }
        if(tokens[0] == "4") {
        for(int j=0; j<8; j++) {
            if(tokens[1] == to_string(j)) {
                lineEdit4[j]->setText(QString::fromStdString(tokens[2]));
                }
            }
        if(tokens[1] == "0") {
        if(tokens[3]=="1")
           ui->checkBox_41->setChecked(true);
        else if(tokens[3]=="0")
            ui->checkBox_41->setChecked(false);
        }
        if(tokens[1] == "1") {
        if(tokens[3]=="1")
           ui->checkBox_42->setChecked(true);
        else if(tokens[3]=="0")
            ui->checkBox_42->setChecked(false);
        }
        if(tokens[1] == "2") {
        if(tokens[3]=="1")
           ui->checkBox_43->setChecked(true);
        else if(tokens[3]=="0")
            ui->checkBox_43->setChecked(false);
        }
        if(tokens[1] == "3") {
        if(tokens[3]=="1")
           ui->checkBox_44->setChecked(true);
        else if(tokens[3]=="0")
            ui->checkBox_44->setChecked(false);
        }
        if(tokens[1] == "4") {
        if(tokens[3]=="1")
           ui->checkBox_45->setChecked(true);
        else if(tokens[3]=="0")
           ui->checkBox_45->setChecked(false);
        }
        if(tokens[1] == "5") {
        if(tokens[3]=="1")
           ui->checkBox_46->setChecked(true);
        else if(tokens[3]=="0")
            ui->checkBox_46->setChecked(false);
        }
        if(tokens[1] == "6") {
        if(tokens[3]=="1")
           ui->checkBox_47->setChecked(true);
        else if(tokens[3]=="0")
            ui->checkBox_47->setChecked(false);
        }
        if(tokens[1] == "7") {
        if(tokens[3]=="1")
           ui->checkBox_48->setChecked(true);
        else if(tokens[3]=="0")
            ui->checkBox_48->setChecked(false);
        }
        }
    }
}
void Junhyeong::Committee::hide() {
    for(int i=0; i<8; i++) {
    widget1[i]->close();
    widget2[i]->close();
    widget3[i]->close();
    widget4[i]->close();
    }
}
void Junhyeong::Committee::save_str1() {
    string file_path = "commandLog_Committee";
    file_path.append("_"+name+".txt");
    output.open(file_path, ios::out);
    for(int i=0; i<8; i++) {
    str1[i] = lineEdit1[i]->text().toStdString();
    if(str1[i].empty()) {
        str1[i]="입력하세요";
    }
    output << 1 << " " << i << " " << str1[i] << " " <<  chk1[i] << endl;
    str2[i] = lineEdit2[i]->text().toStdString();
    if(str2[i].empty()) {
        str2[i]="입력하세요";
    }
    output << 2 << " " << i << " " << str2[i] << " " <<  chk2[i] << endl;
    str3[i] = lineEdit3[i]->text().toStdString();
    if(str3[i].empty()) {
        str3[i]="입력하세요";
    }
    output << 3 << " " << i << " " << str3[i] << " " <<  chk3[i] << endl;
    str4[i] = lineEdit4[i]->text().toStdString();
    if(str4[i].empty()) {
        str4[i]="입력하세요";
    }
    output << 4 << " " << i << " " << str4[i] << " " <<  chk4[i] << endl;
    }
    output.close();
}
void Junhyeong::Committee::role(QWidget* widget, QTextEdit* textEdit, QLineEdit* lineEdit, QPushButton* pushButton) {
    widget->setObjectName(QString::fromUtf8(("widget"+to_string(n)).c_str()));
    widget->setGeometry(QRect(370, 440, 231, 181));
    widget->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 222, 222);\n"
    "border-color: rgb(0, 0, 0);"));
    textEdit->setObjectName(QString::fromUtf8(("textEdit"+to_string(n)).c_str()));
    textEdit->setGeometry(QRect(20, 10, 61, 31));
    textEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 9pt \"1\355\233\210\354\240\220\353\263\264\353\247\230\353\263\264 B\";"));
    textEdit->setPlaceholderText("Role");
    textEdit->setTextInteractionFlags(Qt::NoTextInteraction);
    lineEdit->setObjectName(QString::fromUtf8(("lineEdit"+to_string(n)).c_str()));
    lineEdit->setGeometry(QRect(20, 50, 181, 81));
    lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
    lineEdit->setFrame(true);
    pushButton->setObjectName(QString::fromUtf8(("pushButton"+to_string(n)).c_str()));
    pushButton->setGeometry(QRect(60, 140, 93, 28));
    pushButton->setStyleSheet(QString::fromUtf8("font: 9pt \"1\355\233\210\354\240\220\353\263\264\353\247\230\353\263\264 B\";"));
    pushButton->setText("APPLY");
    widget->show();
}


void Junhyeong::Committee::role11() {
   role(widget1[0], textEdit1[0], lineEdit1[0], pushButton1[0]);
}
void Junhyeong::Committee::role12() {
   role(widget1[1], textEdit1[1], lineEdit1[1], pushButton1[1]);
}
void Junhyeong::Committee::role13() {
   role(widget1[2], textEdit1[2], lineEdit1[2], pushButton1[2]);
}
void Junhyeong::Committee::role14() {
   role(widget1[3], textEdit1[3], lineEdit1[3], pushButton1[3]);
}
void Junhyeong::Committee::role15() {
   role(widget1[4], textEdit1[4], lineEdit1[4], pushButton1[4]);
}
void Junhyeong::Committee::role16() {
   role(widget1[5], textEdit1[5], lineEdit1[5], pushButton1[5]);
}
void Junhyeong::Committee::role17() {
   role(widget1[6], textEdit1[6], lineEdit1[6], pushButton1[6]);
}
void Junhyeong::Committee::role18() {
   role(widget1[7], textEdit1[7], lineEdit1[7], pushButton1[7]);
}
void Junhyeong::Committee::role21() {
   role(widget2[0], textEdit2[0], lineEdit2[0], pushButton2[0]);
}
void Junhyeong::Committee::role22() {
   role(widget2[1], textEdit2[1], lineEdit2[1], pushButton2[1]);
}
void Junhyeong::Committee::role23() {
   role(widget2[2], textEdit2[2], lineEdit2[2], pushButton2[2]);
}
void Junhyeong::Committee::role24() {
   role(widget2[3], textEdit2[3], lineEdit2[3], pushButton2[3]);
}
void Junhyeong::Committee::role25() {
   role(widget2[4], textEdit2[4], lineEdit2[4], pushButton2[4]);
}
void Junhyeong::Committee::role26() {
   role(widget2[5], textEdit2[5], lineEdit2[5], pushButton2[5]);
}
void Junhyeong::Committee::role27() {
   role(widget2[6], textEdit2[6], lineEdit2[6], pushButton2[6]);
}
void Junhyeong::Committee::role28() {
   role(widget2[7], textEdit2[7], lineEdit2[7], pushButton2[7]);
}
void Junhyeong::Committee::role31() {
   role(widget3[0], textEdit3[0], lineEdit3[0], pushButton3[0]);
}
void Junhyeong::Committee::role32() {
   role(widget3[1], textEdit3[1], lineEdit3[1], pushButton3[1]);
}
void Junhyeong::Committee::role33() {
   role(widget3[2], textEdit3[2], lineEdit3[2], pushButton3[2]);
}
void Junhyeong::Committee::role34() {
   role(widget3[3], textEdit3[3], lineEdit3[3], pushButton3[3]);
}
void Junhyeong::Committee::role35() {
   role(widget3[4], textEdit3[4], lineEdit3[4], pushButton3[4]);
}
void Junhyeong::Committee::role36() {
    role(widget3[5], textEdit3[5], lineEdit3[5], pushButton3[5]);
}
void Junhyeong::Committee::role37() {
   role(widget3[6], textEdit3[6], lineEdit3[6], pushButton3[6]);
}
void Junhyeong::Committee::role38() {
   role(widget3[7], textEdit3[7], lineEdit3[7], pushButton3[7]);
}
void Junhyeong::Committee::role41() {
   role(widget4[0], textEdit4[0], lineEdit4[0], pushButton4[0]);
}
void Junhyeong::Committee::role42() {
   role(widget4[1], textEdit4[1], lineEdit4[1], pushButton4[1]);
}
void Junhyeong::Committee::role43() {
   role(widget4[2], textEdit4[2], lineEdit4[2], pushButton4[2]);
}
void Junhyeong::Committee::role44() {
   role(widget4[3], textEdit4[3], lineEdit4[3], pushButton4[3]);
}
void Junhyeong::Committee::role45() {
   role(widget4[4], textEdit4[4], lineEdit4[4], pushButton4[4]);
}
void Junhyeong::Committee::role46() {
   role(widget4[5], textEdit4[5], lineEdit4[5], pushButton4[5]);
}
void Junhyeong::Committee::role47() {
   role(widget4[6], textEdit4[6], lineEdit4[6], pushButton4[6]);
}
void Junhyeong::Committee::role48() {
   role(widget4[7], textEdit4[7], lineEdit4[7], pushButton4[7]);
}




void Junhyeong::Committee::on_pushButton_7_clicked()
{
        emit role_widget11();
}

void Junhyeong::Committee::on_pushButton_2_clicked()
{
        emit role_widget12();
}

void Junhyeong::Committee::on_pushButton_3_clicked()
{
        emit role_widget13();
}

void Junhyeong::Committee::on_pushButton_8_clicked()
{
        emit role_widget14();
}

void Junhyeong::Committee::on_pushButton_6_clicked()
{
        emit role_widget15();
}

void Junhyeong::Committee::on_pushButton_1_clicked()
{
     emit role_widget16();
}

void Junhyeong::Committee::on_pushButton_4_clicked()
{
    emit role_widget17();
}

void Junhyeong::Committee::on_pushButton_5_clicked()
{
    emit role_widget18();
}

void Junhyeong::Committee::on_pushButton_16_clicked()
{
    emit role_widget21();
}

void Junhyeong::Committee::on_pushButton_10_clicked()
{
    emit role_widget22();
}

void Junhyeong::Committee::on_pushButton_13_clicked()
{
    emit role_widget23();
}

void Junhyeong::Committee::on_pushButton_9_clicked()
{
    emit role_widget24();
}

void Junhyeong::Committee::on_pushButton_14_clicked()
{
    emit role_widget25();
}

void Junhyeong::Committee::on_pushButton_15_clicked()
{
    emit role_widget26();
}

void Junhyeong::Committee::on_pushButton_11_clicked()
{
    emit role_widget27();
}

void Junhyeong::Committee::on_pushButton_12_clicked()
{
    emit role_widget28();
}

void Junhyeong::Committee::on_pushButton_21_clicked()
{
    emit role_widget31();
}

void Junhyeong::Committee::on_pushButton_22_clicked()
{
    emit role_widget32();
}

void Junhyeong::Committee::on_pushButton_18_clicked()
{
    emit role_widget33();
}

void Junhyeong::Committee::on_pushButton_19_clicked()
{
    emit role_widget34();
}

void Junhyeong::Committee::on_pushButton_17_clicked()
{
    emit role_widget35();
}

void Junhyeong::Committee::on_pushButton_20_clicked()
{
    emit role_widget36();
}

void Junhyeong::Committee::on_pushButton_23_clicked()
{
    emit role_widget37();
}

void Junhyeong::Committee::on_pushButton_24_clicked()
{
    emit role_widget38();
}

void Junhyeong::Committee::on_pushButton_30_clicked()
{
    emit role_widget41();
}

void Junhyeong::Committee::on_pushButton_33_clicked()
{
    emit role_widget42();
}

void Junhyeong::Committee::on_pushButton_27_clicked()
{
    emit role_widget43();
}

void Junhyeong::Committee::on_pushButton_28_clicked()
{
    emit role_widget44();
}

void Junhyeong::Committee::on_pushButton_25_clicked()
{
    emit role_widget45();
}

void Junhyeong::Committee::on_pushButton_29_clicked()
{
    emit role_widget46();
}

void Junhyeong::Committee::on_pushButton_31_clicked()
{
    emit role_widget47();
}

void Junhyeong::Committee::on_pushButton_32_clicked()
{
    emit role_widget48();
}


void Junhyeong::Committee::on_pushButton_50_clicked()
{
    emit save1();
}

void Junhyeong::Committee::on_pushButton_51_clicked()
{
    emit save2();
}

void Junhyeong::Committee::on_pushButton_52_clicked()
{
    emit save3();
}

void Junhyeong::Committee::on_pushButton_53_clicked()
{
    emit save4();
}



void Junhyeong::Committee::on_checkBox_11_stateChanged(int arg1)
{
    if(ui->checkBox_11->isChecked()) {
        chk1[0]="1";
    }
    else{
        chk1[0]="0";
    }
}

void Junhyeong::Committee::on_checkBox_12_stateChanged(int arg1)
{
    if(ui->checkBox_12->isChecked()) {
        chk1[1]="1";
    }
    else{
        chk1[1]="0";
    }
}

void Junhyeong::Committee::on_checkBox_13_stateChanged(int arg1)
{
    if(ui->checkBox_13->isChecked()) {
        chk1[2]="1";
    }
    else{
        chk1[2]="0";
    }
}

void Junhyeong::Committee::on_checkBox_14_stateChanged(int arg1)
{
    if(ui->checkBox_14->isChecked()) {
        chk1[3]="1";
    }
    else{
        chk1[3]="0";
    }
}

void Junhyeong::Committee::on_checkBox_15_stateChanged(int arg1)
{
    if(ui->checkBox_15->isChecked()) {
        chk1[4]="1";
    }
    else{
        chk1[4]="0";
    }
}

void Junhyeong::Committee::on_checkBox_16_stateChanged(int arg1)
{
    if(ui->checkBox_16->isChecked()) {
        chk1[5]="1";
    }
    else{
        chk1[5]="0";
    }
}

void Junhyeong::Committee::on_checkBox_17_stateChanged(int arg1)
{
    if(ui->checkBox_17->isChecked()) {
        chk1[6]="1";
    }
    else{
        chk1[6]="0";
    }
}

void Junhyeong::Committee::on_checkBox_18_stateChanged(int arg1)
{
    if(ui->checkBox_18->isChecked()) {
        chk1[7]="1";
    }
    else{
        chk1[7]="0";
    }
}

void Junhyeong::Committee::on_checkBox_21_stateChanged(int arg1)
{
    if(ui->checkBox_21->isChecked()) {
        chk2[0]="1";
    }
    else{
        chk2[0]="0";
    }
}

void Junhyeong::Committee::on_checkBox_22_stateChanged(int arg1)
{
    if(ui->checkBox_22->isChecked()) {
        chk2[1]="1";
    }
    else{
        chk2[1]="0";
    }
}

void Junhyeong::Committee::on_checkBox_23_stateChanged(int arg1)
{
    if(ui->checkBox_23->isChecked()) {
        chk2[2]="1";
    }
    else{
        chk2[2]="0";
    }
}

void Junhyeong::Committee::on_checkBox_24_stateChanged(int arg1)
{
    if(ui->checkBox_24->isChecked()) {
        chk2[3]="1";
    }
    else{
        chk2[3]="0";
    }
}

void Junhyeong::Committee::on_checkBox_25_stateChanged(int arg1)
{
    if(ui->checkBox_25->isChecked()) {
        chk2[4]="1";
    }
    else{
        chk2[4]="0";
    }
}

void Junhyeong::Committee::on_checkBox_26_stateChanged(int arg1)
{
    if(ui->checkBox_26->isChecked()) {
        chk2[5]="1";
    }
    else{
        chk2[5]="0";
    }
}

void Junhyeong::Committee::on_checkBox_27_stateChanged(int arg1)
{
    if(ui->checkBox_27->isChecked()) {
        chk2[6]="1";
    }
    else{
        chk2[6]="0";
    }
}

void Junhyeong::Committee::on_checkBox_28_stateChanged(int arg1)
{
    if(ui->checkBox_28->isChecked()) {
        chk2[7]="1";
    }
    else{
        chk2[7]="0";
    }
}

void Junhyeong::Committee::on_checkBox_31_stateChanged(int arg1)
{
    if(ui->checkBox_31->isChecked()) {
        chk3[0]="1";
    }
    else{
        chk3[0]="0";
    }
}

void Junhyeong::Committee::on_checkBox_32_stateChanged(int arg1)
{
    if(ui->checkBox_32->isChecked()) {
        chk3[1]="1";
    }
    else{
        chk3[1]="0";
    }
}

void Junhyeong::Committee::on_checkBox_33_stateChanged(int arg1)
{
    if(ui->checkBox_33->isChecked()) {
        chk3[2]="1";
    }
    else{
        chk3[2]="0";
    }
}

void Junhyeong::Committee::on_checkBox_38_stateChanged(int arg1)
{
    if(ui->checkBox_38->isChecked()) {
        chk3[7]="1";
    }
    else{
        chk3[7]="0";
    }
}

void Junhyeong::Committee::on_checkBox_37_stateChanged(int arg1)
{
    if(ui->checkBox_37->isChecked()) {
        chk3[6]="1";
    }
    else{
        chk3[6]="0";
    }
}

void Junhyeong::Committee::on_checkBox_36_stateChanged(int arg1)
{
    if(ui->checkBox_36->isChecked()) {
        chk3[5]="1";
    }
    else{
        chk3[5]="0";
    }
}

void Junhyeong::Committee::on_checkBox_34_stateChanged(int arg1)
{
    if(ui->checkBox_34->isChecked()) {
        chk3[3]="1";
    }
    else{
        chk3[3]="0";
    }
}

void Junhyeong::Committee::on_checkBox_35_stateChanged(int arg1)
{
    if(ui->checkBox_35->isChecked()) {
        chk3[4]="1";
    }
    else{
        chk3[4]="0";
    }
}

void Junhyeong::Committee::on_checkBox_41_stateChanged(int arg1)
{
    if(ui->checkBox_41->isChecked()) {
        chk4[0]="1";
    }
    else{
        chk4[0]="0";
    }
}

void Junhyeong::Committee::on_checkBox_42_stateChanged(int arg1)
{
    if(ui->checkBox_42->isChecked()) {
        chk4[1]="1";
    }
    else{
        chk4[1]="0";
    }
}

void Junhyeong::Committee::on_checkBox_43_stateChanged(int arg1)
{
    if(ui->checkBox_43->isChecked()) {
        chk4[2]="1";
    }
    else{
        chk4[2]="0";
    }
}

void Junhyeong::Committee::on_checkBox_44_stateChanged(int arg1)
{
    if(ui->checkBox_44->isChecked()) {
        chk4[3]="1";
    }
    else{
        chk4[3]="0";
    }
}

void Junhyeong::Committee::on_checkBox_45_stateChanged(int arg1)
{
    if(ui->checkBox_45->isChecked()) {
        chk4[4]="1";
    }
    else{
        chk4[4]="0";
    }
}

void Junhyeong::Committee::on_checkBox_46_stateChanged(int arg1)
{
    if(ui->checkBox_46->isChecked()) {
        chk4[5]="1";
    }
    else{
        chk4[5]="0";
    }
}

void Junhyeong::Committee::on_checkBox_47_stateChanged(int arg1)
{
    if(ui->checkBox_47->isChecked()) {
        chk4[6]="1";
    }
    else{
        chk4[6]="0";
    }
}

void Junhyeong::Committee::on_checkBox_48_stateChanged(int arg1)
{
    if(ui->checkBox_48->isChecked()) {
        chk4[7]="1";
    }
    else{
        chk4[7]="0";
    }
}

