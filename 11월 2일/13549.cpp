#include <iostream>
#include <queue>
#include <vector>


using namespace std;

const int LIMIT = 100001;

int solution(int n, int k)
{
	int time = 0;
	vector<bool> visited(LIMIT, false);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;//�ð��� �������� ���ĵǸ鼭 ���̰� �ȴ�.
	q.push({ time,n });
	visited[n] = true;

	while (!q.empty())
	{

		time = q.top().first;
		int node = q.top().second; 
		q.pop();

		if (node == k)
			return time;

		if (node * 2 < LIMIT && !visited[node * 2]) //�����̵��� ���� ó���Ǿ����
		{
			q.push({ time,node * 2 }); //�����̵��� �ð� ���ž���
			visited[node * 2] = true;
		}
		if (node + 1 < LIMIT && !visited[node + 1])
		{
			q.push({ time + 1,node + 1});
			visited[node + 1] = true;
		}
		if (node - 1 >=0 && !visited[node - 1])
		{
			q.push({time + 1 ,node - 1});
			visited[node - 1] = true;
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