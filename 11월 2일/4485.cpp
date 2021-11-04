#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> ci;

int INF = 100;
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };

int solution(int n, vector<vector<int>>& graph)
{
	vector<vector<int>> dist(n, vector<int> (n,INF));
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; 
	
	pq.push({ graph[0][0], {0, 0} }); //(0,0)���� ����
	visited[0][0] = true;

	while (!pq.empty())
	{
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		int weight = pq.top().first;
		pq.pop();

		for (int i = 0; i < 4; i++) //�����¿�Ž��
		{
			int next_x = x + dr[i];
			int next_y = y + dc[i];
			
			if (0 <= next_x && next_x <n && 0 <= next_y && next_y < n)
			{
				int next_weight = weight + graph[next_x][next_y]; //����ؼ� weight�� �����ϸ� ���߿� �� weight�� ���� �������� ����
				if (!visited[next_x][next_y] && dist[next_x][next_y] > next_weight)
				{
					visited[next_x][next_y] = true;
					dist[next_x][next_y] = next_weight;
					pq.push({ next_weight, { next_x,next_y} });
				}
			}
		}
	}
		int sum = dist[n-1][n-1];
	return sum;
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