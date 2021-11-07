#include <iostream>
#include <queue>
#include <vector>


using namespace std;

const int LIMIT = 100001;

int solution(int n, int k)
{
	int time = 0;
	vector<bool> visited(LIMIT, false);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;//시간을 기준으로 정렬되면서 쌓이게 된다.
	q.push({ time,n });
	visited[n] = true;

	while (!q.empty())
	{

		time = q.top().first;
		int node = q.top().second; 
		q.pop();

		if (node == k)
			return time;

		if (node * 2 < LIMIT && !visited[node * 2]) //순간이동이 먼저 처리되어야함
		{
			q.push({ time,node * 2 }); //순간이동은 시간 갱신안함
			visited[node * 2] = true;
		}
		if (node + 1 < LIMIT && !visited[node + 1])
		{
			q.push({ time + 1,node + 1});
			visited[node + 1] = true;
		}
		if (node - 1 >=0 && !visited[node - 1])
		{
			q.push({time + 1 ,node - 1});
			visited[node - 1] = true;
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