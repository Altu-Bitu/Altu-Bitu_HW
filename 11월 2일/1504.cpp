#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

typedef pair<int, int> ci;
const int INF = 987654321; //최대 V-1개의 간선을 지나게 됨

//다익스트라
vector<int> dijkstra(int vertex, int start, vector<vector<ci>>& graph) {
    
    vector<int> dist(vertex+1, INF);
    priority_queue<ci, vector<ci>, greater<>> pq; //first : 시작점으로부터의 거리, second : 정점

    //시작 위치 초기화
    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (weight > dist[node]) //이미 확인했던 정점
            continue;
        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first; //연결된 정점
            int next_weight = weight + graph[node][i].second; //시작점으로부터 연결된 정점까지의 거리
            if (dist[next_node] > next_weight) { //더 짧은 경로로 갈 수 있다면
                dist[next_node] = next_weight;
                pq.push({ next_weight, next_node });
            }
        }
    }
    return dist;
}
int main()
{
    //입출력 속도
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
    //루트는  1->node1->node2->v 혹은 1->node2->node1->N
    int answer = min({ ans[v1] + ans1[v2] + ans2[v],ans[v2] + ans2[v1]+ ans1[v]});
    if (answer >= INF || answer < 0)
        cout << -1;
    else
        cout << answer;

	return 0;
}

//참고https://jaimemin.tistory.com/1004