#include <iostream>

using namespace std;

void simulation(int n,int s,bool switches[101])
{
	for (int i = 0; i < s; i++)
	{
		int sex, num;
		cin >> sex >> num;
		if (sex == 1)//���ڸ� ����ٲ�
		{
			for (int j = num; j <= n; j += num)
			{
				switches[j] = !switches[j];
			}
		}

		else //���ڸ� �ֺ� ����ġ �¿��Ī ���� ū�ɷ�
		{
			switches[num] = !switches[num];
			int j = 1;
			while(1)//��Ī���߸� ������ Ȧ����
			{
				if (num - j < 1 || num + j > n)
					break;
				if (switches[num - j] != switches[num + j])
					break;
				switches[num - j] = !switches[num - j];
				switches[num + j] = !switches[num + j];
				j++;
			}
		}
	}

}
int main()
{
	int n;
	cin >> n;//����ġ����
	bool switches[101] = { false, }; //�ε���ó�����
	for (int i = 1; i <= n; i++)
	{
		cin >> switches[i];
	}
	int s;//student number
	cin >> s;
	simulation(n,s, switches);

	for (int i = 1; i <= n; i++)
	{
		cout << switches[i];
		if (n % 20 == 0)//20����� �����
			cout << '\n';
		else
			cout << ' ';
	}
			
	return 0;
}