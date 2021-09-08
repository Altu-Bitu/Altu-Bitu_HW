#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
	int w0, i0, t, d, i, a;
	
		cin >> w0 >> i0 >> t;//값 입력받기
		cin >> d >> i >> a;


		int i1 = i0; //변하는 것
		int i2 = i0; //변하지 않는 것
		int w1 = w0; //일일기초대사량 변화할때 체중
		int w2 = w0; //변하지 않을때 체중
		int flag = 0; //죽는지 아닌지 판별

		while (d--)
		{
			w1 += i - (i1 + a);
			w2 += i - (i2 + a);

			if (abs(i - (i1 + a)) > t) //역치 넘는지 판단
			{
				i1 += (int)floor((i - (i1 + a)) / 2.0);
			}

			if (w1 <= 0 || i1 <= 0)
				flag = 2;

			if (w2 <= 0 || i2 <= 0)
				flag = 1;

		}
		if (flag == 1)
			cout << "Danger Diet\n";
		else
			cout << w2 << ' ' << i2 << '\n';

		if (flag == 2)
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