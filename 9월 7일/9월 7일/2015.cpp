#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	int n, k;
	int input;
	int cnt = 0;

	cin >> n >> k;
	vector<int> a;
	vector<int> sum;
	a.assign(n, 0);
	sum.assign(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sum[0] = a[0];
	for (int i = 1; i < n; i++)
	{
		sum[i] += sum[i - 1] + a[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
			if (sum[j] - sum[i] + a[j-1] == k)
				cnt++;
	}

	cout << cnt;

	return 0;
}