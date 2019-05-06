#include <iostream>
#include <vector>
#include <queue>

#include <string.h>
#include <string>
#include <algorithm>

#include <bitset>

using namespace std;
int recur(int idx, int nth);
int arr[10000];
int cache[10000][2];
int num;
// 2156
int main(int argc, char** argv)
{
	int n;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> n;
		arr[i] = n;
		cache[i] = -1;
	}
	// 합을 최대로
	// 3연속은 x
	int res = 0;
	res = max(res, recur(0, 1));
	cout << res << endl;
	cin >> n;
	return 0;
}

int recur(int idx, int nth) {
	if (idx >= n) return 0;
	if (nth == 3) return cache[idx][0];

	int &ret = cache[idx][1];
	if (ret != -1) return ret;
	
	cache[idx + 1][1] = recur(idx + 1, nth + 1);
	cache[idx + 1][0] = recur(idx + 2, 1);
	ret = max(cache[idx + 1][1], cache[idx + 1][0]);

	ret += arr[idx];
	return ret;
}