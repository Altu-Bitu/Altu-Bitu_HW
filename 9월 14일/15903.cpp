#include <iostream>
#include <queue>

using namespace std;

int main() //주의 할점 long long으로 받기
{
	int n, m;
	long long input,sum=0;
	cin >> n >> m;
	priority_queue<long long, vector<long long>, greater<long long>> pq;
	while (n--)
	{
		cin >> input;
		pq.push(input);
	}

	while(m--)
	{
		long long x, y;
		if (pq.size()>=2) //만약 개수 안맞으면 탈출
		{
			x = pq.top();
			pq.pop();
			y = pq.top();
			pq.pop();
		}
		else
			break;
		x = x + y;
		pq.push(x);
		pq.push(x);
	}

	while (!pq.empty())
	{
		sum += pq.top();
		pq.pop();
	}

	cout << sum;
	
	return 0;
}