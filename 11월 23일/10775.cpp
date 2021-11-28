#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

//Find ����
int findParent(int node) {
	if (parent[node] < 0) //���� ������ ��Ʈ ����
		return node;
	return parent[node] = findParent(parent[node]); //�׷��� �����ϸ� ��Ʈ ���� ã��
}

//Union ����
void unionInput(int x, int y) {
	int xp = findParent(x);
	int yp = findParent(y);
	parent[yp] = xp;
}

int main()
{
	int g,p,gi;
	cin >> g>>p;
	parent.assign(g + 1, -1);

	int cnt = 0;
	for (int i = 0; i < p; i++)
	{
		cin >> gi;
		int root = findParent(gi);//gi�� �θ� ã�´�.
		if (root != 0) //root�� 0�̶�� ���� ���̻� -1��ġ�� �ڸ��� ���ٴ� ��
		{
			cnt++;//��ŷ��
			unionInput(root - 1, root);
		}
		else 
		  break;
	}
	cout << cnt;
	return 0;
}//����https://mygumi.tistory.com/245