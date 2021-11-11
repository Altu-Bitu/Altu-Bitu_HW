#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int SIZE = 10e4;
typedef pair<int, char> ci;

vector<char> back(int x, vector<ci>& path)
{
	vector<char> result(0); //정답 경로
	char c = path[x].second;
	while (x != -1) {
		result.push_back(c);
		x = path[x].first;
		c = path[x].second; //다음 정점
	}
	return result;
}

vector<char> calculate(int a, int b)
{
	vector<bool> check(SIZE + 1, false);
	vector<ci> path(SIZE + 1, { -1,'A' }); //경로 저장 벡터
	queue<int>q;

	check[a] = true;
	q.push(a);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		if (x == b)
		{
			break;
		}

		if (!check[(a * 2) / SIZE])
		{
			int na = (a * 2) / SIZE;
			check[na] = true;
			path[na] = { x,'D' };
			q.push(na);
		}
		
		if (a == 1&&!check[SIZE-1])
		{
			int na = SIZE - 1;
			check[na] = true;
			path[na] = { x,'S' };
			q.push(na);
		}

		if (a != 1 && !check[a - 1])
		{
			int na = a - 1;
			check[na] = true;
			path[na] = { x,'S' };
			q.push(na);
		}

		int na = a / 1000 + (a % 1000) * 10;
		if (!check[na])
		{
			check[na] = true;
			path[na] = { x,'L' };
			q.push(na);
		}


		na = a / 10 + (a % 10) * 1000;
		if (!check[na])
		{
			check[na] = true;
			path[na] = { x,'R' };
			q.push(na);
		}
	}
	vector<char>result = back(b, path);
	return result;
}

int main()
{
	vector<char>result;
	string answer;
	int t, a, b;
	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		result = calculate(a, b);
		for (int i = result.size() - 1; i >= 0; i--)
			answer += result[i];
		answer += '\n';
	}
	cout << answer;
	return 0;
}