#include <iostream>
#include <vector>
#include <string>

using namespace std;
//4093�̶� �ٸ���->�ùٸ� Ʈ���� ���� visited�� cycleȮ�����ʿ����

vector<vector<int>>graph;
vector<int> dp;

int dfs(int node,int parent)
{
	int cnt = 0;
	for (int i = 0; i < graph[node].size(); i++) {
		if (graph[node][i] != parent) //�θ� ������ �ƴ϶��
			cnt+=dfs(graph[node][i], node); //�����������ϱ�
	}
	dp[node] = cnt + 1;
	return dp[node];
}

int main()
{
	int n, r, q,u,v;
	cin >> n >> r >> q;

	graph.assign(n + 1, vector<int>(0));
	dp.assign(n + 1, 0);
	for (int i = 1; i < n; i++)
	{
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	dfs(r,-1);

	int input;
	string output;
	for (int i = 0; i < q; i++)
	{
		cin >> input;
		output += to_string(dp[input]);
		output += '\n';
	}
	cout << output;

	return 0;
}