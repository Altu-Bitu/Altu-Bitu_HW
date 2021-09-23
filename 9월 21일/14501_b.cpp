#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int result = 0;
vector<pair<int, int>> a;

void check(int day, int m)
{
	if (day == n) //������������ �� ���缭 ���ϱ�
		result = max(result, m); //������ day��� result ����
	if (day >= n)
		return;
	check(day + a[day].first, m + a[day].second); //day�� ���� �ϴ� ���
	check(day + 1, m); //day�� ���� ���ϰ� �Ѿ�� ���
}

int main()//**
{
	//����� �ӵ� ���
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	a.assign(n + 1, { 0,0 });
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}

	check(0, 0);
	cout << result;
	return 0;
}