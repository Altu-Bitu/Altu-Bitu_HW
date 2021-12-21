#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;
const int SIZE = 4;

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

vector<vector<ci>> findCard(vector<vector<int>>& board) { //�����ϴ� ��� ī���� ��ġ�� �����ϴ� �Լ�
    vector<vector<ci>> card_pos(7, vector<ci>(0)); //�ִ� ī�� ��
    int cnt = 0; //cnt �ʱ�ȭ
    for (int i = 0; i < SIZE; i++) { //board�� ��ȸȭ������
        for (int j = 0; j < SIZE; j++) { //���߹迭���
            cnt = max(cnt, board[i][j]); //board�� ���� cnt���� ũ�� ����
            if (board[i][j]) //ī���� ��ġ ����
                card_pos[board[i][j]].emplace_back(i, j); //��ġ����
        }
    }
    card_pos.resize(cnt + 1); //���� �����ϴ� ī���� ����ŭ ũ�� ����
    return card_pos; //��ġ ��ȯ
}

pair<int, int> ctrl(int row, int col, int dir, vector<vector<int>>& tmp) { //��Ʈ�ѷ� �̵��ϴ� ��ǥ�� �����ϴ� �Լ�
    while (true) { //���� �ݺ�
        row += dr[dir]; //��ġ ����
        col += dc[dir]; //��ġ ����
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) //�ش� ���⿡ ī�尡 �ϳ��� ���ٸ� �� ������ ���� ������ ĭ���� �̵�
            return make_pair(row - dr[dir], col - dc[dir]); //pair�� ��ȯ
        if (tmp[row][col] != 0) //���� Ű ���⿡ �ִ� ���� ����� ī��
            return make_pair(row, col); //pair�� ��ȯ
    }
}

int bfs(int r1, int c1, int r2, int c2, vector<vector<int>>& tmp) { //���� Ŀ������ ��ǥ ī��� �̵��ϴ� ���� ���� ����� �����ϴ� �Լ�
    vector<vector<int>> visited(SIZE, vector<int>(SIZE, 0)); //�湮 ���� Ȯ��
    queue<pair<int, int>> q; //ť
    visited[r1][c1] = 1; //�ݵ�� ���͸� ������ �� ��. ���͸� �̸� ������ �����ϰ� 1�� ǥ��
    q.push({ r1, c1 }); //�ʱⰪ �־��ֱ�

    while (!q.empty()) { //������� ��������
        int row = q.front().first; //�� ����
        int col = q.front().second; //�� ����
        int dist = visited[row][col]; //dist����
        q.pop(); //ť�� �ִ� �� ����

        if (row == r2 && col == c2) //��ǥ ī�忡 �����ߴٸ�
            return dist; //dist�� ��ȯ

        for (int i = 0; i < 4; i++) { //��Ʈ�� �Է� �̵�
            pair<int, int> np = ctrl(row, col, i, tmp); //��Ʈ�� �� np�� �־� ��ȸ
            if (visited[np.first][np.second]) //�湮�� ���̸� �Ѿ��
                continue;
            visited[np.first][np.second] = dist + 1; //�ƴ϶�� �������ֱ�
            q.push(np); //np�� ť���� ����
        }

        for (int i = 0; i < 4; i++) { //����Ű �Է� �̵�
            int nr = row + dr[i], nc = col + dc[i]; //���ο� ��,�� ����
            if (nr < 0 || nr >= 4 || nc < 0 || nc >= 4 || visited[nr][nc]) //�����Ϳ� �׸��� �湮�ߴ��� Ȯ��
                continue;//�׷� �׳� �Ѿ��
            visited[nr][nc] = dist + 1; //�ƴ϶�� ���� ����
            q.push({ nr, nc }); //���ο� �� �־��ֱ�
        }
    }
    return -1; //��ǥ ī�忡 �������� ���� (�����δ� �Ͼ�� �ʴ� ��)
}

int matchCard(int bit, int num, int r, int c, vector<int>& seq, vector<vector<ci>>& cards, vector<vector<int>> tmp) { //���տ� ���� ī�带 ��Ī�ϴ� �Լ�
    int ans = 0; //ans���ʱ�ȭ
    for (int i = 0; i < num; i++) {//�ݺ��� ���鼭 ĳ���� ���� ��ȸ
        int cur = seq[i]; //�̹��� ��Ī�� ĳ����
        int now = 0; //�ش� ĳ������ 0��° ī����� �����Ѵٰ� ����
        if (bit & (1 << i)) //���� �ش� ��ġ�� ��Ʈ�� 1�� ǥ���ߴٸ� 1��° ī����� ����
            now = 1; //��Ī ī�� �ε��� 1��

        for (int j = 0; j < 2; j++) {//�ݺ��� ���鼭���� ���ŵɺκ� �˻�
            now = (now + j) % 2; //�̹��� ��Ī�� ī�� �ε���
            int nr = cards[cur][now].first, nc = cards[cur][now].second; //�̹��� ��Ī�� ī�� ��ġ
            ans += bfs(r, c, nr, nc, tmp); //���� Ŀ������ ��ǥ ī����� �̵��ϴ� ���

            //ī�� ���� + Ŀ�� �̵�
            tmp[nr][nc] = 0; //ī�� ����
            r = nr; //������ ��ü
            c = nc; //������ ��ü
        }
    }
    return ans; //ans��ȯ
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 1e9; //���� ū������ �ʱ�ȭ �صд�.

    vector<vector<ci>> cards = findCard(board); //�����ϴ� ��� ī���� ��ġ
    int card_cnt = cards.size() - 1; //ī���� ����

    vector<int> seq(card_cnt); //������ ���� �迭
    for (int i = 0; i < card_cnt; i++) //������ ���� �ݺ���
        seq[i] = i + 1; //����

    do { //������ ��� ī�� ������ ����
        for (int bit = 0; bit < (1 << card_cnt); bit++) { //0, 1��° ī�� �� � ī�带 ���� �������� ����
            answer = min(answer, matchCard(bit, card_cnt, r, c, seq, cards, board)); //�ּҰ��� ã�´�
        }
    } while (next_permutation(seq.begin(), seq.end()));//next_permutation�� ���� false�ϰ�� stop
    return answer; //�ּ��� answer�� ��ȯ
}

/**
 * ���̵��
 * 1. ������ ũ�� ����
 * 2. �����ϴ� ��� ī���� ������ 6��, ī�� 2���� �� ���� �̷��.
 * 3. ������ ī�� ������ ���ϴ� ��� ����� ���� 6!(ī�� ����) * 2^6(2���� ī�� �� � ī�带 ���� ��������) -> ���Ʈ���� ����
 * 4. �̹��� ��ǥ�� �ϴ� ī�忡 ���� ���� Ŀ������ ��ǥ ī����� ���� �ִ� ��θ� ���ϸ� �̵� Ƚ�� ���� ���ϰ� �ּڰ� ����
 *
 * ����
 * 1. �����ϴ� ��� ī���� ��ġ�� �����ϸ� ī���� ���� ���� (findCard)
 * 2. ������ ��� ī���� ����(next_permutation)�� �� ī�带 ������ ����(bitmask)�� ����
 *    ex) seq = {3, 1, 2}, bit = 011 �� ��
 *        3��, 1��, 2�� ī���� ������ �����´�.
 *        3�� ī��� 1��° ī�����, 1�� ī��� 0��° ī�����, 2�� ī��� 1��° ī����� �����´�.
 *        bit�� 011�� �տ������� ���� 1, 2, 3�� ī��� ������
 * 3. ���� ī�� ������ �� ī�带 ������ ������ ���� Ŀ�� �̵� Ƚ�� ��� (matchCard)
 *    ���� Ŀ�� ��ġ�� ��ǥ ī�� ��ġ�� ���� bfs �Լ� ����
 *    ��Ʈ�� �Է��� ����ؾ� �ϱ� ������ 4���⿡ ���� ���� �̵��� �߰��� ��Ʈ�� �Էµ� ó���Ѵ�.(ctrl)
 * 4. �� ���տ� ���� board�� ���ŵǹǷ� board�� ������ tmp ���
 * ���� Ǯ�� : https://tech.kakao.com/2021/01/25/2021-kakao-recruitment-round-1/
 */
int main() {
    vector<vector<int>> board = { {1, 0, 0, 3},
                                 {2, 0, 0, 0},
                                 {0, 0, 0, 2},
                                 {3, 0, 1, 0} }; //�ʱ⼳��
    cout << solution(board, 1, 0); //���
}