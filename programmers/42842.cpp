vector<int> solution(int brown, int red) {
	int mid = (int)sqrt(red);
	vector<pair<int, int>> p;
	p.push_back(make_pair(1, red));
	for (int i = 2; i <= mid; i++)
	{
		if (red % i == 0) p.push_back(make_pair(i, red / i));
	}
	int sz = p.size();
	int around = 0;
	int ans = 0;
	for (int i = 0; i < sz; i++)
	{
		around = (p[i].first + p[i].second) * 2 + 4;
		if (around == brown) ans = i;
	}

	vector<int> answer;
	answer.push_back(p[ans].second + 2);
	answer.push_back(p[ans].first + 2);
	return answer;
}
