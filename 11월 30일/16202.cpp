#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;
typedef tuple<int, int, int> tp; //튜플 선언

vector<int> parent; //부모 배열

//Find 연산
int findParent(int node) {
    if (parent[node] < 0) //값이 음수면 루트 정점
        return node; //node 반환
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
bool unionInput(int x, int y) {
    int xp = findParent(x); //부모찾기
    int yp = findParent(y); //부모찾기

    if (xp == yp) //같은 집합에 있다면 유니온 할 수 없음
        return false; //유니온 불가
    if (parent[xp] < parent[yp]) { //새로운 루트 xp
        parent[xp] += parent[yp]; //노드개수 표시
        parent[yp] = xp; //xp를 부모로
    }
    else { //새로운 루트 yp
        parent[yp] += parent[xp]; //노드개수 표시
        parent[xp] = yp; //yp를 부모로
    }
    return true; //유니온했음
}

int kruskal(int n, int idx, vector<tp>& edges) {
    int cnt = 0, sum = 0; //초기화
    for (int i = idx; i < edges.size(); i++) {
        if (cnt == n - 1) //n-1개의 간선을 모두 연결함
            break;//중단
        int dist = get<0>(edges[i]); //튜플값 받아오기
        int x = get<1>(edges[i]);//튜플값 받아오기
        int y = get<2>(edges[i]);//튜플값 받아오기

        if (unionInput(x, y)) { //union하기
            cnt++; //개수 추가
            sum += dist; //거리 증가
        }
    }
    if (cnt < n - 1) //mst를 만들 수 없음
        return 0; //0으로 표시
    return sum; //거리 반환
}

/**
 * MST 알고리즘을 여러 번 실행해도 될까?
 * 1. 크루스칼 알고리즘의 시간 복잡도는 O(ElogE)
 *    이는 오직 간선을 정렬하는 연산의 시간 복잡도!
 *    즉, 모든 간선을 한 번 정렬해서 저장해두면 이후 몇 번의 알고리즘을 수행하여도 연산 시간에 큰 영향이 없음
 * 2. 간선 재사용을 위해 우선순위 큐가 아닌 벡터에 저장하고 크루스칼 알고리즘 k번 실행
 * 3. 매번 크루스칼을 수행할 때마다 제일 먼저 추가한 간선을 제외함
 *    -> 제외될 간선은 배열의 0번째 간선부터 1, 2, 3번째 간선으로 순차적 제외
 * 4. 만약 한 번 MST를 만들 수 없다는게 확인됐다면 이후에도 MST를 만들 수 없으므로 flag 변수로 불필요한 연산 절약
 */
int main() {
    int n, m, k, x, y; //초기화

    cin >> n >> m >> k; //입력
    vector<tp> edges; //재사용할거라 우선순위 큐가 아닌 벡터에 저장
    for (int i = 1; i <= m; i++) { //반복
        cin >> x >> y; //입력
        edges.emplace_back(i, x, y); //튜플벡터에 넣어준다
    }

    bool flag = false; //flag
    for (int i = 0; i < k; i++) { //반복돌면서 mst만든다
        if (flag) { //더이상 mst를 만들 수 없음
            cout << 0 << ' ';
            continue;
        }
        parent.assign(n + 1, -1); //초기화
        int ans = kruskal(n, i, edges); //sum받기
        if (ans == 0) //0이면 mst를 만들수없다는 뜻으로 flag표시
            flag = true; //true로 해서 위에서 conitnue하도록 만든다
        cout << ans << ' '; //ans출력
    }
}