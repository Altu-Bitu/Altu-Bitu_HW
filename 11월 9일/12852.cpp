#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int SIZE = 10e6;

vector<int> back(int x,vector<int>& path)
{
	vector<int> result(0); //정답 경로
	while (x != -1) {
		result.push_back(x);
		x = path[x]; //다음 정점
	}
	return result;
}

int bfs(int n,vector<int> &path)
{
	vector<int> check(SIZE + 1, 0);
	queue<int> q;
	int ans = 0;

	check[n] = 1;
	q.push(n);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		if (x == 1)
		{
			ans = check[x] - 1;
			break;
		}

		if (x % 3 == 0&&!check[x/3])//3으로 나뉘어지면
		{
			int nx = x / 3;
			check[nx] = check[x] + 1;
			path[nx] = x;
			q.push(nx);
		}

		if (x % 2 == 0&&!check[x/2])
		{
			int nx=x /2;
			check[nx] = check[x] + 1;
			path[nx] = x;
			q.push(nx);
		}

		if (!check[x-1])
		{
			int nx = x - 1;
			check[nx] = check[x] + 1;
			path[nx] = x;
			q.push(nx);
		}
	}
	return ans;
}

int main()
{
	int n;
	cin >> n;
	vector<int> path(SIZE + 1, -1);
	int ans = bfs(n, path);
	vector<int> result = back(1,path);

	cout << ans << '\n';
	for (int i = result.size() - 1; i >= 0; i--)
		cout << result[i] << ' ';

	return 0;
}