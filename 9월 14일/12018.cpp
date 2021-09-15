#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int n, m,cnt=0;
	vector<int> s;
	priority_queue<int, vector<int>, greater<int>> pq;

	cin >> n >> m;
	while(n--)
	{
		int p, l;
		cin >> p >> l;
		s.assign(p, 0);
		for (int i = 0; i < p; i++)
			cin >> s[i];
		sort(s.begin(), s.end(), cmp);
		if (p < l)
			pq.push(1);
		else
			pq.push(s[l - 1]);
	}

	while (!pq.empty())
	{
		if (m >= pq.top())
		{
			m -= pq.top();
			pq.pop();
			cnt++;
		}
		else
			break;
	}
	cout << cnt;
	return 0;
}