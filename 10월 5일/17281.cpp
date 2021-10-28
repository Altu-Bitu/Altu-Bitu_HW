#include <iostream>
#include <vector>
using namespace std;
bool ground[4] = { 0, }; //사람이 몇루에있는지 표현

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> p(n, vector<int>(9,0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 9; j++)
			cin >> p[i][j];
	}
	
	
	int point = 0;
	int player = 0;
	for (int i = 0; i < n; i++)
	{
		int out = 0;
		while (out<3)
		{
			if (p[i][player] == 0) //아웃치면
				out++;
			
			else if (p[i][player] == 1)
			{
				for (int k = 3; k > 0; k--)
				{
					if (ground[k])//선수가 있다면
					{
						if (k == 3)//3루?
						{
							point++;
							ground[k] = 0;
						}
						else
						{
							ground[k + 1] = 1;
							ground[k] = 0; //한루 전진
						}
					}
				}
				//한칸씩 전진
				ground[1] = 1;//타자 1루 들어감
			}
			else if (p[i][player] == 2)
			{
				for (int k = 3; k > 0; k--)
				{
					if (ground[k]) //선수 있다면
					{
						if (k == 3 || k == 2)
						{
							point++;
							ground[k] = 0;
						}
						else
						{
							ground[k + 2] = 1;//2루전진
							ground[k] = 0;
						}
					}
				}
				ground[2] = 1;
			}

			else if (p[i][player] == 3)
			{
				for (int k = 1; k <4; k++)
				{
					if (ground[k])
					{
						ground[k] = 0;
						point++;
					}
				}
				ground[3] = 1;
			}

			else
			{
				for (int k = 1; k < 4; k++)
				{
					if (ground[k])
					{
						point++;
						ground[k] = 0;
					}
				}
				point++; //타수도 들어옴
			}
			player++;
			player = player % 9;//9까지 돌면 회전하므로
			cout << player << ' ' << point << '\n';
		}
	}

	cout << point;
	return 0;
}