#include "Vote.h"
using namespace std;
NormalVote::NormalVote() {
	for (int i = 0; i < 10; i++)
		Items[i] = 0;
	count = 0;
	check = 0;
}//Vote Initialization
string NormalVote::GetName()
{
	return VoteName;
}//�Ϲ� ��ǥ �̸� ����
int NormalVote::Getcount()
{
	return count;
}// ��ǥ���� ���� ����
int* NormalVote::Getitems()
{
	return Items;
}//������ �迭 ����->��ǥ���� �ǹ���
bool NormalVote::CheckName(string name)
{
	if (VoteName == name)
		return false;
	else
		return true;
}//��ǥ �̸� �ߺ��˻�
void NormalVote::Voting(int selection)
{
	Items[selection - 1]++;
}//��ǥ
int NormalVote::AlreadyVoted(string RRN)
{
	if (VotedRRN.size() == 0)
		return 1;
	for (int i = 0; i < VotedRRN.size(); i++)
	{
		if (RRN == VotedRRN[i])
		{
			check = 0;
			break;
		}
		else
			check = 1;
	}
	return check;
}//�̹� ��ǥ �ߴ��� �˻�
void NormalVote::AddVotedRRN(string RRN)
{
	VotedRRN.push_back(RRN);
}//��ǥ�� ����� �� ��ǥ ���ϰ�, Ż���ϰ� ������ RRN�� ��ǥ�ϴ� ����� ������ ���� Method
void NormalVote::SetVote(string name, int count)
{
	VoteName = name;
	this->count = count;
}//��ǥ ����
void NormalVote::ShowVote()
{
	cout << "Vote Subject:" << " " << VoteName << "," << "Vote Counts per Items -";
	for (int i = 0; i < count; i++)
	{
		cout << "items" << i + 1 << ":" << Items[i] << " ";
	}
	cout << endl;
}//��ǥ ��Ȳ ���
void NormalVote::init()
{
	VoteName.clear();
	for (int i = 0; i < 10; i++)
		Items[i] = 0;
	count = 0;
	VotedRRN.clear();
}//��ǥ �ε��� �缳���� ���� �ʱ�ȭ
void NormalVote::Shift(string name, int *items, int count)
{
	VoteName = name;
	for (int i = 0; i < 10; i++)
		Items[i] = 0;
	for (int i = 0; i < count; i++)
		Items[i] = items[i];
	this->count = count;
}//��ǥ �ε��� �缳���� ���� ��ĭ�� �̴� ����.