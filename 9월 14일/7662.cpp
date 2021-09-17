#include <iostream>
#include <queue>
#include <string>

using namespace std;

typedef pair<int, int> pp;
int main()
{
	int t, k, n;
	char input;
	string result;
	cin >> t;
	while (t--)
	{
		priority_queue<pp> pq1;
		priority_queue<pp, vector<pp>, greater<pp>> pq2;
		bool visited[1000001];//index역할 수행
		cin >> k;
		for (int i = 0; i < k; i++)
		{
			cin >> input >> n;
			switch (input)
			{
			case 'I':
				pq1.push({ n,i });
				pq2.push({ n,i });
				visited[i] = true;
				break;
			case 'D':
				if (n == 1)
				{
					while (!pq1.empty() && !visited[pq1.top().second])//이미 삭제된거 다른 큐에서도 지우기
						pq1.pop();
					if (!pq1.empty()) {
						int index = pq1.top().second;
						pq1.pop();
						visited[index] = false;
					}

				}

				else
				{
					while (!pq2.empty() && !visited[pq2.top().second])
						pq2.pop();
					if (!pq2.empty())
					{
						int index = pq2.top().second;
						pq2.pop();
						visited[index] = false;
					}
				}
				break;
			}
		}
		while (!pq1.empty() && !visited[pq1.top().second])//이미 삭제된거 다른 큐에서도 지우기
			pq1.pop();
		while (!pq2.empty() && !visited[pq2.top().second])
			pq2.pop();
		if (pq1.empty()&&pq2.empty())
			result+="EMPTY\n";
		else
		{
			result += to_string(pq1.top().first);
			result += ' ';
			result += to_string(pq2.top().first);
			result+='\n';
		}
	}

	cout << result;

	return 0;
}