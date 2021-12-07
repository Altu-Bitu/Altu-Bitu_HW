#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF = 1e5 + 1; //��� ����

int prim(int size, int start, vector<vector<int>>& graph) {
    int sum = 0; //�ʱ�ȭ
    vector<int> dist(size, INF); //�� ������� ���
    vector<bool> visited(size, false); //�� �湮 ����
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; //�켱���� ť ����

    //�ʱ�ȭ
    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int cost = pq.top().first; //���� ����ġ
        int cur = pq.top().second; //���� ��
        pq.pop(); //�����ϱ�

        if (visited[cur]) //�̹� Ȯ���ߴ� ����
            continue;
        sum += cost; //MST ���� ����ġ ����
        visited[cur] = true; //�湮 ó��

        for (int i = 0; i < size; i++) { //�ݺ�������
            if (!visited[i] && graph[cur][i] < dist[i]) { //�̹湮 �����̸鼭 �� ª�� ������ ���� �� �� �ִٸ�
                dist[i] = graph[cur][i]; //������
                pq.push({ dist[i], i }); //�켱���� ť�� �־��ֱ�
            }
        }
    }
    return sum; //��ȯ
}

/**
 * �� ��� ������ ������ ����ϰ�, �칰�� �Ĵ� ��쵵 ���? -> ����
 * �� �߰��� ��� �칰�� ����Ǵ� ������ �ִٰ� ����!
 * ->���� �� �칰�� �Ĵ� ���� ������ �� �� ������ ���� ����ġ��� �� �� ����
 *
 * 0 2 2 2 5
 * 2 0 3 3 4
 * 2 3 0 4 4
 * 2 3 4 0 3
 * 5 4 4 3 0
 *
 * �ε��� 0 ~ n-1�� ��, �ε��� n�� ����
 * 1�� �̻��� ���� �ݵ�� ���� �칰�� �ľ� �ϹǷ� ����(n)���� �����ϴ� ���� �˰���
 */
int main() {
    int n, w; //����

    cin >> n; //�Է�
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0)); //���߹迭 �ʱ�ȭ
    for (int i = 0; i < n; i++) { //�������κ��� ���� ������� ���
        cin >> w; //�Է�
        graph[i][n] = graph[n][i] = w; //�׷��� ������ ǥ��
    }

    for (int i = 0; i < n; i++) { //�ݺ��� ���鼭 �׷��� ���(���) �Է�
        for (int j = 0; j < n; j++)
            cin >> graph[i][j]; //��� ���̿��� ���� ������� ���
    }

    cout << prim(n + 1, n, graph); //�������� �����ϴ� ���� �˰���
}