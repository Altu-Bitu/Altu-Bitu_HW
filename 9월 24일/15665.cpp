#include <iostream>

using namespace std;

const int SIZE = 8;

int n, m, max_num;
int num[SIZE];
bool check[10001];


void backtracking(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < cnt; i++)
			cout << num[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= max_num; i++)
	{
		if (check[i])//수가 있는가?
		{
			num[cnt] = i;
			backtracking(cnt + 1);
		}
	}
}

int main()
{
	int input;
	cin >> n >> m;
	max_num = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		if (max_num < input)
			max_num = input;
		check[input] = true;
	}
	backtracking(0);
	return 0;
}