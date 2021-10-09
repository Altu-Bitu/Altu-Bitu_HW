#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> video;

int blueray(int mid)
{
	int sum = 0, cnt = 0;
	for (int i = 0; i < n; i++)//차례대로 더하면서 몇개 블루레이가 필요한지 세보기
	{
		if (sum + video[i] > mid)//길이를 초과하면 새로운 블루레이로 갈기
		{
			cnt++;
			sum = 0;
		}
		sum += video[i];
	}
	if (sum)//길이 초과안해도 남은거 있으면 개수추가해주기
		cnt++;
	return cnt;
}

int binarySearch(int left, int right, int target)
{
	int ans = 0;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		int cnt = blueray(mid);
		if (cnt > target)//길이 늘려야함
			left = mid + 1;
		else if (cnt <= target)//길이 줄여야함
		{
			right = mid - 1;
			ans = mid;
		}
		
	}
	return ans;
}

int main()//공유기처럼 반대로 블루레이 길이를 찾기
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	
	cin >> n >> m;
	video.assign(n, 0);

	int sum = 0;
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> video[i];
		if (max < video[i])
			max = video[i];
		sum += video[i];
	}
	/*
	int cnt = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (cnt * m >= sum)
		{
			cout << cnt;
			return 0;
		}
		cnt += video[i];
	}
	*///질문! 이런 식으로 하면 왜 오류가 발생하나요?

	cout<<binarySearch(max, sum, m);

		return 0;
}

//reference: velog.io/@961230/%EB%B0%B1%EC%A4%80-2343%EA%B8%B0%ED%83%80-%EB%A0%88%EC%8A%A8-C