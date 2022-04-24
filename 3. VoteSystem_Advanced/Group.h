/*
Group, Group Vote에 관한 Class 선언 헤더 파일이다.
*/
#pragma once
#include <iostream>
#include<string>
#include<vector>
#define MAX_VOTE_COUNT 150
using namespace std;
class Group {
private:
	string GroupName;
	vector<string> GroupMemberList;
	string GroupLeaderID;
public:
	Group();
	void showGroup();
	string showName();
	bool checkName(string Name);
	void setGroup(string Name, string ID);
	void enterGroup(string ID);
	void pop(string ID);
	int BanMember(string ID);
};
class VoteGroup : public Group {
private:
	int check;
	int index;
	int GroupVotecount;
	class GroupVotelist {
	private:
		string GroupVoteName;
		int Items[10];
		int count;
		vector<string> VotedRRN;
	public:
		GroupVotelist() : count(0) {
			for (int i = 0; i < 10; i++)
				Items[i] = 0;
		}
		friend class VoteGroup;
	};
public:
	VoteGroup();
	GroupVotelist Groupvote[MAX_VOTE_COUNT];
	int GetCount();
	void showVotename();
	void ShowVote();
	void SetVote(string name, int count);
	void Remove(string name);
	bool CheckName(string name);
	void Voting(string name, string RRN, int selection, int selection2);
	int AireadyVoted(string name, string RRN);
};