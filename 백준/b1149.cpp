#include <iostream>
#include <vector>
#include <queue>

#include <string.h>
#include <string>
#include <algorithm>

#include <bitset>

using namespace std;
int recur(int idx, int color);
int arr[1000][3];
int cache[1000][3];
int num;
// 1149
int main(int argc, char** argv)
{

	int n1, n2, n3;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		scanf_s("%d %d %d", &n1, &n2, &n3);
		arr[i][0] = n1;
		arr[i][1] = n2;
		arr[i][2] = n3;
	}
	// �̿����� �ٸ� �������� 
	// 0 Red/ 1 Green/ 2 Blue
	// 3! 	
	int ret = 987654321;
	for (int i = 0; i < 3; i++)
	{
		ret = min(recur(0, i), ret);
	}
	cout << ret << endl;
	return 0;
}

int recur(int idx, int color) {
	if (idx == num) return arr[idx][color];
	// 1��° �� 3���� �� �� 1�� ��

	int &ret = cache[idx][color];
	if (ret != 0) return ret;
	// 2��° ������ ���� 2���� �� �� 1�� ��
	// 0 Red �� �� 

	if (color == 0) {
		ret = min(recur(idx + 1, 1), recur(idx + 1, 2));
	}
	else if (color == 1) {
		ret = min(recur(idx + 1, 0), recur(idx + 1, 2));
	}
	else if (color == 2) {
		ret = min(recur(idx + 1, 0), recur(idx + 1, 1));
	}
	ret += arr[idx][color];
	return ret;
}

