#include <string>
#include <vector>
#include <functional>
#include <regex>
#include <algorithm>

using namespace std;
bool cmp1(const int &a, const int &b);

string solution(vector<int> numbers) {
  int size = numbers.size();
	sort(numbers.begin(), numbers.end(), cmp1);
	
	string answer = "";
	for (int i = 0; i < size; i++)
	{
		answer += to_string(numbers[i]);
	}
	answer = regex_replace(answer, regex("^0+"), "0");
	return answer;
}

bool cmp1(const int &a, const int &b) {
	string strA = to_string(a);
	string strB = to_string(b);

	string ab = strA + strB;
	string ba = strB + strA;
	
	int intAb = stoi(ab);
	int intBa = stoi(ba);

	if (intAb > intBa) return true;
	return false;
}
