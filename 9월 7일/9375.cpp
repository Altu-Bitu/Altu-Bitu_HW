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

			cin >> input >> sort;    //�����Ѻκ�->�ʿ���� �� ���� *list[input] �׸��� �� Ȯ�� �ܼ�ȭ
			count[sort]++;
		}
		for (auto iter = count.begin(); iter != count.end(); iter++)
			cnt[i] *= iter->second + 1;	//Ȯ���� ����

	}
	for(int i=0;i<n;i++)
		cout << cnt[i] - 1 << '\n'; //��� ���þ��Ұ�� 1 ����
	return 0;
}