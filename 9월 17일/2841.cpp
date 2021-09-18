#include <iostream>
#include <stack>

using namespace std;
typedef pair<int, int> pp;
int main()
{
	int n, p;
	int cnt = 0;
	int input1, input2;
	
	cin >> n >> p;
	stack<pp> s[7];
	for(int i=0;i<n;i++)
	{
		cin >> input1 >> input2;
		if (s[input1].empty())
		{
			s[input1].push({ input1,input2 });
			cnt++;
		}
		else
		{
			while (s[input1].top().second > input2)
				{
					s[input1].pop();
					cnt++;
					if (s[input1].empty())
						break;
				}
				if (s[input1].empty()||s[input1].top().second != input2)
				{
					s[input1].push({ input1,input2 });
					cnt++;
				}
		}
	}
	cout << cnt;
	return 0;
}