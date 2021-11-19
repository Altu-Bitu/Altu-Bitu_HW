#include <iostream>
#include <vector>

using namespace std;

int n, m;
int robot[51][51];

void count(int i, int j, int d)
{
	int cnt = 0;

	int dr[4] = {-1,0,1,0 }; //북동남서
	int dc[4] = { 0,1,0,-1 };

	robot[i][j] = 9; //청소했다는 표시
	cnt++;

	int nd, nr, nc;
	while (1)
	{
		int dir = 0;
		int original = d;
		for (int k = 0; k < 4; k++)//4방위 체크
		{
			nd = (d - 1 + 4) % 4;
			nr = i + dr[nd];
			nc = j + dc[nd];//갱신
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
			nr = i - dr[original];
			nc = j - dc[original]; //한칸후진
			d = original; //d 복구
			if ((nr < 0 || nc < 0 || nr >= n || nc >= m) || robot[nr][nc] == 1) //벽이거나 못가는곳
				break;
		}
		i = nr;
		j = nc;

	}
	cout << cnt;
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
	count(r, c, d);

	return 0;
}
//참고https://yabmoons.tistory.com/41