#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
	int n;
	string input;
	map<string,int> ans;
	vector<string> res;
	
	cin >> n;
	res.assign(n, "");
	string answer;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		ans[input] = i;//map에 인덱스화하기
	}

	for (int i = 0; i < n; i++)
	{
		cin >> res[i];
	}

	int point = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (ans[res[i]]<ans[res[j]]) //순서가 맞는지 확인
				point++;
		}
	}
	cout << point << '/' << n * (n - 1) / 2;





	return 0;
}