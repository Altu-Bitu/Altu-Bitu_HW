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
	
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				if (checkTriangle(tri[i], tri[j], tri[k]))
				{
					max_num = max(max_num, tri[i] + tri[j] + tri[k]);
					cout << max_num;
					return 0;
				}
			}
		}
	}
	cout << max_num;
	return 0;
}