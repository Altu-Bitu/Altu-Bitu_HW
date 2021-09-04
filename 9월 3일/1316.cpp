#include <iostream>
#include <vector>

using namespace std;


int main() {

	int n;
	string word;
	int cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> word;
		int len = word.length();
		int flag = 1;
		for (int j = 0; j < len; j++)
		{
			if (word[j] != word[j + 1])
			{
				for (int k = 0; k < j; k++)
					if (word[k] == word[j + 1])
					{
						flag = 0;
						break;
					}
					
			}
			
		}
		if (flag)
			cnt++;

	}

	cout << cnt;
	return 0;
}