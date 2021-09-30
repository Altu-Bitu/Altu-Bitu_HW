#include <iostream>
#include <vector>

using namespace std;

struct snake
{
	int x;
	char c;
};
int main()
{
	int n,k;
	cin >> n >> k;
	vector<pair<int, int>> apple;
	apple.assign(k, { 0,0 });
	for (int i = 0; i < k; i++)
	{
		cin >> apple[i].first >> apple[i].second;
	}
	int l;
	vector<snake> s;
	s.assign(l, { 0,' ' });
	for (int i = 0; i < l; i++)
	{
		cin >> s[i].x >> s[i].c;
	}


	return 0;
}