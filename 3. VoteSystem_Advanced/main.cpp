/*
Assignment3는 이전 과제의 업그레이드 버젼으로, 대부분의 기능이 저번과제랑 유사하다.
이 소스파일에서는 각 메뉴의 전체적인 과정을 제어한다.
*/
#include "Group.h"
#include "member.h"
#include "Vote.h"
#include<iostream>
#include<string>
#include<vector>
#include <fstream>
#include <sstream>
#define MAX_MEMBER 150
#define MAX_GROUP 10
#define MAX_VOTE_COUNT 150
using namespace std;
int menucount = 0;//Menu count
int membercount = 0;//멤버의수
int groupcount = 0;//그룹의 수
int currIndex = -1;//현재 로그인한 멤버의 인덱스
int groupindex = -1;//현재 로그인한 멤버가 속한 그룹의 인덱스, non member, Member일 때는 무의미하고 영향을 미치지 않지만, 1->4 2->3,2->4번 메뉴로 진입할 때 갱신된다.
int NormalVotecount = 0;//일반 투표의 개수
void clearTokens(string * tokens)
{
	for (int i = 0; i < 6; i++)
		tokens[i].clear();
}
void printMenu_N()//Menu for Non_Member
{
	cout << "=======================" << endl; fflush(stdout);
	cout << "Num : " << ++menucount << endl; fflush(stdout);
	cout << "=======================" << endl; fflush(stdout);
	cout << "1.1 Register as a Member" << endl; fflush(stdout);
	cout << "1.2 Login" << endl; fflush(stdout);
	cout << "1.3 Program Exit" << endl; fflush(stdout);
	cout << "[Current Position] : Non Member" << endl; fflush(stdout);
	cout << "Select Menu : "; fflush(stdout);
}
int main()
{
	Member *memberlist[MAX_MEMBER];//멤버 Base Class 객체
	VoteGroup Grouplist[MAX_GROUP];//그룹, 그룹투표에 관한 객체
	NormalVote NormalVotelist[MAX_VOTE_COUNT];//일반투표에 관한 객체
	int Mode;
	ifstream inLogRead;
	ofstream inLogWrite;
	string tokens[6], line;
	stringstream stream;
	cout << "Load log file?(1:yes, 0:no(log will be deleted))";
	cin >> Mode;
	if (!Mode)
	{
		getchar();
		inLogWrite.open("commandLog.txt", ios::out);
	}
	else
	{
		inLogRead.open("commandLog.txt", ios::in);
		inLogWrite.open("commandLog.txt", ios::in | ios::app);
	}
	int StopMenu1 = 1;
	int selectMenu1 = -1;//메뉴 선택 중 앞의 것
	int selectMenu2 = 0;//메뉴 선택 중 뒤의 것
	int checkpoint = 1;//각종 분기점에서 검사할 때 쓰이는 변수
	int selection = 0;//투표 개수, 투표 선택
	int selection2 = 0;//그룹 투표에서 투표 선택 중 2번째 란
	int voteIndex = -1;//선택한 투표의 인덱스
	int type = -1;// 투표의 Type
	int BanIndex = -1;//추방 할 사람의 인덱스
	int nTokens;
	string RRN_c;
	string ID_c;
	string PW_c;
	string Groupname_c;
	string VoteName_c;//Class에 값을 넣기전에 임시로 넣어둬서 검사를 진행하게 보조하는 변수
	while (1)
	{
		while (StopMenu1)
		{
			printMenu_N();
			//cin >> selectMenu1 >> selectMenu2;
			if (Mode == 1)
			{
				getline(inLogRead, line);
				if (line == "")
				{
					//end of file with newline
					if (inLogRead.eof())
					{
						//stop reading from logfile 
						//stdin mode starts
						inLogRead.close();
						Mode = 0;
						getline(cin, line);
						if (line == "")
						{
							cout << "Selected Menu: Undefined menu selection" << endl; fflush(stdout);
							continue;
						}
						stream.str(line);
						nTokens = 0;
						clearTokens(tokens);
						//Read all tokens(seperated by " ")
						while (stream >> tokens[nTokens])
							nTokens++;
						stream.clear();
						selectMenu1 = atoi(tokens[0].c_str());
						selectMenu2 = atoi(tokens[1].c_str());
						//when first stdin input was newline
						//continue without loggin input
					}
					//middle of file with new line
					//continue without logging
					else
					{
						cout << "\nSelected Menu: Undefined menu selection" << endl; fflush(stdout);
						continue;
					}
				}

				//inputs != newline
				else
				{
					stream.str(line);
					nTokens = 0;
					clearTokens(tokens);
					//Read all tokens(seperated by " ")
					while (stream >> tokens[nTokens])
						nTokens++;
					stream.clear();
					selectMenu1 = atoi(tokens[0].c_str());
					selectMenu2 = atoi(tokens[1].c_str());
					cout << selectMenu1 << " " << selectMenu2 << endl; fflush(stdout);
				}


			}
			//stdin mode
			else
			{
				getline(cin, line);
				stream.str(line);
				nTokens = 0;
				clearTokens(tokens);
				//Read all tokens(seperated by " ")
				while (stream >> tokens[nTokens])
					nTokens++;
				stream.clear();
				selectMenu1 = atoi(tokens[0].c_str());
				selectMenu2 = atoi(tokens[1].c_str());
			}
			switch (selectMenu2)
			{
			case 0:
				cout << "<Member List>" << endl;
				for (int i = 0; i < membercount; i++)
				{
					if (memberlist[i]->GetInherit() == 0)
						cout << "[ID]: " << memberlist[i]->GetID() << "[Joined Group]: " << "None" << "[Position]: Member" << endl;
					else if (memberlist[i]->GetInherit() == 1)
						cout << "[ID]: " << memberlist[i]->GetID() << "[Joined Group]: " << memberlist[i]->Getname() << "[Position]: Group Member" << endl;
					else if (memberlist[i]->GetInherit() == 2)
						cout << "[ID]: " << memberlist[i]->GetID() << "[Joined Group]: " << memberlist[i]->Getname() << "[Position]: Group Leader" << endl;
				}
				cout << "<Group List>" << endl;
				if (groupcount == 0)
					cout << "None";
				else
				{
					for (int i = 0; i < groupcount; i++)
					{
						cout << Grouplist[i].showName();
						if (groupcount - 1 == i)
							continue;
						else
							cout << ",";
					}
				}
				cout << endl;
				cout << "<General Votes>" << endl;
				if (!NormalVotecount)
					cout << "None";
				else
				{
					for (int i = 0; i < NormalVotecount; i++)
					{
						cout << NormalVotelist[i].GetName();
						if (NormalVotecount - 1 == i)
							continue;
						else
							cout << ",";
					}
				}
				cout << endl;
				cout << "<Group Votes>" << endl;
				for (int i = 0; i < groupcount; i++)
				{
					cout << Grouplist[i].showName() << ": ";
					if (Grouplist[i].GetCount() == 0)
						cout << "None";
					else
					{
						Grouplist[i].showVotename();
					}
					cout << endl;
				}
				if (!Mode)
					inLogWrite << "0" << " " << "0" << " " << endl;
				break;
			case 1:
				cout << "Selected Menu: 1.1 Register as a Member" << endl;
				cout << "RRN: ";
				if (Mode)
				{
					RRN_c = tokens[2];
					cout << RRN_c << endl;
				}
				else
					cin >> RRN_c;
				cout << "ID: ";
				if (Mode)
				{
					ID_c = tokens[3];
					cout << ID_c << endl;
				}
				else
					cin >> ID_c;
				cout << "PW: ";
				if (Mode)
				{
					PW_c = tokens[4];
					cout << PW_c << endl;
				}
				else
				{
					cin >> PW_c;
					getchar();
				}
				if (!membercount)
				{
					memberlist[membercount] = new Member;// 처음 회원가입 한 사용자는 Member의 자격 획득
					memberlist[membercount]->SetMember(RRN_c, ID_c, PW_c);
					membercount++;
					cout << "Successfully Requested!" << endl;
				}
				else
				{
					{
						for (int i = 0; i < membercount; i++)
						{
							if (!memberlist[i]->CheckIfAlready(RRN_c, ID_c))
							{
								checkpoint = 0;
								break;
							}
							else
								checkpoint = 1;

						}
					}
					if (checkpoint)
					{
						memberlist[membercount] = new Member;// 처음 회원가입 한 사용자는 Member의 자격 획득
						memberlist[membercount]->SetMember(RRN_c, ID_c, PW_c);
						membercount++;
						cout << "Successfully Requested!" << endl;
					}
					else
						cout << "Request Failed!" << endl;
				}
				if (!Mode)
					inLogWrite << "1" << " " << "1" << " " << RRN_c << " " << ID_c << " " << PW_c << " " << endl;
				break;
				/***********************************************************/
			case 2:
				cout << "Selected Menu: 1.2 Login" << endl;
				cout << "ID: ";
				if (Mode)
				{
					ID_c = tokens[2];
					cout << ID_c << endl;
				}
				else
					cin >> ID_c;
				cout << "PW: ";
				if (Mode)
				{
					PW_c = tokens[3];
					cout << PW_c << endl;
				}
				else
				{
					cin >> PW_c;
					getchar();
				}
				if (!membercount)
				{
					cout << "Request Failed!" << endl;
					break;
				}
				for (int i = 0; i < membercount; i++)
				{
					if (memberlist[i]->checkList_Login(ID_c, PW_c))
					{
						checkpoint = 1;
						currIndex = i;
						break;
					}
					else
						checkpoint = 0;

				}
				if (checkpoint)
				{
					for (int i = 0; i <= groupcount; i++)
					{
						if (groupcount == 0)
							break;
						if (Grouplist[i].checkName(memberlist[currIndex]->Getname()))
						{
							groupindex = i;
							break;
						}

					}
					memberlist[currIndex]->Login();
					cout << "Successfully Requested!" << endl;
					StopMenu1 = 0;// 로그인을 하면 1번메뉴의 진입을 막고 2,3,4메뉴의 진입을 하게 한다. 메뉴를 출력하는 것은 다형성을 사용한다.

				}
				else
					cout << "Request Failed!" << endl;
				if (!Mode)
					inLogWrite << "1" << " " << "2" << " " << ID_c << " " << PW_c << " " << endl;
				break;
				/******************************************************/
			case 3:
				cout << "Selected Menu: 1.3 Program Exit" << endl;
				if (membercount)
					for (int i = 0; i<membercount; i++)
						delete memberlist[i];// 프로그램 종료시 new로 동적할당한 member포인터 해제.
				inLogWrite.close();
				return 0;
			}

		}
		memberlist[currIndex]->printMenu();//각 derived, base class에 의해 알맞는 메뉴가 출력된다.
		//cin >> selectMenu1 >> selectMenu2;
		if (Mode == 1)
		{
			getline(inLogRead, line);
			if (line == "")
			{
				//end of file with newline
				if (inLogRead.eof())
				{
					//stop reading from logfile 
					//stdin mode starts
					inLogRead.close();
					Mode = 0;
					getline(cin, line);
					if (line == "")
					{
						cout << "Selected Menu: Undefined menu selection" << endl; fflush(stdout);
						continue;
					}
					stream.str(line);
					nTokens = 0;
					clearTokens(tokens);
					//Read all tokens(seperated by " ")
					while (stream >> tokens[nTokens])
						nTokens++;
					stream.clear();
					selectMenu1 = atoi(tokens[0].c_str());
					selectMenu2 = atoi(tokens[1].c_str());
					//when first stdin input was newline
					//continue without loggin input
				}
				//middle of file with new line
				//continue without logging
				else
				{
					cout << "\nSelected Menu: Undefined menu selection" << endl; fflush(stdout);
					continue;
				}
			}

			//inputs != newline
			else
			{
				stream.str(line);
				nTokens = 0;
				clearTokens(tokens);
				//Read all tokens(seperated by " ")
				while (stream >> tokens[nTokens])
					nTokens++;
				stream.clear();
				selectMenu1 = atoi(tokens[0].c_str());
				selectMenu2 = atoi(tokens[1].c_str());
				cout << selectMenu1 << " " << selectMenu2 << endl; fflush(stdout);
			}
		}
		//stdin mode
		else
		{
			getline(cin, line);
			stream.str(line);
			nTokens = 0;
			clearTokens(tokens);
			//Read all tokens(seperated by " ")
			while (stream >> tokens[nTokens])
				nTokens++;
			stream.clear();
			selectMenu1 = atoi(tokens[0].c_str());
			selectMenu2 = atoi(tokens[1].c_str());
		}

		if (selectMenu1 == 2 || (selectMenu1 == 0 && selectMenu2 == 0))
		{
			switch (selectMenu2)
			{
			case 1:
				cout << "Selected Menu: 2.1 Logout" << endl;
				cout << "Successfully Requested" << endl;
				memberlist[currIndex]->Logout();
				StopMenu1 = 1;
				if (!Mode)
					inLogWrite << "2" << " " << "1" << " " << endl;
				break;
				/********************************************************************************************************************************************************************************************************/
			case 2:
				cout << "Selected Menu: 2.2 Unsubscribe from System" << endl;
				cout << "ID: ";
				if (Mode)
				{
					ID_c = tokens[2];
					cout << ID_c << endl;
				}
				else
					cin >> ID_c;
				cout << "PW: ";
				if (Mode)
				{
					PW_c = tokens[3];
					cout << PW_c << endl;
				}
				else
				{
					cin >> PW_c;
					getchar();
				}
				if (memberlist[currIndex]->checkList_Out(ID_c, PW_c))
				{
					if (membercount == 1)
					{
						delete memberlist[currIndex];
						membercount--;
						cout << "Succesfully Requested!" << endl;
						StopMenu1 = 1;
					}
					else if (membercount >= 2) {
						memberlist[currIndex]->Initialization();
						for (int i = currIndex + 1; i < membercount; i++)
						{
							if (memberlist[i]->WhatIsYourInherit() == 0)//회원탈퇴를 요청한 사용자의 뒤의 사용자가 member였으면, 그 전 포인터를 해제하고, 다시 member를 할당 해준다.
							{
								delete memberlist[i - 1];
								memberlist[i - 1] = new Member;
								memberlist[i - 1]->ShiftMember(memberlist[i]->GetRRN(), memberlist[i]->GetID(), memberlist[i]->GetPW(), memberlist[i]->GetLogin(), memberlist[i]->GetInherit());
								memberlist[i - 1]->Logout();
							}
							else if (memberlist[i]->WhatIsYourInherit() == 1)//회원탈퇴를 요청한 사용자의 뒤의 사용자가 Group member였으면, 그 전 포인터를 해제하고, 다시 Group member를 할당 해준다.
							{
								delete memberlist[i - 1];
								memberlist[i - 1] = new GroupMember(memberlist[i]->GetRRN(), memberlist[i]->GetID(), memberlist[i]->GetPW(), memberlist[i]->Getname());
								memberlist[i - 1]->Logout();
								memberlist[i - 1]->SetInherit_1();//위 두개의 코드는 각 클래스의 생성자에서 로그인과, inheritance변수를 각 상황에 맞게 설정하지 않았기 때문에 인위적으로 알맞게 바꿔준다.
							}
							else if (memberlist[i]->WhatIsYourInherit() == 2)//회원탈퇴를 요청한 사용자의 뒤의 사용자가 Group Leader였으면, 그 전 포인터를 해제하고, 다시 Group Leader를 할당 해준다.
							{
								delete memberlist[i - 1];
								memberlist[i - 1] = new GroupLeader(memberlist[i]->GetRRN(), memberlist[i]->GetID(), memberlist[i]->GetPW(), memberlist[i]->Getname(), 1);
								memberlist[i - 1]->Logout();
								memberlist[i - 1]->SetInherit_2();//위 두개의 코드는 각 클래스의 생성자에서 로그인과, inheritance변수를 각 상황에 맞게 설정하지 않았기 때문에 인위적으로 알맞게 바꿔준다.
							}
						}
						delete memberlist[membercount - 1];
						membercount--;
						cout << "Succesfully Requested!" << endl;
						StopMenu1 = 1;
					}
				}
				else
					cout << "Request Failed" << endl;
				if (!Mode)
					inLogWrite << "2" << " " << "2" << " " << ID_c << " " << PW_c << " " << endl;
				break;
				/********************************************************************************************************************************************************************************************************/
			case 3:
				cout << "Selected Menu: 2.3 Delete Existing Vote Item" << endl;
				cout << "<General Votes>" << endl;
				if (!NormalVotecount)
					cout << "None" << endl;
				else
					for (int i = 0; i < NormalVotecount; i++)
						cout << NormalVotelist[i].GetName() << ",";
				cout << endl;
				cout << "Subject to Delete:";
				if (Mode)
				{
					VoteName_c = tokens[3];
					cout << VoteName_c << endl;
				}
				else
				{
					cin >> VoteName_c;
					getchar();
				}
				for (int i = 0; i <= NormalVotecount; i++)
				{
					if (!NormalVotelist[i].CheckName(VoteName_c))
					{
						checkpoint = 1;
						voteIndex = i;
						break;
					}
					else
						checkpoint = 0;
				}
				if (checkpoint)
				{
					if (NormalVotecount == 1)
						NormalVotelist[voteIndex].init();
					else
					{
						NormalVotelist[voteIndex].init();
						for (int i = voteIndex + 1; i < NormalVotecount; i++)
						{
							NormalVotelist[i - 1].Shift(NormalVotelist[i].GetName(), NormalVotelist[i].Getitems(), NormalVotelist[i].Getcount());//
							for (int k = 0; k < NormalVotelist[i].VotedRRN.size(); i++)
							{
								NormalVotelist[i - 1].VotedRRN.clear();
								NormalVotelist[i - 1].VotedRRN.push_back(NormalVotelist[i].VotedRRN[k]);
							}
						}
						NormalVotelist[NormalVotecount - 1].init();
					}
					NormalVotecount--;
					cout << "Successfully Requested!" << endl;
				}
				else
					cout << "Requested Failed" << endl;
				if (!Mode)
					inLogWrite << "2" << " " << "3" << " " << "0" << " " << VoteName_c << " " << endl;
				break;
				/********************************************************************************************************************************************************************************************************/
			case 4:
				cout << "Selected Menu: 2.4 Add a New Vote" << endl;
				cout << "<General Votes>" << endl;
				if (!NormalVotecount)
					cout << "None";
				else
				{
					for (int i = 0; i < NormalVotecount; i++)
					{
						cout << NormalVotelist[i].GetName();
						if (NormalVotecount - 1 == i)
							continue;
						else
							cout << ",";
					}
				}
				cout << endl;
				cout << "Vote Subject:";
				if (Mode)
				{
					VoteName_c = tokens[3];
					cout << VoteName_c << endl;
				}
				else
					cin >> VoteName_c;
				cout << "Vote Items:";
				if (Mode)
				{
					selection = atoi(tokens[4].c_str());
					cout << selection << endl;
				}
				else
				{
					cin >> selection;
					getchar();
				}
				for (int i = 0; i <= NormalVotecount; i++)
				{
					if (!NormalVotelist[i].CheckName(VoteName_c))
					{
						checkpoint = 0;
						break;
					}
					else
						checkpoint = 1;
				}
				if (checkpoint&&selection >= 3 && selection <= 10)//투표안이 3개 이상 10개 이하임을 검사한다.
				{
					NormalVotelist[NormalVotecount].SetVote(VoteName_c, selection);
					NormalVotecount++;
					cout << "Successfully Requested!" << endl;
				}
				else
					cout << "Request Failed!" << endl;
				if (!Mode)
					inLogWrite << "2" << " " << "4" << " " << "0" << " " << VoteName_c << " " << selection << " " << endl;
				break;
				/********************************************************************************************************************************************************************************************************/
			case 5:
				cout << "Selected Menu: 2.5 List All General Vote Items" << endl;
				cout << "<General Vote>" << endl;
				if (!NormalVotecount)
					cout << "None" << endl;
				else
				{
					for (int i = 0; i < NormalVotecount; i++)
						NormalVotelist[i].ShowVote();
				}
				if (!Mode)
					inLogWrite << "2" << " " << "5" << " " << endl;
				break;
				/********************************************************************************************************************************************************************************************************/
			case 6:
				cout << "Selected Menu: 2.6 Cast a Vote" << endl;
				cout << "<General Vote>" << endl;
				if (!NormalVotecount)
					cout << "None" << endl;
				else
				{
					for (int i = 0; i < NormalVotecount; i++)
						NormalVotelist[i].ShowVote();
				}
				cout << "Vote Subjects: ";
				if (Mode)
				{
					VoteName_c = tokens[3];
					cout << VoteName_c << endl;
				}
				else
					cin >> VoteName_c;
				cout << "Vote for:";
				if (Mode)
				{
					selection = atoi(tokens[4].c_str());
					cout << selection << endl;
				}
				else
				{
					cin >> selection;
					getchar();
				}
				for (int i = 0; i < NormalVotecount; i++)
				{
					if (!NormalVotelist[i].CheckName(VoteName_c))
					{
						voteIndex = i;
						checkpoint = 1;
						break;
					}
					else
						checkpoint = 0;
				}

				if (checkpoint)//투표이름이 시스템에 있고, 이 사용자가 투표를 이미 한 사용자인지를, 탈퇴하였다가 동일한 RRN을 지닌채로 다시 투표에 임하는지를 검사한다.
				{
					if (NormalVotelist[voteIndex].AlreadyVoted(memberlist[currIndex]->GetRRN()))
					{
						NormalVotelist[voteIndex].Voting(selection);
						NormalVotelist[voteIndex].AddVotedRRN(memberlist[currIndex]->GetRRN());
						cout << "Successfully Requested!" << endl;
					}
					else
						cout << "Request Failed!" << endl;
				}
				else
					cout << "Request Failed!" << endl;
				if (!Mode)
					inLogWrite << "2" << " " << "6" << " " << "0" << " " << VoteName_c << " " << selection << " " << "0" << " " << endl;
				break;
				/********************************************************************************************************************************************************************************************************/
			case 7:
				cout << "Selected Menu: 2.7 Join Group" << endl;
				cout << "<Group List>" << endl;
				if (groupcount == 0)
					cout << "None";
				else
				{
					for (int i = 0; i < groupcount; i++)
					{
						cout << Grouplist[i].showName();
						if (groupcount - 1 == i)
							continue;
						else
							cout << ",";
					}
				}
				cout << endl << "Group Name to Join:";
				if (Mode)
				{
					Groupname_c = tokens[2];
					cout << Groupname_c << endl;
				}
				else
				{
					cin >> Groupname_c;
					getchar();
				}
				for (int i = 0; i <= groupcount; i++) {
					if (!Grouplist[i].checkName(Groupname_c))
					{
						checkpoint = 0;
					}
					else
					{
						groupindex = i;
						checkpoint = 1;
						break;
					}
				}
				if (checkpoint)
				{
					Grouplist[groupindex].enterGroup(memberlist[currIndex]->GetID());
					string temp1 = memberlist[currIndex]->GetRRN();
					string temp2 = memberlist[currIndex]->GetID();
					string temp3 = memberlist[currIndex]->GetPW();
					memberlist[currIndex] = new GroupMember(temp1, temp2, temp3, Groupname_c);//Group Member로 자격 획득. 일종의 copy constructor 역할을 한다.
					memberlist[currIndex]->SetInherit_1();
					for (int i = 0; i < groupcount; i++)
					{
						if (Grouplist[i].checkName(Groupname_c))
						{
							groupindex = i;
							break;
						}
					}
					cout << "Successfully Requested!" << endl;
				}
				else
					cout << "Request Failed" << endl;
				if (!Mode)
					inLogWrite << "2" << " " << "7" << " " << Groupname_c << " " << endl;
				break;
				/********************************************************************************************************************************************************************************************************/
			case 8:
				cout << "Selected Menu: 2.8 Create a Group" << endl;
				cout << "<Group List>" << endl;
				if (groupcount == 0)
					cout << "None";
				else
				{
					for (int i = 0; i < groupcount; i++)
					{
						cout << Grouplist[i].showName();
						if (groupcount - 1 == i)
							continue;
						else
							cout << ",";
					}
				}
				cout << endl << "Group Name to Create: ";
				if (Mode)
				{
					Groupname_c = tokens[2];
					cout << Groupname_c << endl;
				}
				else
				{
					cin >> Groupname_c;
					getchar();
				}
				for (int i = 0; i <= groupcount; i++) {
					if (Grouplist[i].checkName(Groupname_c))
					{
						cout << "Request Failed" << endl;
						checkpoint = 0;
						break;
					}
					else
					{
						checkpoint = 1;
					}
				}
				if (checkpoint)
				{
					Grouplist[groupcount].setGroup(Groupname_c, memberlist[currIndex]->GetID());
					string temp1 = memberlist[currIndex]->GetRRN();
					string temp2 = memberlist[currIndex]->GetID();
					string temp3 = memberlist[currIndex]->GetPW();
					memberlist[currIndex] = new GroupLeader(temp1, temp2, temp3, Groupname_c, 1);//Group Leader로 자격 획득. 일종의 copy constructor 역할을 한다.
					memberlist[currIndex]->SetInherit_2();
					groupcount++;
					for (int i = 0; i < groupcount; i++)
					{
						if (Grouplist[i].checkName(Groupname_c))
						{
							groupindex = i;
							break;
						}
					}
					cout << "Successfully Requested!" << endl;
				}
				if (!Mode)
					inLogWrite << "2" << " " << "8" << " " << Groupname_c << " " << endl;
				break;
			case 9:
				cout << "Selected Menu: 2.3 Program Exit" << endl;
				if (membercount)
					for (int i = 0; i<membercount; i++)
						delete memberlist[i];
				inLogWrite.close();
				return 0;
			}


		}
		if (selectMenu1 == 3 || (selectMenu2 == 0 && selectMenu1 == 0))
		{
			switch (selectMenu2)
			{
			case 8:
				cout << "Selected Menu: 3.8 Program Exit" << endl;
				if (membercount)
					for (int i = 0; i < membercount; i++)
						delete memberlist[i];
				inLogWrite.close();
				return 0;
			case 1:
				cout << "Selected Menu: 3.1 Logout" << endl;
				cout << "Successfully Requested" << endl;
				memberlist[currIndex]->Logout();
				StopMenu1 = 1;
				if (!Mode)
					inLogWrite << "3" << " " << "1" << " " << endl;
				break;
				/********************************************************************************************************************************************************************************************************/
			case 2:
				cout << "Selected Menu: 3.2 Unsubscribe from System" << endl;
				cout << "ID: ";
				if (Mode)
				{
					ID_c = tokens[2];
					cout << ID_c << endl;
				}
				else
					cin >> ID_c;
				cout << "PW: ";
				if (Mode)
				{
					PW_c = tokens[3];
					cout << PW_c << endl;
				}
				else
				{
					cin >> PW_c;
					getchar();
				}
				if (memberlist[currIndex]->checkList_Out(ID_c, PW_c))
				{
					if (membercount == 1)
					{
						Grouplist[groupindex].pop(ID_c);
						delete memberlist[currIndex];
						membercount--;
						cout << "Succesfully Requested!" << endl;
						StopMenu1 = 1;
					}
					else if (membercount >= 2) {
						Grouplist[groupindex].pop(ID_c);
						memberlist[currIndex]->Initialization();
						for (int i = currIndex + 1; i < membercount; i++)//2.2와 동일하다.
						{
							if (memberlist[i]->WhatIsYourInherit() == 0)
							{
								delete memberlist[i - 1];
								memberlist[i - 1] = new Member;
								memberlist[i - 1]->ShiftMember(memberlist[i]->GetRRN(), memberlist[i]->GetID(), memberlist[i]->GetPW(), memberlist[i]->GetLogin(), memberlist[i]->GetInherit());
								memberlist[i - 1]->Logout();
							}
							else if (memberlist[i]->WhatIsYourInherit() == 1)
							{
								delete memberlist[i - 1];
								memberlist[i - 1] = new GroupMember(memberlist[i]->GetRRN(), memberlist[i]->GetID(), memberlist[i]->GetPW(), memberlist[i]->Getname());
								memberlist[i - 1]->Logout();
								memberlist[i - 1]->SetInherit_1();
							}
							else if (memberlist[i]->WhatIsYourInherit() == 2)
							{
								delete memberlist[i - 1];
								memberlist[i - 1] = new GroupLeader(memberlist[i]->GetRRN(), memberlist[i]->GetID(), memberlist[i]->GetPW(), memberlist[i]->Getname(), 1);
								memberlist[i - 1]->Logout();
								memberlist[i - 1]->SetInherit_2();
							}
						}
						delete memberlist[membercount - 1];
						membercount--;
						cout << "Succesfully Requested!" << endl;
						StopMenu1 = 1;
					}
				}
				else
					cout << "Request Failed" << endl;
				if (!Mode)
					inLogWrite << "3" << " " << "2" << " " << ID_c << " " << PW_c << " " << endl;
				break;
				/********************************************************************************************************************************************************************************************************/
			case 3:
				cout << "Selected Menu: 3.3 Delete Exisiting Vote Item" << endl;
				cout << "<General Votes>" << endl;
				if (!NormalVotecount)
					cout << "None" << endl;
				else
				{
					for (int i = 0; i < NormalVotecount; i++)
					{
						cout << NormalVotelist[i].GetName();
						if (NormalVotecount - 1 == i)
							continue;
						else
							cout << ",";
					}
				}
				cout << endl;
				cout << "<Group Votes>" << endl;
				if (Grouplist[groupindex].GetCount() == 0)
					cout << "None";
				else
					Grouplist[groupindex].showVotename();
				cout << endl << "Select Vote Type(0: general, 1:group): ";
				if (Mode)
				{
					type = atoi(tokens[2].c_str());
					cout << type << endl;
				}
				else
					cin >> type;
				if (type == 0)
				{
					cout << "Subject to Delete:";
					if (Mode)
					{
						VoteName_c = tokens[3];
						cout << VoteName_c << endl;
					}
					else
					{
						cin >> VoteName_c;
						getchar();
					}
					for (int i = 0; i <= NormalVotecount; i++)
					{
						if (!NormalVotelist[i].CheckName(VoteName_c))
						{
							checkpoint = 1;
							voteIndex = i;
							break;
						}
						else
							checkpoint = 0;
					}
					if (checkpoint)
					{
						if (NormalVotecount == 1)
							NormalVotelist[voteIndex].init();
						else
						{
							NormalVotelist[voteIndex].init();
							for (int i = voteIndex + 1; i < NormalVotecount; i++)
							{
								NormalVotelist[i - 1].Shift(NormalVotelist[i].GetName(), NormalVotelist[i].Getitems(), NormalVotelist[i].Getcount());//
								for (int k = 0; k < NormalVotelist[i].VotedRRN.size(); i++)
								{
									NormalVotelist[i - 1].VotedRRN.clear();
									NormalVotelist[i - 1].VotedRRN.push_back(NormalVotelist[i].VotedRRN[k]);
								}
							}
							NormalVotelist[NormalVotecount - 1].init();
						}
						NormalVotecount--;
						cout << "Successfully Requested!" << endl;
					}
					else
						cout << "Requested Failed" << endl;
				}
				else if (type == 1)
				{
					cout << "Subject to Delete:";
					if (Mode)
					{
						VoteName_c = tokens[3];
						cout << VoteName_c << endl;
					}
					else
					{
						cin >> VoteName_c;
						getchar();
					}
					if (Grouplist[groupindex].CheckName(VoteName_c) == false)
					{
						Grouplist[groupindex].Remove(VoteName_c);
						cout << "Successfully Requested!" << endl;
					}
					else
						cout << "Request Failed!" << endl;
				}
				break;
				if (!Mode)
					inLogWrite << "3" << " " << "3" << " " << type << " " << VoteName_c << " " << endl;
				/********************************************************************************************************************************************************************************************************/
			case 4:
				cout << "Selected Menu: 3.4 Add a New Vote" << endl;
				cout << "<General Votes>" << endl;
				if (!NormalVotecount)
					cout << "None";
				else
				{
					for (int i = 0; i < NormalVotecount; i++)
					{
						cout << NormalVotelist[i].GetName();
						if (NormalVotecount - 1 == i)
							continue;
						else
							cout << ",";
					}
				}
				cout << endl;
				cout << "<Group Votes>" << endl;
				if (Grouplist[groupindex].GetCount() == 0)
					cout << "None";
				else
					Grouplist[groupindex].showVotename();
				cout << endl << "Select Vote Type(0: general, 1:group): ";
				if (Mode)
				{
					type = atoi(tokens[2].c_str());
					cout << type << endl;
				}
				else
					cin >> type;
				if (type == 0)
				{
					cout << "Vote Subject:";
					if (Mode)
					{
						VoteName_c = tokens[3];
						cout << VoteName_c << endl;
					}
					else
						cin >> VoteName_c;
					cout << "Vote Items:";
					if (Mode)
					{
						selection = atoi(tokens[4].c_str());
						cout << selection << endl;
					}
					else
					{
						cin >> selection;
						getchar();
					}
					for (int i = 0; i <= NormalVotecount; i++)
					{
						if (!NormalVotelist[i].CheckName(VoteName_c))
						{
							checkpoint = 0;
							break;
						}
						else
							checkpoint = 1;
					}
					if (checkpoint&&selection >= 3 && selection <= 10)
					{
						NormalVotelist[NormalVotecount].SetVote(VoteName_c, selection);
						NormalVotecount++;
						cout << "Successfully Requested!" << endl;
					}
					else
						cout << "Request Failed!" << endl;
				}
				else if (type == 1)
				{
					cout << "Vote Subject:";
					if (Mode)
					{
						VoteName_c = tokens[3];
						cout << VoteName_c << endl;
					}
					else
						cin >> VoteName_c;
					cout << "Vote Items:";
					if (Mode)
					{
						selection = atoi(tokens[4].c_str());
						cout << selection << endl;
					}
					else
					{
						cin >> selection;
						getchar();
					}
					if (Grouplist[groupindex].CheckName(VoteName_c) == true && selection >= 3 && selection <= 10)
					{
						Grouplist[groupindex].SetVote(VoteName_c, selection);
						cout << "Request Success!" << endl;
					}
					else
						cout << "Request Failed" << endl;
				}
				if (!Mode)
					inLogWrite << "3" << " " << "4" << " " << type << " " << VoteName_c << " " << selection << " " << endl;
				break;
				/********************************************************************************************************************************************************************************************************/
			case 5:
				cout << "Selected Menu: 3.5 List All Vote Items" << endl;
				cout << "<General Vote List>" << endl;
				if (NormalVotecount == 0)
					cout << "None" << endl;
				else
				{
					for (int i = 0; i < NormalVotecount; i++)
						NormalVotelist[i].ShowVote();
				}
				cout << "<Group Vote List>" << endl;
				if (Grouplist[groupindex].GetCount() == 0)
					cout << "None" << endl;
				else
				{
					Grouplist[groupindex].ShowVote();
				}
				if (!Mode)
					inLogWrite << "3" << " " << "5" << " " << endl;
				break;
				/********************************************************************************************************************************************************************************************************/
			case 6:
				cout << "Selected Menu: 3.6 Cast a Vote" << endl;
				cout << "<General Votes>" << endl;
				if (!NormalVotecount)
					cout << "None";
				else
				{
					for (int i = 0; i < NormalVotecount; i++)
					{
						cout << NormalVotelist[i].GetName();
						if (NormalVotecount - 1 == i)
							continue;
						else
							cout << ",";
					}
				}
				cout << endl;
				cout << "<Group Votes>" << endl;
				if (Grouplist[groupindex].GetCount() == 0)
					cout << "None";
				else
					Grouplist[groupindex].showVotename();
				cout << endl << "Select Vote Type(0: general, 1:group): ";
				if (Mode)
				{
					type = atoi(tokens[2].c_str());
					cout << type << endl;
				}
				else
					cin >> type;
				if (type == 0)
				{
					cout << "Vote Subjects: ";
					if (Mode)
					{
						VoteName_c = tokens[3];
						cout << VoteName_c << endl;
					}
					else
						cin >> VoteName_c;
					cout << "Vote for:";
					if (Mode)
					{
						selection = atoi(tokens[4].c_str());
						cout << selection << endl;
					}
					else
					{
						cin >> selection;
						getchar();
					}
					for (int i = 0; i < NormalVotecount; i++)
					{
						if (!NormalVotelist[i].CheckName(VoteName_c))
						{
							voteIndex = i;
							checkpoint = 1;
							break;
						}
						else
							checkpoint = 0;
					}

					if (checkpoint)
					{
						if (NormalVotelist[voteIndex].AlreadyVoted(memberlist[currIndex]->GetRRN()))
						{
							NormalVotelist[voteIndex].Voting(selection);
							NormalVotelist[voteIndex].AddVotedRRN(memberlist[currIndex]->GetRRN());
							cout << "Successfully Requested!" << endl;
						}
						else
							cout << "Request Failed!" << endl;
					}
					else
						cout << "Request Failed!" << endl;
				}
				else if (type == 1)
				{
					cout << "Vote Subjects: ";
					if (Mode)
					{
						VoteName_c = tokens[3];
						cout << VoteName_c;
					}
					else
						cin >> VoteName_c;
					cout << "Vote for:";
					if (Mode)
					{
						selection = atoi(tokens[4].c_str());
						selection2 = atoi(tokens[5].c_str());
						cout << selection << " " << selection2 << endl;
					}
					else
					{
						cin >> selection >> selection2;
						getchar();
					}
					if (Grouplist[groupindex].CheckName(VoteName_c) == false && Grouplist[groupindex].AireadyVoted(VoteName_c, memberlist[currIndex]->GetRRN()) && selection != selection2)
					{
						Grouplist[groupindex].Voting(VoteName_c, memberlist[currIndex]->GetRRN(), selection, selection2);
						cout << "Request Success!" << endl;
					}
					else
						cout << "Request Failed!" << endl;
				}
				if (!Mode&&type == 0)
					inLogWrite << "3" << " " << "6" << " " << type << " " << VoteName_c << " " << selection << " " << endl;
				else if (!Mode&&type == 1)
					inLogWrite << "3" << " " << "6" << " " << type << " " << VoteName_c << " " << selection << " " << selection2 << " " << endl;
				break;
				/********************************************************************************************************************************************************************************************************/
			case 7:
				cout << "Selected Menu: 3.7 Unsubscribe from Group" << endl;
				string temp1 = memberlist[currIndex]->GetRRN();
				string temp2 = memberlist[currIndex]->GetID();
				string temp3 = memberlist[currIndex]->GetPW();
				delete memberlist[currIndex];
				memberlist[currIndex] = new Member;//그룹에서 탈퇴하면 사용자는 Member로 돌아가기 때문에, 그 사용자의 인덱스를 찾아 그자리를 해제하고, 다시 그자리에 새로 동적할당을 해준다.
				memberlist[currIndex]->SetMember(temp1, temp2, temp3);
				memberlist[currIndex]->Login();
				Grouplist[groupindex].pop(temp2);
				cout << "Successfully Request!" << endl;
				if (!Mode)
					inLogWrite << "3" << " " << "7" << " " << endl;
				break;


			}
		}
		if (selectMenu1 == 4 || (selectMenu1 == 0 && selectMenu2 == 0))
		{
			switch (selectMenu2)
			{
			case 1:
				cout << "Selected Menu: 4.1 Logout" << endl;
				cout << "Successfully Requested" << endl;
				memberlist[currIndex]->Logout();
				StopMenu1 = 1;
				if (!Mode)
					inLogWrite << "4" << " " << "1" << " " << endl;
				break;
				/********************************************************************************************************************************************************************************************************/
			case 2:
				cout << "Selected Menu: 4.2 Delete Exisiting Vote Item" << endl;
				cout << "<General Votes>" << endl;
				if (!NormalVotecount)
					cout << "None";
				else
				{
					for (int i = 0; i < NormalVotecount; i++)
					{
						cout << NormalVotelist[i].GetName();
						if (NormalVotecount - 1 == i)
							continue;
						else
							cout << ",";
					
					}
				}
				cout << endl;
				cout << "<Group Votes>" << endl;
				if (Grouplist[groupindex].GetCount() == 0)
					cout << "None";
				else
					Grouplist[groupindex].showVotename();
				cout << endl << "Select Vote Type(0: general, 1:group): ";
				if (Mode)
				{
					type = atoi(tokens[2].c_str());
					cout << type << endl;
				}
				else
					cin >> type;
				if (type == 0)
				{
					cout << "Subject to Delete:";
					if (Mode)
					{
						VoteName_c = tokens[3];
						cout << VoteName_c << endl;
					}
					else
					{
						cin >> VoteName_c;
						getchar();
					}
					for (int i = 0; i <= NormalVotecount; i++)
					{
						if (!NormalVotelist[i].CheckName(VoteName_c))
						{
							checkpoint = 1;
							voteIndex = i;
							break;
						}
						else
							checkpoint = 0;
					}
					if (checkpoint)
					{
						if (NormalVotecount == 1)
							NormalVotelist[voteIndex].init();
						else
						{
							NormalVotelist[voteIndex].init();
							for (int i = voteIndex + 1; i < NormalVotecount; i++)
							{
								NormalVotelist[i - 1].Shift(NormalVotelist[i].GetName(), NormalVotelist[i].Getitems(), NormalVotelist[i].Getcount());//
								for (int k = 0; k < NormalVotelist[i].VotedRRN.size(); i++)
								{
									NormalVotelist[i - 1].VotedRRN.clear();
									NormalVotelist[i - 1].VotedRRN.push_back(NormalVotelist[i].VotedRRN[k]);
								}
							}
							NormalVotelist[NormalVotecount - 1].init();
						}
						NormalVotecount--;
						cout << "Successfully Requested!" << endl;
					}
					else
						cout << "Requested Failed" << endl;
				}
				else if (type == 1)
				{
					cout << "Subject to Delete:";
					if (Mode)
					{
						VoteName_c = tokens[3];
						cout << VoteName_c << endl;
					}
					else
					{
						cin >> VoteName_c;
						getchar();
					}
					if (Grouplist[groupindex].CheckName(VoteName_c) == false)
					{
						Grouplist[groupindex].Remove(VoteName_c);
						cout << "Successfully Requested!" << endl;
					}
					else
						cout << "Request Failed!" << endl;
				}
				break;
				if (!Mode)
					inLogWrite << "4" << " " << "2" << " " << type << " " << VoteName_c << " " << endl;
				/********************************************************************************************************************************************************************************************************/
			case 3:
				cout << "Selected Menu: 4.3 Add a New Vote" << endl;
				cout << "<General Votes>" << endl;
				if (!NormalVotecount)
					cout << "None";
				else
				{
					for (int i = 0; i < NormalVotecount; i++)
					{
						cout << NormalVotelist[i].GetName();
						if (NormalVotecount - 1 == i)
							continue;
						else
							cout << ",";
					}
				}
				cout << endl;
				cout << "<Group Votes>" << endl;
				if (Grouplist[groupindex].GetCount() == 0)
					cout << "None";
				else
					Grouplist[groupindex].showVotename();
				cout << endl << "Select Vote Type(0: general, 1:group): ";
				if (Mode)
				{
					type = atoi(tokens[2].c_str());
					cout << type << endl;
				}
				else
					cin >> type;
				if (type == 0)
				{
					cout << "Vote Subject:";
					if (Mode)
					{
						VoteName_c = tokens[3];
						cout << VoteName_c << endl;
					}
					else
						cin >> VoteName_c;
					cout << "Vote Items:";
					if (Mode)
					{
						selection = atoi(tokens[4].c_str());
						cout << selection << endl;
					}
					else
					{
						cin >> selection;
						getchar();
					}
					for (int i = 0; i <= NormalVotecount; i++)
					{
						if (!NormalVotelist[i].CheckName(VoteName_c))
						{
							checkpoint = 0;
							break;
						}
						else
							checkpoint = 1;
					}
					if (checkpoint&&selection >= 3 && selection <= 10)
					{
						NormalVotelist[NormalVotecount].SetVote(VoteName_c, selection);
						NormalVotecount++;
						cout << "Successfully Requested!" << endl;
					}
					else
						cout << "Request Failed!" << endl;
				}
				else if (type == 1)
				{
					cout << "Vote Subject:";
					if (Mode)
					{
						VoteName_c = tokens[3];
						cout << VoteName_c << endl;
					}
					else
						cin >> VoteName_c;
					cout << "Vote Items:";
					if (Mode)
					{
						selection = atoi(tokens[4].c_str());
						cout << selection << endl;
					}
					else
					{
						cin >> selection;
						getchar();
					}
					if (Grouplist[groupindex].CheckName(VoteName_c) == true && selection >= 3 && selection <= 10)
					{
						Grouplist[groupindex].SetVote(VoteName_c, selection);
						cout << "Request Success!" << endl;
					}
					else
						cout << "Request Failed" << endl;
				}
				if (!Mode)
					inLogWrite << "4" << " " << "3" << " " << type << " " << VoteName_c << " " << selection << " " << endl;
				break;
				/********************************************************************************************************************************************************************************************************/
			case 4:
				cout << "Selected Menu: 4.4 List All Vote Items" << endl;
				cout << "<General Vote List>" << endl;
				if (NormalVotecount == 0)
					cout << "None" << endl;
				else
				{
					for (int i = 0; i < NormalVotecount; i++)
						NormalVotelist[i].ShowVote();
				}
				cout << "<Group Vote List>" << endl;
				if (Grouplist[groupindex].GetCount() == 0)
					cout << "None" << endl;
				else
				{
					Grouplist[groupindex].ShowVote();
				}
				if (!Mode)
					inLogWrite << "4" << " " << "4" << " " << " " << endl;
				break;
				/********************************************************************************************************************************************************************************************************/
			case 5:
				cout << "Selected Menu: 4.5 Cast a Vote" << endl;
				cout << "<General Votes>" << endl;
				if (!NormalVotecount)
					cout << "None";
				else
				{
					for (int i = 0; i < NormalVotecount; i++)
					{
						cout << NormalVotelist[i].GetName();
						if (NormalVotecount - 1 == i)
							continue;
						else
							cout << ",";
					}
				}
				cout << endl;
				cout << "<Group Votes>" << endl;
				if (Grouplist[groupindex].GetCount() == 0)
					cout << "None";
				else
					Grouplist[groupindex].showVotename();
				cout << endl << "Select Vote Type(0: general, 1:group): ";
				if (Mode)
				{
					type = atoi(tokens[2].c_str());
					cout << type << endl;
				}
				else
					cin >> type;
				if (type == 0)
				{
					cout << "Vote Subjects: ";
					if (Mode)
					{
						VoteName_c = tokens[3];
						cout << VoteName_c << endl;
					}
					else
						cin >> VoteName_c;
					cout << "Vote for:";
					if (Mode)
					{
						selection = atoi(tokens[4].c_str());
						cout << selection << endl;
					}
					else
					{
						cin >> selection;
						getchar();
					}
					for (int i = 0; i < NormalVotecount; i++)
					{
						if (!NormalVotelist[i].CheckName(VoteName_c))
						{
							voteIndex = i;
							checkpoint = 1;
							break;
						}
						else
							checkpoint = 0;
					}

					if (checkpoint)
					{
						if (NormalVotelist[voteIndex].AlreadyVoted(memberlist[currIndex]->GetRRN()))
						{
							NormalVotelist[voteIndex].Voting(selection);
							NormalVotelist[voteIndex].AddVotedRRN(memberlist[currIndex]->GetRRN());
							cout << "Successfully Requested!" << endl;
						}
						else
							cout << "Request Failed!" << endl;
					}
					else
						cout << "Request Failed!" << endl;
				}
				else if (type == 1)
				{
					cout << "Vote Subjects: ";
					if (Mode)
					{
						VoteName_c = tokens[3];
						cout << VoteName_c << endl;
					}
					else
						cin >> VoteName_c;
					cout << "Vote for:";
					if (Mode)
					{
						selection = atoi(tokens[4].c_str());
						selection2 = atoi(tokens[5].c_str());
						cout << selection << " " << selection2 << endl;
					}
					else
					{
						cin >> selection >> selection2;
						getchar();
					}
					if (Grouplist[groupindex].CheckName(VoteName_c) == false && Grouplist[groupindex].AireadyVoted(VoteName_c, memberlist[currIndex]->GetRRN()) && selection != selection2)
					{
						Grouplist[groupindex].Voting(VoteName_c, memberlist[currIndex]->GetRRN(), selection, selection2);
						cout << "Request Success!" << endl;
					}
					else
						cout << "Request Failed!" << endl;
				}
				if (!Mode&&type == 0)
					inLogWrite << "4" << " " << "5" << " " << type << " " << VoteName_c << " " << selection << " " << endl;
				else if (!Mode&&type == 1)
					inLogWrite << "4" << " " << "5" << " " << type << " " << VoteName_c << " " << selection << " " << selection2 << " " << endl;
				break;
				/********************************************************************************************************************************************************************************************************/
			case 6:
				cout << "Selected Menu: 4.6 List All Group Members" << endl;
				Grouplist[groupindex].showGroup();
				if (!Mode)
					inLogWrite << "4" << " " << "6" << " " << endl;
				break;
				/********************************************************************************************************************************************************************************************************/
			case 7:
				cout << "Selected Menu: 4.7 Ban a Member from Group" << endl;
				cout << "Group Member's ID to Ban:";
				if (Mode)
				{
					ID_c = tokens[2];
					cout << ID_c << endl;
				}
				else
				{
					cin >> ID_c;
					getchar();
				}
				if (Grouplist[groupindex].BanMember(ID_c))//어떠한 사람이 밴되었고 그 사람은 그룹에 속하지 않음->지위 격하 과정 필요
				{
					for (int i = 0; i < membercount; i++)
					{
						if (memberlist[i]->GetID() == ID_c)
						{
							BanIndex = i;
							break;
						}
					}
					string temp1 = memberlist[BanIndex]->GetRRN();
					string temp2 = memberlist[BanIndex]->GetID();
					string temp3 = memberlist[BanIndex]->GetPW();
					delete memberlist[BanIndex];
					memberlist[BanIndex] = new Member(temp1, temp2, temp3);
					memberlist[BanIndex]->Logout();
					memberlist[BanIndex]->SetInherit_0();
					cout << "Sucessfully Requested!" << endl;
				}
				else
					cout << "Request Failed!" << endl;
				if (!Mode)
					inLogWrite << "4" << " " << "7" << " " << " " << ID_c << " " << endl;
				break;
				/********************************************************************************************************************************************************************************************************/
			case 0:
				cout << "<Member List>" << endl;
				for (int i = 0; i < membercount; i++)
				{
					if (memberlist[i]->GetInherit() == 0)
						cout << "[ID]: " << memberlist[i]->GetID() << "[Joined Group]: " << "None" << "[Position]: Member" << endl;
					else if (memberlist[i]->GetInherit() == 1)
						cout << "[ID]: " << memberlist[i]->GetID() << "[Joined Group]: " << memberlist[i]->Getname() << "[Position]: Group Member" << endl;
					else if (memberlist[i]->GetInherit() == 2)
						cout << "[ID]: " << memberlist[i]->GetID() << "[Joined Group]: " << memberlist[i]->Getname() << "[Position]: Group Leader" << endl;
				}
				cout << "<Group List>" << endl;
				if (groupcount == 0)
					cout << "None";
				else
				{
					for (int i = 0; i < groupcount; i++)
					{
						cout << Grouplist[i].showName();
						if (groupcount - 1 == i)
							continue;
						else
							cout << ",";
					}
				}
				cout << endl;
				cout << "<General Votes>" << endl;
				if (!NormalVotecount)
					cout << "None";
				else
				{
					for (int i = 0; i < NormalVotecount; i++)
					{
						cout << NormalVotelist[i].GetName();
						if (NormalVotecount - 1 == i)
							continue;
						else
							cout << ",";
					}
				}
				cout << endl;
				cout << "<Group Votes>" << endl;
				for (int i = 0; i < groupcount; i++)
				{
					cout << Grouplist[i].showName() << ": ";
					if (Grouplist[i].GetCount() == 0)
						cout << "None";
					else
					{
						Grouplist[i].showVotename();
					}
					cout << endl;
				}
				if (!Mode)
					inLogWrite << "0" << " " << "0" << " " << endl;
				break;
			case 8:
				cout << "Selected Menu: 4.8 Program Exit" << endl;
				if (membercount)
					for (int i = 0; i<membercount; i++)
						delete memberlist[i];
				inLogWrite.close();
				return 0;
				/********************************************************************************************************************************************************************************************************/
			}
		}
	}

	return 0;
}