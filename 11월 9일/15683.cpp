#include <iostream>
#include <vector>
using namespace std;

int n, m;
int cnt = 0;
int ans = 65;
vector<vector<int>> matrix;

typedef struct CCTV
{
	int i, j, type;
}CCTV;

vector<CCTV> cctv;

void change(int i, CCTV cctv)
{
	i %= 4;
	int dr[4] = { 0,-1,0,1 };//동북서남
	int dc[4] = { 1,0,-1,0 };
	int r = cctv.i + dr[i];
	int c = cctv.j + dc[i];

	if (i == 0)//동
	{
		while (c < m)
		{
			if (matrix[r][c] == 6) //벽만 아니면 됨
				break;
			matrix[r][c] = -1;
			c++;
		}
	}

	else if (i == 1)//북
	{
		while (r>=0)
		{
			if (matrix[r][c] == 6)
				break;
			matrix[r][c] = -1;
			r--;
		}
	}

	else if (i == 2)//서
	{
		while (c>=0)
		{
			if (matrix[r][c] == 6)
				break;
			matrix[r][c] = -1;
			c--;
		}
	}


	else if (i == 3)//남
	{
		while (r < n)
		{
			if (matrix[r][c] == 6)
				break;
			matrix[r][c] = -1;
			r++;
		}
	}
}

void count(int num)
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (matrix[i][j] == 0) //사각지대 개수 세기
				cnt++;
		}
	}
	if (ans > cnt)
		ans = cnt;
}

void cpy(vector<vector<int>>& a, vector<vector<int>>& b)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = b[i][j];
}

void dfs(int num)
{
	if (num == cctv.size()) //들어있는 CCTV전부 확인했다면 사각지대check
	{
		count(num);
		return;
	}

	vector<vector<int>> temp(n, vector<int>(m, 0));
	int rotation[5] = {4,2,4,4,1 };//회전수
	int type = cctv[num].type;
	for (int i = 0; i < rotation[type-1]; i++)
	{
		cpy(temp, matrix);// 기존거 저장해두기

		switch (type)
		{
		case 1:
			change(i, cctv[num]);
			break;
		case 2://2면 수직으로
			change(i, cctv[num]);
			change(i + 2, cctv[num]);
			break;
		case 3://ㄱ자로
			change(i, cctv[num]);
			change(i + 1, cctv[num]);
			break;
		case 4://3면
			change(i, cctv[num]);
			change(i + 1, cctv[num]);
			change(i + 2, cctv[num]);
			break;
		case 5://4면
			for (int j = i; j < i + 4; j++)
				change(j, cctv[num]);
			break;
		}

		dfs(num + 1);
		cpy(matrix, temp); //matrix 복원
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//시간초과 줄이기용

	cin >> n >> m; //행렬
	matrix.assign(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> matrix[i][j];
			if (matrix[i][j] != 0 && matrix[i][j] != 6)//카메라가 있는 경우에만 탐색
			{
				cctv.push_back({ i,j,matrix[i][j] });
			}
		}
	}
	dfs(0);
	cout << ans;
	return 0;
}//참고https://kevinthegrey.tistory.com/163