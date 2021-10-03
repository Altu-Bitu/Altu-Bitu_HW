#include <iostream>
#include <deque>

using namespace std;
deque<int> dodo;
deque<int> dodoG;
deque<int> su;
deque<int> suG;

void transfer(deque<int> &a, deque<int> &b, deque<int> &c)
{
	while (!a.empty())
	{
		b.push_front(a.front());
		a.pop_front();
	}

	while (!c.empty())
	{
		b.push_front(c.front());
		c.pop_front();
	}
}

int cardGame(deque<int> &a,deque<int>&b,deque<int>&c,deque<int> &d)
{
	b.push_back(a.back());
	a.pop_back();

	if (a.empty())
		return 0;

	if (b.back() == 5)
		transfer(suG, dodo,dodoG);

	if (!b.empty() && !d.empty())
	{
		if (b.back() + d.back() == 5)
			transfer(dodoG, su, suG);
	}
	return 1;
}


int main()
{
	int n, m, input1, input2;
	cin >> n >> m;
	

	for (int i = 0; i < n; i++)
	{
		cin >> input1 >> input2;
		dodo.push_back(input1);
		su.push_back(input2);
	}
	int cnt = 0;
	int flag = 1;
	while (m--)
	{
		if (flag % 2 == 1)
		{
			int result = cardGame(dodo,dodoG,su,suG);
			if (result == 0)
			{
				cout << "su";
				return 0;
			}
		}
		else
		{
			int result = cardGame(su,suG,dodo,dodoG);
			if (result == 0)
			{
				cout << "do";
				return 0;
			}
		}
		flag++;
	}


	if (dodo.size() > su.size())
		cout << "do";
	else if (dodo.size() < su.size())
		cout << "su";
	else
		cout << "dosu";
	return 0;
}