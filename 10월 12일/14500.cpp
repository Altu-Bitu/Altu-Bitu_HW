#include <iostream>
#include <vector>

using namespace std;

int ans, n, m; //전역으로 변수 선언
vector<vector<int>> board; //이중배열 전역으로 선언
int dr[4] = { -1, 1, 0, 0 }; //r 이동(상하좌우) 
int dc[4] = { 0, 0, -1, 1 }; //c 이동(상하좌우)

//board[row][col]을 가운데로 하는 +모양 만들기
int horn(int row, int col) {
    int cnt = 0, min_block = 1001, sum = board[row][col]; //초기화

    for (int i = 0; i < 4; i++) { //반복문 돌면서 상하좌우돌기
        int nr = row + dr[i]; //행 변화
        int nc = col + dc[i]; //열 변화

        if (nr < 0 || nr >= n || nc < 0 || nc >= m) //범위를 벗어나면 무시
            continue;
        min_block = min(min_block, board[nr][nc]); //가장자리 블럭 중 값이 가장 작은 블럭
        sum += board[nr][nc];   //전체합 구하기
        cnt++; //개수 세기
    }

    if (cnt < 3) //가능한 가장자리가 최소 3개 이상이어야 함
        return 0; 
    if (cnt == 3) //ㅗㅏㅜㅓ
        return sum;
    //+
    return sum - min_block;  //cnt가 위 조건이 아닐시 sum에서 값이 가장 작은 블럭을 제외한다.
}

//한붓 그리기가 가능한 블럭들 백트래킹 탐색
void backtracking(int row, int col, int cnt, int sum) {
    if (cnt == 4) { //기저조건 : 4개의 블럭을 탐색함
        ans = max(ans, sum);    //ans 갱신해준다.
        return;
    }

    for (int i = 0; i < 4; i++) { //상하좌우 이동
        int nr = row + dr[i];   //행 변화
        int nc = col + dc[i]; //열 변화

        if (nr < 0 || nr >= n || nc < 0 || nc >= m || !board[nr][nc]) //범위를 벗어나거나, 이미 방문했다면
            continue;
        int save = board[nr][nc];   //board값 저장해두고
        board[nr][nc] = 0;      //0으로 초기화한다
        backtracking(nr, nc, cnt + 1, sum + save);  //재귀함수 실행
        board[nr][nc] = save;   //다시 restore해준다.
    }
}

/**
 * 1. 각 블럭을 백트래킹이 가능한 블럭과 불가능한 블럭으로 나누기
 *    -> 블럭을 한붓 그리기로 그릴 수 있으면 백트래킹이 가능 아니라면 불가능
 *    -> 보라색 블럭을 제외하면 모두 백트래킹 가능
 * 2. 보라색 블럭은 + 모양에서 가장자리를 하나 제거한 것과 같음
 *    -> 가운데 블럭을 중심으로 가장자리 블럭을 붙여보고 가능한 최댓값 구하기
 * 3. 각 블럭에 대해 깊이가 4인 백트래킹 함수를 수행하며 최댓값 갱신
 *
 * 해설 : https://myunji.tistory.com/297
 * *코드가 살짝 달라요(블로그 코드는 최적화 하기 전)
 */
int main() {
    //입력
    cin >> n >> m;
    board.assign(n, vector<int>(m, 0)); //초기화
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> board[i][j]; //입력받기
    }

    //연산
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = max(ans, horn(i, j)); //보라색 블럭 처리
            int save = board[i][j];     //save에 값 저장해둔다.

            board[i][j] = 0;    //그 후 0으로 초기화한다음에 함수 진입
            backtracking(i, j, 1, save); //나머지 모양 처리
            board[i][j] = save; //복구
        }
    }

    //출력
    cout << ans;    
}