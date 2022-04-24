#include<iostream>
#include <cstring>
#include<cstdio>
#include<vector>
#include <fstream>
#include <sstream>
using namespace std;
int memberCount = 0;
int voteCount = 0;
int login_entire = 0;//logout상태 0 login상태 1 - >사용자 한명이라도 로그인 한 상태라면 1
class Memberlist {
public:
	string RRN;
	string ID;
	string PW;
	int login = 0;//사용자별 로그인 식별값. 
	void SignUp(string RRN_m, string ID_m, string PW_m)
	{
		RRN = RRN_m;
		ID = ID_m;
		PW = PW_m;
	}//회원 가입 중 정보 class에 대입
	void Unsubscribe()
	{
		RRN.clear();
		ID.clear();
		PW.clear();
		login = 0;
	}//회원 탈퇴, class 오브젝트는 사라지지 않지만, 내부 멤버의 값은 모두 초기화
};
class Vote {
public:
	string VoteName;
	int room[10] = { 0 };//투표 선지
	int selectionCount = 0;//투표 선지의 갯수
	vector<string> VotedRRN;//투표한 사용자의 RRN저장. -> 이는 회원 탈퇴를 진행하여도 사라지지 않는다.
	vector<string> VotedID;//투표한 사용자의 ID 저장 - > 회원 탈퇴시 사라진다.
	void Reset()
	{
		VoteName.clear();
		for (int i = 0; i < selectionCount; i++)
			room[i] = 0;
		selectionCount = 0;
		VotedRRN.clear();
		VotedID.clear();
	}//투표안 삭제. 
	void selection(int select)
	{
		room[select - 1]++;
	}//선택한 기호에 ++
	void SaveInfo(string RRN, string ID)
	{
		VotedRRN.push_back(RRN);
		VotedID.push_back(ID);
	}
	int CheckIfVoted(string RRN_c)//회원탈퇴 검사용.
	{
		int check = 1;
		for (int i = 0; i < VotedRRN.size(); i++)
		{
			if (VotedRRN[i] == RRN_c)
			{
				check = 0;
				break;
			}
			else
				check = 1;
		}
		return check;
	}
	int CheckIfVoted_ID(string ID_c)//회원탈퇴는 안했지만, 이미 투표한 사람 검색용
	{
		int check_2 = 1;
		for (int i = 0; i < VotedID.size(); i++)
		{
			if (VotedID[i] == ID_c)
			{
				check_2 = 0;
				break;
			}
			else
				check_2 = 1;
		}
		return check_2;

	}
	void IDRemoveForOut(string ID_c)
	{
		for (int i = 0; i < VotedID.size(); i++)
		{
			if (VotedID[i] == ID_c)
			{
				VotedID[i].clear();
				break;
			}
		}
	}//회원탈퇴를 시도하는 사용자 중 성공한 사용자의 ID값 삭제.
	int CheckIfAlready(string VoteName_c)
	{
		if (VoteName_c == VoteName)
			return 1;
		else
			return 0;
	}//투표안이 이미 있는지 확인
	void ShowItems()
	{
		cout << "Vote Subject : " << VoteName << ", Vote Counts per Item - ";
		for (int i = 0; i < selectionCount; i++)
		{
			cout << "item" << i + 1 << ": " << room[i] << " ";
		}
	}//투표안 모두 공개
};
void printMenu2(int count)
{
	cout << "\n\n=======================" << endl; fflush(stdout);
	cout << "\n\nNum : " << count << endl; fflush(stdout);
	cout << "\n\n=======================" << endl; fflush(stdout);
	cout << "1. Register as a Member" << endl; fflush(stdout);
	cout << "2. Unsubscribe from System" << endl; fflush(stdout);
	cout << "3. Login" << endl; fflush(stdout);
	cout << "4. Logout" << endl; fflush(stdout);
	cout << "5. Delete Existing Vote Item" << endl; fflush(stdout);
	cout << "6. Add a New Vote Item" << endl; fflush(stdout);
	cout << "7. List All Vote Items" << endl; fflush(stdout);
	cout << "8. Cast a Vote" << endl; fflush(stdout);
	cout << "9. Program Exit" << endl; fflush(stdout);
	cout << "=======================" << endl; fflush(stdout);
	cout << "Select Menu:"; fflush(stdout);
}
void clearTokens(string * tokens)
{
	for (int i = 0; i < 4; i++)
		tokens[i].clear();
}
int main()
{
	int Mode;
	ifstream inLogRead;
	ofstream inLogWrite;
	string tokens[4], line;
	stringstream stream;
	cout << "Load log file?(1:yes, 0:no (log will be deleted)):"; fflush(stdout);
	getline(cin, line);
	Mode = atoi(line.c_str());
	const char* tmp = line.c_str();
	if (!Mode)
	{
		inLogWrite.open("commandLog.txt", ios::out);
	}
	else
	{
		inLogRead.open("commandLog.txt", ios::in);
		inLogWrite.open("commandLog.txt", ios::in | ios::app);
	}
	int menucount = 1;
	int menu = 0;
	Memberlist member[50];
	Vote Votelist[100];
	while (menu != 9)
	{
		printMenu2(menucount);
		menucount++;
		string ID_c = "";
		string PW_c = "";
		string VoteName_c = "";
		int selectionCount = 0;
		int select_before = 0;
		int index = -1;
		int login_check = 0;
		int check_2 = 1;
		int check_3 = 1;
		int check_5 = 1;
		int check_6 = 1;
		int check_8 = 1;//대다수의 메뉴에서 바로 진행하지 않고 일종의 체크포인트를 두어 체크포인트가 조건을 만족하면 진행한다. 어떠한 변수는 여러 메뉴에서 사용되기 때문에, WHILE을 한번 돌때마다 지정한 값으로 초기화한다.
		int nTokens = 0;
		int tmp = 0;
		if (Mode)
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
					//when first stdin input was newline
					//continue without loggin input
					if (line == "")
					{
						cout << "Selected Menu: Undefined menu selection" << endl; fflush(stdout);
						continue;
					}
					menu = atoi(line.c_str());
				}
				//middle of file with new line
				//continue without logging
				else
				{
					cout << "\nSelected Menu: Undefined menu selection" << endl; fflush(stdout);
					continue;
				}
			}
			else
			{
				stream.str(line);
				nTokens = 0;
				clearTokens(tokens);
				//Read all tokens(seperated by " ")
				while (stream >> tokens[nTokens])
					nTokens++;
				stream.clear();
				menu = atoi(tokens[0].c_str());
				cout << menu << endl; fflush(stdout);
			}
		}
		else
		{
			getline(cin, line);
			if (line == "")
			{
				cout << "Selected Menu: Undefined menu selection" << endl; fflush(stdout);
				continue;
			}
			menu = atoi(line.c_str());
		}
		
		switch (menu)
		{
		case 1:
		{
			int check = 0;
			string RRN;
			string ID;
			string PW;
			cout << "Selected Menu :1. Register as a Member" << endl;
			cout << "1. Resident Registration Number: ";
			if (Mode)
			{
				RRN = tokens[1];
				cout << RRN << endl;
			}
			else
				cin >> RRN;
			cout << "ID: ";
			if (Mode)
			{
				ID = tokens[2];
				cout << ID << endl;
			}
			else
				cin >> ID;
			cout << "Password: ";
			if (Mode)
			{
				PW = tokens[3];
				cout << PW << endl;
			}
			else
			{
				cin >> PW;
				getchar();// 마지막으로 Enter를 입력 할시에 입력버퍼에 Enter가 남아 Undefined Menu가 출력됨. 이를 막기위한 getchar.
			}
			for (int i = 0; i < memberCount + 1; i++)
			{
				if (member[i].login == 1 || member[i].RRN == RRN || member[i].ID == ID)
				{
					cout << "Registration Fail";
					break;
				}
				else if (member[i].login == 0 && member[i].RRN != RRN && member[i].ID != ID)
				{
					check = 1;
				}
			}//로그인되어있는 사용자가 있거나, RRN이 같은 사람이 있거나, ID가 같은 사람이 있다면 실패문구 출력후 loop탈출. 모든 조건을 만족한다면 check =1
			if (check)
			{
				member[memberCount].SignUp(RRN, ID, PW);
				memberCount++;
				cout << "Registration Done!";
			}//첫번째 등록 사용자는 member[0]에 들어간다. 그러므로 먼저 정보를 넣어준 후, memberCount를 ++하여준다. -> 한명 등록 ->memberCount는 1이므로 알맞다.
			if (!Mode)
				inLogWrite << "1 " << RRN << " " << ID << " " << PW << " " << endl;
			break;
		}
		case 2:
		{
			cout << "Selected Menu :2. Unsubscribe from System" << endl;
			cout << "ID: ";
			if (Mode)
			{
				ID_c = tokens[1];
				cout << ID_c << endl;
			}
			else
				cin >> ID_c;
			cout << "Password: ";
			if (Mode)
			{
				PW_c = tokens[2];
				cout << PW_c << endl;
			}
			else
			{
				cin >> PW_c;
				getchar();
			}
			for (int i = 0; i < 50; i++)
			{
				if (member[i].ID != ID_c)
					check_2 = 0;
				else if (member[i].ID == ID_c)
				{
					index = i;
					check_2 = 1;
					break;
				}
			}//ID가 일치한다면 그 사용자의 class에 접근하기위해 index를 저장한다.
			if (index<0|| check_2 == 0 || member[index].login == 0)
				cout << "Unsubscribe Fail";
			else if (index>=0&&check_2&&member[index].login == 1)
			{
				if (member[index].PW == PW_c)
				{
					for (int i = 0; i < voteCount; i++)
					{
						Votelist[i].IDRemoveForOut(member[index].ID);//투표한 상태에서 투표 상황에는 변화를 주진 않지만, 주민번호만 다르고 아이디만 같은 사용자가 재투표할때는 투표가 가능하기때문에, ID값을 지워준다.
					}
					member[index].Unsubscribe();
					for (int i = index+1; i < 50; i++)
					{
						member[i - 1].RRN = member[i].RRN;
						member[i - 1].ID = member[i].ID;
						member[i - 1].PW = member[i].PW;
						member[i - 1].login = member[i].login;
					}//
					member[memberCount - 1].Unsubscribe();
					memberCount--;
					login_entire = 0;//전체 로그아웃
									 //삭제 절차...
					cout << "Unsubscribe Success!";
				}//PW가 일치한다면, 저장되어있는 member를 한칸씩 앞으로 당겨준다. 그리고 마지막 사용자의 class는 초기화를 시킨다. 이 과정을 모두 마치고 나서 memberCount--,그리고 전체 로그인 값도 0으로 바꿔준다.
				else
					cout << "Unsubscribe Fail";
			}
			if (!Mode)
				inLogWrite << "2 " << ID_c << " " << PW_c << " " << endl;
			break;
		}
		case 3:
		{
			cout << "Selected Menu :3. Login" << endl;
			cout << "ID: ";
			if (Mode)
			{
				ID_c = tokens[1];
				cout << ID_c << endl;
			}
			else
				cin >> ID_c;
			cout << "Password: ";
			if (Mode)
			{
				PW_c = tokens[2];
				cout << PW_c << endl;
			}
			else
			{
				cin >> PW_c;
				getchar();
			}
			for (int i = 0; i < 50; i++)
			{
				if (ID_c == member[i].ID)
				{
					index = i;
					check_3 = 1;
					break;
				}
				else if (ID_c != member[i].ID)
				{
					check_3 = 0;
				}

			}
			if (index>=0&&member[index].login == 0)
			{
				if (member[index].PW == PW_c)
				{
					member[index].login = 1;
					login_entire = 1;
					cout << "Login Success!";
				}
				else
					cout << "Login Failed";

			}//ID가 같고, LOGIN또한 되어있지않고, PW가 일치하다면 LOGIN성공.
			else if (index<0||member[index].login == 1 || check_3 == 0)
				cout << "Login Failed";
			if (!Mode)
				inLogWrite << "3 " << ID_c << " " << PW_c << " " << endl;
			break;
		}
		case 4:
		{
			cout << "Selected Menu :4. Logout" << endl;
			for (int i = 0; i < memberCount; i++)
			{
				if (member[i].login == 1)
				{
					index = i;
					login_check = 1;
					break;
				}
				else
					login_check = 0;
			}
			if (index>=0&&login_check == 1)
			{
				member[index].login = 0;
				login_entire = 0;
				cout << "Logout Success!";
			}
			else if (index<0||login_check == 0)
				cout << "Logout Fail";
			if (!Mode)
				inLogWrite << "4 " << " " << endl;
			break;

		}
		case 5:
		{
			cout << "Selected Menu :5. Delete Existing Vote" << endl;
			cout << "Vote Subject to Delete : ";
			if (Mode)
			{
				VoteName_c = tokens[1];
				cout << VoteName_c << endl;
			}
			else
			{
				cin >> VoteName_c;
				getchar();
			}
			for (int i = 0; i < voteCount+1; i++)
			{
				if (Votelist[i].CheckIfAlready(VoteName_c) == 1)
				{
					index = i;
					check_5 = 1;
					break;
				}
				else if (Votelist[i].CheckIfAlready(VoteName_c) == 0)
				{
					check_5 = 0;
				}
			}
			if (index>=0&&check_5 == 1 && login_entire == 1)
			{
				Votelist[index].Reset();
				for (int i = index + 1; i < 100; i++)
				{
					Votelist[i - 1].VoteName = Votelist[i].VoteName;
					Votelist[i - 1].selectionCount = Votelist[i].selectionCount;
					for (int j = 0; j < 10; j++)
					{
						Votelist[i - 1].room[j] = Votelist[i].room[j];
					}
					for (int k = 0; k < Votelist[i].VotedRRN.size(); k++)
					{
						if (Votelist[i].VotedRRN.size() == 0)
							continue;
						else
							Votelist[i - 1].VotedRRN.push_back(Votelist[i].VotedRRN[k]);
					}
					for (int m = 0; m<Votelist[i].VotedID.size(); m++)
					{
						if (Votelist[i].VotedID.size() == 0)
							continue;
						else
							Votelist[i - 1].VotedID.push_back(Votelist[i].VotedID[m]);;
					}
				}
				Votelist[voteCount - 1].Reset();
				voteCount--;
				cout << "Request Success!";
			}//회원탈퇴의 방법과 동일하다.
			else if (index<0||check_5 == 0 || login_entire == 0)
			{
				cout << "Request Failed";
			}
			if (!Mode)
				inLogWrite << "5 " << VoteName_c << " " << endl;
			break;
		}
		case 6:
		{
			cout << "Selected Menu :6. Add a New Vote Item" << endl;
			cout << "Vote subject : ";
			if (Mode)
			{
				VoteName_c = tokens[1];
				cout << VoteName_c << endl;
			}
			else
				cin >> VoteName_c;
			cout << "Number of Vote Items: ";
			if (Mode)
			{
				selectionCount = atoi(tokens[2].c_str());
				cout << selectionCount << endl;
			}
			else
			{
				cin >> selectionCount;
				getchar();
			}
			for (int i = 0; i < voteCount + 1; i++)
			{
				if (Votelist[i].CheckIfAlready(VoteName_c))
				{
					check_6 = 0;
					break;
				}
				else
					check_6 = 1;
			}
			if (check_6&&login_entire)
			{
				Votelist[voteCount].VoteName = VoteName_c;
				Votelist[voteCount].selectionCount = selectionCount;
				voteCount++;
				cout << "Request processed successfully!";
			}//투표명이 이미 존재하지 않고, 로그인 되어있다면, Vote class에 정보를 대입한다.
			else if (check_6 == 0 || login_entire == 0)
			{
				cout << "Request Failed";
			}
			if (!Mode)
				inLogWrite << "6 " << VoteName_c << " " << selectionCount << " " << endl;
			break;
		}
		case 7:
		{
			cout << "Selected Menu :7. View All Existing Votes" << endl;
			if (login_entire == 1)
			{
				for (int i = 0; i < voteCount; i++)
				{
					Votelist[i].ShowItems();
					cout << endl;
				}
			}//로그인만 되어있다면, 정보 출력.
			else if (login_entire == 0)
			{
				cout << "Request Failed";
			}
			if (!Mode)
				inLogWrite << "7 " << " " << endl;
			break;
		}
		case 8:
		{
			int index_Vote = -1;//Vote Class에 접근하기 위한 메뉴 8에서만 사용하는 index변수이다.
			cout << "Selected Menu :8. Cast a Vote" << endl;
			cout << "Vote Subject: ";
			if (Mode)
			{
				VoteName_c = tokens[1];
				cout << VoteName_c << endl;
			}
			else
				cin >> VoteName_c;
			cout << "Vote for: ";
			if (Mode)
			{
				select_before = atoi(tokens[2].c_str());
				cout << select_before << endl;
			}
			else
			{
				cin >> select_before;
				getchar();
			}
			for (int i = 0; i < memberCount; i++)//login한 사용자 식별-> 이는 투표할 사용자임을 의미한다.
			{
				if (member[i].login == 1)
				{
					index = i;
					break;
				}//이 메뉴에서 멤버별 로그인값에 접근하는 이유는, 투표한 이의 정보를 저장하여야 하기 때문이다.
				else
					continue;
			}
			for (int i = 0; i < voteCount; i++)
			{
				if (VoteName_c == Votelist[i].VoteName)
				{
					index_Vote = i;
					check_8 = 1;
					break;
				}
				else
					check_8 = 0;
			}
			if (index >= 0 && index_Vote >= 0)
			{
				if (Votelist[index_Vote].CheckIfVoted_ID(member[index].ID) == 0 || Votelist[index_Vote].CheckIfVoted(member[index].RRN) == 0 || check_8 == 0 || member[index].login == 0)
				{
					cout << "Request Failed";
				}
				else if (Votelist[index_Vote].CheckIfVoted_ID(member[index].ID) == 1 && Votelist[index_Vote].CheckIfVoted(member[index].RRN) == 1 && check_8 == 1 && member[index].login == 1)
				{
					Votelist[index_Vote].selection(select_before);
					Votelist[index_Vote].SaveInfo(member[index].RRN, member[index].ID);
					cout << "Request Success!";
				}
			}
			else
				cout << "Request Failed";
			if (!Mode)
				inLogWrite << "8 " << VoteName_c << " " << select_before << " " << endl;
			break;
		}
		case 9:
		{
			inLogWrite.close();
			break;
		}//종료.
		default:
		{
			cout << "Selected Menu: Undefined menu selection" << endl; fflush(stdout);
			if (!Mode) {
				inLogWrite << menu << endl;
				continue;
			}
			break;
		}

		if (!Mode && (menu != 4 && menu != 7)) {
			getchar();
		}
		}

		
	}
	return 0;
}



