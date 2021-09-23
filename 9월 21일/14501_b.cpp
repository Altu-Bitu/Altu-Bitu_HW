#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int result = 0;
vector<pair<int, int>> a;

void check(int day, int m)
{
	if (day == n) //마지막날가지 딱 맞춰서 일하기
		result = max(result, m); //가능한 day라면 result 갱신
	if (day >= n)
		return;
	check(day + a[day].first, m + a[day].second); //day에 일을 하는 경우
	check(day + 1, m); //day에 일을 안하고 넘어가는 경우
}

int main()//**
{
	//입출력 속도 향상
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