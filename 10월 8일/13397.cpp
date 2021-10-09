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
	for (int i = n-1; i >=0; i--)//���ʴ�� ���ϸ鼭 ������� �ټ��ִ��� ������
	{
		len = snack[i];
		while(len>= mid)//���̸� �ʰ��ϸ� �ټ��ִ�
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
		if (cnt >= target)//���� �÷�����
		{
			left = mid + 1;
			ans = mid;
		}
		else if (cnt <target)//���� �ٿ�����
			right = mid - 1;
		
	}
	return ans;
}

int main()//�ݴ�� ���� ���̿��� �ټ��ִ� ���� ������ *��緹��ó�� Ǯ��
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