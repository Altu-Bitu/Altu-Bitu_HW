#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<double> num;
stack<double> s;
double eval(string input)
{
	char ch;
	int len = input.length();
	double op1, op2;
	int value;
	for (int i = 0; i < len; i++) //���ڸ� ���ÿ� �ְ� ������ ������ ����ؼ� �ٽ� ���ÿ� �ֱ�
	{
		ch = input[i];
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/')
		{
			value = ch - 65;
			s.push(num[value]);
		}
		else
		{
			op2 = s.top();
			s.pop();
			op1 = s.top();
			s.pop();
			switch (ch)
			{
			case '+':
				s.push(op1 + op2);
				break;
			case '-':
				s.push(op1 - op2);
				break;
			case'*':
				s.push(op1 * op2);
				break;
			case '/':
				s.push(op1 / (double)op2);
				break;
			}
			

		}

	}
	return s.top();
}

int main()
{
	int n;
	char c;
	cin >> n;
	num.assign(n, 0);
	string input;
	cin >> input;
	for(int i=0;i<n;i++)
	{
		cin >> num[i];
	}

	cout<<fixed;
	cout.precision(2);
	cout << eval(input);
	return 0;
}