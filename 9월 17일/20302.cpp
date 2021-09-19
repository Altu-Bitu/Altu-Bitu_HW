#include <iostream>
#include <string>
#include <cmath>

using namespace std;
const int MAX = 100000;

int p[MAX + 1];//넣어두는 집합

void put(int num)
{
	int a = sqrt(num); //소인수분해확인
	for(int i=2;i<=a;i++)
		while (!(num % i)) //나뉘어지면
		{
			num /= i; //수를 나누고
			p[i]++; //나눈 소수를 배열에 넣는다->있다고 표시하는것
		}
	if (num > 1)
		p[num]++; //남은 수가 소수라면 그 수를 넣는다.
}

void remove(int num)
{
	int a = sqrt(num);
	for(int i=2;i<=a;i++)
		while (!(num % i)) //나뉘어지면
		{
			num /= i; //수를 나누고
			p[i]--; //나눈 소수를 배열에 넣는다->있다고 표시하는것
		}
	if (num > 1)
		p[num]--;//p에 만약에 음수가있다면 분모라는것
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
			if (num < 0)//수가 음수인건 정수 유리수에 영향을 미치지 않는다
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
	if (zero_flag) //만약에 zero가 있다면 그건 분자임(무조건)->무조건 정수란 의미
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