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
}//일반 투표 이름 리턴
int NormalVote::Getcount()
{
	return count;
}// 투표안의 개수 리턴
int* NormalVote::Getitems()
{
	return Items;
}//아이템 배열 리턴->투표안을 의미함
bool NormalVote::CheckName(string name)
{
	if (VoteName == name)
		return false;
	else
		return true;
}//투표 이름 중복검사
void NormalVote::Voting(int selection)
{
	Items[selection - 1]++;
}//투표
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
}//이미 투표 했는지 검사
void NormalVote::AddVotedRRN(string RRN)
{
	VotedRRN.push_back(RRN);
}//투표한 사용자 재 투표 못하게, 탈퇴하고 동일한 RRN을 투표하는 사용자 방지를 위한 Method
void NormalVote::SetVote(string name, int count)
{
	VoteName = name;
	this->count = count;
}//투표 생성
void NormalVote::ShowVote()
{
	cout << "Vote Subject:" << " " << VoteName << "," << "Vote Counts per Items -";
	for (int i = 0; i < count; i++)
	{
		cout << "items" << i + 1 << ":" << Items[i] << " ";
	}
	cout << endl;
}//투표 현황 출력
void NormalVote::init()
{
	VoteName.clear();
	for (int i = 0; i < 10; i++)
		Items[i] = 0;
	count = 0;
	VotedRRN.clear();
}//투표 인덱스 재설정을 위한 초기화
void NormalVote::Shift(string name, int *items, int count)
{
	VoteName = name;
	for (int i = 0; i < 10; i++)
		Items[i] = 0;
	for (int i = 0; i < count; i++)
		Items[i] = items[i];
	this->count = count;
}//투표 인덱스 재설정을 위해 한칸씩 미는 과정.