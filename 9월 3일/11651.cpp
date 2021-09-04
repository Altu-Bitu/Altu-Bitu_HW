#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point {
	int x;
	int y;
};

bool cmp(const point& p1, const point& p2)
{
	if (p1.y == p2.y)
		return p1.x < p2.x;
	return p1.y < p2.y;
}

int main() {
	int n;
	cin >> n;
	vector<point> p;
	p.assign(n, {});

	for (int i = 0; i < n; i++)
		cin >> p[i].x >> p[i].y;

	sort(p.begin(), p.end(), cmp);

	for (int i = 0; i < n; i++)
		cout << p[i].x <<' '<< p[i].y << '\n';

	return 0;
}