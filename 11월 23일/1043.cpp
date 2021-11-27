#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
int truth[51];
int party[51][51];

//Find ����
int findParent(int node) {
	if (parent[node]<0) //������ ��Ʈ ����
		return node;
	return parent[node] = findParent(parent[node]); //�׷��� �����ϸ� ��Ʈ ���� ã��
}

//Union ����
void unionInput(int x, int y) {
	int xp = findParent(x);
	int yp = findParent(y);

	if (xp == yp) //���� ���տ� �ִٸ� ���Ͽ� �� �� ����
		return;
	else //���ο� ��Ʈ xp->party[i][0]�� ��Ʈ�� ��������ϱ⶧��
		parent[yp] = xp;
}

int main()
{
	int n,m,t;
	cin >> n >> m>>t;
	parent.assign(51, -1);

	for (int i = 0; i < t; i++)
	{
		cin >> truth[i];
	}

	int num;
	for (int i = 0; i < m; i++)
	{
		cin >> num;
		cin >> party[i][0];
		for (int j = 1; j < num; j++)
		{
			cin >> party[i][j];
			unionInput(party[i][0], party[i][j]); //Ʈ�� ���� �̶� party[i][0]�� �������� �����Ѵ�.
		}
	}
	
	int cnt = 0;
	for (int i = 0; i < m; i++)
	{ 
		int flag = 1;
		for (int j = 0; j < t; j++)
		{
			if (findParent(party[i][0]) == findParent(truth[j])) //�θ� ������ ���� ��Ƽ�� �ִٴ� ��
			{//����:�� findParent(party[i][j])==findParent(truth[j])�� �ϸ� ���� �����������? ���� �θ� ���� �ʳ���?
				flag = 0;
				break;
			}
		}
		if (flag) //���Ǿƴ� ����� �� ��Ƽ�� ����
			cnt++;
	}
	cout << cnt;
	return 0;
}
//����https://jaehoon0124welcome.tistory.com/123