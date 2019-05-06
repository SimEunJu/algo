#include <iostream>
#include <vector>
#include <queue>

#include <string.h>
#include <string>
#include <algorithm>

#include <bitset>

using namespace std;

// 1003
int main(int argc, char** argv)
{
	int num, n;
	cin >> num;
	vector<int> arr(num, 0);
	int cache[41][2];
	for (int i = 0; i < num; i++)
	{
		cin >> n;
		arr[i] = n;
	}

	cache[0][0] = 1;
	cache[0][1] = 0;
	cache[1][0] = 0;
	cache[1][1] = 1;

	for (int i = 2; i <= 40; i++)
	{
		cache[i][0] = cache[i - 1][0] + cache[i - 2][0];
		cache[i][1] = cache[i - 1][1] + cache[i - 2][1];

	}
	for (int i = 0; i <num; i++)
	{
		cout << cache[arr[i]][0] << " " << cache[arr[i]][1] << '\n';
	}
	return 0;
}

