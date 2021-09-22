#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()//**
{
	int n;
	
	vector<pair<int, int>> a;
	cin >> n;
	a.assign(n+1, { 0,0 });
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}

	int sum[17] = { 0 };

	for (int i = n; i >0; i--)
	{
		if (a[i].first > n - i + 1)
			sum[i] = sum[i + 1];
		else
			sum[i] = max(sum[i + 1], a[i].second + sum[i + a[i].first]);
	}
	cout << sum[1];
	return 0;
}