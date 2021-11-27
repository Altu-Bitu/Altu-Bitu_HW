#include <iostream>
#include <vector>

using namespace std;

vector<bool> cycle;
vector<int> parent;


int flag = 0;
int n, m;
//Find ����
int findParent(int node) {
    if (parent[node] < 0) //���� ������ ��Ʈ ����
        return node;
    return parent[node] = findParent(parent[node]); //�׷��� �����ϸ� ��Ʈ ���� ã��
}

//Union ����
void unionInput(int x, int y,int cnt) {
    int xp = findParent(x);
    int yp = findParent(y);

    if (xp == yp) { //���� ���տ� �ִٸ� ���Ͽ� �� �� ����
        flag = 1;
        cout << cnt;
        return;
    }
 
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
	cin >> n >> m;
	parent.assign(n, -1);
	cycle.assign(n, false);

	int x, y;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		unionInput(x, y,i+1);
        if (flag)
            return 0;
	}
    cout << 0;

	return 0;
}