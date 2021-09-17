#include <iostream>

using namespace std;

int main()
{
	string input;
	string result;

	int java=0,c=0,all=1;
	int cnt = 0;
	cin >> input;
	int len = input.size();

	if ('A' <= input[0] && input[0] <= 'Z')
	{
		cout << "Error!";
		return 0;
	}
	if (input[0] == '_')
	{
		cout << "Error!";
		return 0;
	}
	if (input[len - 1] == '_')
	{
		cout << "Error!";
		return 0;
	}
	for (int i = 0; i < len; i++)
	{
		
		if ('A' <= input[i] && input[i] <= 'Z')
		{
			java = 1;
			all = 0;
		}
		else if (input[i] == '_')
		{
			if (cnt == 1)
			{
				cout << "Error!";
				return 0;
			}
			c = 1;
			all = 0;
			cnt = 1;
		}
		else
		{
			cnt = 0;
		}

		if (java==1 && c==1)
		{
			cout << "Error!";
			return 0;
		}
	}

	if (java == 1)
	{
		for (int i = 0; i < len; i++)
		{
			result += input[i];
			if (i + 1 != len)
			{
				if ('A' <= input[i + 1] && input[i + 1] <= 'Z')
				{
					result += '_';
					input[i + 1] = tolower(input[i + 1]);
				}
			}
		}
	}

	else if (c == 1)
	{
		for (int i = 0; i < len; i++)
		{
			result += input[i];
			if (i + 1 != len)
			{
				if (input[i + 1] == '_')
				{
					i++;
					input[i + 1] = toupper(input[i + 1]);
				}
			}
		}
	}

	else if (all == 1)
	{
		result = input;
	}

	else
	{
		cout << "Error!";
		return 0;
	}

	cout << result;
	return 0;
}