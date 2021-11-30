#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int INF = 401; //INF ���� �ʱ�ȭ
typedef pair<int, int> ci; //pair<int,int> ci�� ��Īȭ

pair<int, ci> nextPos(int n, int shark_size, ci& shark, vector<vector<int>>& board) { //next ��ġ�� �˻����ִ� �Լ�
    int dr[4] = { -1, 1, 0, 0 }; //�����¿�
    int dc[4] = { 0, 0, -1, 1 }; //�����¿�

    int min_dist = INF; //�ּ� �Ÿ��� ã�°��̱⶧���� INF�� �ʱ�ȭ
    queue<ci> q; //�� �� �� �ִ� ��
    vector<vector<int>> visited(n, vector<int>(n, 0)); //����� �湮 ����
    vector<ci> list; //�� ���� �� �ִ� �������� ��ġ

    visited[shark.first][shark.second] = 1; //����ó�� �ִ����� ��� �湮 ǥ��
    q.push(shark); //queue�� �ִ´�
    while (!q.empty()) { //ť�� ���� ��������
        int row = q.front().first; //��
        int col = q.front().second; //��
        int dist = visited[row][col]; //�Ÿ�
        q.pop(); //�׸��� ť���� ������

        if (dist >= min_dist) //�ִܰŸ� �̻��� Ž���� �ʿ� ����
            continue;
        for (int i = 0; i < 4; i++) { //for�� ���鼭 �����¿� Ȯ���غ���
            int nr = row + dr[i]; //����
            int nc = col + dc[i]; //����
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc] || board[nr][nc] > shark_size) //��� ũ�⺸�� ũ�� ���Դµ�
                continue;

            visited[nr][nc] = visited[row][col] + 1; //�Ÿ� ����
            if (board[nr][nc] && board[nr][nc] < shark_size) { //���� �� �ִ� ����� �߰�
                list.emplace_back(nr, nc); //������ �࿭ �־��ش�
                min_dist = visited[nr][nc]; //�ּҰŸ� ����
                continue;
            }
            q.push({ nr, nc }); //bfs�� ���� �߰��ϱ�
        }
    }

    if (list.empty()) //�� �� �� �ִ� ���� ����
        return { min_dist, {-1, -1} }; //�����ִ� ���� ���ٸ� ��ȯ

    sort(list.begin(), list.end(), [](const ci& p1, const ci& p2) { //����
        if (p1.first != p2.first)  //first�� ���� ������
            return p1.first < p2.first; //��������
        return p1.second < p2.second; //�ƴϸ� second���� ��������
        });
    return { min_dist - 1, list[0] }; //�ּҰŸ�-1�� �࿭(��ġ)�� ��ȯ
}

int simulation(int n, pair<int, int>& shark, vector<vector<int>>& board) { //�ùķ��̼� ������ �Լ�
    int ans = 0, size = 2, cnt = 0; //�ʱ⼳��
    while (true) { //���� �ݺ�
        pair<int, ci> result = nextPos(n, size, shark, board); //���� ��ġ�� ���� ������� ��ȯ�޴´�
        if (result.first == INF) //�� �̻� ���� �� �ִ� ����Ⱑ ������ ����
            break;
        ans += result.first; //�Ÿ� �߰������� ���ؼ� ���� �Ÿ� ���ϱ�
        cnt++; //���� ����(���ũ��� ��������)
        if (cnt == size) { //��� ũ�� ����
            cnt = 0; //�ʱ�ȭ
            size++; //ũ�� ������Ű��
        }

        //��� �̵�
        ci pos = result.second;
        board[shark.first][shark.second] = 0; //��� ��ġ ǥ��
        shark = pos; //����
    }
    return ans; //�Ÿ� ��ȯ
}

/**
 * 1. ���κ��� ���� ����� �Ÿ��� �ִ� ��� ����� Ž�� (BFS)
 * 2. �켱���� ���ǿ� ���߾� ������ �� ����� Ȯ��
 *    Ž���ϴ� ���⿡ �켱������ �δ� �ɷ� �ذ���� ����! (���� �Է� 4) ���� �ʿ�
 * 3. �� �̵��� �� �ִ� ���� ���� ������ BFS Ž�� �ݺ�
 *
 * �Է� ������ �۱� ������ �Ź� BFS Ž���� �ݺ��ص� �ð� �ʰ� X
 * ������ ������� �ִ� ���� �� : 399����
 * �ִ� BFS Ž�� Ƚ�� : 399ȸ, 1ȸ Ž������ while ���� �ִ� 400ȸ �̸����� ��ȸ
 * �� ���� Ƚ�� �� 160000������ ����� ����
 *
 * �ؼ� : https://myunji.tistory.com/378
 * *�� ��ü�� ���� ������ �ȵǰ�...�׳� �����丵�ϸ� �ڵ尡 �̷��� �Ǵ±��� ������ ���ּ���
 */
int main() {
    int n; //�ʱ�ȭ
    pair<int, int> shark_pos; //��� ��ġ �ʱ�ȭ

    //�Է�
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n)); //board �ʱ�ȭ
    for (int i = 0; i < n; i++) { //�ݺ� ���鼭
        for (int j = 0; j < n; j++) { 
            cin >> board[i][j]; //�ʱ���� ����� �Է¹ޱ�
            if (board[i][j] == 9) //����� �ʱ� ��ġ
                shark_pos = make_pair(i, j); //��� ��ġ ǥ��
        }
    }

    //���� & ���
    cout << simulation(n, shark_pos, board);
}