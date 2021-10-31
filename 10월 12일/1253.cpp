#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int value,int i, vector<int>& a, int left, int right)
{
	while (left < right)
	{
		int sum = a[left] + a[right];
		if (sum == value)
		{
			if (left != i && right != i)//다른 수여야한다.
			{
				return 1;
			}
			else if (left == i)
				left++;
			else if (right == i)
				right--;
		}
		else if (sum < value)
			left++;
		else
			right--;
	}
	return 0;
}

int main()
{
	int n;
	int cnt = 0;
	cin >> n;
	vector<int> a(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++)
	{
		cnt+=solution(a[i], i, a, 0, n - 1);
	}
	cout << cnt;
	return 0;
}