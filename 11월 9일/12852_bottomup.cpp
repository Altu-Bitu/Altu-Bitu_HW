#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int SIZE = 10e6;
int dp[1000001]; //�������� �������ֵ�������.


void route(vector<int>&path,int n)
{
	while (n != -1)
	{
		cout << n<<' '; //���������� ����
		n = path[n];//path�� n�� �������� �鸥 ������ ���ڸ� ����
	}
}

void bottomup(int n)
{
	dp[1] = 0;//�������� dp���� 0���� ����
	vector<int> path(SIZE + 1, -1);
	for(int i=2;i<=n;i++)
	{
		//�⺻��
		dp[i] = dp[i - 1] + 1;
		path[i] = i - 1;

		//3���� ������
		if (i % 3 == 0)//��������
		{
			if (dp[i] > dp[i / 3] + 1)//3���� �������� ���İ��������� ����
			{
				dp[i] = dp[i / 3] + 1;
				path[i] = i / 3;
			}
		}
		//2�� ������
		if (i % 2 == 0)
		{
			if (dp[i] > dp[i / 2] + 1)//3���� �������� ���İ��������� ����
			{
				dp[i] = dp[i / 2] + 1;
				path[i] = i / 2;
			}
		}

		
		
	}
	cout << dp[n] << '\n';
	route(path,n);

}

int main()
{
	int n;
	cin >> n;
	bottomup(n);
	return 0;
}