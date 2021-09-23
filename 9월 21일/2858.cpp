#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int r, b;
	cin >> r >> b;
	int size = r + b; //너비를 구함
	int l, w;
	for (int i = 1; i <=sqrt(size); i++)
	{
		if (size % i != 0) //가능한 너비일때
			continue;
		int num = i + size / i - 2;
		if (r / 2 == num && b == size - 2 * num)//개수가 맞다면
		{
			l = size / i; //i가 1부터 중간까지인데 l이 큰쪽이므로 size/i가 l이다
			w = i;
			break; //유일하므로
		
		}
	}
	cout << l << ' ' << w;

	return 0;
}