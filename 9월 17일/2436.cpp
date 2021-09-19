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
	for (i = sqrt(num); i > 0; i--) //�߰����� ã�� �����ؾ� ���� ���� ���� ���� ���ڰ� ���´�
		if (num % i == 0 && gcd(i, num / i) == 1) //gcd�� 1�̸� ���μ�
			break;
	cout << a * i << ' ' << a * (num / i);

	return 0;
}