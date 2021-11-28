#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

//Find 연산
int findParent(int node) {
	if (parent[node] < 0) //값이 음수면 루트 정점
		return node;
	return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
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
		int root = findParent(gi);//gi의 부모를 찾는다.
		if (root != 0) //root가 0이라는 것은 더이상 -1위치에 자리가 없다는 뜻
		{
			cnt++;//도킹함
			unionInput(root - 1, root);
		}
		else 
		  break;
	}
	cout << cnt;
	return 0;
}//참고https://mygumi.tistory.com/245