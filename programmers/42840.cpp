vector<int> solution(vector<int> ans) {
	int one[] = { 1,2,3,4,5 };
	int two[] = { 2,1,2,3,2,4,2,5 };
	int three[] = { 3,3,1,1,2,2,4,4,5,5 };
	int ansSize = ans.size();
	int oneSize = 5, twoSize = 8, threeSize = 10;
	int oneScore = 0, twoScore = 0, threeScore = 0;
	for (int i = 0; i < ansSize; i++)
	{
		if (ans[i] == one[i%oneSize]) oneScore++;
		if (ans[i] == two[i%twoSize]) twoScore++;
		if (ans[i] == three[i%threeSize]) threeScore++;
	}
	int scores[] = { oneScore, twoScore, threeScore };
	int max = scores[0], maxIdx = 0;
	
	for (int i = 1; i < 3; i++)
	{
		if (max < scores[i]) {
			max = scores[i];
			maxIdx = i;
		}
	}
	
	vector<int> answer = { maxIdx + 1 };
	for (int i = 0; i < 3; i++)
	{
		if (i != maxIdx && scores[i] == max) answer.push_back(i+1);
	}
	
	sort(answer.begin(), answer.end());
	return answer;
}
