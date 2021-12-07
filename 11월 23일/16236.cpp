#include <iostream>
#include <queue>

using namespace std;

int fish[21][21];
int visited[21][21] = { 0 };
int n;
int shark_size = 2;

void bfs(int r, int c)
{
	//상, 하, 좌, 우
	int dr[4] = { -1, 1, 0, 0 };
	int dc[4] = { 0, 0, -1, 1 };
	
	queue<pair<int, int>> q;
	q.push({ r,c });
	int time = 0;
	while (!q.empty())
	{
		int cr = q.front().first;
		int cc = q.front().second;
		q.pop();
		time = visited[cr][cc];
		for (int i = 0; i < 4; i++)
		{
			int nr = cr + dr[i];
			int nc = cc + dc[i];
			if (nr >= 0 && nr < n && nc >= 0 && nc < n && fish[nr][nc] == 0&&fish[nr][nc]<=shark_size)
			{
				visited[nr][nc] = visited[cr][cc] + 1;//시간증가
				if (fish[nr][nc] < shark_size)
				{
					fish[nr][nc] = 0;
				}
				q.push({ nr,nc });
			}
		
		}
	}
}

int main()
{
	cin >> n;
	int r, c;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> fish[i][j];
			if (fish[i][j] == 9)
			{
				fish[i][j] = 0; //물고기로 착각하면 안되니까
				r = i;
				c = j;
			}
		}
	}

	int cnt = 0;
	bfs(r, c);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cnt += visited[i][j];
		}
	}
	cout << cnt;
	

	return 0;
}