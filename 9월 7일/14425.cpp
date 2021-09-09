#include <iostream>
#include <map>
using namespace std;

int main() 
{
	int n, m;
	cin >> n >> m;
	int cnt = 0;
	string input;
	map<string, int> a;
	while(n--)
	{
		cin >> input;
		a[input] = 1;
	}
	while (m--)
	{
		cin >> input;
		if (a[input] == 1)
			cnt++;
	}

	cout << cnt;
	return 0;
}