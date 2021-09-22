#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int check(int num,vector<string> m,vector<pair<int,int>> a)
{
	string s = to_string(num);
	if (s[0] != s[1] && s[1] != s[2])
	{
		for (int i = 0; i < m.size(); i++)
		{
			int strike = 0;
			int ball = 0;
			for (int j = 0; j < 3; j++)
			{
				if (m[i].find(s[j]) == j)
					strike++;
				else if (m[i].find(s[j]) != m[i].npos)
					ball++;
			}
			if (ball != a[i].second || strike != a[i].first)
				return 0;
		}
		return 1;
	}
	return 0;
}

int main()
{
	int n, s, b;
	int cnt = 0;
	string num;
	
	cin >> n;
	vector<string> m;
	m.assign(n, "");
	vector<pair<int, int>> res;
	res.assign(n, { 0,0 });

	for (int i = 0; i < n; i++)
	{
		cin >> num >> s >> b;
		m[i] = num;
		res[i] = { s,b };
	}

	for (int i = 123; i <= 999; i++)
	{
		cnt+=check(i, m, res);
	}

	cout << cnt;
	
	return 0;
}