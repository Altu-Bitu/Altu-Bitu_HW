#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	int n,s,t;
	pair<int, int> p[200001];
	priority_queue<int, vector<int>, greater<int> > pq;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> s >> t;
		p[i] = { s,t }; 
	}

	sort(p, p+n); //�켱 �����ϴ� ������ ���� ����

	pq.push(p[0].second); //������ �ð� �־�α�

	for (int i = 1; i < n; i++)
	{
		if (p[i].first>= pq.top()) //���� ���� ������ �ͺ��� ���� ���� �߰��Ǵ� �����̴ʰ� �����ϸ�
		{
			pq.pop(); //���޾� �����Ұ��̴� �� �������� �ð��� �����Ѵ�.
			pq.push(p[i].second);
		}
		else
			pq.push(p[i].second); //�ƴϸ� ���ο� ���ǽ��� �ʿ��ϹǷ� ���ž��� �׳� �߰�
	}

	cout << pq.size();
	return 0;
}