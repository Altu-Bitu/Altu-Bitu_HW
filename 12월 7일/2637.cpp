#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

//위상정렬 + DP
vector<vector<int>> topologicalSort(int n, vector<int>& indegree, vector<vector<ci>>& graph) {
    queue<int> q; //큐 배열
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0)); //각 부품이 몇 개 필요한지 저장

    for (int i = 1; i <= n; i++) { //반복하면서 진입차수 확인
        if (!indegree[i]) { //진입차수가 0이라면 -> 기본 부품
            q.push(i); //큐 넣기
            dp[i][i] = 1; //기본 부품 초기화
        }
    }
    while (!q.empty()) { //큐 비어있지않다면
        int node = q.front(); //가장 먼저 넣은 값을 꺼낸뒤
        q.pop(); //큐에서 제거한다

        for (int i = 0; i < graph[node].size(); i++) { //그래프 다 돌면서
            int next_node = graph[node][i].first; //다음 노드를 찾아서 확인한다
            int cnt = graph[node][i].second; //필요한 부품 수
            indegree[next_node]--; //연결된 정점의 진입차수를 1씩 감소
            if (!indegree[next_node]) //연결된 정점의 진입차수가 0이 되었다면
                q.push(next_node); //큐에서 제거

            for (int j = 1; j <= n; j++) //반복문 돌면서
                dp[next_node][j] += dp[node][j] * cnt; //(현재 정점을 이루는 부품 개수 * 필요한 현재 정점의 개수)를 더함
        }
    }
    return dp; //dp반환
}

/**
 * 각 부품마다 종류별 필요한 부품 개수를 저장하기 위해 2차원 배열 사용 (행: 부품, 열: 행을 이루는데 각 부품별 필요한 개수)
 * 위상 정렬 순서에 따라, 이어진 다음 정점의 부품별 개수를 (현재 정점을 이루는 부품별 개수 * 필요한 현재 정점 수)를 더해주며 구함
 */

int main() {
    int n, m, x, y, k; //초기화

    //입력
    cin >> n >> m;
    vector<vector<ci>> graph(n + 1, vector<ci>(0)); //그래프 초기화
    vector<int> indegree(n + 1, 0); //진입차수 초기화
    while (m--) { //m개만큼 입력
        cin >> x >> y >> k; //y -> x
        indegree[x]++; //진입차수 증가
        graph[y].push_back({ x, k }); //그래프에 넣기
    }

    //연산
    vector<vector<int>> result = topologicalSort(n, indegree, graph);

    //출력
    for (int i = 1; i <= n; i++) {
        if (result[i][i]) //기본 부품이라면
            cout << i << ' ' << result[n][i] << '\n'; //출력
    } 
    return 0; //끝
}