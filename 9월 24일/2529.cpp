#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//아이디어: 순열구하고 구한 순열에 순서에 맞는지 확인해서 배열에 넣어서관리
int k;
bool check[10];
char op[10];
vector<char> list;
vector<string> result;

bool check_val(int i, char c)
{
	if (c == '<')
	{
		if (list[i] - '0' < list[i + 1] - '0')
			return true;
		else
			return false;
	}
	else
		if (list[i] - '0' > list[i + 1] - '0')
			return true;
		else
			return false;
}

bool cal()
{
	for (int i = 0; i < k; i++)
	{
		if (!check_val(i, op[i]))//한번이라도 안맞으면 false
			return false;
	}
	return true;
}

void dfs() //순열 구하는 방법
{
	if (list.size() == k+1)//만약 nPr에서 r개의 순열 구했으면
	{
		if (cal())//부등호랑 순서가 맞는지 체크
		{
			string s;
			for (int i = 0; i < k+1; i++)
			{
				s += list[i];
			}
			result.push_back(s);
		}
		return;
	}

	for (int i = 0; i <= 9; i++)
	{
		if (!check[i])
		{
			check[i] = true;
			list.push_back(i+'0');
			dfs();
			list.pop_back();
			check[i] = false;
		}
	}
}


int main()
{
	cin >> k;
	for (int i = 0; i < k; i++)
		cin >> op[i];
	dfs();
	sort(result.begin(), result.end());
	cout << result.at(result.size() - 1) << endl;
	cout << result.at(0) << endl;
	return 0;
}