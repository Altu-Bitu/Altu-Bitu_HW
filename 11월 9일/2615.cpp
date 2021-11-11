#include <iostream>

using namespace std;

typedef pair<int, pair<int, int>> ci;

ci winner(int matrix[19][19],int i, int j,ci result)
{
	int flag = 1;
	//����
	for (int k = 1; k < 5; k++)
	{
		if (matrix[i][j + k] != matrix[i][j]) //�����ְ� ���� ���ΰ��
		{
			flag = 0;
			break;
		}
	}

	//6��° Ȯ���غ���
	if (flag && matrix[i][j] == matrix[i][j + 5])
		flag = 0;

	int flag1 = 1;
	//����
	for (int k = 1; k < 5; k++)
	{
		if (matrix[i+k][j] != matrix[i][j])
		{
			flag1 = 0;
			break;
		}
	}

	//6��° Ȯ���غ���
	if (flag1 && matrix[i][j] == matrix[i+5][j])
		flag1 = 0;

	int flag2 = 1;
	//�밢��
	for (int k = 1; k < 5; k++)
	{
		if (matrix[i + k][j+k] != matrix[i][j])
		{
			flag2 = 0;
			break;
		}
	}

	//6��° Ȯ���غ���
	if (flag2 && matrix[i][j] == matrix[i + 5][j+5])
		flag2 = 0;

	int flag3 = 1; 
	//���� �밢��
	for (int k = 1; k < 5; k++)
	{
		if (matrix[i -k][j+k] != matrix[i][j])
		{
			flag3 = 0;
			break;
		}
	}

	//6��° Ȯ���غ���
	if (flag3 && matrix[i][j] == matrix[i - 5][j+5])
		flag3 = 0;

	/*	if (flag && flag1 || flag && flag2 || flag&&flag3||flag1 && flag2||flag1&&flag3||flag2&&flag3) //�ΰ��̻��� ��ģ�ٸ� ����
		return result;
	else if (!flag && !flag1 && !flag2&&!flag3)
		return result;
	else*/
	if(flag||flag1||flag2||flag3)
	{
		if (matrix[i][j] == 1)
			result = { 1,{i + 1,j + 1} };
		else
			result = { 1,{i + 1,j + 1} };
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