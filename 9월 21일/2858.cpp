#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int r, b;
	cin >> r >> b;
	int size = r + b; //�ʺ� ����
	int l, w;
	for (int i = 1; i <=sqrt(size); i++)
	{
		if (size % i != 0) //������ �ʺ��϶�
			continue;
		int num = i + size / i - 2;
		if (r / 2 == num && b == size - 2 * num)//������ �´ٸ�
		{
			l = size / i; //i�� 1���� �߰������ε� l�� ū���̹Ƿ� size/i�� l�̴�
			w = i;
			break; //�����ϹǷ�
		
		}
	}
	cout << l << ' ' << w;

	return 0;
}