#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int num(string a)
{
	int sum = 0;
	for (int i = 0; i < a.length();i++)
	{
		
		if (a[i]-'0' >=0 && a[i]-'0' < 10)
		{
			sum += a[i] - '0';
			
		}
	}
	return sum;
}

bool cmp(const string &a, const string &b)
{
	if (a.length() != b.length())
		return a.length() < b.length();

	int num_a = num(a);
	int num_b = num(b);

	if (num_a != num_b)
		return num_a < num_b;
	return a < b;

}

int main()
{
	int n;
	cin >> n;
	vector<string> a;
	a.assign(n, "");
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	sort(a.begin(), a.end(), cmp);

	for (int i = 0; i < n; i++)
		cout << a[i] << '\n';

	return 0;
}