#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	vector<pair<int, int>> a;
	cin >> n;
	a.assign(n+1, { 0,0 });
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}

	vector<int> sum;
	sum.assign(n+2, 0);
	for (int i = n; i >= 1; i--)
	{
		if (a[i].first > n - i + 1)//가능한 날의 일이 아니라면
			sum[i] = sum[i + 1];
		else
			sum[i] = max(sum[i + 1], a[i].second + sum[i + a[i].first]); //그날을 포함안하기vs포함하기(i의 이익이랑 i일을 하는데 걸리는 시간후의 sum을 더한값
	}

	cout << sum[1];
	return 0;
}