#include <iostream>
#include <vector>

using namespace std;

bool lattice[101][101] = { false };
const int MAX = 100;

void solution(int y, int x, int d, int g)
{
	int dr[4] = { 0,-1,0,1 }; //우상좌하
	int dc[4] = { 1,0,-1,0 };
	
	//초기설정
	lattice[y][x] = true; //시작점표기
	vector<int> original;
	original.push_back(d);

	while (g--)
	{
		int len = original.size() - 1;
		for (int i = len; i >= 0; i--) //k세대는 k-1세대만큼 더 이동하므로 기존에 있던 개수만큼 새로운 회전방향을 추가해줘야한다.
		{
			original.push_back((original[i] + 1) % 4); //k-1세대의 회전 방향은 k세대에서 인덱스가 증가한 회전방향 형태로 나타난다.즉 k-1세대에 d가 0이면 k세대에 d가 1이된다.
		}
	}
	for(int i=0;i<original.size();i++)
	{
		y += dr[original[i]];
		x += dc[original[i]]; //원하는 방향으로 시작점 새로만듬
		if(y>=0&&y<=MAX&&x>=0&&x<=MAX)
			lattice[y][x] = true;
		
	}


	
} //이부분만 참고https://jaimemin.tistory.com/1163

int count()
{
	int cnt = 0;
	for (int i = 0; i < MAX; i++) 
	{
		for (int j = 0; j < MAX; j++)
		{
			if (lattice[i][j] && lattice[i + 1][j + 1] && lattice[i][j + 1] && lattice[i + 1][j]) //한 점을 기준으로 옆위로 증가시켜 정사각형을 조사하면 중복없이 조사가능
				cnt++;
		}
	}
	return cnt;
}

int main()
{
	//입출력 속도 감소
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, x, y, d, g;
	cin >> n;
	while (n--)
	{
		cin >> x >> y >> d >> g;
		solution(y, x, d, g);
	}
	cout << count();
	return 0;
}