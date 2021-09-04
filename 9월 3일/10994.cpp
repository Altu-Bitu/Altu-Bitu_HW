#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
char stars[401][401];

void star(int n,int a)
{
	if (n == 1)
	{
		stars[a][a] = '*';
		return;
	}

	int end = 1 + 4 * (n - 1);

	for (int i = a; i < a+end; i++)
	{
		stars[a][i] = '*';
		stars[a + end - 1][i] = '*';
	}
	//���� ���� ä���

	for (int i = a; i < a+end; i++)
	{
		stars[i][a] = '*';
		stars[i][a + end - 1] = '*';
	}
	//�� �� �׵θ� ���� ä���->�̷��� �ؼ� n�϶� �ٱ� �ϼ�!
	
	star(n - 1, a + 2);
	return;

}
int main()
{
	int n;
	cin >> n;
	int end = 1 + 4 * (n - 1);

	for (int i = 0; i < end; i++)
	{
		for (int j = 0; j < end; j++)
			stars[i][j] = ' ';
	}

	star(n, 0);

	for (int i = 0; i < end; i++)
	{
		for (int j = 0; j < end; j++)
		{
			cout << stars[i][j];
		}
		cout << '\n';
	}

	return 0;
}