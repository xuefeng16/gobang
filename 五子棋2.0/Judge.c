#include<stdio.h>
#include "FiveInRow.h"

int Judge(int Position[16][16], int i, int j)  //Judge���������ж��Ƿ��γ�����
{											   //ֻ��ɨ���������λ�Ӹ��������Ӽ���
	int a = 0, b = 0;
	for(a = j - 4; a<= j; a++)//��
	{
		if(a>= 1 && a+4 <= 15 && Position[i][a]== 1 && Position[i][a+1]==1 && Position[i][a+2]==1 && Position[i][a+3]==1 && Position[i][a+4] ==1)
		{
			return 1;
		}
	}

	for(a = i - 4; a<= i; a++)//��
	{
		if(a >= 1 && a+4 <= 15 && Position[a][j]== 1 && Position[a+1][j]==1 && Position[a+2][j]==1 && Position[a+3][j]==1 && Position[a+4][j]==1)
		{
			return 1;
		}
	}

	for(a = i - 4, b = j - 4; a <= i; a++, b++)//һ�����޶Խ���
	{
		if(a >= 1 && b >= 1 && a+4 <= 15 && b+4 <= 15 && Position[a][b]== 1 && Position[a+1][b+1]==1 && Position[a+2][b+2]==1 && Position[a+3][b+3]==1 && Position[a+4][b+4]==1)
		{
			return 1;
		}
	}

	for(a = i - 4, b = j + 4; a <= i; a++, b--)//�������޶Խ���
	{
		if(a >= 1 && b <= 15 && a+4 <=15 && b-4>=1 && Position[a][b]== 1 && Position[a+1][b-1]==1 && Position[a+2][b-2]==1 && Position[a+3][b-3]==1 && Position[a+4][b-4]==1)
		{
			return 1;
		}
	}

	return 0;
}
