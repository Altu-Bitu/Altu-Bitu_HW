#include <iostream>
#include <vector>
#include <string>
#include <queue>;

using namespace std;


typedef pair<int, int>ci;

void solution(int w, int h, vector<vector<int>>& map,queue<ci>q,bool visited[51][51])
{
	int dr[8] = { -1,1,0,0,1,1,-1,-1 }; //��,��,��,��,�ϵ�,����,����,�ϼ�
	int dc[8] = { 0,0,-1,1,1,-1,-1 ,1};

	while (!q.empty()) { //bfs������
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
		cin >> h >> w; //h�� �� w�� ��
		vector<vector<int>> map(w+1, vector<int>(h+1, 0));
		for (int i = 1; i <= w; i++)
		{
			for (int j = 1; j <= h; j++)
			{
				cin >> map[i][j];
				
			}
		}
		//�Է¿Ϸ�

		int cnt = 0;
		bool visited[51][51] = { false };
		//���̽��� �ʱ�ȭ
		for (int i = 1; i <= w; i++)
		{
			for (int j = 1; j <= h; j++)
			{
				if (map[i][j] == 1 && !visited[i][j]) //���尡���Ѱ��� bfs�� ���� �� ���� ������ �ϳ��� ������Ų��.
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