#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <string>
#include <algorithm>

using namespace std;

struct point {
	int x;
	int y;
	int len;
	int dist1;
	int dist2;
	bool isStair;
};
bool compare1(point p1, point p2);
bool compare2(point p2, point p3);
int recur();
pair<int, int> calc(int idx1, int idx2, int sub);
vector<point> dist1;
vector<point> dist2;
vector<point> people;
vector<point> stairs;
int sz;
int main(int argc, char** argv)
{
	int testNum = 0;
	cin >> testNum;
	people = vector<point>(10);
	dist1 = vector<point>();
	dist2 = vector<point>();
	stairs = vector<point>(2);
	for (int i = 0; i < testNum; i++)
	{
		cin >> sz;
		// 입력 개선시키기
		int tmp = 0;
		int sidx = 0;
		int pidx = 0;
		for (int i = 0; i < sz; i++)
		{
			for (int j = 0; j < sz; j++)
			{
				cin >> tmp;
				if (tmp == 1) {
					people[pidx].x = i;
					people[pidx].y = j;
					pidx++;
				}
				else if (tmp > 1) {
					stairs[sidx].x = i;
					stairs[sidx].y = j;
					stairs[sidx].len = tmp;
					sidx++;
				}
			}
		}
		// for문을 한 번 더 돌면서 dist 관리
		for (int i = 0; i < pidx; i++)
		{
			int d1 = abs(people[i].x - stairs[0].x) + abs(people[i].y + stairs[0].y);
			int d2 = abs(people[i].x - stairs[1].x) + abs(people[i].y + stairs[1].y);
			people[i].dist1 = d1+stairs[0].len;
			people[i].dist2 = d2+stairs[1].len;
			dist1.push_back(people[i]);
			dist2.push_back(people[i]);
		}
		sort(dist1.begin(), dist1.end(), compare1);
		sort(dist2.begin(), dist2.end(), compare2);
		cout << recur() << endl;
	}
}
bool compare1(point p1, point p2) {
	return p1.dist1 < p2.dist1;
}
bool compare2(point p1, point p2) {
	return p1.dist2 < p2.dist2;
}
int recur() {
	queue<point> q1, q2;
	
	int total = 0;
	int idx1 = 0, idx2 = 0;
	while(true)
	{
	
		int sub = 0;
		
		if (dist1[idx1].dist1 > dist2[idx2].dist2) {
			sub = dist2[idx2].dist2;
		}
		else if (dist1[idx1].dist1 < dist2[idx2].dist2) {
			sub = dist1[idx1].dist1;
		}
		else {
			sub = dist1[idx1].dist1;
		}
		pair<int, int> ret = calc(idx1, idx2, sub);
		idx1 = ret.first == -1 ? idx1 : ret.first + 1;
		idx2 = ret.second == -1 ? idx2 : ret.second + 1;
		total += sub;
		if (idx1 >= dist1.size()) {
			for (int i = idx2; i < dist2.size(); i++)
			{
				i = i + 2 >= dist2.size() ? dist2.size() - 1 : i + 2;
				total += dist2[i].dist2;
			}
			return total;
		}
		else if (idx2 >= dist2.size()) {
			for (int i = idx1; i < dist1.size(); i++)
			{
				i = i + 2 >= dist1.size() ? dist1.size() - 1 : i + 2;
				total += dist1[i].dist1;
			}
			return total;
		}
		cout << sub << endl;
	}
	return total;
}

pair<int, int> calc(int idx1, int idx2, int sub) {
	int cnt1 = 0, cnt2 = 0;
	int ret1 = -1, ret2 = -1;
	for (; idx1 < dist1.size(); idx1++)
	{
		dist1[idx1].dist1 -= sub;
		if (dist1[idx1].dist1 == 0 && cnt1++ < 3) ret1 = idx1;
	}
	for (; idx2 < dist2.size(); idx2++)
	{
		dist2[idx2].dist2 -= sub;
		if (dist2[idx2].dist2 == 0 && cnt2++ < 3) ret2 = idx2;
	}
	return pair<int, int>(ret1, ret2);
}