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
			if (input < s.top().second) //�տ� �ִ°��� ����ž�̶��
			{
				cout << s.top().first << ' ';//���
				break;
			}
			s.pop();//�ƴ϶�� input�� �ڿ����� �͵��� ����ž�� �ǹǷ� �������->����
		}
		if (s.empty())
			cout << 0 << ' ';
		s.push(make_pair(i + 1, input));
	}

	return 0;
}