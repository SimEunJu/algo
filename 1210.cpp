#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <string>
#include <algorithm>

using namespace std;
int dfs(int x, int y);
int arr[100][100];
int main(int argc, char** argv)
{
	int testNum = 0;
	cin >> testNum;
	vector<pair<int, int>> sp;
	pair<int, int> end;
	for (int i = 0; i < testNum; i++)
	{
		int tmp;
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				cin >> tmp;
				arr[i][j] = tmp;
				if (tmp == 2) {
					end.first = i;
					end.second = j;
				}
			}
		}
	}
	cout << dfs(end.first, end.second) << endl;
}
int offset[][] = { {-1, 0}, {1, 1}, {1, 0} };
// 동적계획법 적용? x
int dfs(int x, int y) {
	if (x == 0) return x;
	if (arr[i][j] == 0) return 0;
	if (x < 0 || y < 0 || x >= 100 || y >= 100) return 0;
	for (int i = 0; i < 3; i++)
	{
		dfs(x + offset[i][0], y + offset[i][1]);
	}
}