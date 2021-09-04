#include <iostream>
#include <vector>

using namespace std;

vector<int> a;

int main()
{
	int n,b,c;
	long long num = 0;

	cin >> n;
	a.assign(n, 0);
	
	for(int i=0;i<n;i++)
		cin >> a[i];
	cin >> b >> c;
	for (int i = 0; i < n; i++)
	{
		a[i]=a[i]-b;
		num++;
		if (a[i] > 0)
		{
			if (a[i] % c == 0)
				num += (a[i] / c);
			else
			{
				num += (a[i] / c);
				num += 1;
			}
		}
	}
	cout << num;

	return 0;
}