#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int t,vector<int> a, vector<int> b)
{
	int low = 0;
	int high = b.size() - 1;
	long long result=0;
	while (low < a.size() && high >= 0) //����ũ�⳻��������
	{
		int add = a[low] + b[high]; 
		if (add == t)
		{
			long long i = 1, j = 1; //�ϴ� 1�� ã�Ұ�
			while (low < a.size() - 1 && a[low] == a[low + 1]) //�Ȱ����� �ִٸ�
			{
				++low;
				++i;
			}
			while (high >= 1 && b[high] == b[high - 1])
			{
				--high;
				++j;
			}
		
			result += i * j;
		
			++low;//��ĭ�̵�
		}
		else if (add < t)
			++low; //���� �����ϱ� Ű���ֱ�
		else
			--high; //����ũ�ϱ� �ٿ��ֱ�
	}
	return result;
}

void partsum(vector<long long> &c, vector<int> &c_list, int n)
{
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = i; j < n; j++)
		{
			sum += c[j];
			c_list.push_back(sum);
		}
	}
}

int main()
{
	int t, n,m;
	
	cin >> t >> n;
	vector<long long> a(n, 0);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> m;
	vector<long long> b(m, 0);
	for (int i = 0; i < m; i++)
		cin >> b[i];

	vector<int> a_list;
	a_list.reserve(n * n); 
	vector<int> b_list;
	b_list.reserve(m * m);
	//���� �κ��� ���ϱ�
	partsum(a, a_list, n);
	partsum(b, b_list, m);
	
	sort(a_list.begin(), a_list.end());
	sort(b_list.begin(), b_list.end()); //������Ʈ ����غ�

	long long result = solution(t,a_list, b_list);
	cout << result;
	return 0;
}//����https://ghdic.github.io/ps/boj-2143/