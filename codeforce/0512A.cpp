#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

int main(int argc, char** argv)
{
	int num;
	cin >> num;
	int res = 0;
	string sym;
	cin >> sym;
	for (int i = 0; i < num; i++)
	{
		if (res == 0 && sym[i] == '-') continue;
		else if (sym[i] == '+') res++;
		else res--;
	}
	cout << res << '\n';
}