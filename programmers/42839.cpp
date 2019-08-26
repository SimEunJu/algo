vector<int> nums;
set<int> ans;
int numSz;
int solution(string numbers) {
	// n 개의 숫자 중에 m개를 선택
	// m개의 숫자를 조합
	// 소수인지 판별
	numSz = numbers.size();
	
	for (int i = 0; i < numSz; i++)
	{
		nums.push_back(numbers[i] - '0');
	}
	for (int i = 1; i <= numSz; i++)
	{
		vector<int> picked;
		combination(picked, i);
	}
	int answer = ans.size();
	return answer;
}
// n개의 수 중에서 m개를 선택
void combination(vector<int> &picked, int toPick) {
	if (toPick == 0) {
		calcPrime(picked);
		return;
	}

	int bidx = picked.empty() ? 0 : picked.back()+1;
	for (int i = bidx; i < numSz; i++)
	{
		picked.push_back(i); 
		combination(picked, toPick - 1);
		picked.pop_back();
	}
}
void calcPrime(vector<int> &idx) {
	int temp = 0;
	int numSz = idx.size();
	do {
		temp = 0;
		for (int i = 0; i < numSz; i++)
		{
			temp += nums[idx[i]] * pow(10, numSz - i - 1);
		}
		if (isPrime(temp)) ans.insert(temp);
	} while (next_permutation(idx.begin(), idx.end()));
}
bool isPrime(int num) {
	if (num == 1 || num == 0) return false;
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0) return false;
	}
	return true;
}
