int solution(vector<int> scoville, int K) {
	int answer = 0;
	vector<int> h = {};
	
	int sz = scoville.size();
	for (int i = 0; i < sz; i++)
	{
		if (scoville[i] < K)  h.push_back(-scoville[i]);
	}
	make_heap(h.begin(), h.end());
	while (true)
	{
		int first = h.front();
		if (-first >= K) break;
		if (h.size() == 1) {
			answer = -1;
			break;
		}
		pop_heap(h.begin(), h.end());
		h.pop_back();
		int second = h.front();
		pop_heap(h.begin(), h.end());
		h.pop_back();
		
		h.push_back(first + second * 2);
		push_heap(h.begin(), h.end());
		
		answer++;
	}
	return answer;
}
