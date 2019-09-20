int arr[500][500] = { 0, };
vector<vector<int> > tri;
int h;
int solution(vector<vector<int> > triangle) {
	memset(arr, 0, sizeof(arr));
	tri = triangle;
	h = tri.size();
	
	calc(0,0);
	
	int answer = arr[0][0];
	
	return answer;
}

int calc(int y, int x) {
	if (y < h && x < tri[y].size()) {
		if (y == h - 1) return tri[y][x];
		if (arr[y][x] != 0) return arr[y][x];
		
		arr[y][x] = tri[y][x] + max(calc(y + 1, x), calc(y + 1, x + 1));
		return arr[y][x];
	}
	return 0;
}
