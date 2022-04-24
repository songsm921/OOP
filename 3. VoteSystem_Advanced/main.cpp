/*
Assignment3�� ���� ������ ���׷��̵� ��������, ��κ��� ����� ���������� �����ϴ�.
�� �ҽ����Ͽ����� �� �޴��� ��ü���� ������ �����Ѵ�.
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
int membercount = 0;//����Ǽ�
int groupcount = 0;//�׷��� ��
int currIndex = -1;//���� �α����� ����� �ε���
int groupindex = -1;//���� �α����� ����� ���� �׷��� �ε���, non member, Member�� ���� ���ǹ��ϰ� ������ ��ġ�� ������, 1->4 2->3,2->4�� �޴��� ������ �� ���ŵȴ�.
int NormalVotecount = 0;//�Ϲ� ��ǥ�� ����
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
	Member *memberlist[MAX_MEMBER];//��� Base Class ��ü
	VoteGroup Grouplist[MAX_GROUP];//�׷�, �׷���ǥ�� ���� ��ü
	NormalVote NormalVotelist[MAX_VOTE_COUNT];//�Ϲ���ǥ�� ���� ��ü
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
	int selectMenu1 = -1;//�޴� ���� �� ���� ��
	int selectMenu2 = 0;//�޴� ���� �� ���� ��
	int checkpoint = 1;//���� �б������� �˻��� �� ���̴� ����
	int selection = 0;//��ǥ ����, ��ǥ ����
	int selection2 = 0;//�׷� ��ǥ���� ��ǥ ���� �� 2��° ��
	int voteIndex = -1;//������ ��ǥ�� �ε���
	int type = -1;// ��ǥ�� Type
	int BanIndex = -1;//�߹� �� ����� �ε���
	int nTokens;
	string RRN_c;
	string ID_c;
	string PW_c;
	string Groupname_c;
	string VoteName_c;//Class�� ���� �ֱ����� �ӽ÷� �־�ּ� �˻縦 �����ϰ� �����ϴ� ����
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
					memberlist[membercount] = new Member;// ó�� ȸ������ �� ����ڴ� Member�� �ڰ� ȹ��
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
						memberlist[membercount] = new Member;// ó�� ȸ������ �� ����ڴ� Member�� �ڰ� ȹ��
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
					StopMenu1 = 0;// �α����� �ϸ� 1���޴��� ������ ���� 2,3,4�޴��� ������ �ϰ� �Ѵ�. �޴��� ����ϴ� ���� �������� ����Ѵ�.

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
						delete memberlist[i];// ���α׷� ����� new�� �����Ҵ��� member������ ����.
				inLogWrite.close();
				return 0;
			}

		}
		memberlist[currIndex]->printMenu();//�� derived, base class�� ���� �˸´� �޴��� ��µȴ�.
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
							if (memberlist[i]->WhatIsYourInherit() == 0)//ȸ��Ż�� ��û�� ������� ���� ����ڰ� member������, �� �� �����͸� �����ϰ�, �ٽ� member�� �Ҵ� ���ش�.
							{
								delete memberlist[i - 1];
								memberlist[i - 1] = new Member;
								memberlist[i - 1]->ShiftMember(memberlist[i]->GetRRN(), memberlist[i]->GetID(), memberlist[i]->GetPW(), memberlist[i]->GetLogin(), memberlist[i]->GetInherit());
								memberlist[i - 1]->Logout();
							}
							else if (memberlist[i]->WhatIsYourInherit() == 1)//ȸ��Ż�� ��û�� ������� ���� ����ڰ� Group member������, �� �� �����͸� �����ϰ�, �ٽ� Group member�� �Ҵ� ���ش�.
							{
								delete memberlist[i - 1];
								memberlist[i - 1] = new GroupMember(memberlist[i]->GetRRN(), memberlist[i]->GetID(), memberlist[i]->GetPW(), memberlist[i]->Getname());
								memberlist[i - 1]->Logout();
								memberlist[i - 1]->SetInherit_1();//�� �ΰ��� �ڵ�� �� Ŭ������ �����ڿ��� �α��ΰ�, inheritance������ �� ��Ȳ�� �°� �������� �ʾұ� ������ ���������� �˸°� �ٲ��ش�.
							}
							else if (memberlist[i]->WhatIsYourInherit() == 2)//ȸ��Ż�� ��û�� ������� ���� ����ڰ� Group Leader������, �� �� �����͸� �����ϰ�, �ٽ� Group Leader�� �Ҵ� ���ش�.
							{
								delete memberlist[i - 1];
								memberlist[i - 1] = new GroupLeader(memberlist[i]->GetRRN(), memberlist[i]->GetID(), memberlist[i]->GetPW(), memberlist[i]->Getname(), 1);
								memberlist[i - 1]->Logout();
								memberlist[i - 1]->SetInherit_2();//�� �ΰ��� �ڵ�� �� Ŭ������ �����ڿ��� �α��ΰ�, inheritance������ �� ��Ȳ�� �°� �������� �ʾұ� ������ ���������� �˸°� �ٲ��ش�.
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
				if (checkpoint&&selection >= 3 && selection <= 10)//��ǥ���� 3�� �̻� 10�� �������� �˻��Ѵ�.
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

				if (checkpoint)//��ǥ�̸��� �ý��ۿ� �ְ�, �� ����ڰ� ��ǥ�� �̹� �� �����������, Ż���Ͽ��ٰ� ������ RRN�� ����ä�� �ٽ� ��ǥ�� ���ϴ����� �˻��Ѵ�.
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
					memberlist[currIndex] = new GroupMember(temp1, temp2, temp3, Groupname_c);//Group Member�� �ڰ� ȹ��. ������ copy constructor ������ �Ѵ�.
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
					memberlist[currIndex] = new GroupLeader(temp1, temp2, temp3, Groupname_c, 1);//Group Leader�� �ڰ� ȹ��. ������ copy constructor ������ �Ѵ�.
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
						for (int i = currIndex + 1; i < membercount; i++)//2.2�� �����ϴ�.
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
				memberlist[currIndex] = new Member;//�׷쿡�� Ż���ϸ� ����ڴ� Member�� ���ư��� ������, �� ������� �ε����� ã�� ���ڸ��� �����ϰ�, �ٽ� ���ڸ��� ���� �����Ҵ��� ���ش�.
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
				if (Grouplist[groupindex].BanMember(ID_c))//��� ����� ��Ǿ��� �� ����� �׷쿡 ������ ����->���� ���� ���� �ʿ�
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