vector<int> nums;
int sz;
int tsum;
int solution(vector<int> numbers, int target) {
	nums = numbers;
	sz = nums.size();
	tsum = target;

	int answer = recur(0, 0, true)+recur(0,0, false);
	return answer;
}

int recur(int idx, int sum, bool isPlus) {
	int temp = 0;
	if (isPlus) temp = sum + nums[idx];
	else temp = sum - nums[idx];

	if (idx+1 == sz) {
		if (temp == tsum) return 1;
		else return 0;
	}
	
	return recur(idx + 1, temp, true) + recur(idx + 1, temp, false);
}
