#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	int n,k;
	cin >> n;
	set<int> num;
	vector<int> a;
	vector<int> b;
	b.assign(n, 0);

	for(int i=0;i<n;i++)
	{
		cin >> k;
		num.insert(k); //중복자동제거+정렬
		b[i] = k;
	}

	for (auto iter = num.begin(); iter != num.end(); iter++)
		a.push_back(*iter);

	for (int i = 0; i < n; i++) //같은 수 찾기
	{
		int left = 0;
		int right = a.size();
		int mid;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (a[mid] > b[i])
				right = mid - 1;
			else if (a[mid] < b[i])
				left = mid + 1;
			else
				break;
		}
		cout << mid<<' ';
	}

	return 0;
}