#include <iostream>
#include <vector>

using namespace std;
vector<int> t;

void prec() //1000������ �ԷµǹǷ� �ű������ Tn���صд�
{
	int n = 1;
	while (n * (n + 1) / 2 < 1000)
	{
		t.push_back(n * (n + 1) / 2);
		n++;
	}
}

bool check(int input) //bool�� ����
{
	for (int i = 0; i < t.size(); i++)
	{
		for (int j = 0; j < t.size(); j++)
		{
			for (int k = 0; k < t.size(); k++)
				if (t[i] + t[j] + t[k] == input) //Tn�� �ִ� ���� 3�� ���ؼ� ���� �����°�?
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