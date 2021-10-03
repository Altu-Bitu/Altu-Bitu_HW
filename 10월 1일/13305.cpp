#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int cost(int n,int dist,vector<pair<int,int>> s,vector<int> sum)
{
	int total = 0;
	int distance = 0;
	int sums;
	int standard;
	for (int i = 0; i < n - 1; i++)
	{
		
		if (i == 0)
		{
			sums = sum[s[i].second];
			standard = i;
		}
		else if (s[i].second < s[standard].second)
		{
			sums = sum[s[i].second] - sum[s[standard].second];
			standard = i;
		}
		else
			continue;
		if (sums == 0)
			return total;
		total += s[i].first * sums;
		distance += sums;
		if (distance == dist)
			return total;
	}
}

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
	if (a.first != b.first)
		return a.first < b.first;
	return a.second < b.second;
}

int main()
{
	int n;
	cin >> n;
	vector<int> oil(n, 0);
	vector<int> dist(n, 0);
	vector<pair<int, int>> s(n - 1, { 0, 0});
	for (int i = 0; i < n-1; i++)
		cin >>dist[i];
	for (int i = 0; i < n; i++)
	{
		cin >> oil[i];
		if (i != n - 1)
			s[i] = { oil[i],i };
	}

	sort(s.begin(), s.end(),cmp);

	vector<int> sum(n-1, 0);
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i; j < n - 1; j++)
			sum[i] += dist[j];
	}

	cout << cost(n,sum[0],s, sum);
	return 0;
}