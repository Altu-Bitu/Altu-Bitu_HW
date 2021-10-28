#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> number;

int secondBig(int r, int c)
{
	vector<int> res;
	for (int i = r; i < r+2; i++)
	{
		for (int j = c; j < c+2; j++)
		{
			res.push_back(number[i][j]);
		}
	}
	sort(res.begin(), res.end());
	return res[2]; //2��° ū�� ��ȯ
}

void divide(int n)
{
	if (n==1)
	{
		cout << number[0][0];
		return;
	}

	else
	{
		for (int i = 0; i < n; i+=2)//�� �������� �տ� �κ� index
		{
			for (int j = 0; j < n; j+=2)
			{
				number[i / 2][j / 2] = secondBig(i, j);//����ᵵ ������� ������ ���Ұ��� [0][0]�� ���� ������
			}
		}
		divide(n / 2);
	}
}
int  main()
{
	int n;
	cin >> n;
	number.assign(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> number[i][j];

	divide(n);
		
	return 0;
}