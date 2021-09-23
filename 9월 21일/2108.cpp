#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<int, int> m;

double avg(vector<int> a)
{
	double sum = 0;
	for(int i=0;i<a.size();i++)
		sum += a[i];
	return sum / a.size();
}

int mid(vector<int> a)
{
	int size = a.size() / 2;
	return a[size];
}

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second > b.second;
}

int mode()
{
	vector<pair<int, int>> vec(m.begin(), m.end());
	sort(vec.begin(), vec.end(), cmp);
	if (vec[0].second == vec[1].second)
		return vec[1].first;
	return vec[0].first;
}

int diff(vector<int> a)
{
	return a[a.size()-1] - a[0];
}

int main()
{
	int n;
	cin >> n;
	vector<int> a;
	a.assign(n, 0);
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		m[a[i]]++;
	}
	sort(a.begin(), a.end());
	cout << fixed;
	cout.precision(0);
	cout << avg(a)<<'\n' << mid(a) << '\n' << mode() << '\n' << diff(a);
	return 0;
}