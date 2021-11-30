#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int INF = 401; //INF 숫자 초기화
typedef pair<int, int> ci; //pair<int,int> ci로 명칭화

pair<int, ci> nextPos(int n, int shark_size, ci& shark, vector<vector<int>>& board) { //next 위치를 검사해주는 함수
    int dr[4] = { -1, 1, 0, 0 }; //상하좌우
    int dc[4] = { 0, 0, -1, 1 }; //상하좌우

    int min_dist = INF; //최소 거리를 찾는것이기때문에 INF로 초기화
    queue<ci> q; //상어가 갈 수 있는 곳
    vector<vector<int>> visited(n, vector<int>(n, 0)); //상어의 방문 여부
    vector<ci> list; //상어가 먹을 수 있는 물고기들의 위치

    visited[shark.first][shark.second] = 1; //제일처음 있던곳에 상어 방문 표시
    q.push(shark); //queue에 넣는다
    while (!q.empty()) { //큐에 값이 있을동안
        int row = q.front().first; //행
        int col = q.front().second; //열
        int dist = visited[row][col]; //거리
        q.pop(); //그리고 큐에서 꺼내기

        if (dist >= min_dist) //최단거리 이상은 탐색할 필요 없음
            continue;
        for (int i = 0; i < 4; i++) { //for문 돌면서 상하좌우 확인해보기
            int nr = row + dr[i]; //갱신
            int nc = col + dc[i]; //갱신
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc] || board[nr][nc] > shark_size) //상어 크기보다 크면 못먹는데
                continue;

            visited[nr][nc] = visited[row][col] + 1; //거리 갱신
            if (board[nr][nc] && board[nr][nc] < shark_size) { //먹을 수 있는 물고기 발견
                list.emplace_back(nr, nc); //갱신한 행열 넣어준다
                min_dist = visited[nr][nc]; //최소거리 갱신
                continue;
            }
            q.push({ nr, nc }); //bfs를 위해 추가하기
        }
    }

    if (list.empty()) //상어가 갈 수 있는 곳이 없음
        return { min_dist, {-1, -1} }; //갈수있는 곳이 없다면 반환

    sort(list.begin(), list.end(), [](const ci& p1, const ci& p2) { //정렬
        if (p1.first != p2.first)  //first가 같지 않으면
            return p1.first < p2.first; //오름차순
        return p1.second < p2.second; //아니면 second기준 오름차순
        });
    return { min_dist - 1, list[0] }; //최소거리-1과 행열(위치)를 반환
}

int simulation(int n, pair<int, int>& shark, vector<vector<int>>& board) { //시뮬레이션 돌리는 함수
    int ans = 0, size = 2, cnt = 0; //초기설정
    while (true) { //무한 반복
        pair<int, ci> result = nextPos(n, size, shark, board); //다음 위치에 대한 결과값을 반환받는다
        if (result.first == INF) //더 이상 먹을 수 있는 물고기가 공간에 없음
            break;
        ans += result.first; //거리 추가적으로 더해서 최종 거리 구하기
        cnt++; //개수 증가(상어크기와 연관있음)
        if (cnt == size) { //상어 크기 증가
            cnt = 0; //초기화
            size++; //크기 증가시키기
        }

        //상어 이동
        ci pos = result.second;
        board[shark.first][shark.second] = 0; //상어 우치 표시
        shark = pos; //갱신
    }
    return ans; //거리 반환
}

/**
 * 1. 상어로부터 가장 가까운 거리에 있는 모든 물고기 탐색 (BFS)
 * 2. 우선순위 조건에 맞추어 먹으러 갈 물고기 확정
 *    탐색하는 방향에 우선순위를 두는 걸로 해결되지 않음! (예제 입력 4) 정렬 필요
 * 3. 상어가 이동할 수 있는 곳이 없을 때까지 BFS 탐색 반복
 *
 * 입력 범위가 작기 때문에 매번 BFS 탐색을 반복해도 시간 초과 X
 * 가능한 물고기의 최대 마리 수 : 399마리
 * 최대 BFS 탐색 횟수 : 399회, 1회 탐색마다 while 문은 최대 400회 미만으로 순회
 * 총 연산 횟수 약 160000번으로 충분히 가능
 *
 * 해설 : https://myunji.tistory.com/378
 * *글 자체는 별로 도움이 안되고...그냥 리팩토링하면 코드가 이렇게 되는구나 정도만 봐주세요
 */
int main() {
    int n; //초기화
    pair<int, int> shark_pos; //상어 위치 초기화

    //입력
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n)); //board 초기화
    for (int i = 0; i < n; i++) { //반복 돌면서
        for (int j = 0; j < n; j++) { 
            cin >> board[i][j]; //초기상태 어땠는지 입력받기
            if (board[i][j] == 9) //상어의 초기 위치
                shark_pos = make_pair(i, j); //상어 위치 표기
        }
    }

    //연산 & 출력
    cout << simulation(n, shark_pos, board);
}