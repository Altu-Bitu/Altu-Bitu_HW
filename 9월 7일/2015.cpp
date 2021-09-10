#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	int n, k;
	long long cnt = 0;
	cin >> n >> k;
	vector<int> a;
	vector<int> sum;
	map<int, long long> list;
	a.assign(n, 0);
	sum.assign(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sum[0] = a[0];
	for (int i = 1; i < n; i++)
	{
		sum[i] += sum[i - 1] + a[i];
	}

	for (int i = 0; i < n; i++) //���� �����ź��� ����
	{
		if (sum[i] == k) //������ ����
			cnt += 1; 
		cnt += list[sum[i]-k]; //������ �߰��ؼ� k�� �Ǵ°� ������ �� ���� ���ϱ�
		list[sum[i]]++; //���� ���������ֱ�
	}

	cout << cnt;

	return 0;
}