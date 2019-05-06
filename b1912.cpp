#include <iostream>
#include <vector>
#include <queue>

#include <string.h>
#include <string>
#include <algorithm>

#include <bitset>

using namespace std;

// 1912
int main(int argc, char** argv)
{
	int num, n;
	cin >> num;
	vector<int> arr(num, 0);
	vector<int> sum(num, 0);
	for (int i = 0; i < num; i++)
	{
		cin >> n;
		arr[i] = n;
	}
	int res = -1000;
	sum[0] = arr[0];
	for (int i = 1; i < num; i++) {
		sum[i] = max(sum[i - 1] + arr[i], arr[i]);
		res = max(res, sum[i]);
	}
	res = max(res, sum[0]);
	cout << res << endl;
	cin >> n;
	return 0;
}

