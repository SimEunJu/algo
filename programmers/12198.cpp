int solution(vector<int> cit) {
	sort(cit.begin(), cit.end());
	int size = cit.size();
	// 배열 안에 h idx가 있는 경우
	for (int i = size - 1; i >= 0; i--)
	{
		if (i != 0) {
			for (int j = cit[i]; j > cit[i-1] ; j--)
			{
				if (j <= (size - i)) return j;
			}
		}
		if (cit[i] <= (size - i)) return cit[i];
	}
	return size;
}
