#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int t,vector<int> a, vector<int> b)
{
	int low = 0;
	int high = b.size() - 1;
	long long result=0;
	while (low < a.size() && high >= 0) //제한크기내에있을때
	{
		int add = a[low] + b[high]; 
		if (add == t)
		{
			long long i = 1, j = 1; //일단 1개 찾았고
			while (low < a.size() - 1 && a[low] == a[low + 1]) //똑같은게 있다면
			{
				++low;
				++i;
			}
			while (high >= 1 && b[high] == b[high - 1])
			{
				--high;
				++j;
			}
		
			result += i * j;
		
			++low;//한칸이동
		}
		else if (add < t)
			++low; //합이 작으니까 키워주기
		else
			--high; //합이크니까 줄여주기
	}
	return result;
}

int main()
{
	int t, n,m;
	
	cin >> t >> n;
	vector<long long> a(n, 0);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> m;
	vector<long long> b(m, 0);
	for (int i = 0; i < m; i++)
		cin >> b[i];

	vector<int> a_list;
	a_list.reserve(n * n); //왜 a_list(n*n,0)으로 하면 오류가 나나요?
	vector<int> b_list;
	b_list.reserve(m * m);
	//각각 부분합 구하기
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = i; j < n; j++)
		{
			sum += a[j];
			a_list.push_back(sum);
		}
	}
	for (int i = 0; i < m; i++)
	{
		int sum = 0;
		for (int j = i; j < m; j++)
		{
			sum += b[j];
			b_list.push_back(sum);
		}
	}
	
	sort(a_list.begin(), a_list.end());
	sort(b_list.begin(), b_list.end()); //투포인트 사용준비

	long long result = solution(t,a_list, b_list);
	cout << result;
	return 0;
}//참고https://ghdic.github.io/ps/boj-2143/