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
        for (int j = 0; j < n; j++)
        {
            if (board[n - 1 - j][i] != 0)
                list[i + 1].push(board[n - 1 - j][i]);
        }
    }

    for (int i = 0; i < moves.size(); i++)
    {
        if (!list[moves[i]].empty())
        {
            int num = list[moves[i]].top();
            list[moves[i]].pop();
            if (s.empty())
            {
                s.push(num);
            }
            else {
                if (s.top() == num)
                {
                    s.pop();
                    answer += 2;
                }
                else
                {
                    s.push(num);
                }

            }
        }
    }

    return answer;
}