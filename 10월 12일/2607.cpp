#include <iostream>

using namespace std;

bool cmp(int* a, int* b)
{
	int cnt = 0;
	int index = -1;
	for (int i = 0; i < 26; i++)
	{
		
		if (a[i] != b[i])
		{
			if (index == -1)
				index = i;
			if (abs(a[i] - b[i]) > 1)
				return false; //차이 두개이상 나므로 틀린거
			else
			{
				cnt++; //개수차이나는 알파벳 추가
				if (cnt == 2) //딱 두개차이날때
					if ((a[index] + a[i]) != (b[index] + b[i])) //한쪽문자에만 다른게 두개있다면
						return false;
				if (cnt > 2)
					return false;

			}
		}
	}
	return true;
}

int main()
{
	int n,cnt=0;
	int alphabet[26] = { 0 };
	cin >> n;
	string word;
	cin >> word;
	for (int j = 0; j < word.size(); j++)
		alphabet[word[j]-'A']++;
	for (int i = 1; i < n; i++)
	{
		cin >> word;
		int alphabet_cmp[26] = { 0 };
		for (int j = 0; j < word.size(); j++)
			alphabet_cmp[word[j]-'A']++;
		if (cmp(alphabet, alphabet_cmp))
			cnt++;
	}

	cout << cnt;
	return 0;
}
//참고https://jeonggyun.tistory.com/59