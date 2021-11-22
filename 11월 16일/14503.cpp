#include <iostream>
#include <vector>

using namespace std;

int n, m;
int robot[51][51];

int count(int r, int c, int d)
{
	int cnt = 0;

	int dr[4] = {-1,0,1,0 }; //북동남서
	int dc[4] = { 0,1,0,-1 };

	robot[r][c] = 9; //청소했다는 표시
	cnt++;

	int nd, nr, nc;
	while (1)
	{
		int dir = 0;
		int original = d;
		for (int k = 0; k < 4; k++)//4방위 체크
		{
			nd = (d +3) % 4;
			nr = r + dr[nd];
			nc = c + dc[nd];//갱신
			if ((nr < 0 || nr >= n || nc < 0 || nc >= m)||robot[nr][nc]!=0)
			{
				d = nd;
				dir++;
			}

			else if(robot[nr][nc]==0)
			{
				robot[nr][nc] = 9; //청소표시
				cnt++;
				d = nd;
				break;
			}
		}

		if (dir == 4)//4면다 청소 못하면
		{
			nr = r - dr[original];
			nc = c - dc[original]; //한칸후진
			d = original; //d 복구
			if (robot[nr][nc] == 1) //벽이거나 못가는곳
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

	//입력
	cin >> n >> m >> r >> c >> d;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> robot[i][j];
		}
	}

	//개수구하기
	cout<<count(r, c, d);

	return 0;
}
//참고https://yabmoons.tistory.com/41