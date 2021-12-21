#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<char>> board;
int dr[2] = { 1, 0 };
int dc[2] = { 0, 1 };

int cntCandy(int n, int row, int col, int dir) {
    int ans = 0, cnt = 0;  //초기화
    char cur = ' '; //초기화
    for (int i = 0; i < n; i++) { //입력된 값만큼 반복문을 돌면서
        if (cur == board[row][col]) { //연속된 사탕
            cnt++; //cnt를 증가시키고
            ans = max(ans, cnt); //최대값을 ans에 넣는다
        }
        else { //불연속
            cnt = 1; //cnt횟ㅅ를 초기화 시키고
            cur = board[row][col]; //현재값을 cur에 넣는다.
        }
        row += dr[dir]; //방향 바꾸기
        col += dc[dir]; //열 방향 바꾸기
    }
    return ans; //ans값반환(캔디 개수)
}

int findCandy(int n) {
    int ans = 0; //초기화
    for (int i = 0; i < n; i++) { //반복문을 돌면서
        ans = max(ans, cntCandy(n, 0, i, 0)); //같은 열에 대해
        ans = max(ans, cntCandy(n, i, 0, 1)); //같은 행에 대해
    }
    return ans; //cntCandy를 통해 얻은 max값을 찾는다
}

int switchCandy(int n, int row, int col, char candy) {
    int ans = 0; //초기화
    for (int i = 0; i < 2; i++) { //오른쪽, 아래에 있는 사탕과 바꿔보기
        int nr = row + dr[i], nc = col + dc[i]; //행,열 방향 바꾸기
        if (nr < n && nc < n && candy != board[nr][nc]) { //범위내에있고 board에 없는 값이면
            swap(board[row][col], board[nr][nc]); //새로운 것과 기존것을 바꾸고
            ans = max(ans, findCandy(n)); //ans값도 갱신한뒤
            swap(board[row][col], board[nr][nc]); //다시 기존것과 새로운것을 swap한다
        }
    }
    return ans; //그후 갱신된 ans값을 반환한다.
}

/**
 * 입력 범위가 크지 않으므로 바꿀 수 있는 사탕을 모두 바꿔보며 먹을 수 있는 사탕 계산
 * 오른쪽, 아래에 있는 사탕과만 바꿔도 모든 경우 고려 가능(왼쪽, 위 고려 X)
 *
 * 1. 사탕의 색이 다른 사탕만 교환하기
 * 2. 각 열, 행이 모두 같은 사탕일 때 사탕의 개수가 갱신되지 않도록 주의 (ans 갱신을 line 18~21에서 하는 경우)
 */
int main() {
    int n, max_candy = 0; //초기화

    //입력
    cin >> n;
    board.assign(n, vector<char>(n, ' '));//board를 입력하기위해 초기화 시킨다.
    for (int i = 0; i < n; i++) //반복문돌면서
        for (int j = 0; j < n; j++) //board를
            cin >> board[i][j]; //입력한다.

    //연산
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) //반복문 돌면서
            max_candy = max(max_candy, switchCandy(n, i, j, board[i][j])); //max값을 찾는다
    }

    //출력
    cout << max_candy;
}