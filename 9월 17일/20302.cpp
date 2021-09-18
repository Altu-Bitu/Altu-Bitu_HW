#include <iostream>
#include <deque>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int n;
	string input;
	deque<char> op;
	deque<double>num;

	cin >> n;
	for(int i=1;i<2*n;i++)
	{
		cin >> input;
		if (input != "/" && input != "*")
			num.push_back(double(stoi(input))); //���ڸ� ���� ����
		else
			op.push_back(input[0]); //�����̸� ���ĵ��� �־� ����
	}
	
	double value=0;
	while (!op.empty()) //������� �������� ����
	{
		double num1 = num.front();
		num.pop_front();
		
		char opr = op.front();
		op.pop_front();
		
		double num2 = num.front();
		num.pop_front();
		
		switch (opr)
		{
		case '/':
			value = num1 / num2;
			break;
		case '*':
			value = num1 * num2;
			break;
		}
		
		num.push_front(value);
	}

	double result = num.front();
	if (result - (int)result) //�����̸� 0�� ��� �ƴϸ� 0�� �ƴ� ������ ��
		cout << "toothpaste";
	else
		cout << "mint chocolate";
	return 0;
}