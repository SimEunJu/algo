#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(int argc, char** argv)
{
	int num, n;
	cin >> num;
	int arr[300000];
	for (int i = 0; i < num; i++)
	{
		cin >> n;
		arr[i] = n;
	}
	int idx = 0;
	int k = 1000000001;
	int limit = num / 2;
	int m, res;
	for (int j = 0; j < limit; j++)
	{
		for (int i = num - 1; i>j; i--)
		{
			m = min(arr[j], arr[i]);
			res = m / (i-j);
			if (res < k) k = res;
		}
	}

	cout << k << endl;
}
