#include <iostream>
#include <vector>

using namespace std;

vector<bool> visited;
vector<vector<int>> graph;

string check(int t, int k)
{
	if (t == 1)//단절점인지
	{
		//graph[k]가 다른거랑 연결되어 있는게 두개이상이면 제거시 무조건 단절됨
		if (graph[k].size() >= 2)
			return "yes";
		else
			return "no";
	}

	else//단절선인지
	{
		//트리에서는 간선 제거하면 무조건 단절됨->선 하나로만 연결되어있음
		return "yes";
	}
}

int main()
{
	int n,a,b,q,t,k;
	cin >> n;
	graph.assign(n + 1, vector<int>(0));
	for (int i = 1; i < n; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	string output;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> t >> k;
		output += check(t, k);
		output += '\n';
	}

	cout << output;
	return 0;
}