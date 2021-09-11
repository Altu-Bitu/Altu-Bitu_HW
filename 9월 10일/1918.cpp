#include <iostream>
#include <stack>
using namespace std;

int prec(char op) //우선순위 파악
{
	switch (op)
	{
	case '(':
	case ')':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	}
	return -1;
}

int main()
{
	string input;
	cin >> input;
	int len = input.length();
	char ch,top;
	stack<char> s;
	for (int i = 0; i < len; i++)
	{
		ch = input[i];
		switch (ch)
		{
		case '+': case '-': case '/': case '*':
			while (!s.empty() && (prec(ch) <= prec(s.top()))) //기존에 있는게 우선순위 크면 비지 않는 동안 출력
			{
				cout << s.top();
				s.pop();
			}
			s.push(ch);
			break;
		case '(':
			s.push(ch);
			break;
		case ')': 
			top = s.top();
			s.pop();
			while (top != '(') //괄호가 끝날때까지 출력
			{
				cout << top;
				top = s.top();
				s.pop();
			}
			break;
		default:
			cout << ch;
			break;
		}
	}
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
	return 0;
}