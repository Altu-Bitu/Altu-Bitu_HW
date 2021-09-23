#include <iostream>
#include <vector>

using namespace std;
vector<pair<int, int>> a;
vector<pair<int, int>> b;
int cnt = 0;
int n;
int up;
int down;

void stepOne()
{
	/*pair<int, int> temp = a[2 * n];
	for (int i = 2 * n; i >= 1; i--)
		a[i] = a[i - 1];
	a[1] = temp;
	//이렇게 함으로써 한칸 회전했다.*/
	
	up--;
	down--;
	if (up < 1)
		up = 2 * n;
	if (down < 1)
		down = 2 * n;
	
	if (a[down].second)
		a[down].second = 0;//내릴곳에 로봇있으면 로봇 제거

}

void stepTwo()
{
	int num = down;
	int next;
	while(1)
	{
		next = num;
		if (num == 1)
			num = 2 * n;
		else
			num--;
		if (a[num].second)//로봇이있다면
		{
			if (!a[next].second && a[next].first >= 1) //앞칸에 로봇없고 내구도 1이상일때 옮기기
			{
				a[next].second = 1;
				a[next].first--; //내구도 감소
				a[num].second = 0; //로봇 이동했으니 사라짐

				if (a[next].first == 0)
					cnt++;
			}
		}
		if (num == up)
			break;
	}
	if (a[down].second == 1)//다 끝나고 로봇 내릴거있음 내리기
		a[down].second = 0;
}

void stepThree()
{
	if (a[up].first >= 1 && !a[up].second)
	{
		a[up].first--;
		a[up].second = 1;
		if (a[up].first == 0)
			cnt++;
	}
}



int main()
{
	//입출력 속도 향상
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int k, input;
	cin >> n >> k;
	a.assign(201, { 0,0 });
	b.assign(201, { 0,0 });
	up = 1;
	down = n;
	for (int i = 1; i <= 2 * n; i++)
	{
		cin >> input;
		a[i].first = input;
	}
	int t = 0;
	
	while (1)
	{
		stepOne();
		stepTwo();
		stepThree();

		t++;
		if (cnt >= k)
		{
			cout << t;
			return 0;
		}

	}

	return 0;
}