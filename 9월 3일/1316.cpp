#include <iostream>
#include <vector>

using namespace std;


int main() {

	int n;
	string word;
	int cnt = 0;
	cin >> n;
	while(n--)
	{
		cin >> word;
		int len = word.length();
		int flag = 1;
		for (int j = 0; j < len-1; j++)
		{
			if (word[j] != word[j + 1])
			{
				if (word.find(word[j+1])<j+1)
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