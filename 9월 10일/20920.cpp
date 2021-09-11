#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define pp pair<string,int>

using namespace std;

bool cmp(const pp &a,const pp &b) //���� ���� ����
{
	if (a.second != b.second)
		return a.second > b.second; 
	if (a.first.length() != b.first.length())
		return a.first.length() > b.first.length();
	return a.first < b.first;
}

int main()
{
	int n, m;
	
	map<string, int> word;
	string input;

	cin >> n >> m;

	while (n--)
	{
		cin >> input;
		if(input.length()>=m) //m�̻��� �ܾ �ִ´�.
			word[input]++;
	}

	vector<pp> vec(word.begin(), word.end());
	sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < vec.size(); i++)
		cout << vec[i].first << '\n';

	return 0;
}