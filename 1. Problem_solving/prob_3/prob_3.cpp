/*나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다. 20180085 송수민*/
#include<iostream>
#include "stdlib.h"
using namespace std;
void dfs(int y, int x, int** ICE_T, int** ICE);
int horizon = 0;//WIDTH
int vertical = 0;//높이
int year = 0;//년수
typedef struct {
	int y, x;
}Direction;
Direction move_ice[4] = { {1,0},{-1,0},{0,1},{0,-1} };//DFS에서 4방위를 확인할때, 쓰이는 일종의 XY-COMPONENTS

int main()
{
	cin >> horizon;
	cin >> vertical;
	cin >> year;
	int **ice = new int*[vertical];
	for (int i = 0; i < vertical; i++)
		ice[i] = new int[horizon];
	int **ice_T = new int*[vertical];
	for (int i = 0; i < vertical; i++)
		ice_T[i] = new int[horizon];//2차원 어레이 동적할당, ice는 본래 값을 담는 2차원 어레이. ice_T는 DFS시 이 곳을 거쳤는지 안 거쳤는지 확인하는 2차원 어레이
	for (int i = 0; i < vertical; i++)
	{
		for (int j = 0; j < horizon; j++)
		{
			cin >> ice[i][j];
		}
	}
		//2차원 어레이에 성분 입력
	for (int i = 0; i < vertical; i++)
	{
		for (int j = 0; j < horizon; j++)
		{
			ice[i][j] = ice[i][j] - year;
			if (ice[i][j] <= 0)
			{
				ice[i][j] = 0;
			}
			
		}
	}//2차원 어레이에 년수 만큼 뺀 성분 입력, 그 후 0보다 작거나 같은 곳에는 모두 0으로 처리합니다.
	for (int i = 0; i < vertical; i++)
	{
		for (int j = 0; j < horizon; j++)
		{
			ice_T[i][j] = false;
		}
	}//ice_T 2차원 어레이 모두 false로 초기화 합니다. 이곳을 dfs에 지나갈시, True로 값이 변경됩니다.
	int count = 0;
	for (int i = 0; i < vertical; i++)
	{
		for (int j = 0; j < horizon; j++)
			if (!ice_T[i][j] && ice[i][j])
			{
				dfs(i, j, ice_T,ice);
				count++;
			}
	}//dfs실행. 여기서 dfs한번 끊길때, 이는 한덩어리가 생겼음을 의미하므로 count++
	cout << count << endl;
	for (int i = 0; i < vertical; i++)
	{
		delete[] ice[i];
		delete[] ice_T[i];
	}//2차원 어레이 1차 동적할당 해제
	delete[] ice;
	delete[] ice_T;//동적할당 해제 마무리
	return 0;

}
void dfs(int y, int x, int** ICE_T,int** ICE)
{
	ICE_T[y][x] = true;//일단 이곳을 왔으므로, true로 값변환
	for (int i = 0; i < 4; i++)
	{
		int nextY = y + move_ice[i].y;

		int nextX = x + move_ice[i].x;//위에서 언급한 xy-component로 4방위 검사.


	
		if (0 <= nextY && nextY < vertical && 0 <= nextX && nextX < horizon)
		{
			if (!ICE_T[nextY][nextX] && ICE[nextY][nextX])

				dfs(nextY, nextX, ICE_T, ICE);
		}
		
		
	}
}

