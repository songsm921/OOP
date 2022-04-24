//나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다. 20180085 송수민
#include <iostream>
using namespace std;
int column = 0;//기둥의 갯수
int *height;//기둥의 높이
int main()
{
	int max_left = 0;
	int max_right = 0;
	int count_left = 1;
	int count_right = 1;//초기값 1로 설정. 각각 SIDE에서 보았을때, 무조건 1개는 보이기때문입니다.
	cin >> column;//기둥의 갯수 입력 받습니다.
	height = new int[column];//기둥의 갯수에따라 동적할당.
	for (int i = 0; i < column; i++)
		cin >> height[i];//기둥의 높이 각 배열에 입력
	max_left = height[0];//왼쪽에서 보았을때의 MAX
	max_right = height[column - 1];//오른쪽에서 보았을때의 MAX
	for (int i = 0; i < column - 1; i++)
	{
		if (max_left<height[i + 1])
		{
			max_left = height[i + 1];
			count_left++;
		}
	}
	for (int i = column - 1; i >= 1; i--)
	{
		if (max_right<height[i - 1])
		{
			max_right = height[i - 1];
			count_right++;
		}
	}//각 사이드 별로 나누어서 계산하며, 최대를 볼때마다 최대값 변화.
	cout << count_left + count_right << endl;
	delete[] height;//동적할당 해제.
	return 0;
}


