#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	string input;
	float total = 0;
	map<string, int> list;

	while (getline(cin,input)) //한줄씩 입력받기
	{
		total++;
		if (list.find(input)==list.end()) //개수 세기
			list[input] = 1;
		else
			list[input]++;
	}

	cout << fixed;
	cout.precision(4);
	for (auto iter = list.begin(); iter != list.end(); iter++)
		cout << iter->first << ' '<<(iter->second)/total*100.0<<'\n';
	return 0;
}