#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int SIZE = 10000;
typedef pair<int, char> ci;

vector<char> back(int x, vector<ci>& path)
{
	vector<char> result(0); //정답 경로
	char c = path[x].second;
	while (1) {
		result.push_back(c);
		x = path[x].first; //이전 숫자 찾음
		if (x == -1)
			break;
		c = path[x].second; //다음 노드
	}
	return result;
}

vector<char> calculate(int a, int b)
{
	vector<bool> check(SIZE + 1, false);
	vector<ci> path(SIZE + 1, { -1,' ' }); //경로 저장 벡터
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
		 //D
		if (!check[(x * 2) % SIZE])
		{
			int na = (x * 2) % SIZE;
			check[na] = true;
			path[na] = { x,'D' };
			q.push(na);
		}
		 //S
		int na = (x - 1) < 0 ? SIZE - 1 : x - 1;
		if (!check[na])
		{
			check[na] = true;
			path[na] = { x,'S' };
			q.push(na);
		}

		//L
		na = x / 1000 + (x % 1000) * 10;
		if (!check[na])
		{
			check[na] = true;
			path[na] = { x,'L' };
			q.push(na);
		}

		//R
		na = x / 10 + (x % 10) * 1000;
		if (!check[na])
		{
			check[na] = true;
			path[na] = { x,'R' };
			q.push(na);
		}
	}
	//path돌면서 계산루트 찾기
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
		for (int i = result.size() - 2; i >= 0; i--)
			answer += result[i];
		answer += '\n';
	}
	cout << answer;
	return 0;
}