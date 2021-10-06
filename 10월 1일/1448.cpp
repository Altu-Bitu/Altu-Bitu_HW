#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool checkTriangle(int a, int b, int c)
{
	return(a < b + c && b < a + c && c < a + b);
}

int main()
{
	int n;
	cin >> n;
	vector<int> tri(n, 0);
	for (int i = 0; i < n; i++)
		cin >> tri[i];
	sort(tri.begin(), tri.end(), greater<>());
	int max_num = -1;
	for (int i = 0; i <= n-3; i++) //어차피 그 앞에 맨 처음 세수만 해주면됨
	{
		if (checkTriangle(tri[i], tri[i + 1], tri[i + 2]))
		{
			max_num = tri[i] + tri[i + 1] + tri[i + 2];
			break;
		}
	}
	cout << max_num;
	return 0;
}