// x, y 좌표와 2차원 배열 순서를 헷갈리지 말자!
int solution(int m, int n, vector<vector<int>> puddles) {
	int arr[101][101] = { 0, };
	int dp[101][101] = { 0, };
	//memset(arr, 0, sizeof(arr));
	int len = puddles.size();
	for (int i = 0; i < len; i++)
	{
		arr[puddles[i][1]][puddles[i][0]] = -1;
	}
	dp[0][1] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (arr[i][j] == -1) dp[i][j] = 0;
			else dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
		}
	}
	return dp[n][m];
}
