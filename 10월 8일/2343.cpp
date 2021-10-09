#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> video;

int blueray(int mid)
{
	int sum = 0, cnt = 0;
	for (int i = 0; i < n; i++)//���ʴ�� ���ϸ鼭 � ��緹�̰� �ʿ����� ������
	{
		if (sum + video[i] > mid)//���̸� �ʰ��ϸ� ���ο� ��緹�̷� ����
		{
			cnt++;
			sum = 0;
		}
		sum += video[i];
	}
	if (sum)//���� �ʰ����ص� ������ ������ �����߰����ֱ�
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
		if (cnt > target)//���� �÷�����
			left = mid + 1;
		else if (cnt <= target)//���� �ٿ�����
		{
			right = mid - 1;
			ans = mid;
		}
		
	}
	return ans;
}

int main()//������ó�� �ݴ�� ��緹�� ���̸� ã��
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
	*///����! �̷� ������ �ϸ� �� ������ �߻��ϳ���?

	cout<<binarySearch(max, sum, m);

		return 0;
}

//reference: velog.io/@961230/%EB%B0%B1%EC%A4%80-2343%EA%B8%B0%ED%83%80-%EB%A0%88%EC%8A%A8-C