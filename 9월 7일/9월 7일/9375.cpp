#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n, a;
	cin >> n;
	string input;
	string sort;
	vector<int> cnt;
	cnt.assign(n, 1);
	for(int i=0;i<n;i++)
	{
		cin >> a;
		map<string, string> list;
		map<string, int> count;
		while (a--)
		{

			cin >> input >> sort;
			list[input] = sort;
			if (count.find(sort) == count.end()) //존재하는가?
				count[sort] = 1;
			else
				count[sort]++;
		}
		for (auto iter = count.begin(); iter != count.end(); iter++)
			cnt[i] *= iter->second + 1;	//확률식 적용

	}
	for(int i=0;i<n;i++)
		cout << cnt[i] - 1 << '\n'; //모두 선택안할경우 1 빼기
	return 0;
}