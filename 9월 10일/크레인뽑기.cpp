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
        for (int j = n - 1; j >= 0; j--) //for문을 이용해 n-1이라는 필요없는 부분 단일화 수정
        {
            if (board[j][i] == 0)
                break;
            list[i + 1].push(board[j][i]); 
        }
    }

    for (int i = 0; i < moves.size(); i++)
    {
        if (list[moves[i]].empty()) //empty()check먼저 하도록 수정
            continue;

        int num = list[moves[i]].top();
        list[moves[i]].pop();
        if (!s.empty() && s.top() == num) //중복 줄임 수정
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