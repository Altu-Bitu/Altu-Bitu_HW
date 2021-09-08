#include <iostream>
#include <set>
#include <map>
using namespace std;

int main() {

	int n, m;
	map<string,int> a;
	set<string>b;
	string k;
	int cnt = 0;
	cin >> n >> m;
	while (n--) //map에 넣기
	{
		cin >> k;
		a[k] = 1;
	}
	while (m--)//넣은 것과 겹치는 거 있는지 확인하기
	{
		cin >> k;
		if (a[k] == 1)
		{
			cnt++;
			b.insert(k);//자동 정렬
		}
	}
	cout << cnt << '\n';
	for (auto iter = b.begin(); iter != b.end(); iter++)
		cout << *iter << '\n';




	return 0;
}