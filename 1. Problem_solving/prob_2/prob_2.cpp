/*나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다. 20180085 송수민*/
#include <iostream>
#include<algorithm>
using namespace std;
int column = 0;//기둥의 갯수 변수
int *height;//기둥의 높이를 담는 어레이
int main()
{
	int count = 0;
	cin >> column;
	height = new int[column];//기둥의 갯수만큼 동적할당.
	for (int j = 0; j < column; j++)
	{
		cin >> height[j];
		auto now = lower_bound(height, height + count, height[j]);
		*now =height[j];
		if (now == height + count)
			count++;
	}//시간 복잡도 NlogN의 방식. STL에 있는 lower_bound 함수를 사용하여 검사.
	cout << count << endl;
	delete[] height;//동적할당 해제.
	return 0;
}

