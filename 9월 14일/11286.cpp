#include <iostream>
#include <queue>
#include <cstdlib>

using namespace std;

struct cmp
{
	bool operator()(int a, int b)
	{
		if(abs(a)!=abs(b))
			return abs(a) > abs(b);
		return a > b;
	}
};

int main()
{
	int n,x;
	vector<int> s;
	priority_queue<int, vector<int>, cmp> pq;
	cin >> n;
	while (n--)
	{
		cin >> x;
		if (x == 0)
		{
			if (!pq.empty())
			{
				s.push_back(pq.top());
				pq.pop();
			}
			else
				s.push_back(0);
		}

		else
			pq.push(x);
	}

	for (int i = 0; i < s.size(); i++)
		cout << s[i]<<'\n';
	return 0;
}