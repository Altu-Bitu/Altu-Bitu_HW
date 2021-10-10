#include <iostream>
#include <vector>
using namespace std;

string smallest(string input)
{
	vector<char> small(input.size(),'0');
	int flag = 0;
	for (int i = 0; i < input.size(); i++)
	{
		if (!flag && input[i] == 'M')
		{
			small[i] = '1';
			flag = 1;
		}
		
		else if(input[i]=='K')
		{
			small[i] = '5';
			flag = 0;
		}
	}
	string s;
	for (int i = 0; i < input.size(); i++)
		s += small[i];
	return s;
}

string biggest(string input)
{
	vector<char> big(input.size(),'0');
	int flag = 0;
	int cnt = 0;
	for (int i = 0; i < input.size(); i++)
	{
		if (!flag && input[i] == 'M')
		{
			flag = 1;
			cnt = i;
		}
		else if(input[i]=='K')
		{
			if (cnt!=-1)
				big[cnt] = '5';
			else
				big[i] = '5';
			flag = 0;
			cnt = -1;
		}
	}
	if (flag)
	{
		for (int i = cnt; i < input.size(); i++)
			big[i] = '1';
	}
	string s;
	for (int i = 0; i < input.size(); i++)
		s += big[i];
	return s;
}
int main()
{
	string input;
	cin >> input;

	cout << biggest(input)<< '\n'<<smallest(input);
	return 0;
}