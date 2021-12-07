#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
int truth[51];
int party[51];
vector<bool> cycle;

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
	{
		cycle[xp] = true;
		return;
	}
	if (cycle[xp] || cycle[yp]) //�� �� �ϳ��� ����Ŭ�� ������ ǥ��
		cycle[xp] = cycle[yp] = true;
	if (parent[xp] < parent[yp]) { //���ο� ��Ʈ xp
		parent[xp] += parent[yp];
		parent[yp] = xp;
	}
	else { //���ο� ��Ʈ yp
		parent[yp] += parent[xp];
		parent[xp] = yp;
	}
}

int main()
{
	int n,m,t;
	cin >> n >> m>>t;
	parent.assign(51, -1);
	cycle.assign(51, false);
	for (int i = 0; i < t; i++)
	{
		cin >> truth[i];
	}

	int num;
	int input;
	for (int i = 0; i < m; i++)
	{
		cin >> num;
		cin >> party[i];
		for (int j = 1; j < num; j++)
		{
			cin >> input;
			unionInput(party[i], input); //Ʈ�� ���� �̶� party[i][0]�� �������� �����Ѵ�.
		}
	}
	
	int cnt = 0;
	for (int i = 0; i < m; i++)
		if (parent[party[i]] < 0 && !cycle[i+1])
			cnt++;
	cout << cnt;
	return 0;
}
//����https://jaehoon0124welcome.tistory.com/123