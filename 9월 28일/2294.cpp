#include <iostream>
#include <vector>

using namespace std;

const int INF=10001; //최대값

int main() //가방문제에서 가치를 동전수 1 더하는걸로 풀기
{
	int n, k;
	cin >> n >> k;
	vector<int> w(n + 1, 0);
	for (int i = 1; i <= n; i++)
		cin >> w[i];

	vector<int> dp(k + 1, INF);
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j =w[i]; j<=k; j++)
		{
			dp[j] = min(dp[j - w[i]] + 1, dp[j]); //
		}
	}
	if (dp[k] == INF)
		cout << -1;
	else
		cout << dp[k];
	return 0;
}