#include <iostream>
#include <vector>

using namespace std;

vector<bool> visited;
vector<vector<int>> graph;

string check(int t, int k)
{
	if (t == 1)//����������
	{
		//graph[k]�� �ٸ��Ŷ� ����Ǿ� �ִ°� �ΰ��̻��̸� ���Ž� ������ ������
		if (graph[k].size() >= 2)
			return "yes";
		else
			return "no";
	}

	else//����������
	{
		//Ʈ�������� ���� �����ϸ� ������ ������->�� �ϳ��θ� ����Ǿ�����
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