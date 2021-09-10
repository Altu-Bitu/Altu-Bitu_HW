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

	for (int i = 0; i < n; i++) //가장 작은거부터 시작
	{
		if (sum[i] == k) //같으면 증가
			cnt += 1; 
		cnt += list[sum[i]-k]; //이전에 추가해서 k가 되는게 있으면 그 개수 더하기
		list[sum[i]]++; //개수 증가시켜주기
	}

	cout << cnt;

	return 0;
}