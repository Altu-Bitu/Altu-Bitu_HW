#include <iostream>
#include <deque>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int t;
	int flag = 0;
	int r_flag = 0;
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
			if (s[i] != ',')
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
				if (rev % 2 != 0) //r�� Ȧ������->r�� �Ѱ��ΰ�ó��
					r_flag = 1;
				else
					r_flag = 2; //r�� ¦������->r�� 0���ΰ� ó��
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
					if (r_flag == 1)
						q1.pop_back();
					else if(r_flag==2)
						q1.pop_front();
				}
			}

			

			/*else if (input[i] == 'R')
			{
				while(!q1.empty())
				{
					q2.push_back(q1.back());
					q1.pop_back();
				}

				while(!q2.empty())
				{
					q1.push_back(q2.front());
					q2.pop_front();
				}
			}*/

		}

		if (flag == 0)//error�� �ƴϸ� ���� �迭 ����ϱ�
		{
			int n = q1.size();
			str += "[";
			while(!q1.empty())
			{
				if (r_flag == 2)
				{
					str += to_string(q1.front());
					q1.pop_front();
				}

				if (r_flag == 1)
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
		rev = 0; //�ʱ�ȭ
		flag = 0;
		
	}
	cout << str;

	return 0;
}