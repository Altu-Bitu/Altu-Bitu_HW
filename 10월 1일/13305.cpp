#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	int n,input;
	cin >> n;
	vector<int> oil(n, 0);
	vector<int> dist(n, 0);
	
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
	int sum = 0;
	for (int i = 0; i < n - 1; i++)
		sum += dist[i] * oil[i];
	cout << sum;
	return 0;
}