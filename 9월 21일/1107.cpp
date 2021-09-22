#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int error[10];
int INF=1000001; //고장났을경우 고려

int check(int now)
{
	string s = to_string(now);
	for (int i = 0; i < s.length(); i++)
	{
		if (error[s[i] - '0'])
			return 0;
	}
	return 1;
}
int main()//**
{
	int n, m,input;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> input;
		error[input] = 1;
	}

	int now = abs(n - 100);//+ 혹은 -로만 접근
	int cnt = 0;
	int Min = 1000001;
	for (int i = 0; i <= INF; i++)
	{
		if (check(i)) //숫자로 누를수있는지 체크
		{
			cnt = to_string(i).length(); //몇개를 숫자로 눌렀는가
			cnt += abs(i - n); //조정하기
			Min = min(cnt, Min);
		}
	}
	cout << min(Min, now);
	return 0;
}