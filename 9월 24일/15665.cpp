#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 8;

int n, m, max_num;
int num[SIZE];
vector<int> inputs;
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
	for (int i = 0; i < inputs.size(); i++)
	{
		num[cnt] = inputs[i];
		backtracking(cnt + 1);
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
		if (check[input])
			continue;
		inputs.push_back(input);
		check[input] = true;
	}
	sort(inputs.begin(), inputs.end());
	backtracking(0);
	return 0;
}