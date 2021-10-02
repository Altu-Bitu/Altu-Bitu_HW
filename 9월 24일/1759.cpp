#include <iostream>
#include <algorithm>

using namespace std;

bool isvowel[26];
char code[15];
char list[16]; //선택된 암호 넣는 배열
int l, c;

void backtracking(int pos,int start,int cnt_j,int cnt)
{
	if (pos == l) //암호개수일때
	{
		if (cnt_j >= 2 && cnt >= 1)//조건에 맞다면
		{
			for (int i = 0; i < l; i++)
				cout << list[i];
			cout << '\n';
			return;
		}
	}

	for (int i = start; i < c; i++)
	{
		char a = code[i];
		list[pos] = a;
		if (isvowel[i])//모음이면
		{
			backtracking(pos + 1, i + 1, cnt_j, cnt + 1);
		}
		else//자음이면
			backtracking(pos + 1, i + 1, cnt_j+1, cnt);

	}
}

int main()
{
	cin >> l >> c;

	for (int i = 0; i < c; i++)
	{
		cin >> code[i];
	}

	sort(code, code+c); //사전식 정렬
	for (int i = 0; i < c; i++)
	{
		if (code[i] == 'a' || code[i] == 'e' || code[i] == 'i' || code[i] == 'o' || code[i] == 'u')
			isvowel[i] = true;
	}
	
	backtracking(0, 0, 0, 0);
	return 0;
}