#include <iostream>
#include <vector>

using namespace std;

int index[100001] = { 0 };

int solution(vector<int>& a,int n,int k)
{
	int len = 0;
	int left = 0, right = 0;
	index[a[0]]++;
	while (left <= right &&right!=n)
	{
		if (index[a[right]] > k) //개수초과하면 left 전진
		{
			index[a[left]]--;
			left++;
		}
		else
		{
			len = max(len, right - left + 1);
			right++; //더 늘리기
			if(right!=n)
				index[a[right]]++;
		}
	}
	return len;
}
int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n, 0);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	cout << solution(a,n,k);
	return 0;
} //참고https://velog.io/@kpg0518/%EB%B0%B1%EC%A4%80-20922%EB%B2%88-%EA%B2%B9%EC%B9%98%EB%8A%94-%EA%B1%B4-%EC%8B%AB%EC%96%B4