#include <iostream>
#include <vector>

using namespace std;

int n, m;
int robot[51][51];

int count(int r, int c, int d)
{
	int cnt = 0;

	int dr[4] = {-1,0,1,0 }; //�ϵ�����
	int dc[4] = { 0,1,0,-1 };

	robot[r][c] = 9; //û���ߴٴ� ǥ��
	cnt++;

	int nd, nr, nc;
	while (1)
	{
		int dir = 0;
		int original = d;
		for (int k = 0; k < 4; k++)//4���� üũ
		{
			nd = (d +3) % 4;
			nr = r + dr[nd];
			nc = c + dc[nd];//����
			if ((nr < 0 || nr >= n || nc < 0 || nc >= m)||robot[nr][nc]!=0)
			{
				d = nd;
				dir++;
			}

			else if(robot[nr][nc]==0)
			{
				robot[nr][nc] = 9; //û��ǥ��
				cnt++;
				d = nd;
				break;
			}
		}

		if (dir == 4)//4��� û�� ���ϸ�
		{
			nr = r - dr[original];
			nc = c - dc[original]; //��ĭ����
			d = original; //d ����
			if (robot[nr][nc] == 1) //���̰ų� �����°�
				break;
		}
		r = nr;
		c = nc;

	}
	return cnt;
}

int main()
{
	int r, c, d;

	//�Է�
	cin >> n >> m >> r >> c >> d;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> robot[i][j];
		}
	}

	//�������ϱ�
	cout<<count(r, c, d);

	return 0;
}
//����https://yabmoons.tistory.com/41