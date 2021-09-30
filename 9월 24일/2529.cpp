#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//���̵��: �������ϰ� ���� ������ ������ �´��� Ȯ���ؼ� �迭�� �־����
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
		if (!check_val(i, op[i]))//�ѹ��̶� �ȸ����� false
			return false;
	}
	return true;
}

void dfs() //���� ���ϴ� ���
{
	if (list.size() == k+1)//���� nPr���� r���� ���� ��������
	{
		if (cal())//�ε�ȣ�� ������ �´��� üũ
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