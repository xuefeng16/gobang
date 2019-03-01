#include<stdio.h>
#include <stdlib.h>
#include "FiveInRow.h"

struct point FindNextStep(int Mode) //电脑寻找下一步位置
{
	int i, j;
	struct point Position = {8, 8}; //初始定义在棋盘中心 

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
					Position1[i][j] = 1;   //为了检测下一步是否禁手，需要将Position[i][j]改为1，然后在改回0
					if( (Value[i][j] > Value[Position.x][Position.y]) && ForbiddenMove(i,j) != 3 ) //如果电脑为黑子，则不能走禁手的位置
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