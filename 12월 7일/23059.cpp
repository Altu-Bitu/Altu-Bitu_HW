#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>

using namespace std;

unordered_map<string, int> indegree;
unordered_map<string, vector<string>> graph;

//��������
vector<string> topologicalSort(set<string>& item) {
    vector<string> result; //result�迭
    priority_queue<string, vector<string>, greater<>> pq, pq_temp; //�켱���� ť

    for (auto iter = item.begin(); iter != item.end(); iter++) { //������ Ȯ���ϸ鼭
        if (indegree.find(*iter) == indegree.end()) //���������� �������� �ʴ´ٸ�(0 �̶��)
            pq.push(*iter); //ť�� �ִ´�.
    }
    while (!pq.empty()) { //��������ʴٸ�
        string node = pq.top(); //node�� top(�����ִ� ���� �ְ�)
        pq.pop(); //ť���� �����Ѵ�

        result.push_back(node); //���� ���� ������ ����
        for (int i = 0; i < graph[node].size(); i++) { //�� �������� ����� �������Ȯ��
            string next_node = graph[node][i]; //���� ��� �湮
            indegree[next_node]--; //����� ������ ���������� 1�� ����
            if (indegree[next_node] == 0) //����� ������ ���������� 0�� �Ǿ��ٸ�
                pq_temp.push(next_node); //�켱 pq_temp�� ����
        }
        if (pq.empty() && !pq_temp.empty()) //������ ���������� 0�̿��� ������ ��� Ž���߰�, ���� Ž���� ������ �ִٸ�
            swap(pq, pq_temp); //swap
    }
    return result; //result�迭 ��ȯ
}

/**
 * ���ڿ��� �ε����� ����ؾ� �ϱ⶧���� map�� ���
 *
 * !����! �Ϲ� map�� ����ϸ� �ð��ʰ�. ���� map���� �˻� �ӵ��� ���� unordered_map ����ؾ� ��
 *       -> map�� ���� Ž�� Ʈ�� ���·� key���� �����ؼ� �ð� ���⵵�� logN ������, unordered_map�� hash���·� �����ؼ� �ð� ���⵵�� 1�̴�
 * !����! ���� ������ �� �� ������ ���� ����� ���������� �ش� ������ ������ġ�� �߿� (������ ���� 3 ����)
 *       1. ���������� 0�� �����鳢�� �����ؼ� ����ؾ� ��
 *       2. ���������� 0�� ������ ���ÿ� ���� ���� ��� �ش� �������� ���� ������ ��ġ�ؾ� ��.
 *      -> ���� �켱���� ť�� ����Ͽ� ���������� 0�� �������� ����. �̶� ���ÿ� ���������� 0�� �� �������� ���� ��ġ�ؾ� �ϹǷ� �켱���� ť�� 2�� ���.
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    set<string> item; //�����ϴ� ������(����)
    int n; 
    string a, b;

    //�Է�
    cin >> n;
    while (n--) { //�Է¼���ŭ ��� �Է�
        cin >> a >> b; //a < b
        indegree[b]++; //�������� ����
        graph[a].push_back(b); //�ܹ��� �׷���
        item.insert(a); //������ ����
        item.insert(b); //������ ����
    }

    //����
    vector<string> result = topologicalSort(item);

    //���
    if (result.size() != item.size()) {
        cout << "-1\n"; //-1���
        return 0; //��
    }
    for (int i = 0; i < result.size(); i++) //�迭 ũ�⸸ŭ ���鼭
        cout << result[i] << '\n'; //�迭 ���

    return 0; //��
}