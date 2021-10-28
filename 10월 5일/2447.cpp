#include <iostream>

using namespace std;

char star[2187][2187];

void starDraw(int i,int j,int num)
{
	if ((i / num) % 3 == 1 && (j / num) % 3 == 1)//ã����Ģ
				star[i][j] = ' ';
	else
		if(num>=3) //num�� 3���� �ɰ��� ��� ���డ���ϸ�
			starDraw(i,j,num / 3); //��ͷ� �����ؼ� �������� ���ϱ��� �� ������ڸ� ã���ش�
}

int main()
{

	int n;
	cin >> n;
	
	for (int i = 0; i <n; i++)
	{
		for (int j = 0; j < n; j++)
			star[i][j] = '*'; //�� ���� �ʱ�ȭ
	}
	for (int i = 0; i < n; i++)
	{
		for(int j=0;j<n;j++) //n*n ��ĵ��鼭 ����� ã�Ƽ� ����ȭ���ֱ�
			starDraw(i,j,n);
	}
	for (int i = 0; i < n; i++) //���
		{
			for (int j = 0; j < n; j++)
				cout << star[i][j];
			cout << '\n';
		}
	

	return 0;
}