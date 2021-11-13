#include <iostream>

using namespace std;

typedef pair<int, pair<int, int>> ci;

ci winner(int matrix[19][19],int i, int j,ci result)
{
	int flag = 1;
	//����
	for (int k = 1; k < 5; k++)
	{
		if (j + k >= 19)
		{
			flag = 0;
			break;
		}
		if (matrix[i][j + k] != matrix[i][j]) //�����ְ� ���� ���ΰ��
		{
			flag = 0;
			break;
		}
	}

	//-1,6��° Ȯ���غ���
	if (j+5<19&&flag && matrix[i][j] == matrix[i][j + 5])
		flag = 0;
	if (j-1>=0&&flag && matrix[i][j] == matrix[i][j-1])
		flag = 0;

	int flag1 = 1;
	//����
	for (int k = 1; k < 5; k++)
	{
		if (i + k >= 19)
		{
			flag1 = 0;
			break;
		}
		if (matrix[i+k][j] != matrix[i][j])
		{
			flag1 = 0;
			break;
		}
	}

	//-1,6��° Ȯ���غ���
	if (i+5<19&&flag1 && matrix[i][j] == matrix[i+5][j])
		flag1 = 0;
	if (i-1>=0&&flag1 && matrix[i][j] == matrix[i-1][j])
		flag1 = 0;

	int flag2 = 1;
	//�Ʒ��밢��
	for (int k = 1; k < 5; k++)
	{
		if (i + k >= 19 || j + k >= 19)
		{
			flag2 = 0;
			break;
		}
		if (matrix[i + k][j+k] != matrix[i][j])
		{
			flag2 = 0;
			break;
		}
	}

	//-1,6��° Ȯ���غ���
	if (i+5<19&&j+5<19&&flag2 && matrix[i][j] == matrix[i + 5][j+5])
		flag2 = 0;
	if (i-1>=0&&j-1>=0&&flag2 && matrix[i][j] == matrix[i-1][j-1])
		flag2 = 0;
	
	int flag3 = 1; 
	//���� �밢��
	for (int k = 1; k < 5; k++)
	{
		if (i - k<0 || j + k>=19)
		{
			flag3 = 0;
			break;
		}
		if (matrix[i -k][j+k] != matrix[i][j])
		{
			flag3 = 0;
			break;
		}
	}

	//-1,6��° Ȯ���غ���
	if (i-5>=0&&j+5<19&&flag3 && matrix[i][j] == matrix[i - 5][j+5])
		flag3 = 0;
	if (i+1<19&&j-1>=0&&flag3 && matrix[i][j] == matrix[i + 1][j - 1])
		flag3 = 0;

	if(flag||flag1||flag2||flag3)//���õǴ� ���� ���⶧���� 4���� �ϳ��� 1�̸� �ȴ�
	{
		if (matrix[i][j] == 1)
			result = { 1,{i + 1,j + 1} };
		else
			result = { 2,{i + 1,j + 1} };
	}

	return result;
}

int main()
{
	ci result;
	result = { 0,{-1,-1} };
	int matrix[19][19];
	for (int i = 0; i < 19; i++)
		for (int j = 0; j < 19; j++)
			cin >> matrix[i][j]; //�Է¹ޱ�

	//���� ���� �������� Ȯ���غ��� �� ���� �������� ���� ���� �밢�� �� ����츸 ����
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if(matrix[i][j]!=0)//���� �ִ� ��츸 Ȯ���غ���
				result = winner(matrix,i,j,result);
		}
	}

	if (result.first == 0)
		cout << result.first;
	else
		cout << result.first << '\n' << result.second.first << ' ' << result.second.second;

	return 0;
}