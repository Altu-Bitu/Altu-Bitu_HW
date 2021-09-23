#include <iostream>
#include <vector>

using namespace std;
vector<pair<int, int>> a;
vector<pair<int, int>> b;
int cnt = 0;
int n;

void stepOne()
{
	pair<int, int> temp = a[2 * n];
	for (int i = 2 * n; i >= 1; i--)
		a[i] = a[i - 1];
	a[1] = temp;
	//�̷��� �����ν� ��ĭ ȸ���ߴ�.
	if (a[n].second)
		a[n].second = 0;//�������� �κ������� �κ� ����

}

void stepTwo()
{
	for (int i = n - 1; i >= 1; i--)
	{
		if (a[i].second)//�κ����ִٸ�
		{
			if (!a[i + 1].second && a[i + 1].first >= 1) //��ĭ�� �κ����� ������ 1�̻��϶� �ű��
			{
				a[i + 1].second = 1;
				a[i + 1].first--; //������ ����
				a[i].second = 0; //�κ� �̵������� �����

				if (a[i + 1].first == 0)
					cnt++;
			}
		}
	}
	if (a[n].second == 1)//�� ������ �κ� ���������� ������
		a[n].second = 0;
}

void stepThree()
{
	if (a[1].first >= 1 && !a[1].second)
	{
		a[1].first--;
		a[1].second = 1;
		if (a[1].first == 0)
			cnt++;
	}
}



int main()
{
	//����� �ӵ� ���
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int k, input;
	cin >> n >> k;
	a.assign(201, { 0,0 });
	b.assign(201, { 0,0 });

	for (int i = 1; i <= 2 * n; i++)
	{
		cin >> input;
		a[i].first = input;

	}
	int t = 0;
	
	while (1)
	{
		stepOne();
		stepTwo();
		stepThree();

		t++;
		if (cnt >= k)
		{
			cout << t;
			return 0;
		}

	}

	return 0;
}