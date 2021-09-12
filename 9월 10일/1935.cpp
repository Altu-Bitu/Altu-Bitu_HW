#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<double> num;
stack<double> s;

void compute(double op1,double op2,char ch)
{
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
	return;
}

double eval(string input)
{
	char ch;
	int len = input.length();
	double op1, op2;
	int value;
	for (int i = 0; i < len; i++) //숫자만 스택에 넣고 연산자 나오면 계산해서 다시 스택에 넣기
	{
		ch = input[i];
		if ('A'<=ch&&ch<='Z') //더 깔끔한 방법으로 수정
		{
			value = ch - 'A';
			s.push(num[value]);
		}
		else
		{
			op2 = s.top();
			s.pop();
			op1 = s.top();
			s.pop();
			compute(op1, op2, ch);
			
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