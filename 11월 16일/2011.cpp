#include <iostream>
#include <vector>

using namespace std;

int MAX = 5001;
int LEFT = 1000000;
//��ȭ�� �ΰ�
//dp[i]+=dp[i-1]->1~9����
//dp[i]+=dp[i-2]->10~26����

int main()
{
	string num;
	cin >> num;
	vector<int> dp(5001, 0);
	vector<int> list(num.size()+1,0);

	for (int i = 1; i <= num.size(); i++)
	{
		list[i]=num[i-1] - '0';
	}

	if (num.length() == 1) //1�� ������ �ϳ��θ� �ؼ���
	{
		cout << 0;
		return 0;
	}

	dp[0] = 1;//�ʱ⼳��
	for (int i = 1; i <= num.length(); i++)
	{
		if (list[i]>=1&&list[i]<=9)
		{
			dp[i] += dp[i - 1];//12�� ������ 1, 2�� �����Ƿ� �ٷ� �����Ϳ� ���ش�
			dp[i] %= LEFT;
		}

		if (i == 1)//���� ó����
			continue;

		int second = list[i] + list[i - 1] * 10; //�Ѳ����� �б����� ó��
		if (second>= 10 && second <= 26)
		{
			dp[i] += dp[i - 2]; //12�� ������ �ϳ��� �����Ƿ� �ι�°�� ���� �Ϳ� �����ش�
			dp[i] %= LEFT;
		}
	}

	cout << dp[num.length()];

	return 0;
}//����https://yabmoons.tistory.com/163