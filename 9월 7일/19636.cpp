#include <iostream>
#include <cmath>
using namespace std;

int main() //������ �κ�: flag�� ���Ĺ����� �Ѵ� danger diet���� Ȯ���Ҷ� �����߻�->result1,result2�� ����
{
	int w0, i0, t, d, i, a;
	
		cin >> w0 >> i0 >> t;//�� �Է¹ޱ�
		cin >> d >> i >> a;


		int i1 = i0; //���ϴ� ��
		int i2 = i0; //������ �ʴ� ��
		int w1 = w0; //���ϱ��ʴ�緮 ��ȭ�Ҷ� ü��
		int w2 = w0; //������ ������ ü��
		int result1 = 0; //�״��� �ƴ��� �Ǻ�
		int result2 = 0;
		while (d--)
		{
			w1 += i - (i1 + a);
			w2 += i - (i2 + a);

			if (abs(i - (i1 + a)) > t) //��ġ �Ѵ��� �Ǵ�
			{
				/*int num = i - (i1 + a);
				if (num < 0 && num % 2 != 0)
					i1 += (num / 2 - 1);
				else
					i1 += num / 2;
				*/
				i1 += (int)floor((i - (i1 + a)) / 2.0);
			}

			if (w1 <= 0 || i1 <= 0)
			{
				result1 = 2; 
			}

			if (w2 <= 0 || i2 <= 0)
			{
				result2 = 1;
			}

		}
		if (result2 == 1)
			cout << "Danger Diet\n";
		else
			cout << w2 << ' ' << i2 << '\n';

		if (result1 == 2)
		{
			cout << "Danger Diet";

		}
		else
		{
			cout << w1 << ' ' << i1 << ' ';

			if (i0 - i1 > 0)
				cout << "YOYO";
			else
				cout << "NO";
		}
	
	return 0;
}