#include <iostream>
#include <vector>
#include <deque>

using namespace std;


bool body[101][101];
int x[4] = { 0,1,0,-1 }; //ȸ���ҽ� ���� ��õ��
int y[4] = { 1,0,-1,0 }; //ȸ���ҽ� ���� ��õ�� D�� �������� 4��(�ݴ�ΰ��� L����)
deque<pair<int, int>> s;
bool apple[101][101] = { false };
char time[10001];

int snakeGame(int n)
{

	s.push_back({ 1,1 });//ó�� start��ġ
	body[1][1] = true; //���� �����ؿ�
	int times = 0;
	int now = 0;
	while (1)
	{
		times++;

		int next_r = s.back().first + x[now]; //��ĭ ����
		int next_c = s.back().second + y[now];

		if (next_r<1 || next_r>n || next_c<1 || next_c>n)
			break;

		s.push_back({ next_r,next_c }); //�Ӹ�����
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
			apple[next_r][next_c] = false; //��� �ȳ�
		else
		{

			body[s.front().first][s.front().second] = false;
			s.pop_front(); //���� �����
		}

		if (!body[next_r][next_c])
			body[next_r][next_c] = true; //�߰�

	}
	return times;
}

int main()
{
	//����� 
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
	 //�Է� ��

	

	cout << snakeGame(n);

	return 0;
}