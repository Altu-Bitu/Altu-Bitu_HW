#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main()
{
	deque<int> deque ;
	vector<int> list;
	int n;
	string input;
	cin >> n;
	list.assign(n, -2);
	int i = 0;
	while(n--)
	{
		cin >> input;
		if (input == "push_front")
		{
			int k;
			cin >> k;
			deque.push_front(k);
		}
		else if (input == "push_back")
		{
			int k;
			cin >> k;
			deque.push_back(k);
		}
		else if (input == "front")
		{
			if (deque.empty())
				list[i++] = -1;
			else
				list[i++] = deque.front();
		}
		else if (input == "back")
		{
			if (deque.empty())
				list[i++] = -1;
			else
				list[i++] = deque.back();
		}
		else if (input == "pop_front")
		{
			if (deque.empty())
				list[i++] = -1;
			else
			{
				list[i++] = deque.front();
				deque.pop_front();
			}
		}
		else if (input == "pop_back")
		{
			if (deque.empty())
				list[i++] = -1;
			else
			{
				list[i++] = deque.back();
				deque.pop_back();
			}
		}
		else if (input == "size")
			list[i++] = deque.size();
		else if (input == "empty")
		{
			if (deque.empty())
				list[i++] = 1;
			else
				list[i++] = 0;
		}

	}

	for (int i = 0; list[i] != -2; i++)
		cout << list[i] << '\n';

	return 0;
}