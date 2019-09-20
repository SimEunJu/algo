vector<vector<int>> arr(50, vector<int>(50, 0));
int wordsSize;
vector<string> words; 
int targetIdx = -1;
int solution(string begin, string target, vector<string> wordList) {
	int answer = 100;
	wordsSize = wordList.size();
	words = wordList;
	vector<int> beginIdx;
	for (int i = 0; i < wordsSize; i++)
	{
		if (isLinked(begin, wordList[i]))  beginIdx.push_back(i);
	}
	targetIdx = findIdx(target, words);
	if (targetIdx == -1) return 0;
	makeGraph(words);
	for (int i = 0; i < beginIdx.size(); i++)
	{
		answer = min(answer, recur(-1, beginIdx[i], 0));
	}
	if (answer > wordsSize) return 0;
	return answer;
}
int recur(int prev, int idx, int cnt) {
	if (cnt > wordsSize) return 100;
	if (idx == targetIdx) return cnt + 1;
	int ans = 100;
	for (int i = 0; i < wordsSize; i++)
	{
		if (i != prev && arr[idx][i] == 1) {
			ans = min(ans, recur(idx, i, cnt + 1));
		}
	}
	return ans;
}
int findIdx(string target, vector<string> words) {
	int len = words.size();
	for (int i = 0; i < len; i++)
	{
		if (target == words[i]) return i;
	}
}
void makeGraph(vector<string> words) {
	int len = words.size();
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (arr[i][j] == 0 && isLinked(words[i], words[j])) {
				arr[i][j] = 1;
				arr[j][i] = 1;
			}
		}
	}
}
bool isLinked(string a, string b) {
	int cnt = 0;
	int len = a.size();
	for (int i = 0; i < len; i++)
	{
		if (a[i] != b[i]) cnt++;
	}
	if (cnt == 1) return true;
	return false;
}
