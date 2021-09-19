#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	//����� �ӵ� ���
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string str;
	vector<int> list;

	while (1)
	{
		cin >> n;
		if (n == 0)
			break;
		list.push_back(n);
	}
	int max = *max_element(list.begin(), list.end());//���� ū �Է¼��� �������� �Ҽ� �迭 ���صα�
		vector<bool> is_prime(max + 1, true);
		
		for (int i = 2; i*i <= max; i++)
		{
			if (is_prime[i]) {
				for (int j = i+i; j <= max; j += i) {
					if (!is_prime[j])
						continue;
					is_prime[j] = false;
				}
			}
	
		}
		for (int k = 0; k < list.size(); k++)
		{
			for (int i = 3; i < list[k]; i++)
			{
				if (is_prime[i]&&is_prime[list[k]-i])
				{
						int b = list[k] - i;
						str += to_string(list[k]);
						str += " = ";
						str += to_string(i);
						str += " + ";
						str += to_string(b);
						str += '\n';
						break;
				}
			}
		}

	cout << str;
	return 0;
}