#include <iostream>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m,input;
	string input_s;
	map<int, string> name;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> input_s>>input;
		if(name[input]=="")//먼저들어간게 우선
			name[input] = input_s;
	}
	string result = "";
	for (int i = 0; i < m; i++)
	{
		cin >> input;
		result += name.lower_bound(input)->second;
		result += '\n';
	}
	cout << result;
	return 0;
}