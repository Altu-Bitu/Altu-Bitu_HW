#include <iostream>
#include <vector>

using namespace std;

vector<bool> cycle;
vector<int> parent;


int flag = 0;
int n, m;
//Find 연산
int findParent(int node) {
    if (parent[node] < 0) //값이 음수면 루트 정점
        return node;
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
void unionInput(int x, int y,int cnt) {
    int xp = findParent(x);
    int yp = findParent(y);

    if (xp == yp) { //같은 집합에 있다면 유니온 할 수 없음
        flag = 1;
        cout << cnt;
        return;
    }
 
    if (parent[xp] < parent[yp]) { //새로운 루트 xp
        parent[xp] += parent[yp];
        parent[yp] = xp;
    }
    else { //새로운 루트 yp
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