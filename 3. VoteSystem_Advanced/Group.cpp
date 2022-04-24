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
}//4.6 �޴��� ���̴� Method ��vector�� erase�Լ��� ���� size�� �ڵ����� �� ���� �Ǵ� ������ �˰� ������, ������ �� ���� ���� �ʾ�, ���ڸ� continue
string Group::showName()
{
	return GroupName;
}
bool Group::checkName(string Name)
{
	return GroupName == Name;
}//�׷��̸� �ߺ��˻�
void Group::setGroup(string Name, string ID)
{
	GroupName = Name;
	GroupMemberList.push_back(ID);
	GroupLeaderID = ID;
}//2.8�� ���̴� method
void Group::enterGroup(string ID)
{
	GroupMemberList.push_back(ID);
}//2.7�� ���̴� method
void Group::pop(string ID)
{
	for (unsigned i = 0; i < GroupMemberList.size(); i++)
	{
		if (ID == GroupMemberList[i])
		{
			GroupMemberList[i].erase();
		}
	}
}//3.7�� ���̴� method
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
}//4.7�� ���̴� method
VoteGroup::VoteGroup() :Group() {
	GroupVotecount = 0;
	index = -1;
	check = 1;
}//�׷���ǥ defalut�� ����.
int VoteGroup::	GetCount()
{
	return GroupVotecount;
}//�׷���ǥ�� ����
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
}//��ǥ �̸� ���
void VoteGroup::ShowVote()
{
	for (int i = 0; i < GroupVotecount; i++)
	{
		cout << "Vote Subject:" << Groupvote[i].GroupVoteName << "Vote Counts per Items:";
		for (int k = 0; k < Groupvote[i].count; k++)
			cout << "items" << k + 1 << ":" << Groupvote[i].Items[k] << " ";
		cout << endl;
	}
}//��ǥ ��Ȳ ���
void VoteGroup::SetVote(string name, int count)
{
	string temp = name;
	int temp2 = count;
	Groupvote[GroupVotecount].GroupVoteName = temp;
	Groupvote[GroupVotecount].count = temp2;
	GroupVotecount++;
}//3.4 4.3�� ���̴� method
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

}//3.3 4.2�� ���̴� method->���� ��ǥ�� ���� ������ �ʱ�ȭ �� ��ǥ �ε��� �缳��
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
}//��ǥ �̸� �ߺ�Ȯ��
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
}//�׷���ǥ 
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
}//�̹� ��ǥ �� ��������� �˻�

