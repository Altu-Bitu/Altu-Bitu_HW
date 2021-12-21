#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//위상정렬
vector<int> topologicalSort(int n, vector<int>& indegree, vector<vector<int>>& graph) {
    vector<int> result; //배열형성
    queue<int> q; //큐 형성

    for (int i = 1; i <= n; i++) { //반복문 돌면서
        if (!indegree[i]) //진입차수가 0이라면
            q.push(i); //큐에 넣기
    }

    while (!q.empty()) { //비어있지않으면
        int node = q.front(); //가장 먼저 넣은 값을 꺼낸뒤
        q.pop(); //pop하여 제거

        result.push_back(node); //현재 정점 순서에 삽입
        for (int i = 0; i < graph[node].size(); i++) { //그래프를 다 돌면서
            int next_node = graph[node][i]; //다음 노드를 찾고
            indegree[next_node]--; //연결된 정점의 진입차수를 1씩 감소
            if (!indegree[next_node]) //연결된 정점의 진입차수가 0이 되었다면
                q.push(next_node); //next_node를 큐에 넣는다.
        }
    }
    return result;//정점순서대로 삽입된 배열 반환
}

/**
 * 기본적인 위상 정렬 문제
 * 현재 가수와 바로 전 가수 사이의 선후관계를 정의
 * 순서를 정하는 것이 불가능한 경우(위상정렬을 할 수 없는 경우)는 모든 정점을 탐색하지 못한 경우
 */

int main() {
    int n, m, cnt, prev, cur; //초기화

    //입력
    cin >> n >> m; //입력
    vector<int> indegree(n + 1, 0); //배열 초기화
    vector<vector<int>> graph(n + 1, vector<int>(0)); //그래프 초기화
    while (m--) { //m개수 만큼
        cin >> cnt; //담당 가수의 수
        cin >> prev; //처음 가수 입력
        while (--cnt) { //선후관계 정의
            cin >> cur; //입력
            indegree[cur]++; //진입차수 증가
            graph[prev].push_back(cur);//그래프에 넣기
            prev = cur; //갱신
        }
    }

    //연산
    vector<int> result = topologicalSort(n, indegree, graph); //위상정렬한값을 result로 반환받기

    //출력
    if (result.size() != n) { //순서를 정하는 것이 불가한 경우
        cout << "0\n"; //0을 출력하고 
        return 0; //끝
    }
    for (int i = 0; i < result.size(); i++) //배열값을 출력해서
        cout << result[i] << '\n'; //정렬된 값을 보여준다.
}