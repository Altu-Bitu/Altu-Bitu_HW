#include <iostream>
#include <vector>

using namespace std;

bool lattice[101][101] = { false };
const int MAX = 100;

void solution(int y, int x, int d, int g)
{
	int dr[4] = { 0,-1,0,1 }; //�������
	int dc[4] = { 1,0,-1,0 };
	
	//�ʱ⼳��
	lattice[y][x] = true; //������ǥ��
	vector<int> original;
	original.push_back(d);

	while (g--)
	{
		int len = original.size() - 1;
		for (int i = len; i >= 0; i--) //k����� k-1���븸ŭ �� �̵��ϹǷ� ������ �ִ� ������ŭ ���ο� ȸ�������� �߰�������Ѵ�.
		{
			original.push_back((original[i] + 1) % 4); //k-1������ ȸ�� ������ k���뿡�� �ε����� ������ ȸ������ ���·� ��Ÿ����.�� k-1���뿡 d�� 0�̸� k���뿡 d�� 1�̵ȴ�.
		}
	}
	for(int i=0;i<original.size();i++)
	{
		y += dr[original[i]];
		x += dc[original[i]]; //���ϴ� �������� ������ ���θ���
		if(y>=0&&y<=MAX&&x>=0&&x<=MAX)
			lattice[y][x] = true;
		
	}


	
} //�̺κи� ����https://jaimemin.tistory.com/1163

int count()
{
	int cnt = 0;
	for (int i = 0; i < MAX; i++) 
	{
		for (int j = 0; j < MAX; j++)
		{
			if (lattice[i][j] && lattice[i + 1][j + 1] && lattice[i][j + 1] && lattice[i + 1][j]) //�� ���� �������� ������ �������� ���簢���� �����ϸ� �ߺ����� ���簡��
				cnt++;
		}
	}
	return cnt;
}

int main()
{
	//����� �ӵ� ����
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