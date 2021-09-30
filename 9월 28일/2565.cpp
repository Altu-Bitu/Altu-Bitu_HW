#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct line
{
	int a, b;
};

bool cmp(const line& l1, const line& l2)
{
	return l1.a < l2.a;
}

int main()
{
	int n;
	vector<line> list;
	cin >> n;
	list.assign(n, { 0,0 });
	for (int i = 0; i < n; i++)
		cin >> list[i].a >> list[i].b;
	sort(list.begin(), list.end(), cmp); //a를 오름차순으로 정렬 그러면 b만 비교하면됨

	vector<int> length;
	length.assign(n, 0);
	for (int i = 0; i < n; i++)
	{
		length[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (list[j].b < list[i].b)
				length[i] = max(length[i], length[j] + 1);//만약 추가될수 있는 전깃줄이라면 추가하는게 이득인지 아닌지 판단
		}
	}

	cout << n-length[n - 1]; //최대 배열을 전체에서 빼면 빠지는 전깃줄 파악가능
	return 0;
}