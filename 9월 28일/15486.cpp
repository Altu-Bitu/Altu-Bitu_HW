#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	vector<pair<int, int>> a;
	cin >> n;
	a.assign(n+1, { 0,0 });
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}

	vector<int> sum;
	sum.assign(n+2, 0);
	for (int i = n; i >= 1; i--)
	{
		if (a[i].first > n - i + 1)//������ ���� ���� �ƴ϶��
			sum[i] = sum[i + 1];
		else
			sum[i] = max(sum[i + 1], a[i].second + sum[i + a[i].first]); //�׳��� ���Ծ��ϱ�vs�����ϱ�(i�� �����̶� i���� �ϴµ� �ɸ��� �ð����� sum�� ���Ѱ�
	}

	cout << sum[1];
	return 0;
}