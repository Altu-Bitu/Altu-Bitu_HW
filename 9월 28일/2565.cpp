#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct line
{
	int a, b;
};

vector<line> list;

bool cmp(const line& l1, const line& l2)
{
	return l1.a < l2.a;
}

int len(int n)
{
	vector<int> length;
	length.assign(n, 0);
	for (int i = 0; i < n; i++)
	{
		length[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (list[j].b < list[i].b)
				length[i] = max(length[i], length[j] + 1);//���� �߰��ɼ� �ִ� �������̶�� �߰��ϴ°� �̵����� �ƴ��� �Ǵ�
		}
	}
	sort(length.begin(), length.end());
	return n - length[n - 1];
}

int main()
{
	int n;
	cin >> n;
	list.assign(n, { 0,0 });
	for (int i = 0; i < n; i++)
		cin >> list[i].a >> list[i].b;
	sort(list.begin(), list.end(), cmp); //a�� ������������ ���� �׷��� b�� ���ϸ��

	

	cout << len(n); //�ִ� �迭�� ��ü���� ���� ������ ������ �ľǰ���
	return 0;
}