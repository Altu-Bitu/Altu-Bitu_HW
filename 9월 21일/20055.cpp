#include <iostream>
#include <vector>

using namespace std;
vector<pair<int, int>> a;
vector<pair<int, int>> b;
int main()
{
	//입출력 속도 향상
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k, input, cnt = 0;
	cin >> n >> k;
	a.assign(201, { 0,0 });
	b.assign(201, { 0,0 });

	for (int i = 1; i <= 2 * n; i++)
	{
		cin >> input;
		a[i].first = input;
		a[i].second = 0;

	}
	int t = 0;
	while (1)
	{
		b[1] = a[2 * n];
		for (int i = 2; i <= 2 * n; i++)
			b[i] = a[i - 1];
		for (int i = 1; i <= 2 * n; i++)
			a[i] = b[i];
		//이렇게 함으로써 한칸 회전했다.
		if (a[n].second)
			a[n].second = 0;//내릴곳에 로봇있으면 로봇 제거


		for (int i = n - 1; i >= 1; i--)
		{
			if (a[i].second)//로봇이있다면
			{
				if (!a[i + 1].second && a[i + 1].first >= 1) //앞칸에 로봇없고 내구도 1이상일때 옮기기
				{
					a[i + 1].second = 1;
					a[i + 1].first--; //내구도 감소
					a[i].second = 0; //로봇 이동했으니 사라짐

					if (a[i + 1].first == 0)
						cnt++;
				}
			}
		}
		if (a[n].second == 1)//다 끝나고 로봇 내릴거있음 내리기
			a[n].second = 0;

		if (a[1].first >= 1 && !a[1].second)
		{
			a[1].first--;
			a[1].second = 1;
			if (a[1].first == 0)
				cnt++;
		}

		t++;
		if (cnt >= k)
		{
			cout << t;
			return 0;
		}

	}

	return 0;
}