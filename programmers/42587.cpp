int solution(vector<int> p, int location) {
	int answer = 0;
	int sz = p.size();
	int idx = 0;
	int cnt = 0;
	while (true)
	{
		//if(cnt++ > 10) return 10;
		bool flag = false;
		for (int i = 1; i < sz; i++)
		{
			int j = (idx + i) % sz;
			if (p[j] == 0) continue;
			if (p[j] > p[idx]) {
				flag = true;
				break;
			}
		}
		if (!flag) {
			p[idx] = 0;
			answer++;
			if (idx == location) {
				//cout << cnt << endl;
				return answer;
			}
		}
		idx = (idx + 1) % sz;
        
	}
	return answer;
}
