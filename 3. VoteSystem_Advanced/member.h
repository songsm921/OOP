/*
Member�� ���� Class ���� ��� �����̴�.
*/
#pragma once
#include <iostream>
#include<string>
using namespace std;
class Member {
private:
	string RRN;
	string PW;
	int personalLogin;
	int inheritance;//����� ����Ǿ��� -> �޸� �ű涧 �ʿ�.
protected:
	string ID;
public:
	Member();
	Member(string RRN, string ID, string PW);
	int GetLogin();
	int GetInherit();
	string GetRRN();
	string GetID();
	string GetPW();
	virtual string Getname();
	void Login();
	void Logout();
	void SetInherit_0();
	void SetInherit_1();
	void SetInherit_2();
	int WhatIsYourInherit();
	virtual void printMenu();
	void SetMember(string RRN, string ID, string PW);
	bool CheckIfAlready(string RRN, string ID);
	bool checkList_Login(string ID_c, string PW_c);
	bool checkList_Out(string ID_c, string PW_c);
	void ShiftMember(string RRN, string ID, string PW, int login, int inheritance);
	void Initialization();
};
class GroupMember :public Member {
protected:
	string Name;
public:
	GroupMember(string RRN, string ID, string PW, string Name);
	virtual void printMenu();
	string Getname();
};
class GroupLeader :public GroupMember {
private:
	int leader;
public:
	GroupLeader(string RRN, string ID, string PW, string Name, int leader);
	void printMenu();
};
