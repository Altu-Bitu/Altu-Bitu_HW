#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int SIZE = 10e6;
int dp[1000001]; //이전값을 저장해주도록하자.


void route(vector<int>&path,int n)
{
	while (n != -1)
	{
		cout << n<<' '; //시작점부터 시작
		n = path[n];//path는 n에 오기전에 들른 지점의 숫자를 저장
	}
}

void bottomup(int n)
{
	dp[1] = 0;//목적지의 dp값을 0으로 설정
	vector<int> path(SIZE + 1, -1);
	for(int i=2;i<=n;i++)
	{
		//기본값
		dp[i] = dp[i - 1] + 1;
		path[i] = i - 1;

		//3으로 나눌때
		if (i % 3 == 0)//나눠질때
		{
			if (dp[i] > dp[i / 3] + 1)//3으로 나눈것을 거쳐갈수있으면 갱신
			{
				dp[i] = dp[i / 3] + 1;
				path[i] = i / 3;
			}
		}
		//2로 나눌때
		if (i % 2 == 0)
		{
			if (dp[i] > dp[i / 2] + 1)//3으로 나눈것을 거쳐갈수있으면 갱신
			{
				dp[i] = dp[i / 2] + 1;
				path[i] = i / 2;
			}
		}

		
		
	}
	cout << dp[n] << '\n';
	route(path,n);

}

int main()
{
	int n;
	cin >> n;
	bottomup(n);
	return 0;
}