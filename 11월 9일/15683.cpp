#include <iostream>
#include <vector>
using namespace std;

void change(vector<vector<int>>& matrix,int n,int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (matrix[i][j] == 0)
				continue;
			if (matrix[i][j] == 1)
			{

			}

			if (matrix[i][j] == 2)
			{

			}

			if (matrix[i][j] == 3)
			{

			}

			if (matrix[i][j] == 4)
			{

			}
		}
	}
}
int main()
{
	int n, m;
	cin >> n >> m; //За·Д
	vector<vector<int>> matrix(n, vector<int>(m,0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> matrix[i][j];
	}
	change(matrix,n,m);

	return 0;
}