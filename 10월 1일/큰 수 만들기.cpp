#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;



string solution(string number, int k) {
    string answer = "";

    deque<char> res;
    int len = number.length() - k;
    for (int i = 0; i < number.length(); i++)
    {
        while (!res.empty() && k != 0 && res.back() < number[i])
        {
            res.pop_back();
            k--;
        }
        res.push_back(number[i]);//반복문 돌동안 계속해서 push하기


    }
    for (int i = 0; i < len; i++)
    {

        answer += res.front();
        res.pop_front();
    }
    return answer;
}

int main()
{
    
    string number;
    int k;
    cin >> number >> k;
    cout << solution(number, k);
    return 0;
}