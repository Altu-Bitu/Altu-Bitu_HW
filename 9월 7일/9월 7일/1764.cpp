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
	while (n--) //map�� �ֱ�
	{
		cin >> k;
		a[k] = 1;
	}
	while (m--)//���� �Ͱ� ��ġ�� �� �ִ��� Ȯ���ϱ�
	{
		cin >> k;
		if (a[k] == 1)
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