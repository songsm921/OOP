#include "Group.h"
using namespace std;
Group::Group() {}
void Group::showGroup()
{
	cout << "<Group Members>" << endl;
	if (GroupMemberList.size() == 0)
		cout << "None";
	else
		for (int i = 0; i < GroupMemberList.size(); i++)
		{
			if (GroupMemberList[i] != "")
			{
				cout << GroupMemberList[i];
				if (GroupMemberList.size() - 1 == i)
					continue;
				else
					cout << ",";
			}
			else
				continue;
		}
	cout << endl;
}//4.6 메뉴에 쓰이는 Method ※vector를 erase함수를 쓰면 size도 자동으로 재 설정 되는 것으로 알고 있으나, 디버깅시 재 설정 되지 않아, 빈문자면 continue
string Group::showName()
{
	return GroupName;
}
bool Group::checkName(string Name)
{
	return GroupName == Name;
}//그룹이름 중복검사
void Group::setGroup(string Name, string ID)
{
	GroupName = Name;
	GroupMemberList.push_back(ID);
	GroupLeaderID = ID;
}//2.8에 쓰이는 method
void Group::enterGroup(string ID)
{
	GroupMemberList.push_back(ID);
}//2.7에 쓰이는 method
void Group::pop(string ID)
{
	for (unsigned i = 0; i < GroupMemberList.size(); i++)
	{
		if (ID == GroupMemberList[i])
		{
			GroupMemberList[i].erase();
		}
	}
}//3.7에 쓰이는 method
int Group::BanMember(string ID)
{
	for (unsigned i = 0; i < GroupMemberList.size(); i++)
	{
		if (ID == GroupMemberList[i] && ID != GroupLeaderID)
		{
			GroupMemberList[i].erase();
			return 1;
		}
	}
	return 0;
}//4.7에 쓰이는 method
VoteGroup::VoteGroup() :Group() {
	GroupVotecount = 0;
	index = -1;
	check = 1;
}//그룹투표 defalut값 설정.
int VoteGroup::	GetCount()
{
	return GroupVotecount;
}//그룹투표수 리턴
void VoteGroup::showVotename()
{
	if (GroupVotecount == 0)
		cout << "None";
	else
		for (int i = 0; i < GroupVotecount; i++)
		{
			cout << Groupvote[i].GroupVoteName;
			if (GroupVotecount - 1 == i)
				continue;
			else
				cout << ",";
		}
}//투표 이름 출력
void VoteGroup::ShowVote()
{
	for (int i = 0; i < GroupVotecount; i++)
	{
		cout << "Vote Subject:" << Groupvote[i].GroupVoteName << "Vote Counts per Items:";
		for (int k = 0; k < Groupvote[i].count; k++)
			cout << "items" << k + 1 << ":" << Groupvote[i].Items[k] << " ";
		cout << endl;
	}
}//투표 현황 출력
void VoteGroup::SetVote(string name, int count)
{
	string temp = name;
	int temp2 = count;
	Groupvote[GroupVotecount].GroupVoteName = temp;
	Groupvote[GroupVotecount].count = temp2;
	GroupVotecount++;
}//3.4 4.3에 쓰이는 method
void VoteGroup::Remove(string name)
{
	for (int i = 0; i < GroupVotecount; i++)
	{
		if (name == Groupvote[i].GroupVoteName)
		{
			index = i;
			break;
		}
		else
			continue;
	}
	if (GroupVotecount == 1)
	{
		Groupvote[index].count = 0;
		Groupvote[index].GroupVoteName.clear();
		for (int i = 0; i<10; i++)
			Groupvote[index].Items[i] = 0;
		Groupvote[index].VotedRRN.clear();
	}
	else
	{
		for (int i = index + 1; i < GroupVotecount; i++)
		{
			Groupvote[i - 1].count = Groupvote[i].count;
			Groupvote[i - 1].GroupVoteName = Groupvote[i].GroupVoteName;
			Groupvote[i - 1].VotedRRN.clear();
			for (int k = 0; k < 10; k++)
				Groupvote[i - 1].Items[k] = Groupvote[i].Items[k];
			for (int j = 0; j < Groupvote[i].VotedRRN.size(); j++)
			{
				if (Groupvote[i].VotedRRN.size() == 0)
					continue;
				Groupvote[i - 1].VotedRRN.push_back(Groupvote[i].VotedRRN[j]);
			}
		}
	}
	Groupvote[GroupVotecount - 1].count = 0;
	Groupvote[GroupVotecount - 1].GroupVoteName.clear();
	for (int i = 0; i<10; i++)
		Groupvote[GroupVotecount - 1].Items[i] = 0;
	Groupvote[GroupVotecount - 1].VotedRRN.clear();
	GroupVotecount--;

}//3.3 4.2에 쓰이는 method->각종 투표에 관한 변수들 초기화 및 투표 인덱스 재설정
bool VoteGroup::CheckName(string name)
{
	if (GroupVotecount == 0)
		return true;
	for (int i = 0; i < GroupVotecount; i++)
	{
		if (Groupvote[i].GroupVoteName == name)
		{
			return false;
			break;
		}
		else
			continue;
	}
	return true;
}//투표 이름 중복확인
void VoteGroup::Voting(string name, string RRN, int selection, int selection2)
{
	for (int i = 0; i < GroupVotecount; i++)
	{
		if (name == Groupvote[i].GroupVoteName)
		{
			index = i;
			break;
		}
		else
			continue;
	}
	Groupvote[index].Items[selection - 1]++;
	Groupvote[index].Items[selection2 - 1]++;
	Groupvote[index].VotedRRN.push_back(RRN);
}//그룹투표 
int VoteGroup::AireadyVoted(string name, string RRN)
{
	for (int i = 0; i < GroupVotecount; i++)
	{
		if (name == Groupvote[i].GroupVoteName)
		{
			index = i;
			break;
		}
		else
			continue;
	}
	if (Groupvote[index].VotedRRN.size() == 0)
	{
		return 1;
	}
	for (int i = 0; i < Groupvote[index].VotedRRN.size(); i++)
	{
		if (Groupvote[index].VotedRRN[i] == RRN)
		{
			return 0;
			break;
		}
		else
			continue;
	}
	return 1;
}//이미 투표 한 사용자인지 검사

