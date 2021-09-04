#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int n,all=0;
	cin >> n;
	vector<int>sum;
	sum.assign(n, 0);
	vector<int>p;
	p.assign(n, 0);
	for (int i = 0; i < n; i++)
		cin >> p[i];
	sort(p.begin(), p.end());
	for (int i = 0; i < n; i++)
	{
		sum[i] += p[i];
		if (i != 0)
			sum[i] += sum[i - 1];
		all += sum[i];
		
	}

	cout << all;
	return 0;
}