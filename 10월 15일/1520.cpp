#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int m, n;
int matrix[501][501];
int index[501][501] = { 0 };

int solution(int i,int j)
{
	int dr[4] = { -1,1,0,0}; //��,��,��,��
	int dc[4] = { 0,0,-1,1 };

	if (i == m && j == n) //������ ���ٸ�
		return 1; //1�� ��ȯ
	for (int k = 0; k < 4; k++) //�����¿� ���鼭 �� ����
	{
		int nr = i + dr[k]; //����
		int nc = j + dc[k];
		if (nr > 0 && nr <= m && nc > 0 && nc <= n && matrix[i][j] > matrix[nr][nc])
			index[i][j] += solution(nr, nc);
	}
	return index[i][j];
}

int main()
{
	cin >> m >> n;
	
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> matrix[i][j];
	cout<<solution(1,1);
	return 0;
}
//����https://sihyungyou.github.io/baekjoon-1520/