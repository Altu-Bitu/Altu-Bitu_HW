#include <iostream>
#include <vector>
#include <string>

using namespace std;
int cnt;
int a[51][51];
int b[51][51];

void trans(int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (b[i][j] != a[i][j])
			{
				if (i + 3 > n || j + 3 > m)
					continue;

					cnt++;
					for (int k = i; k < i + 3; k++)
					{
						for (int l = j; l < j + 3; l++)
							if (a[k][l] == 1)
								a[k][l] = 0;
							else
								a[k][l] = 1;
					}

			}
		}
	}
}
int main()
{
	int n, m;
	string line;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> line;
		for (int j = 0; j < m; j++)
			a[i][j] = line[j] - '0';
	}

	cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> line;
		for (int j = 0; j < m; j++)
			b[i][j] = line[j] - '0';
	}


	trans(n, m);
	int flag = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] != b[i][j])
				flag = 0;
	if (flag)
		cout << cnt;
	else
		cout << -1;
	return 0;
}