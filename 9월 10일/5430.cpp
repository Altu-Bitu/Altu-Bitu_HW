#include <iostream>
#include <deque>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int t;
	int flag = 0;
	int rev = 0;
	deque<int> q1;
	deque<int> q2;
	int n;
	string s,input;
	string str,ss;
	int x = 0;
	cin >> t;
	while (t--)
	{
		cin >> input;
		cin >> n;
		cin >> s;
		for (int i = 1; i < s.length()-1; i++)
		{
			if ('0'<=s[i]&&s[i]<='9') //숫자인지 판단하기
				ss += s[i];
			else
			{
				if(ss!="")
					q1.push_back(stoi(ss));
				ss = "";
			}
		}
		if(ss!="")
			q1.push_back(stoi(ss));
		ss = "";
		
		for (int i = 0; i < input.length(); i++)
		{
			if (input[i] == 'R')
			{
				rev++;
			}

			else if (input[i] == 'D')
			{
				if (q1.empty())
				{
					flag = 1;
					str += "error\n";
					break;
				}
				else
				{
					if (rev % 2 != 0)
						q1.pop_back();
					else
						q1.pop_front();
				}
			}

		}

		if (flag == 0)//error가 아니면 숫자 배열 출력하기
		{
			if (q1.empty())
			{
				str += "[]\n";
			}
			else
			{
				int n = q1.size();
				str += "[";
				while (!q1.empty())
				{
					if (rev % 2 == 0)
					{
						str += to_string(q1.front());
						q1.pop_front();
					}

					else
					{
						str += to_string(q1.back());
						q1.pop_back();
					}
					if (q1.empty())
					{
						str += "]\n";
						break;
					}
					else
					{
						str += ",";
					}
				}
			}
		}
		rev = 0; //초기화
		flag = 0;
		
	}
	cout << str;

	return 0;
}