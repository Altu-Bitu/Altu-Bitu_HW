#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

typedef pair<int, int> ci;
const int INF = 987654321; //�ִ� V-1���� ������ ������ ��

//���ͽ�Ʈ��
vector<int> dijkstra(int vertex, int start, vector<vector<ci>>& graph) {
    
    vector<int> dist(vertex+1, INF);
    priority_queue<ci, vector<ci>, greater<>> pq; //first : ���������κ����� �Ÿ�, second : ����

    //���� ��ġ �ʱ�ȭ
    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (weight > dist[node]) //�̹� Ȯ���ߴ� ����
            continue;
        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first; //����� ����
            int next_weight = weight + graph[node][i].second; //���������κ��� ����� ���������� �Ÿ�
            if (dist[next_node] > next_weight) { //�� ª�� ��η� �� �� �ִٸ�
                dist[next_node] = next_weight;
                pq.push({ next_weight, next_node });
            }
        }
    }
    return dist;
}
int main()
{
    //����� �ӵ�
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	int v, e, a, b, c,v1,v2;
	cin >> v >> e;
	vector<vector<ci>> graph(v + 1, vector<ci>(0));
	while (e--)
	{
		cin >> a >> b >> c;
		graph[a].emplace_back(v, c);
	}
	cin >> v1 >> v2;

	vector<int> ans = dijkstra(v,1, graph);
    vector<int> ans1 = dijkstra(v, v1, graph);
    vector<int>ans2 = dijkstra(v, v2, graph);
    //��Ʈ��  1->node1->node2->v Ȥ�� 1->node2->node1->N
    int answer = min({ ans[v1] + ans1[v2] + ans2[v],ans[v2] + ans2[v1]+ ans1[v]});
    if (answer >= INF || answer < 0)
        cout << -1;
    else
        cout << answer;

	return 0;
}

//����https://jaimemin.tistory.com/1004