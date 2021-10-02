#include <iostream>
#include <vector>

using namespace std;
vector<pair<int, int>> a;
int sums(int n)
{
	vector<int> sum;
	sum.assign(n + 2, 0);
	for (int i = n; i >= 1; i--)
	{
		if (a[i].first > n - i + 1)//������ ���� ���� �ƴ϶��
			sum[i] = sum[i + 1];
		else
			sum[i] = max(sum[i + 1], a[i].second + sum[i + a[i].first]); //�׳��� ���Ծ��ϱ�vs�����ϱ�(i�� �����̶� i���� �ϴµ� �ɸ��� �ð����� sum�� ���Ѱ�
	}
	return sum[1];
}

int main()
{
	int n;
	cin >> n;
	a.assign(n+1, { 0,0 });
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}

	cout << sums(n);
	return 0;
}