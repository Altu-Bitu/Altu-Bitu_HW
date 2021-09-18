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
			num.push_back(double(stoi(input))); //숫자면 숫자 덱에
		else
			op.push_back(input[0]); //수식이면 수식덱에 넣어 관리
	}
	
	double value=0;
	while (!op.empty()) //결과값만 남았을때 멈춤
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
	if (result - (int)result) //정수이면 0이 출력 아니면 0이 아닌 값으로 참
		cout << "toothpaste";
	else
		cout << "mint chocolate";
	return 0;
}