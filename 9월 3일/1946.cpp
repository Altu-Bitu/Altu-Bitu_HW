#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct info {
	int s1, s2;
};

vector<info> a;

bool cmp(const info& i1, const info& i2)
{
	return i1.s1 < i2.s1;
}

int check(int n)
{
	int num = 1;
	
	int ans = a[0].s2;
	for (int i = 1; i < n; i++)
	{
		if (ans > a[i].s2)
		{
			num++;
			ans = a[i].s2;
		}
	}
	return num;
}

int main() {

	int t, n;
	vector<int> cnt;
	cin >> t;
	cnt.assign(t, 0);
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		a.assign(n, {});
		for (int j = 0; j < n; j++)
			cin >> a[j].s1 >> a[j].s2;
		sort(a.begin(), a.end(), cmp);
		cnt[i] = check(n);
	}

	for (int i = 0; i < t; i++)
		cout << cnt[i] << '\n';
	return 0;
}