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
	sort(a.begin(), a.end());
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
	else
		return vec[0].first;
}

int diff(vector<int> a)
{
	int max_num = a[0];
	for (int i = 1; i < a.size(); i++)
		if (max_num < a[i])
			max_num = a[i];
	int min_num = a[0];
	for (int i = 1; i < a.size(); i++)
		if (min_num > a[i])
			min_num = a[i];
	return max_num - min_num;
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
	cout << fixed;
	cout.precision(0);
	cout << avg(a)<<'\n' << mid(a) << '\n' << mode() << '\n' << diff(a);
	return 0;
}