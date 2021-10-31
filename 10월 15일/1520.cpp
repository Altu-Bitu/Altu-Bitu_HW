#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int m, n;
int matrix[501][501]; 
int index[501][501];

int solution(int i, int j)
{
	int dr[4] = { -1,1,0,0 }; //상,하,좌,우
	int dc[4] = { 0,0,-1,1 };

	if (i == m && j == n) //끝까지 갔다면
		return 1; //1을 반환
	if (index[i][j] == -1) //dp가 처음 접근하는 경우만 갱신
	{
		index[i][j] = 0; //더할수있게 값을 변경해주자+0이된순간 이 dp에는 접근을 했던것이라는것을 알려줌
		for (int k = 0; k < 4; k++) //상하좌우 돌면서 길 선택
		{
			int nr = i + dr[k]; //갱신
			int nc = j + dc[k];
			if (nr > 0 && nr <= m && nc > 0 && nc <= n && matrix[i][j] > matrix[nr][nc])
				index[i][j] += solution(nr, nc);
			
		}
	}
	return index[i][j];
}

int main()
{
	cin >> m >> n;

	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			matrix[i][j] = 10001; //index가 0일때 접근해도 값이 변경되지 않게 10001최대값으로 설정
			index[i][j] = -1;
		}
	}
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> matrix[i][j];
	cout << solution(1, 1);
	return 0;
}
//참고https://sihyungyou.github.io/baekjoon-1520/