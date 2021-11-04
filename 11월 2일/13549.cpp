#include <iostream>
#include <queue>
#include <vector>


using namespace std;

int limit = 100001;

int solution(int n, int k)
{
	int time = 0;
	vector<bool> visited(limit, false);
	//queue<pair<int, int>> q;  //����!! �׳� queue�� �ȵǴ� ������ 0���� �����̵��� ������ ���� �������ϱ⶧���ΰ���?
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;//�ð��� �������� ���ĵǸ鼭 ���̰� �ȴ�.

	q.push({ time,n });
	visited[n] = true;

	while (!q.empty())
	{
		//int node = q.front().first;
		//time = q.front().second;

		time = q.top().first;
		int node = q.top().second; 
		q.pop();

		if (node == k)
			return time;

		if (node + 1 < limit && !visited[node + 1])
		{
			q.push({ time + 1,node + 1});
			visited[node + 1] = true;
		}
		if (node - 1 >=0 && !visited[node - 1])
		{
			q.push({time + 1 ,node - 1});
			visited[node - 1] = true;
		}
		if (node*2 < limit && !visited[node*2])
		{
			q.push({time,node * 2}); //�����̵��� �ð� ���ž���
			visited[node*2] = true;
		}
		
	}
}

int main()
{
	int n, k;
	cin >> n >> k;
	cout << solution(n, k);
	return 0;
}