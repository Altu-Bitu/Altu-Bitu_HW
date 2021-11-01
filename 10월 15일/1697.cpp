#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int limit = 100001;

int solution(int n, int k)
{
	int time = 0;
	queue<pair<int,int>> q;
	vector<bool> visited(limit, false);

	q.push({ n,time });
	visited[n] = true;

	while (!q.empty())
	{
		int node = q.front().first;
		time = q.front().second;
		q.pop();
		if (node == k)
			return time;
		if (node + 1 < limit && !visited[node + 1])
		{
			q.push({ node + 1,time + 1 });
			visited[node + 1] = true;
	
		}
		if (node - 1 >= 0 && !visited[node - 1])
		{
			q.push({ node - 1,time + 1 });
			visited[node - 1] = true;

		}
		if (node * 2 < limit && !visited[node * 2])
		{
			q.push({ node * 2,time + 1 });
			visited[node*2] = true;
		}

	}
}
int main()
{
	int n, k;
	cin >> n >> k;
	cout << solution(n, k);
	return 0;
}

//참조https://chanhuiseok.github.io/posts/baek-14/
//참조https://jaimemin.tistory.com/581