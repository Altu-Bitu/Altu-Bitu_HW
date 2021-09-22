#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int error[10];
int INF=1000001; //���峵����� ���

int check(int now)
{
	string s = to_string(now);
	for (int i = 0; i < s.length(); i++)
	{
		if (error[s[i] - '0'])
			return 0;
	}
	return 1;
}
int main()//**
{
	int n, m,input;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> input;
		error[input] = 1;
	}

	int now = abs(n - 100);//+ Ȥ�� -�θ� ����
	int cnt = 0;
	int Min = 1000001;
	for (int i = 0; i <= INF; i++)
	{
		if (check(i)) //���ڷ� �������ִ��� üũ
		{
			cnt = to_string(i).length(); //��� ���ڷ� �����°�
			cnt += abs(i - n); //�����ϱ�
			Min = min(cnt, Min);
		}
	}
	cout << min(Min, now);
	return 0;
}