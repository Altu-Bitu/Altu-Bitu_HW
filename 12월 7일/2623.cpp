#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//��������
vector<int> topologicalSort(int n, vector<int>& indegree, vector<vector<int>>& graph) {
    vector<int> result; //�迭����
    queue<int> q; //ť ����

    for (int i = 1; i <= n; i++) { //�ݺ��� ���鼭
        if (!indegree[i]) //���������� 0�̶��
            q.push(i); //ť�� �ֱ�
    }

    while (!q.empty()) { //�������������
        int node = q.front(); //���� ���� ���� ���� ������
        q.pop(); //pop�Ͽ� ����

        result.push_back(node); //���� ���� ������ ����
        for (int i = 0; i < graph[node].size(); i++) { //�׷����� �� ���鼭
            int next_node = graph[node][i]; //���� ��带 ã��
            indegree[next_node]--; //����� ������ ���������� 1�� ����
            if (!indegree[next_node]) //����� ������ ���������� 0�� �Ǿ��ٸ�
                q.push(next_node); //next_node�� ť�� �ִ´�.
        }
    }
    return result;//����������� ���Ե� �迭 ��ȯ
}

/**
 * �⺻���� ���� ���� ����
 * ���� ������ �ٷ� �� ���� ������ ���İ��踦 ����
 * ������ ���ϴ� ���� �Ұ����� ���(���������� �� �� ���� ���)�� ��� ������ Ž������ ���� ���
 */

int main() {
    int n, m, cnt, prev, cur; //�ʱ�ȭ

    //�Է�
    cin >> n >> m; //�Է�
    vector<int> indegree(n + 1, 0); //�迭 �ʱ�ȭ
    vector<vector<int>> graph(n + 1, vector<int>(0)); //�׷��� �ʱ�ȭ
    while (m--) { //m���� ��ŭ
        cin >> cnt; //��� ������ ��
        cin >> prev; //ó�� ���� �Է�
        while (--cnt) { //���İ��� ����
            cin >> cur; //�Է�
            indegree[cur]++; //�������� ����
            graph[prev].push_back(cur);//�׷����� �ֱ�
            prev = cur; //����
        }
    }

    //����
    vector<int> result = topologicalSort(n, indegree, graph); //���������Ѱ��� result�� ��ȯ�ޱ�

    //���
    if (result.size() != n) { //������ ���ϴ� ���� �Ұ��� ���
        cout << "0\n"; //0�� ����ϰ� 
        return 0; //��
    }
    for (int i = 0; i < result.size(); i++) //�迭���� ����ؼ�
        cout << result[i] << '\n'; //���ĵ� ���� �����ش�.
}