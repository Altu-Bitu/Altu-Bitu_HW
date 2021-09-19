#include <iostream>
#include <string>
#include <cmath>

using namespace std;
const int MAX = 100000;

int p[MAX + 1];//�־�δ� ����

void put(int num)
{
	int a = sqrt(num); //���μ�����Ȯ��
	for(int i=2;i<=a;i++)
		while (!(num % i)) //����������
		{
			num /= i; //���� ������
			p[i]++; //���� �Ҽ��� �迭�� �ִ´�->�ִٰ� ǥ���ϴ°�
		}
	if (num > 1)
		p[num]++; //���� ���� �Ҽ���� �� ���� �ִ´�.
}

void remove(int num)
{
	int a = sqrt(num);
	for(int i=2;i<=a;i++)
		while (!(num % i)) //����������
		{
			num /= i; //���� ������
			p[i]--; //���� �Ҽ��� �迭�� �ִ´�->�ִٰ� ǥ���ϴ°�
		}
	if (num > 1)
		p[num]--;//p�� ���࿡ �������ִٸ� �и��°�
}
int main()
{
	int n,num;
	char op;
	int zero_flag = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			cin >> num;
			if (num < 0)//���� �����ΰ� ���� �������� ������ ��ġ�� �ʴ´�
				num = abs(num);
			else if (num == 0)
				zero_flag = 1;
			if (num)
				put(num);
		}
		else
		{
			cin >> op >> num;
			if (num < 0)
				num = abs(num);
			else if (num == 0)
				zero_flag = 1;
			if (op == '/')
				remove(num);
			else if (num)
				put(num);
		}
	}
	int flag = 0;
	if (zero_flag) //���࿡ zero�� �ִٸ� �װ� ������(������)->������ ������ �ǹ�
		cout << "mint chocolate";
	else
	{
		for (int i = 2; i <= MAX; i++)
			if (p[i] < 0)
				flag = 1;
		if (flag)
			cout << "toothpaste";
		else
			cout << "mint chocolate";
		
	}
	return 0;
}