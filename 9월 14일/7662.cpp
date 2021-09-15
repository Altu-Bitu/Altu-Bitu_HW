#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
	int t, k, n;
	priority_queue<int> pq1;
	priority_queue<int, vector<int>, greater<int>> pq2;

	char input;
	string result;
	cin >> t;
	while (t--)
	{
		cin >> k;
		for (int i = 0; i < k; i++)
		{
			cin >> input >> n;
			switch (input)
			{
			case 'I':
				pq1.push(n);
				break;
			case 'D':
				if (!pq1.empty())
				{
					if (n == -1)
					{
						while (!pq1.empty())
						{
							pq2.push(pq1.top());
							pq1.pop();
						}
						pq2.pop();

						while (!pq2.empty())
						{
							pq1.push(pq2.top());
							pq2.pop();
						}
					}

					else
						pq1.pop();
				}
			}
		}
		if (pq1.empty())
			result += "EMPTY\n";
		else
		{
			result += to_string(pq1.top());
			while (!pq1.empty())
			{
				pq2.push(pq1.top());
				pq1.pop();
			}
			result += ' ';
			result += to_string(pq2.top());
			result += '\n';

		}
	}

	cout << result;
	return 0;
}