#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<char>> board;
int dr[2] = { 1, 0 };
int dc[2] = { 0, 1 };

int cntCandy(int n, int row, int col, int dir) {
    int ans = 0, cnt = 0;  //�ʱ�ȭ
    char cur = ' '; //�ʱ�ȭ
    for (int i = 0; i < n; i++) { //�Էµ� ����ŭ �ݺ����� ���鼭
        if (cur == board[row][col]) { //���ӵ� ����
            cnt++; //cnt�� ������Ű��
            ans = max(ans, cnt); //�ִ밪�� ans�� �ִ´�
        }
        else { //�ҿ���
            cnt = 1; //cntȽ���� �ʱ�ȭ ��Ű��
            cur = board[row][col]; //���簪�� cur�� �ִ´�.
        }
        row += dr[dir]; //���� �ٲٱ�
        col += dc[dir]; //�� ���� �ٲٱ�
    }
    return ans; //ans����ȯ(ĵ�� ����)
}

int findCandy(int n) {
    int ans = 0; //�ʱ�ȭ
    for (int i = 0; i < n; i++) { //�ݺ����� ���鼭
        ans = max(ans, cntCandy(n, 0, i, 0)); //���� ���� ����
        ans = max(ans, cntCandy(n, i, 0, 1)); //���� �࿡ ����
    }
    return ans; //cntCandy�� ���� ���� max���� ã�´�
}

int switchCandy(int n, int row, int col, char candy) {
    int ans = 0; //�ʱ�ȭ
    for (int i = 0; i < 2; i++) { //������, �Ʒ��� �ִ� ������ �ٲ㺸��
        int nr = row + dr[i], nc = col + dc[i]; //��,�� ���� �ٲٱ�
        if (nr < n && nc < n && candy != board[nr][nc]) { //���������ְ� board�� ���� ���̸�
            swap(board[row][col], board[nr][nc]); //���ο� �Ͱ� �������� �ٲٰ�
            ans = max(ans, findCandy(n)); //ans���� �����ѵ�
            swap(board[row][col], board[nr][nc]); //�ٽ� �����Ͱ� ���ο���� swap�Ѵ�
        }
    }
    return ans; //���� ���ŵ� ans���� ��ȯ�Ѵ�.
}

/**
 * �Է� ������ ũ�� �����Ƿ� �ٲ� �� �ִ� ������ ��� �ٲ㺸�� ���� �� �ִ� ���� ���
 * ������, �Ʒ��� �ִ� �������� �ٲ㵵 ��� ��� ��� ����(����, �� ��� X)
 *
 * 1. ������ ���� �ٸ� ������ ��ȯ�ϱ�
 * 2. �� ��, ���� ��� ���� ������ �� ������ ������ ���ŵ��� �ʵ��� ���� (ans ������ line 18~21���� �ϴ� ���)
 */
int main() {
    int n, max_candy = 0; //�ʱ�ȭ

    //�Է�
    cin >> n;
    board.assign(n, vector<char>(n, ' '));//board�� �Է��ϱ����� �ʱ�ȭ ��Ų��.
    for (int i = 0; i < n; i++) //�ݺ������鼭
        for (int j = 0; j < n; j++) //board��
            cin >> board[i][j]; //�Է��Ѵ�.

    //����
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) //�ݺ��� ���鼭
            max_candy = max(max_candy, switchCandy(n, i, j, board[i][j])); //max���� ã�´�
    }

    //���
    cout << max_candy;
}