#include <iostream>
#include <vector>
#include <string>
#include <queue>;

using namespace std;


typedef pair<int, int>ci;

void solution(int w, int h, vector<vector<int>>& map,queue<ci>q,bool visited[51][51])
{
	int dr[8] = { -1,1,0,0,1,1,-1,-1 }; //상,하,좌,우,북동,남동,남서,북서
	int dc[8] = { 0,0,-1,1,1,-1,-1 ,1};

	while (!q.empty()) { //bfs돌리기
		int cr = q.front().first;
		int cc = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int nr = cr + dr[i];
			int nc = cc + dc[i];
			if (nr > 0 && nr <= w && nc > 0 && nc <= h && map[nr][nc] == 1 && !visited[nr][nc])
			{
				visited[nr][nc] = true;
				q.push(ci(nr, nc));
			}
		}
	}
	
}

int main()
{
	int w, h;
	queue<ci>q;
	vector<int> result;
	do
	{
		cin >> h >> w; //h가 행 w가 열
		vector<vector<int>> map(w+1, vector<int>(h+1, 0));
		for (int i = 1; i <= w; i++)
		{
			for (int j = 1; j <= h; j++)
			{
				cin >> map[i][j];
				
			}
		}
		//입력완료

		int cnt = 0;
		bool visited[51][51] = { false };
		//케이스별 초기화
		for (int i = 1; i <= w; i++)
		{
			for (int j = 1; j <= h; j++)
			{
				if (map[i][j] == 1 && !visited[i][j]) //입장가능한곳만 bfs를 돌린 후 섬의 개수를 하나씩 증가시킨다.
				{
					q.push(ci(i, j));
					solution(w, h, map, q, visited);
					cnt++;
				}
			}
		}
		result.push_back(cnt);
	} while (w != 0 || h != 0);
	
	for (int i = 0; i < result.size() - 1; i++)
		cout << result[i] << '\n';
	return 0;
}