#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
/*
struct point {
	int x;
	int y;
};*/

bool cmp(const pair<int,int> &p1, const pair<int,int>& p2)
{
	if (p1.second == p2.second)
		return p1.first < p2.first;
	return p1.second < p2.second;
}

int main() {
	int n;
	cin >> n;
	
	vector<pair<int, int>> p;
	p.assign(n, {});

	for (int i = 0; i < n; i++)
		cin >> p[i].first >> p[i].second;

	sort(p.begin(), p.end(), cmp);

	for (int i = 0; i < n; i++)
		cout << p[i].first <<' '<< p[i].second << '\n';

	return 0;
}