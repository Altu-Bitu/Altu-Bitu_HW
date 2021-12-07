#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;
typedef tuple<int, int, int> tp; //Ʃ�� ����

vector<int> parent; //�θ� �迭

//Find ����
int findParent(int node) {
    if (parent[node] < 0) //���� ������ ��Ʈ ����
        return node; //node ��ȯ
    return parent[node] = findParent(parent[node]); //�׷��� �����ϸ� ��Ʈ ���� ã��
}

//Union ����
bool unionInput(int x, int y) {
    int xp = findParent(x); //�θ�ã��
    int yp = findParent(y); //�θ�ã��

    if (xp == yp) //���� ���տ� �ִٸ� ���Ͽ� �� �� ����
        return false; //���Ͽ� �Ұ�
    if (parent[xp] < parent[yp]) { //���ο� ��Ʈ xp
        parent[xp] += parent[yp]; //��尳�� ǥ��
        parent[yp] = xp; //xp�� �θ��
    }
    else { //���ο� ��Ʈ yp
        parent[yp] += parent[xp]; //��尳�� ǥ��
        parent[xp] = yp; //yp�� �θ��
    }
    return true; //���Ͽ�����
}

int kruskal(int n, int idx, vector<tp>& edges) {
    int cnt = 0, sum = 0; //�ʱ�ȭ
    for (int i = idx; i < edges.size(); i++) {
        if (cnt == n - 1) //n-1���� ������ ��� ������
            break;//�ߴ�
        int dist = get<0>(edges[i]); //Ʃ�ð� �޾ƿ���
        int x = get<1>(edges[i]);//Ʃ�ð� �޾ƿ���
        int y = get<2>(edges[i]);//Ʃ�ð� �޾ƿ���

        if (unionInput(x, y)) { //union�ϱ�
            cnt++; //���� �߰�
            sum += dist; //�Ÿ� ����
        }
    }
    if (cnt < n - 1) //mst�� ���� �� ����
        return 0; //0���� ǥ��
    return sum; //�Ÿ� ��ȯ
}

/**
 * MST �˰����� ���� �� �����ص� �ɱ�?
 * 1. ũ�罺Į �˰����� �ð� ���⵵�� O(ElogE)
 *    �̴� ���� ������ �����ϴ� ������ �ð� ���⵵!
 *    ��, ��� ������ �� �� �����ؼ� �����صθ� ���� �� ���� �˰����� �����Ͽ��� ���� �ð��� ū ������ ����
 * 2. ���� ������ ���� �켱���� ť�� �ƴ� ���Ϳ� �����ϰ� ũ�罺Į �˰��� k�� ����
 * 3. �Ź� ũ�罺Į�� ������ ������ ���� ���� �߰��� ������ ������
 *    -> ���ܵ� ������ �迭�� 0��° �������� 1, 2, 3��° �������� ������ ����
 * 4. ���� �� �� MST�� ���� �� ���ٴ°� Ȯ�εƴٸ� ���Ŀ��� MST�� ���� �� �����Ƿ� flag ������ ���ʿ��� ���� ����
 */
int main() {
    int n, m, k, x, y; //�ʱ�ȭ

    cin >> n >> m >> k; //�Է�
    vector<tp> edges; //�����ҰŶ� �켱���� ť�� �ƴ� ���Ϳ� ����
    for (int i = 1; i <= m; i++) { //�ݺ�
        cin >> x >> y; //�Է�
        edges.emplace_back(i, x, y); //Ʃ�ú��Ϳ� �־��ش�
    }

    bool flag = false; //flag
    for (int i = 0; i < k; i++) { //�ݺ����鼭 mst�����
        if (flag) { //���̻� mst�� ���� �� ����
            cout << 0 << ' ';
            continue;
        }
        parent.assign(n + 1, -1); //�ʱ�ȭ
        int ans = kruskal(n, i, edges); //sum�ޱ�
        if (ans == 0) //0�̸� mst�� ��������ٴ� ������ flagǥ��
            flag = true; //true�� �ؼ� ������ conitnue�ϵ��� �����
        cout << ans << ' '; //ans���
    }
}