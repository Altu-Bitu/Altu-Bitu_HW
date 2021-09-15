#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

typedef pair<int, int> pp;

struct cmp {
	bool operator()(pp& a, pp& b) {
		return a.second <= b.first;
	}
};
int main()
{
	int n,s,t;
	vector<int> num;
	num.push_back(-1);
	int b = 0;
	int cnt = 0;
	//priority_queue<pp,vector<pp>,cmp> pq;
	
	cin >> n;
	vector<priority_queue<pp, vector<pp>, cmp>> pq;
	for(int i=0;i<n;i++)
	{
		cin >> s >> t;
		if(num>s)
			pq[++b].push({ s,t });
	}

	int flag = 0;
	while (!pq.empty())
	{
		for (int i = 1; i < pq.size(); i++)
		{
			int num = pq.top().second;
			pq.pop();
			if (num <= pq.top().first)
				pq.pop();
			else
				break;
		}
		cnt++;
		flag = 0;
	}
	cout << cnt;

	return 0;
}