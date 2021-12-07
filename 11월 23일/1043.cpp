#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
int truth[51];
int party[51];
vector<bool> cycle;

//Find 연산
int findParent(int node) {
	if (parent[node]<0) //음수면 루트 정점
		return node;
	return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
void unionInput(int x, int y) {
	int xp = findParent(x);
	int yp = findParent(y);

	if (xp == yp) //같은 집합에 있다면 유니온 할 수 없음
	{
		cycle[xp] = true;
		return;
	}
	if (cycle[xp] || cycle[yp]) //둘 중 하나라도 사이클이 있으면 표시
		cycle[xp] = cycle[yp] = true;
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
			unionInput(party[i], input); //트리 구성 이때 party[i][0]을 기준으로 구성한다.
		}
	}
	
	int cnt = 0;
	for (int i = 0; i < m; i++)
		if (parent[party[i]] < 0 && !cycle[i+1])
			cnt++;
	cout << cnt;
	return 0;
}
//참고https://jaehoon0124welcome.tistory.com/123