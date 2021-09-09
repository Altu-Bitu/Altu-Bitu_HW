#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()//수정한부분 float->double변경, map에 입력한게 있는지 확인하는 부분 단일화
{
	string input;
	double total = 0;
	map<string, int> list;

	while (getline(cin,input)) //한줄씩 입력받기
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