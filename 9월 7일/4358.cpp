#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()//�����Ѻκ� float->double����, map�� �Է��Ѱ� �ִ��� Ȯ���ϴ� �κ� ����ȭ
{
	string input;
	double total = 0;
	map<string, int> list;

	while (getline(cin,input)) //���پ� �Է¹ޱ�
	{
		total++;
		list[input]++; 
	}

	cout << fixed;
	cout.precision(4);
	for (auto iter = list.begin(); iter != list.end(); iter++)
		cout << iter->first << ' '<<(iter->second)/total*100.0<<'\n';
	return 0;
}