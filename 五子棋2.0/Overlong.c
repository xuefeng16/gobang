#include<stdio.h>
#include "FiveInRow.h"

int Overlong(int m, int j)
{
	//�������֣�ֻ���ж�����������������
	int count = 0;		//������
	int a = 0, b = 0;

	for(a = j - 5; a<= j; a++)//��
	{
		if(Position1[m][a]== 1 && Position1[m][a+1]==1 && Position1[m][a+2]==1 && Position1[m][a+3]==1 && Position1[m][a+4] ==1 && Position1[m][a+5] ==1)
			count ++;
	}

	for(a = m - 5; a<= m; a++)//��
	{
		if(Position1[a][j]== 1 && Position1[a+1][j]==1 && Position1[a+2][j]==1 && Position1[a+3][j]==1 && Position1[a+4][j]==1 && Position1[a+5][j]==1)
			count ++;
	}

	for(a = m - 5, b = j - 5; a <= m; a++, b++)//һ�����޶Խ���
	{
		if(Position1[a][b]== 1 && Position1[a+1][b+1]==1 && Position1[a+2][b+2]==1 && Position1[a+3][b+3]==1 && Position1[a+4][b+4]==1 && Position1[a+5][b+5] == 1)
			count ++;
	}

	for(a = m - 5, b = j + 5; a <= m; a++, b--)//�������޶Խ���
	{
		if(Position1[a][b]== 1 && Position1[a+1][b-1]==1 && Position1[a+2][b-2]==1 && Position1[a+3][b-3]==1 && Position1[a+4][b-4]==1 && Position1[a+5][b-5] == 1)
			count ++;
	}

	if(count >= 1)
	{
		return 2;
	}
	else
		return 0;
}