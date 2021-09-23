#include <iostream>
#include <vector>

using namespace std;
vector<int> t;

void prec() //1000까지만 입력되므로 거기까지만 Tn구해둔다
{
	int n = 1;
	while (n * (n + 1) / 2 < 1000)
	{
		t.push_back(n * (n + 1) / 2);
		n++;
	}
}

bool check(int input) //bool로 수정
{
	for (int i = 0; i < t.size(); i++)
	{
		for (int j = 0; j < t.size(); j++)
		{
			for (int k = 0; k < t.size(); k++)
				if (t[i] + t[j] + t[k] == input) //Tn에 있는 것중 3개 더해서 값이 나오는가?
					return 1;
		}
	}
	return 0;
}

int main()//**
{
	int k,input;
	vector<int>a;
	cin >> k;
	prec();
	while(k--)
	{
		cin >> input;
		a.push_back(check(input));
	}
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << '\n';
	return 0;
}