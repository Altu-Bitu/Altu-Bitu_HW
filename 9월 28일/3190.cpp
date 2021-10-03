#include <iostream>
#include <vector>
#include <deque>

using namespace std;


bool body[101][101];
int x[4] = { 0,1,0,-1 }; //회전할시 행의 변천사
int y[4] = { 1,0,-1,0 }; //회전할시 열의 변천사 D를 기준으로 4개(반대로가면 L기준)
deque<pair<int, int>> s;
bool apple[101][101] = { false };
char time[10001];

int snakeGame(int n)
{

	s.push_back({ 1,1 });//처음 start위치
	body[1][1] = true; //뱀이 존재해요
	int times = 0;
	int now = 0;
	while (1)
	{
		times++;

		int next_r = s.back().first + x[now]; //한칸 전진
		int next_c = s.back().second + y[now];

		if (next_r<1 || next_r>n || next_c<1 || next_c>n)
			break;

		s.push_back({ next_r,next_c }); //머리갱신
		if (body[next_r][next_c])
			break;
		if (time[times] == 'D')
		{
			now += 1;
			if (now == 4)
				now = 0;
		}

		else if (time[times] == 'L')
		{
			now--;
			if (now == -1)
				now = 3;
		}

		if (apple[next_r][next_c])
			apple[next_r][next_c] = false; //사과 냠냠
		else
		{

			body[s.front().first][s.front().second] = false;
			s.pop_front(); //꼬리 지우기
		}

		if (!body[next_r][next_c])
			body[next_r][next_c] = true; //추가

	}
	return times;
}

int main()
{
	//입출력 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, r, c,t;
	char d;
	cin >> n >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> r >> c;
		apple[r][c] = true;
	}

	int l;
	cin >> l;
	
	for (int i = 0; i < l; i++)
	{ 
		cin >> t >> d;
		time[t] = d;
	}
	 //입력 끝

	

	cout << snakeGame(n);

	return 0;
}