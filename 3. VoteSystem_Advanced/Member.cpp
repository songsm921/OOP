#include "member.h"
using namespace std;
extern int menucount;
Member::Member() :personalLogin(0), inheritance(0) {}//처음 member생성 1->2메뉴 Case
Member::Member(string RRN, string ID, string PW) : personalLogin(1) {
	this->RRN = RRN;
	this->ID = ID;
	this->PW = PW;
}//member에서 Group으로 진행 할 때 생성자. 2->3 2->4또는 3->2(이 상황은 따로 설정이 필요하다 )
int Member::GetLogin()
{
	return personalLogin;
}//로그인 값 리턴
int Member::GetInherit()
{
	return inheritance;
}//이 멤버의 직위를 나타내는 변수리턴/ 다르게 말하면 이 사용자가 몇번 상속된 클래스 소속자인지를 말한다 0->member 1->Group member 2->Group Leader
string Member::GetRRN()
{
	return RRN;
}
string Member::GetID()
{
	return ID;
}
string Member::GetPW()
{
	return PW;
}
string Member:: Getname() {
	return "Not Correct Accept";
}// 각 멤버의 정보 리턴// 이 method는 member에 쓰이지 않기 때문에, virtual을 사용한다.
void Member::Login()
{
	personalLogin = 1;
}
void Member::Logout()
{
	personalLogin = 0;
}//로그인, 로그아웃
void Member::SetInherit_0()
{
	inheritance = 0;
}
void Member::SetInherit_1()
{
	inheritance = 1;
}
void Member::SetInherit_2()
{
	inheritance = 2;
}//사용자의 현재 직위 명시
int Member::WhatIsYourInherit()
{
	if (inheritance == 0)
		return 0;
	else if (inheritance == 1)
		return 1;
	else if (inheritance == 2)
		return 2;
	return 100;
}//사용자의 직위에 따라 맞는 값 리턴
void Member::printMenu()
{
	cout << "=======================" << endl; fflush(stdout);
	cout << "Num : " << ++menucount << endl; fflush(stdout);
	cout << "=======================" << endl; fflush(stdout);
	cout << "2.1 Logout" << endl; fflush(stdout);
	cout << "2.2 Unsubscribe from System" << endl; fflush(stdout);
	cout << "2.3 Delete Exsiting Vote Item" << endl; fflush(stdout);
	cout << "2.4 Add a Vote Item" << endl; fflush(stdout);
	cout << "2.5 List All Vote Items" << endl; fflush(stdout);
	cout << "2.6 Cast a Vote" << endl; fflush(stdout);
	cout << "2.7 Join Group" << endl; fflush(stdout);
	cout << "2.8 Create a Group" << endl; fflush(stdout);
	cout << "2.9 Program Exit" << endl; fflush(stdout);
	cout << "[ID]: " << ID << "[Current Position] : Member" << endl; fflush(stdout);//ID값 Pass
	cout << "Select Menu : "; fflush(stdout);
}//2번 메뉴 출력(Virtual)
void Member::SetMember(string RRN, string ID, string PW)
{
	this->RRN = RRN;
	this->ID = ID;
	this->PW = PW;
}//1.1메뉴/회원 가입
bool Member::CheckIfAlready(string RRN, string ID)
{
	if (this->RRN == RRN)
		return false;
	if (this->ID == ID)
		return false;
	return true;
}//회원 가입 중복 검사
bool Member::checkList_Login(string ID_c, string PW_c)
{
	if (PW == PW_c && ID == ID_c && !personalLogin)
		return true;
	else
		return false;
}//로그인 과정 중 검사
bool Member::checkList_Out(string ID_c, string PW_c)
{
	if (PW == PW_c && ID == ID_c && personalLogin)
		return true;
	else
		return false;
}//회원 탈퇴 과정 중 검사
void Member::ShiftMember(string RRN, string ID, string PW, int login, int inheritance)
{
	this->RRN = RRN;
	this->ID = ID;
	this->PW = PW;
	this->personalLogin = login;
	this->inheritance = inheritance;
}//회원 탈퇴후 사용자들 인덱스 재 설정을 위해 한칸씩 밀때 사용하는 method
void Member::Initialization()
{
	RRN.clear();
	ID.clear();
	PW.clear();
	personalLogin = 0;
	inheritance = 0;
}//확실한 재 설정을 위해 초기화
GroupMember::GroupMember(string RRN, string ID, string PW, string Name) :Member(RRN, ID, PW) {
	this->Name = Name;
}//Group Member에 관한 생성자
void GroupMember::printMenu()
{
	cout << "=======================" << endl; fflush(stdout);
	cout << "Num : " << ++menucount << endl; fflush(stdout);
	cout << "=======================" << endl; fflush(stdout);
	cout << "3.1 Logout" << endl; fflush(stdout);
	cout << "3.2 Unsubscribe from System" << endl; fflush(stdout);
	cout << "3.3 Delete Exsiting Vote Item" << endl; fflush(stdout);
	cout << "3.4 Add a Vote Item" << endl; fflush(stdout);
	cout << "3.5 List All Vote Items" << endl; fflush(stdout);
	cout << "3.6 Cast a Vote" << endl; fflush(stdout);
	cout << "3.7 Unsubscribe from Group" << endl; fflush(stdout);
	cout << "3.8 Program Exit" << endl; fflush(stdout);
	cout << "[ID]: " << ID << "[Current Position] : Group Member" << "[Joined Group]:" << Name << endl; fflush(stdout);//ID,g값 Pass
	cout << "Select Menu : "; fflush(stdout);
}//3번 메뉴 출력(Virtual)
string GroupMember::Getname()
{
	return Name;
}//Group 이름 리턴
GroupLeader::GroupLeader(string RRN, string ID, string PW, string Name, int leader) :GroupMember(RRN, ID, PW, Name)
{
	this->leader = leader;
}// 원래는 leader변수의 값이 0이지만, 리더가 되면 1 대입
void GroupLeader::printMenu()
{
	cout << "=======================" << endl; fflush(stdout);
	cout << "Num : " << ++menucount << endl; fflush(stdout);
	cout << "=======================" << endl; fflush(stdout);
	cout << "4.1 Logout" << endl; fflush(stdout);
	cout << "4.2 Delete Exsiting Vote Item" << endl; fflush(stdout);
	cout << "4.3 Add a Vote Item" << endl; fflush(stdout);
	cout << "4.4 List All Vote Items" << endl; fflush(stdout);
	cout << "4.5 Cast a Vote" << endl; fflush(stdout);
	cout << "4.6 List All Group Members" << endl; fflush(stdout);
	cout << "4.7 Ban a Member from Group" << endl; fflush(stdout);
	cout << "4.8 Program Exit" << endl; fflush(stdout);
	cout << "[ID]: " << ID << "[Current Position] : Group Leader" << "[Joined Group]:" << Name << endl; fflush(stdout);//ID,g값 Pass
	cout << "Select Menu : "; fflush(stdout);
}//4번 메뉴 출력(Virtual)



