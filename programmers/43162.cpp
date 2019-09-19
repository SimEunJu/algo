int solution(int n, vector<vector<int>> com) {
	vector<vector<bool> > arr(200, vector<bool>(200, false));
	int x = 0, y = 0;
	int answer = 0;
	queue<pair<int, int>> q;
	
	do
	{
		pair<int, int> t = testAllTrue(n, arr, com);
		if (t.first != -1) {
			q.push(t);
			arr[t.first][t.second] = true;
			arr[t.second][t.first] = true;
		}
		else break;
		do
		{
			// 원소를 큐에서 꺼낸다
			pair<int, int> p = q.front();
			q.pop();
			// 원소와 연결된 원소 중 방문하지 않은 원소를 큐에 넣는다
			
			for (int i = 0; i < n; i++)
			{
				if (com[p.first][i] == 1 && com[i][p.first] == 1 && arr[p.first][i] == false && arr[i][p.first] == false) {
					arr[p.first][i] = true;
					arr[i][p.first] = true;
					q.push(make_pair(p.first, i));
				}
				if (com[p.second][i] == 1 && com[i][p.second] == 1 && arr[p.second][i] == false && arr[i][p.second] == false) {
					arr[p.second][i] = true;
					arr[i][p.second] = true;
					q.push(make_pair(p.second, i));
				}
			}
			// 원소를 방문했다고 표시한다
			if (q.empty()) {
				answer++;
				break;
			}

		} while (true);
	} while (true);
	
	return answer;
}
pair<int, int> testAllTrue(int n, vector<vector<bool>> arr, vector<vector<int>> com){
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == false && arr[j][i] == false && com[i][j] == 1 && com[j][i] == 1) return make_pair(i, j);
		}
	}
	return make_pair(-1, -1);
}
