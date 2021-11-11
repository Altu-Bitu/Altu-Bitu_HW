#include <iostream>

using namespace std;

typedef pair<int, pair<int, int>> ci;

ci winner(int matrix[19][19],int i, int j,ci result)
{
	int flag = 1;
	//가로
	for (int k = 1; k < 5; k++)
	{
		if (matrix[i][j + k] != matrix[i][j]) //돌이있고 같은 돌인경우
		{
			flag = 0;
			break;
		}
	}

	//6번째 확인해보기
	if (flag && matrix[i][j] == matrix[i][j + 5])
		flag = 0;

	int flag1 = 1;
	//세로
	for (int k = 1; k < 5; k++)
	{
		if (matrix[i+k][j] != matrix[i][j])
		{
			flag1 = 0;
			break;
		}
	}

	//6번째 확인해보기
	if (flag1 && matrix[i][j] == matrix[i+5][j])
		flag1 = 0;

	int flag2 = 1;
	//대각선
	for (int k = 1; k < 5; k++)
	{
		if (matrix[i + k][j+k] != matrix[i][j])
		{
			flag2 = 0;
			break;
		}
	}

	//6번째 확인해보기
	if (flag2 && matrix[i][j] == matrix[i + 5][j+5])
		flag2 = 0;

	int flag3 = 1; 
	//위로 대각선
	for (int k = 1; k < 5; k++)
	{
		if (matrix[i -k][j+k] != matrix[i][j])
		{
			flag3 = 0;
			break;
		}
	}

	//6번째 확인해보기
	if (flag3 && matrix[i][j] == matrix[i - 5][j+5])
		flag3 = 0;

	/*	if (flag && flag1 || flag && flag2 || flag&&flag3||flag1 && flag2||flag1&&flag3||flag2&&flag3) //두개이상이 겹친다면 실패
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
			cin >> matrix[i][j]; //입력받기

	//가장 왼쪽 기준으로 확인해볼때 그 돌을 기준으로 가로 세로 대각선 이 세경우만 가능
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if(matrix[i][j]!=0)//돌이 있는 경우만 확인해보기
				result = winner(matrix,i,j,result);
		}
	}

	if (result.first == 0)
		cout << result.first;
	else
		cout << result.first << '\n' << result.second.first << ' ' << result.second.second;

	return 0;
}