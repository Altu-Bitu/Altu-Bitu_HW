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
				return false; //���� �ΰ��̻� ���Ƿ� Ʋ����
			else
			{
				cnt++; //�������̳��� ���ĺ� �߰�
				if (cnt == 2) //�� �ΰ����̳���
					if ((a[index] + a[i]) != (b[index] + b[i])) //���ʹ��ڿ��� �ٸ��� �ΰ��ִٸ�
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
//����https://jeonggyun.tistory.com/59