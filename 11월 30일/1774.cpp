#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <cmath>

using namespace std;
typedef pair<double, double> ci; //pair ci로 재선언
typedef tuple<double, int, int> tp; //tuple 선언

vector<int> parent; //parent 배열

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
        return false; //못하므로 false반환
    if (parent[xp] < parent[yp]) { //새로운 루트 xp
        parent[xp] += parent[yp]; //가장 노드 개수 많은게 부모할수있게 표시
        parent[yp] = xp; //xp를 부모로
    }
    else { //새로운 루트 yp
        parent[yp] += parent[xp]; //가장 노드 개수 많은게 부모할수있게 표시
        parent[xp] = yp; //yp를 부모로
    }
    return true; //true반환
}

double kruskal(int v, priority_queue<tp, vector<tp>, greater<>>& pq) {
    int cnt = 0; //초기화
    double sum = 0; //초기화

    while (cnt < v - 1) { //사용한 간선의 수가 v-1보다 적을 동안
        double cost = get<0>(pq.top()); //cost에 넣어주고
        int x = get<1>(pq.top()); //각각 x
        int y = get<2>(pq.top());//y에 넣어준다/

        pq.pop();//그후 제거
        if (unionInput(x, y)) { //유니온 했다면
            cnt++; //사용된 간선 증가
            sum += cost; //간선의 가중치
        }
    }
    return sum; //가중치 반환
}

/**
 * 4386번 : 별자리 만들기의 응용 문제
 * 이미 연결된 정점들이 존재한다는 것을 제외하고는 4386번과 동일
 *
 * 1. 임의의 두 별에 대한 거리(간선) 모두 구하기
 * 2. 이미 존재하는 통로들 표시
 *    !주의! 통로의 개수가 m개라면 v-m-1개의 간선만 더 추가하면 될까?
 *          이미 연결된 통로들도 사이클을 이룰 수 있기 때문에 유니온 연산을 하며 사이클 없이 연결된 간선만 세기
 * 3. 이미 연결된 통로의 수를 k개라고 하면 v-k-1개의 간선을 추가로 선택
 */
int main() {
    //초기화
    int n, m, a, b, v = 0;
    priority_queue<tp, vector<tp>, greater<>> pq;

    //입력
    cin >> n >> m;
    parent.assign(n + 1, -1); //재초기화
    vector<ci> stars(n + 1); //초기화
    for (int i = 1; i <= n; i++) //입력
        cin >> stars[i].first >> stars[i].second;


    //연산
    //임의의 두 별에 대한 거리(간선) 모두 구하기
    for (int i = 1; i <= n - 1; i++) { //반복문 돌면서
        for (int j = i + 1; j <= n; j++) {
            double xd = stars[i].first - stars[j].first; //간선 구해서 넣어준다
            double yd = stars[i].second - stars[j].second; //간선 구하기
            pq.push({ sqrt(xd * xd + yd * yd), i, j }); //구한 간선을 pq에 넣어준다
        }
    }
    while (m--) { //m만큼 반복문 돌면서
        cin >> a >> b; //입력
        if (unionInput(a, b)) //이미 연결된 통로
            v++;
    }

    //연산 & 출력
    cout << fixed; //소수점 고정
    cout.precision(2); //2자리까지
    cout << kruskal(n - v, pq); //출력
}