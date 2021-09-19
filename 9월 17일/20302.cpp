#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
const int MAX = 100000;

int p[MAX + 1];//�־�δ� ����

const int SIZE = 100000;
vector<int> isPrime() {
	vector<int> prime(SIZE, 0);

	//���� ��� ���� �Ҽ��� �����ϰ�, i��° �ε����� i�� ����
	for (int i = 2; i <= SIZE; i++)
		prime[i] = i;

	//�Ҽ� �Ǻ�
	for (int i = 2; i <= sqrt(SIZE); i++) {
		if (prime[i] == i) { //�Ҽ����
			for (int j = i * i; j <= SIZE; j += i) { //����� �Ҽ�(i) ����
				if (prime[j] == j) { //����� �Ҽ��� ���� ��츸
					prime[j] = i; //�Ҽ� ����
				}
			}
		}
	}

	return prime;
}

vector<int>prime = isPrime();


void put(int num)
{
	while (num > 1)
	{
		p[prime[num]]++;
		num = num / prime[num];
	}
}

void remove(int num)
{
	while (num > 1)
	{
		p[prime[num]]--;
		num = num / prime[num];
	}
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