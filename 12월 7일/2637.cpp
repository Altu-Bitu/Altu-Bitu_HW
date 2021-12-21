#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

//�������� + DP
vector<vector<int>> topologicalSort(int n, vector<int>& indegree, vector<vector<ci>>& graph) {
    queue<int> q; //ť �迭
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0)); //�� ��ǰ�� �� �� �ʿ����� ����

    for (int i = 1; i <= n; i++) { //�ݺ��ϸ鼭 �������� Ȯ��
        if (!indegree[i]) { //���������� 0�̶�� -> �⺻ ��ǰ
            q.push(i); //ť �ֱ�
            dp[i][i] = 1; //�⺻ ��ǰ �ʱ�ȭ
        }
    }
    while (!q.empty()) { //ť ��������ʴٸ�
        int node = q.front(); //���� ���� ���� ���� ������
        q.pop(); //ť���� �����Ѵ�

        for (int i = 0; i < graph[node].size(); i++) { //�׷��� �� ���鼭
            int next_node = graph[node][i].first; //���� ��带 ã�Ƽ� Ȯ���Ѵ�
            int cnt = graph[node][i].second; //�ʿ��� ��ǰ ��
            indegree[next_node]--; //����� ������ ���������� 1�� ����
            if (!indegree[next_node]) //����� ������ ���������� 0�� �Ǿ��ٸ�
                q.push(next_node); //ť���� ����

            for (int j = 1; j <= n; j++) //�ݺ��� ���鼭
                dp[next_node][j] += dp[node][j] * cnt; //(���� ������ �̷�� ��ǰ ���� * �ʿ��� ���� ������ ����)�� ����
        }
    }
    return dp; //dp��ȯ
}

/**
 * �� ��ǰ���� ������ �ʿ��� ��ǰ ������ �����ϱ� ���� 2���� �迭 ��� (��: ��ǰ, ��: ���� �̷�µ� �� ��ǰ�� �ʿ��� ����)
 * ���� ���� ������ ����, �̾��� ���� ������ ��ǰ�� ������ (���� ������ �̷�� ��ǰ�� ���� * �ʿ��� ���� ���� ��)�� �����ָ� ����
 */

int main() {
    int n, m, x, y, k; //�ʱ�ȭ

    //�Է�
    cin >> n >> m;
    vector<vector<ci>> graph(n + 1, vector<ci>(0)); //�׷��� �ʱ�ȭ
    vector<int> indegree(n + 1, 0); //�������� �ʱ�ȭ
    while (m--) { //m����ŭ �Է�
        cin >> x >> y >> k; //y -> x
        indegree[x]++; //�������� ����
        graph[y].push_back({ x, k }); //�׷����� �ֱ�
    }

    //����
    vector<vector<int>> result = topologicalSort(n, indegree, graph);

    //���
    for (int i = 1; i <= n; i++) {
        if (result[i][i]) //�⺻ ��ǰ�̶��
            cout << i << ' ' << result[n][i] << '\n'; //���
    } 
    return 0; //��
}