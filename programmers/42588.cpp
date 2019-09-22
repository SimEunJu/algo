vector<int> solution(vector<int> h) {
	vector<int> answer;
	int sz = h.size();
	while (true)
	{
		if (sz <= 0) break;
		bool flag = false;
		for (int i = sz-2; i >= 0; i--)
		{
			if (h[i] > h[sz - 1]) {
				answer.push_back(i+1);
				flag = true;
				break;
			}
		}
		if (!flag) answer.push_back(0);
		sz--;
	}
	reverse(answer.begin(), answer.end());
	return answer;
}
