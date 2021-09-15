#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n,input;
	cin >> n;
	stack<pair<int,int>> s;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		while (!s.empty())
		{
			if (input < s.top().second) //앞에 있는것이 수신탑이라면
			{
				cout << s.top().first << ' ';//출력
				break;
			}
			s.pop();//아니라면 input이 뒤에오는 것들의 수신탑이 되므로 쓸모없음->빼기
		}
		if (s.empty())
			cout << 0 << ' ';
		s.push(make_pair(i + 1, input));
	}

	return 0;
}