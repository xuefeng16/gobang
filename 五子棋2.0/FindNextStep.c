#include<stdio.h>
#include <stdlib.h>
#include "FiveInRow.h"

struct point FindNextStep(int Mode) //����Ѱ����һ��λ��
{
	int i, j;
	struct point Position = {8, 8}; //��ʼ�������������� 

	for(i = 1; i<= 15; i++)
		for(j = 1; j<= 15; j++)
		{
			if(Position1[i][j] == 0 && Position2[i][j] ==0)
			{
				if(Mode == Black)
				{
					if( Value[i][j] > Value[Position.x][Position.y] )
					{
						Position.x = i;
						Position.y = j;
					}
				}
				if(Mode == White)
				{	
					Position1[i][j] = 1;   //Ϊ�˼����һ���Ƿ���֣���Ҫ��Position[i][j]��Ϊ1��Ȼ���ڸĻ�0
					if( (Value[i][j] > Value[Position.x][Position.y]) && ForbiddenMove(i,j) != 3 ) //�������Ϊ���ӣ������߽��ֵ�λ��
					{
						if( Judge(Position1,i,j) == 1 ||( ForbiddenMove(i,j) != 1 && ForbiddenMove(i,j) != 2) )
						{
							Position.x = i;
							Position.y = j;
						}
					}
					Position1[i][j] = 0;
				}
			}
		}
	return Position;
}