#include <iostream>
#include <vector>
#include <queue>

#include <string.h>
#include <string>
#include <algorithm>

#include <bitset>

using namespace std;

// 2156
int main(int argc, char** argv)
{
	int num, n;
	cin >> num;
	vector<int> arr(num + 1, 0);
	vector<int> cache(num + 1, 0);
	for (int i = 1; i <= num; i++)
	{
		cin >> n;
		arr[i] = n;
	}
	if (num == 1) {
		cout << arr[1] << endl;
		return 0;
	}
	else if (num == 2) {
		cout << arr[1] + arr[2] << endl;
		return 0;
	}
	else {
		cache[1] = arr[1];
		cache[2] = arr[1] + arr[2];
	}
	//else if (num == 3) cache[2] = max(arr[0] + arr[1], arr[1] + arr[2], arr[0]+arr[2]);
	// 
	// idx
	// idx-1 idx
	int ret = 0;
	for (int i = 3; i <= num; i++)
	{
		ret = max(cache[i - 1], cache[i - 2] + arr[i]);
		ret = max(cache[i - 3] + arr[i - 1] + arr[i], ret);
		cache[i] = ret;
	}
	cout << cache[num] << endl;
	return 0;
}

