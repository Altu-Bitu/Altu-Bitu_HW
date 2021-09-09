#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int>a;
vector<int>b;
vector<int>c;

int add(int len)
{
	for (int i = 0; i < len-1; i++)
	{
		int num =  c[i] + a[i] + b[i]; //�� ���ؼ�
		c[i] = num%10;  //���� �ڸ�
		c[i + 1] = num / 10; //���� �ڸ� ������ ä���ֱ�
		
	}
	if (c[len-1] == 0)
		return len - 1;  //���� �տ��� 0�̶�� size�ϳ� �ٿ��� ��ȯ 
	return len;
}

int main()
{
	string a1;
	string b1;
	cin >> a1 >> b1;
	int num_a = a1.length();
	int num_b = b1.length();
	int size = max(num_a, num_b);
	a.assign(size, 0);
	b.assign(size, 0);
	c.assign(size+1, 0);

	for (int i = 0; i < size; i++)
	{
		if (i < num_a)
			a[i] = a1[num_a - 1 - i] - '0';
		else
			a[i] = 0;
	}
	for (int i = 0; i < size; i++)
	{
		if (i < num_b)
			b[i] = b1[num_b - 1 - i] - '0';
		else
			b[i] = 0;
	}
	
	int len=add(size+1);

	for (int i = len-1; i >= 0; i--)
	{	
		cout << c[i];
	}

	return 0;
}