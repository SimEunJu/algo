#include <iostream>
#include <vector>
#include <queue>

#include <string.h>
#include <string>
#include <algorithm>

#include <bitset>

using namespace std;
int arr[500][500];
int cache[1000][3];
int num;
// 1932
int main(int argc, char** argv)
{

	int n;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			cin >> n;
			arr[i][j] = n;
		}
	}
	// 이웃집은 다른 색상으로 
	// 0 Red/ 1 Green/ 2 Blue
	// 3! 	
	int ret = 0;
	for (int i = num - 2; i >= 0; i--)
	{
		for (int j = 0; j <= i; j++)
		{
			arr[i][j] += max(arr[i + 1][j], arr[i + 1][j + 1]);
		}
	}
	cout << arr[0][0] << endl;
	return 0;
}
