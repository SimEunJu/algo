vector<long long> arr = { 1,1 };
long long solution(int N) {
	if (arr.size() == 2) {
		for (int i = 2; i < 80; i++)
		{
			arr.push_back(arr[i - 1] + arr[i - 2]);
		}
	}
	long long answer = 0;
	// 1 1 2 3 5 8
	// N*4 + (N-1)*2
	answer = arr[N - 1] * 4 + arr[N - 2] * 2;
	return answer;
}
