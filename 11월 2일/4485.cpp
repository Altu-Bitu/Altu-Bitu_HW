#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> ci;

int INF = 987654321;
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };

int solution(int n, vector<vector<int>>& graph)
{
	vector<vector<int>> dist(n, vector<int>(n, INF));
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; 
	pq.push({ graph[0][0], {0, 0} }); //(0,0)���� ����
	dist[0][0] = pq.top().first;

	while (!pq.empty())
	{
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		int weight = pq.top().first;
		pq.pop();

		if (weight > dist[x][y])
			continue;
		for (int i = 0; i < 4; i++) //�����¿�Ž��
		{
			int next_x = x + dr[i];
			int next_y = y + dc[i];
			
			if (0 > next_x || next_x >= n || 0 > next_y || next_y >= n)
				continue;
			int next_weight = dist[x][y] + graph[next_x][next_y]; //����ؼ� weight�� �����ϸ� ���߿� �� weight�� ���� �������� ����
			if ( dist[next_x][next_y] > next_weight)
			{
				dist[next_x][next_y] = next_weight;
				pq.push({ next_weight, { next_x, next_y} });
			}
	
		}
	}
	return dist[n-1][n-1];

}

int main()
{
	int n,w;
	vector<int> result;
	while(1)
	{
		cin >> n;
		if (n == 0)
			break;
		vector<vector<int>> graph(n, vector<int>(n,0));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> w;
				graph[i][j] = w;
			}
		}
		result.push_back(solution(n, graph));
	}
	for (int i = 0; i < result.size(); i++)
		cout << "Problem " << i + 1 << ": " << result[i]<<"\n";
	return 0;
}
//����https://jaimemin.tistory.com/1209