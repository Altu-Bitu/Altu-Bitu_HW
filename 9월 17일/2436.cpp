#include <iostream>
#include <cmath>

using namespace std;
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
int main()
{
	int a, b;
	cin >> a >> b;
	int num = b / a;
	int i;
	for (i = sqrt(num); i > 0; i--) //중간부터 찾기 시작해야 서로 차가 가장 적은 숫자가 나온다
		if (num % i == 0 && gcd(i, num / i) == 1) //gcd가 1이면 서로소
			break;
	cout << a * i << ' ' << a * (num / i);

	return 0;
}