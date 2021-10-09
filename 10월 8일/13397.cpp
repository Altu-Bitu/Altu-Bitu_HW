#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
vector<int> snack;

int snacks(int mid)
{
	int cnt = 0;
	int len = 0;
	for (int i = n-1; i >=0; i--)//차례대로 더하면서 몇명한테 줄수있는지 세보기
	{
		len = snack[i];
		while(len>= mid)//길이를 초과하면 줄수있다
		{
			cnt++;
			len -= mid;
		}
	}

	return cnt;
}

int binarySearch(int left, int right, int target)
{
	int ans = 0;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		int cnt = snacks(mid);
		if (cnt >= target)//길이 늘려야함
		{
			left = mid + 1;
			ans = mid;
		}
		else if (cnt <target)//길이 줄여야함
			right = mid - 1;
		
	}
	return ans;
}

int main()//반대로 과자 길이에서 줄수있는 개수 세보기 *블루레이처럼 풀기
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m >> n;
	snack.assign(n, 0);
	for (int i = 0; i < n; i++)
		cin >> snack[i];
	sort(snack.begin(), snack.end());
	cout<<binarySearch(1, snack[n-1], m);
	return 0;
}