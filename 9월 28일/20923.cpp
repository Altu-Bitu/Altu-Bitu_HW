#include <iostream>
#include <deque>

using namespace std;

int main()
{
	int n, m,input1,input2;
	cin >> n >> m;
	deque<int> a;
	deque<int> b;
	deque<int> x;
	deque<int> y;

	for (int i = 0; i < n; i++)
	{
		cin >> input1 >> input2;
		a.push_back(input1);
		b.push_back(input2);
	}
	int cnt = 0;

	while(1)
	{
		x.push_back(a.back());
		a.pop_back();
		
		if (a.empty())
		{
			cout << "su";
			return 0;
		}

		if (x.back() == 5)
			{
				while (!y.empty())
				{
					a.push_front(y.front());
					y.pop_front();
				}

				while (!x.empty())
				{
					a.push_front(x.front());
					x.pop_front();
				}

		}

	

		if (!x.empty()&&!y.empty())
		{
			if (x.back() + y.back() == 5)
			{
				while (!x.empty())
				{
					b.push_front(x.front());
					x.pop_front();
				}

				while (!y.empty())
				{
					b.push_front(y.front());
					y.pop_front();
				}

			}
		}

		cnt++;

		if (cnt == m)
			break;

		y.push_back(b.back());
		b.pop_back();

		if (b.empty())
		{
			cout << "do";
			return 0;
		}

		if (y.back() == 5)
		{
			while (!y.empty())
			{
				a.push_front(y.front());
				y.pop_front();
			}

			while (!x.empty())
			{
				a.push_front(x.front());
				x.pop_front();
			}

		}

			if (cnt == m)
				break;
			if (!x.empty() && !y.empty())
			{
				if (x.back() + y.back() == 5)
				{
					while (!x.empty())
					{
						b.push_front(x.front());
						x.pop_front();
					}
					
					while (!y.empty())
					{
						b.push_front(y.front());
						y.pop_front();
					}

				}
			}
			cnt++;
			if (cnt == m)
				break;
	}


	if (a.size() > b.size())
		cout << "do";
	else if (a.size() < b.size())
		cout << "su";
	else
		cout << "dosu";
	return 0;
}