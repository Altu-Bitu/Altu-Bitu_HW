#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
int truth[51];
int party[51];

//Find 연산
int findParent(int node) {
	if (parent[node] < 0) //음수면 루트 정점
		return node;
	return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
void unionInput(int x, int y) {
	int xp = findParent(x);
	int yp = findParent(y);

	if (xp == yp) //같은 집합에 있다면 유니온 할 수 없음
		return;
	else //새로운 루트 xp->party[i][0]만 루트로 세우려고하기때문
		parent[yp] = xp;
}

int main()
{
	int n, m, t;
	cin >> n >> m >> t;
	parent.assign(51, -1);

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
	{
		int flag = 1;
		for (int j = 0; j < t; j++)
		{
			if (findParent(party[i]) == findParent(truth[j])) //부모가 같으면 같은 파티에 있다는 뜻
			{
				flag = 0;
				break;
			}
		}
		if (flag) //진실아는 사람이 그 파티에 없음
			cnt++;
	}
	cout << cnt;
	return 0;
}
//참고https://jaehoon0124welcome.tistory.com/123