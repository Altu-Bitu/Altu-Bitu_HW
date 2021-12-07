#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <tuple>
#include <algorithm>

using namespace std;
typedef vector<vector<int>> matrix; //���߹迭
typedef tuple<int, int, int> tp; //Ʃ�� ��� 3��

queue<tp> spring(matrix& land, deque<tp>& tree, queue<pair<int, int>>& breeding_tree) {
    queue<tp> dead_tree; //queue����
    int size = tree.size(); //size ����
    while (size--) { //��� ���� �˻�
        int age = get<0>(tree.front()); //����
        int row = get<1>(tree.front()); //��
        int col = get<2>(tree.front()); //��
        tree.pop_front(); //�տ� �ִ� ���� �����Ѵ�.

        if (land[row][col] < age) { //�ڽ��� ���̸�ŭ ����� ���� �� ���ٸ�
            dead_tree.push({ age, row, col }); //�׾��ٰ� ǥ��
            continue; //����ϱ�
        }
        land[row][col] -= age; //���̸�ŭ �����ϱ�
        tree.emplace_back(age + 1, row, col); //Ʈ���� ���� �߰�
        if ((age + 1) % 5 == 0) //���̰� 5�� ������
            breeding_tree.push({ row, col }); //���� �߰�
    }
    return dead_tree;
}

void summer(queue<tp>& dead_tree, matrix& land) {
    while (!dead_tree.empty()) { //���� ������ �ִ� �迭�� ��������ʴٸ�
        int age = get<0>(dead_tree.front()); //���� ������ ����
        int row = get<1>(dead_tree.front()); //���� ������ �� ��ġ
        int col = get<2>(dead_tree.front()); //���� ������ �� ��ġ
        dead_tree.pop(); //�ϳ��� ����
        land[row][col] += (age / 2); //land�� ����
    }
}

void fall(int n, deque<tp>& tree, queue<pair<int, int>>& breeding_tree) {
    int dr[8] = { -1, 1, 0, 0, -1, -1, 1, 1 }; //����ǥ�� �����¿� �밢��
    int dc[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };  //����ǥ�� 

    while (!breeding_tree.empty()) {
        int row = breeding_tree.front().first; //������ ������ ��
        int col = breeding_tree.front().second; //������ ������ ��
        breeding_tree.pop(); //���ĳ����� �ִ°� �ϳ�����

        for (int j = 0; j < 8; j++) { //���⵹������
            int nr = row + dr[j]; //��
            int nc = col + dc[j]; //��
            if (nr < 0 || nr >= n || nc < 0 || nc >= n) //�迭 ������ �Ѿ�ٸ� ����
                continue; //�ݺ��� �����
            tree.push_front({ 1, nr, nc }); //���� ���� ����
        }
    }
}

void winter(int n, matrix& a, matrix& land) {
    for (int i = 0; i < n; i++)  //�ݺ��� ���鼭 land ���� �߰�
        for (int j = 0; j < n; j++) //���߹ݺ���
            land[i][j] += a[i][j]; //land �߰�
}

/**
 * [���� ����] - �ܼ� ���� ����
 * ��: �ϳ��� ĭ���� ���̰� � �������� �ڽ��� ���̸�ŭ ����� �԰�, ���̰� 1 ������
 *    �� ĭ�� ����� ������ �ڽ��� ���̸�ŭ ����� �� �Դ� ������ ��� ����
 * ����: ���� ���� ������ ������� ����. ���� �������� ���̸� 2�� ���� ���� ������� �߰� (�Ҽ��� ����)
 * ����: ���̰� 5�� ����� ������ ����. ������ 8�� ĭ�� ���̰� 1�� ������ ����
 * �ܿ�: �κ�(S2D2)�� ���� ���ƴٴϸ鼭 A[r][c]��ŭ �� ĭ�� ��� �߰�
 *
 * K���� ���� �� ���� ���� ����ִ� ������ ����
 *
 * [���� Ǯ��]
 * a: �κ�(S2D2)�� �ܿ￡ �ִ� ����� ��
 * land: ���� ���
 * breeding_tree: ���̰� 5�� ����� Ʈ�� (������ Ʈ��)
 * tree: ���� ���� ���� ����, ��, �� ����
 * -> deque �����̳ʸ� Ȱ���� ������ ������ �տ� �־��ָ� �Է� �Ŀ��� �����ؼ� ��� ����
 *
 * ������ ������ ������ ������ ����
 */

int main() {
    int n, m, k, x, y, z;

    //�Է�
    cin >> n >> m >> k;
    matrix a(n, vector<int>(n, 0)); //�ʱ�ȭ
    matrix land(n, vector<int>(n, 5)); //ó�� ��� ��� ĭ�� 5
    queue<pair<int, int>> breeding_tree; //������ Ʈ��
    deque<tp> tree; //tree��ü
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j]; //�ݺ��� ���鼭 �Է¹ޱ�
    while (m--) {
        cin >> x >> y >> z; //�Է�
        tree.emplace_back(z, x - 1, y - 1); //(0, 0)���� �����ϵ��� �����ϱ����� 1�� ���� �ε����� ����
    }

    //����
    sort(tree.begin(), tree.end()); //� ���� ������ ����
    while (k--) { //k��ŭ �ݺ�����
        queue<tp> dead_tree = spring(land, tree, breeding_tree); //���� ������ ���� ����
        summer(dead_tree, land); //����
        fall(n, tree, breeding_tree); //����
        winter(n, a, land); //�ܿ�
    }

    //���
    cout << tree.size(); //���� ũ�� ���
}