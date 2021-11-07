#include <iostream>
#include <vector>
#include <string>

using namespace std;

int kingr, kingc, stoner, stonec;


void change(int r, int c,int rs,int cs, int i)
{
	int dr[8] = { 0,0,-1,1,1,1,-1,-1 };
	int dc[8] = { 1,-1,0,0,1,-1,1,-1 };

	int nr = r + dr[i];
	int nc = c + dc[i];
	if (nr >= 0 && nr < 8 && nc >= 0 && nc < 8)
	{
		if (nr == stoner && nc == stonec)//stoneÀÌ¶û °ãÄ¡¸é
		{
			int nrs = rs + dr[i];
			int ncs = cs + dc[i];
			if (nrs >= 0 && nrs < 8 && ncs >= 0 && ncs < 8)
			{
				stoner = rs + dr[i];
				stonec = cs + dc[i];
				kingr = nr;
				kingc = nc;
			}
		}
		else
		{
			kingr = nr;
			kingc = nc;
		}
	}
	return;
}

void solution(string move,int r,int c,int rs,int rc)
{
	string direction[8] = { "R", "L", "B","T","RT","LT","RB","LB" };
	for (int i = 0; i < 8; i++)
	{
		if (move == direction[i])
		{
			change(r, c, rs, rc, i);
			return;
		}
	}
}

int main()
{
	string king, stone;
	int n;
	cin >> king >> stone >> n;
	kingr = king[1]-'1';
	kingc = king[0] - 'A';
	stoner = stone[1] - '1';
	stonec = stone[0] - 'A';

	for (int i = 0; i < n; i++)
	{
		string move;
		cin >> move;
		solution( move,kingr,kingc,stoner,stonec);
	}

	char k= kingc + 'A';
	char s = stonec + 'A';
	cout <<k << kingr+1<<'\n';
	cout << s<< stoner+1;
	return 0;
}