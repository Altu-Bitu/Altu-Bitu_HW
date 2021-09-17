#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	int n,s,t;
	pair<int, int> p[200001];
	priority_queue<int, vector<int>, greater<int> > pq;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> s >> t;
		p[i] = { s,t }; 
	}

	sort(p, p+n); //우선 시작하는 순서로 먼저 정렬

	pq.push(p[0].second); //끝나는 시간 넣어두기

	for (int i = 1; i < n; i++)
	{
		if (p[i].first>= pq.top()) //가장 빨리 끝나는 것보다 현재 새로 추가되는 수업이늦게 시작하면
		{
			pq.pop(); //연달아 수업할것이니 그 수업종료 시간을 갱신한다.
			pq.push(p[i].second);
		}
		else
			pq.push(p[i].second); //아니면 새로운 강의실이 필요하므로 갱신없이 그냥 추가
	}

	cout << pq.size();
	return 0;
}