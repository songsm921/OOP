/*
NormalVote에 관한 Class 선언 헤더 파일이다.
*/
#pragma once
#include <iostream>
#include<string>
#include<vector>
using namespace std;
class NormalVote {
private:
	string VoteName;
	int Items[10];
	int count;
	int check;
public:
	vector<string> VotedRRN;
	NormalVote();
	string GetName();
	int Getcount();
	int* Getitems();
	bool CheckName(string name);
	void Voting(int selection);
	int AlreadyVoted(string RRN);
	void AddVotedRRN(string RRN);
	void SetVote(string name, int count);
	void ShowVote();
	void init();
	void Shift(string name, int *items, int count);
};
