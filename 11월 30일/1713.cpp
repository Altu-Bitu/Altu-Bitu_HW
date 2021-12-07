#include <iostream>
#include <vector>
#include <map>

using namespace std;
typedef pair<int, int> ci; //pair������

map<int, ci>::iterator delCandidate(map<int, ci>& candidate) {
    auto del = candidate.begin(); //ó�� �ĺ��� �����Ѵ� ����
    int cnt = candidate.begin()->second.first; //ó�� �ĺ��� ��õ Ƚ��
    int t = candidate.begin()->second.second; //ó�� �ĺ��� �Խ� �ð�
    for (auto iter = ++candidate.begin(); iter != candidate.end(); iter++) { //�ĺ� �ݺ����鼭
        int cur_cnt = iter->second.first; //��õȽ��
        int cur_t = iter->second.second; //�Խýð�
        if (cur_cnt < cnt) { //��õ Ƚ���� ���� ���� �ĺ� ã��
            cnt = cur_cnt; //��õ ȹ�� ����
            t = cur_t; //�Խýð� ����
            del = iter; //del�� �ֱ�
        }
        else if (cur_cnt == cnt && cur_t < t) { //��õ Ƚ���� ���� ���� �ĺ��� �������̶��, �Խ� �ð��� ������ �ĺ� ã��
            t = cur_t; //�Խýð� ����
            del = iter; //del�� �ֱ�
        }
    }
    return del; //��ȯ
}

/**
 * 1. ����ִ� ����Ʋ�� ���� ���, ���� ��õ���� ���� �л� �� �Խ� �ð��� ������ �л��� ����
 * 2. �ĺ� �л��� �ٷ� ã�� ���� �� Ǯ�̴� map �����̳ʸ� ����� ����
 *
 * !����! �Խ� �ð� ���� ���� ��, �ĺ��� �ö� ���� ù �ð��� ����. �̹� �ĺ��� �ִµ� �Խ� �ð��� ���ŵ��� �ʵ��� ����.
 */

int main() {
    int n, m, input; //��������

    //�Է� & ����
    cin >> n >> m;
    map<int, ci> candidate; //first: �ĺ� �л�, second: {��õ Ƚ��, �Խ� �ð�}
    for (int i = 0; i < m; i++) { //�ݺ��� ���鼭
        cin >> input; //�Է¹ޱ�
        if (candidate.size() == n && candidate.find(input) == candidate.end()) //����ִ� ����Ʋ�� ���� ���
            candidate.erase(delCandidate(candidate)); //����

        if (candidate.find(input) == candidate.end()) //ù �Խö��
            candidate[input].second = i; //�ʱ�ȭ
        candidate[input].first++; //��õ Ƚ�� ����
    }

    //���
    for (auto iter = candidate.begin(); iter != candidate.end(); iter++)
        cout << iter->first << ' '; //���� ���
}