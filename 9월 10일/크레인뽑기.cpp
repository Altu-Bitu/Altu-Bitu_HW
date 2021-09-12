#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    stack<int> s;
    stack<int> list[31];
    int n = board[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j >= 0; j--) //for���� �̿��� n-1�̶�� �ʿ���� �κ� ����ȭ ����
        {
            if (board[j][i] == 0)
                break;
            list[i + 1].push(board[j][i]); 
        }
    }

    for (int i = 0; i < moves.size(); i++)
    {
        if (list[moves[i]].empty()) //empty()check���� �ϵ��� ����
            continue;

        int num = list[moves[i]].top();
        list[moves[i]].pop();
        if (!s.empty() && s.top() == num) //�ߺ� ���� ����
        {
            s.pop();
            answer += 2;
        }
        else
        {
            s.push(num);
        }

    }


    return answer;
}