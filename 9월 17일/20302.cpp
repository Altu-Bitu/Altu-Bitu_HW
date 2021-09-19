#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
const int MAX = 100000;

int p[MAX + 1];//넣어두는 집합

const int SIZE = 100000;
vector<int> isPrime() {
	vector<int> prime(SIZE, 0);

	//먼저 모든 수를 소수라 가정하고, i번째 인덱스에 i값 저장
	for (int i = 2; i <= SIZE; i++)
		prime[i] = i;

	//소수 판별
	for (int i = 2; i <= sqrt(SIZE); i++) {
		if (prime[i] == i) { //소수라면
			for (int j = i * i; j <= SIZE; j += i) { //배수에 소수(i) 저장
				if (prime[j] == j) { //저장된 소수가 없을 경우만
					prime[j] = i; //소수 저장
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