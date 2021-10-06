#include <iostream>

using namespace std;

void simulation(int n,int s,bool switches[101])
{
	for (int i = 0; i < s; i++)
	{
		int sex, num;
		cin >> sex >> num;
		if (sex == 1)//남자면 배수바꿈
		{
			for (int j = num; j <= n; j += num)
			{
				switches[j] = !switches[j];
			}
		}

		else //여자면 주변 스위치 좌우대칭 가장 큰걸로
		{
			switches[num] = !switches[num];
			int j = 1;
			while(1)//대칭맞추면 무조건 홀수됨
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
	cin >> n;//스위치개수
	bool switches[101] = { false, }; //인덱스처럼사용
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
		if (n % 20 == 0)//20배수면 끊어가기
			cout << '\n';
		else
			cout << ' ';
	}
			
	return 0;
}