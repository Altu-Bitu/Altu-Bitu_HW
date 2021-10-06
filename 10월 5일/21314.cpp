#include <iostream>

using namespace std;

int main()
{
	string input;
	string small, big;
	cin >> input;
	int cnt = 0;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == 'M')
			cnt++;
		else
		{
			if (cnt != 0)
			{
				small += '1';
				for (int j = 1; j < cnt; j++)
					small += '0';
				cnt = 0;
			}
			small += '5';
		}
	}
	cnt = 0;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == 'M')
			cnt++;
		else
		{
			big += '5';
			for (int j = 0; j < cnt; j++)
				big += '0';
			cnt = 0;
		}
	}
	if (cnt)
	{
		small += '1';
		for (int j = 1; j < cnt; j++)
			small += '0';
	}
	if (cnt)
	{
		big += '1';
		for (int j = 1; j < cnt; j++)
			big += '0';
	}

	cout << big << '\n'<<small;
	return 0;
}