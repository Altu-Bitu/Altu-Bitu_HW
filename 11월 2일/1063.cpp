#include <iostream>
#include <vector>
#include <string>

using namespace std;

int kingr, kingc, stoner, stonec;

void change(vector<vector<bool>>& board, int r, int c, int i)
{
	int dr[8] = { 0,0,-1,1,1,1,-1,-1 };
	int dc[8] = { 1,-1,0,0,1,-1,1,-1 };

	int nr = r + dr[i];
	int nc = c + dc[i];
	if (nr >= 0 && nr < 8 && nc >= 0 && nc < 8)
	{
		board[r][c] = false;
		if (board[nr][nc] == 1) //stone이 존재하므로
		{
			if (nr + dr[i] >= 0 && nr + dr[i] < 8 && nc + dc[i] >= 0 && nc + dc[i] < 8)
			{
				board[nr + dr[i]][nc + dc[i]] = true;
				board[nr][nc] = true;
				stoner = nr + dr[i];
				stonec = nc + dc[i];
				kingr = nr;
				kingc = nc;
			}
		}
		else
		{
			board[nr][nc] = true;
			kingr = nr;
			kingc = nc;
		}
	}
	return;
}
void solution(vector<vector<bool>> &board, string move,int r,int c)
{

	
	if (move == "R")
		change(board, r, c, 0);
	else if (move == "L")
		change(board, r, c, 1);
	else if (move == "B")
		change(board, r, c, 2);
	else if (move == "T")
		change(board, r, c, 3);
	else if (move == "RT")
		change(board, r, c, 4);
	else if (move == "LT")
		change(board, r, c, 5);
	else if (move == "RB")
		change(board, r, c, 6);
	else if (move == "LB")
		change(board, r, c, 7);
}

int main()
{
	vector<vector<bool>> board(8, vector<bool>(8, false));
	string king, stone;
	int n;
	cin >> king >> stone >> n;
	kingr = king[1]-'1';
	kingc = king[0] - 'A';
	stoner = stone[1] - '1';
	stonec = stone[0] - 'A';
	
	board[kingr][kingc] = true;
	board[stoner][stonec] = true;

	for (int i = 0; i < n; i++)
	{
		string move;
		cin >> move;
		solution(board, move,kingr,kingc);
	}
	char k= kingc + 'A';
	char s = stonec + 'A';
	cout <<k << kingr+1<<'\n';
	cout << s<< stoner+1;
	return 0;
}