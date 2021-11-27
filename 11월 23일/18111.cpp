#include <iostream>
#include <vector>

using namespace std;

int MAX = 214748391;
int min_num = MAX;
int height;

void find(int n,int m, int b,int k, vector<vector<int>>& ground)
{
	int remove = 0;
	int fill = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int h = ground[i][j];
			if (k < h)//기준보다 크면
				remove += (h - k);
			else if (k > h) //기준보다 작으면
				fill += (k - h);
		}
	}

	if (remove + b - fill >= 0)
	{
		int time = remove * 2 + fill;
		if (min_num > time)
		{
			min_num = time;
			height = k;
		}
	}
}
int main()
{
	int n, m, b;
	cin >> n >> m >> b;
	vector<vector<int>> ground(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> ground[i][j];
		}
	}
	
	for (int k = 0; k < 257; k++)
	{
		find(n, m,b, k, ground);
	}
	cout << min_num <<' '<< height;
	return 0;
}
//참고https://codecollector.tistory.com/678