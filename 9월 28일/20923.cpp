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

int cardGameDo()
{
	dodoG.push_back(dodo.back());
	dodo.pop_back();

	if (dodo.empty())
	{
		cout << "su";
		return 0;
	}

	if (dodoG.back() == 5)
		transfer(suG, dodo, dodoG);

	if (!dodoG.empty() && !suG.empty())
	{
		if (dodoG.back() + suG.back() == 5)
			transfer(dodoG, su, suG);
	}
	return 1;
}

int cardGameSu()
{
	suG.push_back(su.back());
	su.pop_back();

	if (su.empty())
	{
		cout << "do";
		return 0;
	}

	if (suG.back() == 5)
		transfer(suG, dodo, dodoG);

	if (!dodoG.empty() && !suG.empty())
	{
		if (dodoG.back() + suG.back() == 5)
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
			int result = cardGameDo();
			if (result == 0)
				return 0;
		}
		else
		{
			int result = cardGameSu();
			if (result == 0)
				return 0;
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