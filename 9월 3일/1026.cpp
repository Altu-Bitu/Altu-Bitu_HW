#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> a;
vector<int> b;
bool cmp(int i, int j)
{
	return i>j;
}

int main()
{
	int n,sum=0;
	cin >> n;
	a.assign(n, 0);
	b.assign(n, 0);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), cmp);
	for (int i = 0; i < n; i++)
		sum += a[i] * b[i];
	cout << sum;
	return 0;
}