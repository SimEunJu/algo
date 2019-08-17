vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	int times = commands.size();
	int size = array.size();
	int start, end, nth, ans;
	for (int i = 0; i < times; i++)
	{
		start = commands[i][0] - 1 ;
		end = commands[i][1];
		nth = commands[i][2] - 1;
		
		vector<int> v;
		v.assign(array.begin() + start, array.begin() + end);
		sort(v.begin(), v.end());
		answer.push_back(v[nth]);
	}
	return answer;
}
