#include <iostream>
#include <vector>

using namespace std;

int ans, n, m; //�������� ���� ����
vector<vector<int>> board; //���߹迭 �������� ����
int dr[4] = { -1, 1, 0, 0 }; //r �̵�(�����¿�) 
int dc[4] = { 0, 0, -1, 1 }; //c �̵�(�����¿�)

//board[row][col]�� ����� �ϴ� +��� �����
int horn(int row, int col) {
    int cnt = 0, min_block = 1001, sum = board[row][col]; //�ʱ�ȭ

    for (int i = 0; i < 4; i++) { //�ݺ��� ���鼭 �����¿쵹��
        int nr = row + dr[i]; //�� ��ȭ
        int nc = col + dc[i]; //�� ��ȭ

        if (nr < 0 || nr >= n || nc < 0 || nc >= m) //������ ����� ����
            continue;
        min_block = min(min_block, board[nr][nc]); //�����ڸ� �� �� ���� ���� ���� ��
        sum += board[nr][nc];   //��ü�� ���ϱ�
        cnt++; //���� ����
    }

    if (cnt < 3) //������ �����ڸ��� �ּ� 3�� �̻��̾�� ��
        return 0; 
    if (cnt == 3) //�Ǥ��̤�
        return sum;
    //+
    return sum - min_block;  //cnt�� �� ������ �ƴҽ� sum���� ���� ���� ���� ���� �����Ѵ�.
}

//�Ѻ� �׸��Ⱑ ������ ���� ��Ʈ��ŷ Ž��
void backtracking(int row, int col, int cnt, int sum) {
    if (cnt == 4) { //�������� : 4���� ���� Ž����
        ans = max(ans, sum);    //ans �������ش�.
        return;
    }

    for (int i = 0; i < 4; i++) { //�����¿� �̵�
        int nr = row + dr[i];   //�� ��ȭ
        int nc = col + dc[i]; //�� ��ȭ

        if (nr < 0 || nr >= n || nc < 0 || nc >= m || !board[nr][nc]) //������ ����ų�, �̹� �湮�ߴٸ�
            continue;
        int save = board[nr][nc];   //board�� �����صΰ�
        board[nr][nc] = 0;      //0���� �ʱ�ȭ�Ѵ�
        backtracking(nr, nc, cnt + 1, sum + save);  //����Լ� ����
        board[nr][nc] = save;   //�ٽ� restore���ش�.
    }
}

/**
 * 1. �� ���� ��Ʈ��ŷ�� ������ ���� �Ұ����� ������ ������
 *    -> ���� �Ѻ� �׸���� �׸� �� ������ ��Ʈ��ŷ�� ���� �ƴ϶�� �Ұ���
 *    -> ����� ���� �����ϸ� ��� ��Ʈ��ŷ ����
 * 2. ����� ���� + ��翡�� �����ڸ��� �ϳ� ������ �Ͱ� ����
 *    -> ��� ���� �߽����� �����ڸ� ���� �ٿ����� ������ �ִ� ���ϱ�
 * 3. �� ���� ���� ���̰� 4�� ��Ʈ��ŷ �Լ��� �����ϸ� �ִ� ����
 *
 * �ؼ� : https://myunji.tistory.com/297
 * *�ڵ尡 ��¦ �޶��(��α� �ڵ�� ����ȭ �ϱ� ��)
 */
int main() {
    //�Է�
    cin >> n >> m;
    board.assign(n, vector<int>(m, 0)); //�ʱ�ȭ
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> board[i][j]; //�Է¹ޱ�
    }

    //����
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = max(ans, horn(i, j)); //����� �� ó��
            int save = board[i][j];     //save�� �� �����صд�.

            board[i][j] = 0;    //�� �� 0���� �ʱ�ȭ�Ѵ����� �Լ� ����
            backtracking(i, j, 1, save); //������ ��� ó��
            board[i][j] = save; //����
        }
    }

    //���
    cout << ans;    
}