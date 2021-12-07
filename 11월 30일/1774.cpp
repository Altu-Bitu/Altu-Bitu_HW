#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <cmath>

using namespace std;
typedef pair<double, double> ci; //pair ci�� �缱��
typedef tuple<double, int, int> tp; //tuple ����

vector<int> parent; //parent �迭

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
        return false; //���ϹǷ� false��ȯ
    if (parent[xp] < parent[yp]) { //���ο� ��Ʈ xp
        parent[xp] += parent[yp]; //���� ��� ���� ������ �θ��Ҽ��ְ� ǥ��
        parent[yp] = xp; //xp�� �θ��
    }
    else { //���ο� ��Ʈ yp
        parent[yp] += parent[xp]; //���� ��� ���� ������ �θ��Ҽ��ְ� ǥ��
        parent[xp] = yp; //yp�� �θ��
    }
    return true; //true��ȯ
}

double kruskal(int v, priority_queue<tp, vector<tp>, greater<>>& pq) {
    int cnt = 0; //�ʱ�ȭ
    double sum = 0; //�ʱ�ȭ

    while (cnt < v - 1) { //����� ������ ���� v-1���� ���� ����
        double cost = get<0>(pq.top()); //cost�� �־��ְ�
        int x = get<1>(pq.top()); //���� x
        int y = get<2>(pq.top());//y�� �־��ش�/

        pq.pop();//���� ����
        if (unionInput(x, y)) { //���Ͽ� �ߴٸ�
            cnt++; //���� ���� ����
            sum += cost; //������ ����ġ
        }
    }
    return sum; //����ġ ��ȯ
}

/**
 * 4386�� : ���ڸ� ������� ���� ����
 * �̹� ����� �������� �����Ѵٴ� ���� �����ϰ�� 4386���� ����
 *
 * 1. ������ �� ���� ���� �Ÿ�(����) ��� ���ϱ�
 * 2. �̹� �����ϴ� ��ε� ǥ��
 *    !����! ����� ������ m����� v-m-1���� ������ �� �߰��ϸ� �ɱ�?
 *          �̹� ����� ��ε鵵 ����Ŭ�� �̷� �� �ֱ� ������ ���Ͽ� ������ �ϸ� ����Ŭ ���� ����� ������ ����
 * 3. �̹� ����� ����� ���� k����� �ϸ� v-k-1���� ������ �߰��� ����
 */
int main() {
    //�ʱ�ȭ
    int n, m, a, b, v = 0;
    priority_queue<tp, vector<tp>, greater<>> pq;

    //�Է�
    cin >> n >> m;
    parent.assign(n + 1, -1); //���ʱ�ȭ
    vector<ci> stars(n + 1); //�ʱ�ȭ
    for (int i = 1; i <= n; i++) //�Է�
        cin >> stars[i].first >> stars[i].second;


    //����
    //������ �� ���� ���� �Ÿ�(����) ��� ���ϱ�
    for (int i = 1; i <= n - 1; i++) { //�ݺ��� ���鼭
        for (int j = i + 1; j <= n; j++) {
            double xd = stars[i].first - stars[j].first; //���� ���ؼ� �־��ش�
            double yd = stars[i].second - stars[j].second; //���� ���ϱ�
            pq.push({ sqrt(xd * xd + yd * yd), i, j }); //���� ������ pq�� �־��ش�
        }
    }
    while (m--) { //m��ŭ �ݺ��� ���鼭
        cin >> a >> b; //�Է�
        if (unionInput(a, b)) //�̹� ����� ���
            v++;
    }

    //���� & ���
    cout << fixed; //�Ҽ��� ����
    cout.precision(2); //2�ڸ�����
    cout << kruskal(n - v, pq); //���
}