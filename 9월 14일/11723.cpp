#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

 
bool s[21] = { false };//�迭�� üũ/��üũ�� ǥ��

int main()
{
	ios::sync_with_stdio(false); //�ӵ� ���
	cin.tie(NULL);

	int n,x;
	string input;
	
	
	cin >> n;
	while (n--)
	{
		cin >> input;
		
		if (input == "add")
		{
			cin >> x;
			s[x] = true;
		}
		else if (input == "remove")
		{
			cin >> x;
			s[x] = false;
		}
		else if (input == "check")
		{
			cin >> x;
			if (s[x])
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (input == "toggle")
		{
			cin >> x;
			s[x] = !s[x];
		}
		else if (input == "all")
		{
			memset(s, true, sizeof(s));
		}
		else if (input == "empty")
		{
			memset(s, false, sizeof(s));
		}


	}
	return 0;
}