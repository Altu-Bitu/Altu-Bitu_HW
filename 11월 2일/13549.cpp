#include <iostream>
#include <queue>
#include <vector>


using namespace std;

int limit = 100001;

int solution(int n, int k)
{
	int time = 0;
	vector<bool> visited(limit, false);
	//queue<pair<int, int>> q;  //질문!! 그냥 queue가 안되는 이유가 0초인 순간이동이 앞으로 가게 만들어야하기때문인가요?
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;//시간을 기준으로 정렬되면서 쌓이게 된다.

	q.push({ time,n });
	visited[n] = true;

	while (!q.empty())
	{
		//int node = q.front().first;
		//time = q.front().second;

		time = q.top().first;
		int node = q.top().second; 
		q.pop();

		if (node == k)
			return time;

		if (node + 1 < limit && !visited[node + 1])
		{
			q.push({ time + 1,node + 1});
			visited[node + 1] = true;
		}
		if (node - 1 >=0 && !visited[node - 1])
		{
			q.push({time + 1 ,node - 1});
			visited[node - 1] = true;
		}
		if (node*2 < limit && !visited[node*2])
		{
			q.push({time,node * 2}); //순간이동은 시간 갱신안함
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