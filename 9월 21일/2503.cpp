#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

typedef struct baseball
{
	string num;
	int s;
	int b;
}baseball;

bool check(int num, vector<baseball> m)
{
	string s = to_string(num);

	if (s[0] == '0' || s[1] == '0' || s[2] == '0')
		return 0;
	if (s[0] == s[1] || s[1] == s[2] || s[0] == s[2])
		return 0;

	for (int i = 0; i < m.size(); i++)
	{
		int strike = 0;
		int ball = 0;
		for (int j = 0; j < 3; j++)
		{
			if (m[i].num.find(s[j]) == j)
				strike++;
			else if (m[i].num.find(s[j]) != m[i].num.npos)
				ball++;
		}
		if (ball != m[i].b|| strike != m[i].s)
			return 0;
	}
	return 1;

}

int main()
{
	int n,s, b;
	int cnt = 0;
	string num;
	
	cin >> n;
	vector<baseball> m;

	for (int i = 0; i < n; i++)
	{
		cin >> num >> s >> b;
		m.push_back({ num,s,b });
	}

	for (int i = 123; i <= 987; i++)
	{
		cnt+=check(i, m);
	}

	cout << cnt;
	
	return 0;
}