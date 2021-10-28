#include <iostream>

using namespace std;

char star[2187][2187];

void starDraw(int i,int j,int num)
{
	if ((i / num) % 3 == 1 && (j / num) % 3 == 1)//찾은규칙
				star[i][j] = ' ';
	else
		if(num>=3) //num이 3으로 쪼개서 재귀 실행가능하면
			starDraw(i,j,num / 3); //재귀로 실행해서 가장작은 패턴까지 들어가 빈공간자리 찾아준다
}

int main()
{

	int n;
	cin >> n;
	
	for (int i = 0; i <n; i++)
	{
		for (int j = 0; j < n; j++)
			star[i][j] = '*'; //다 별로 초기화
	}
	for (int i = 0; i < n; i++)
	{
		for(int j=0;j<n;j++) //n*n 행렬돌면서 빈공간 찾아서 공백화해주기
			starDraw(i,j,n);
	}
	for (int i = 0; i < n; i++) //출력
		{
			for (int j = 0; j < n; j++)
				cout << star[i][j];
			cout << '\n';
		}
	

	return 0;
}