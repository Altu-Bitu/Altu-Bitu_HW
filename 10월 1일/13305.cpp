#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	int n,input;
	cin >> n;
	vector<long long> oil(n, 0);
	vector<long long> dist(n, 0);
	
	for (int i = 0; i < n-1; i++)
		cin >>dist[i];
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		if (i == 0)
			oil[i] = input;
		else
		{
			if (oil[i - 1] < input)
				oil[i] = oil[i - 1];
			else
				oil[i] = input;
		}
	}
	unsigned long long sum = 0;
	for (int i = 0; i < n - 1; i++)
		sum += dist[i] * oil[i];
	cout << sum;
	return 0;
}