#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{
	//입출력 속도 향상
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t, n;
	long long sum; //long long형 사용하기
	vector<int> list;
	string str;
	cin >> t;
	while (t--)
	{
		cin >> n;
		list.assign(n, 0);
		sum = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> list[i];
		}
		
		sort(list.begin(), list.end(), greater<int>());

		for (int i = 0; i < n - 1; i++)//최대값부터 나열했으므로 그 다음값들에 관한 gcd만 구하면 됨
		{
			for (int j = i + 1; j < n; j++)
				sum += gcd(list[i], list[j]);
		}
		str += to_string(sum);
		str += '\n';
	}
	cout << str;
	return 0;
}