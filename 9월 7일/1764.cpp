#include <iostream>
#include <set>
#include <map>
using namespace std;

int main() {

	int n, m;
	//map<string,int> a;
	set<string>a;
	set<string>b;
	string k;
	int cnt = 0;
	cin >> n >> m;
	while (n--) //map�� �ֱ�
	{
		cin >> k;
		a.insert(k);
	}
	while (m--)//���� �Ͱ� ��ġ�� �� �ִ��� Ȯ���ϱ�
	{
		cin >> k;
		if (a.count(k))
		{
			cnt++;
			b.insert(k);//�ڵ� ����
		}
	}
	cout << cnt << '\n';
	for (auto iter = b.begin(); iter != b.end(); iter++)
		cout << *iter << '\n';




	return 0;
}