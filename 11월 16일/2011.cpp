#include <iostream>
#include <vector>

using namespace std;

int MAX = 5001;
int LEFT = 1000000;
//점화식 두개
//dp[i]+=dp[i-1]->1~9사이
//dp[i]+=dp[i-2]->10~26사이

int count(vector<int> &dp,vector<int>&list,string num)
{
	for (int i = 1; i <= num.size(); i++)
	{
		list[i] = num[i - 1] - '0';
	}

	if (num.length() == 1 && num[0] == '0') //잘못된 암호일때
	{
		return 0;
	}

	dp[0]= 1;//초기설정
	if (list[1] >= 1 && list[1] <= 9)
		dp[1] = 1;
	for (int i = 2; i <= num.length(); i++)
	{
		if (list[i] >= 1 && list[i] <= 9)//한자리수면
		{
			dp[i] += dp[i - 1];//12가 있으면 1, 2로 읽으므로 바로 이전것에 해준다
			dp[i] %= LEFT;
		}

		int second = list[i] + list[i - 1] * 10; //한꺼번에 읽기위해 처리
		if (second >= 10 && second <= 26)
		{
			dp[i] += dp[i - 2]; //12가 있으면 하나로 읽으므로 두번째거 전에 것에 더해준다
			dp[i] %= LEFT;
		}
	}
	return dp[num.length()];

}

int main()
{
	string num;
	cin >> num;
	vector<int> dp(5001, 0);
	vector<int> list(num.size()+1,0);


	cout << count(dp, list,num);

	return 0;
}//참고https://yabmoons.tistory.com/163