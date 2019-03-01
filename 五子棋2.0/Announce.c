#include<stdio.h>
#include "FiveInRow.h"

int Announce (int i, int j) //Announce函数，用于宣布游戏结果
{
	static int count = 0;
	count ++;               //单数判断黑棋,双数判断白棋

	if(count%2 == 1) 
	{
		if(Judge(Position1, i, j) == 1 && ForbiddenMove(i,j) != 3)  //五连与三三、四四禁手同时成立禁手失效，因此先判断是否五连，再判断禁手
		{															//ForbiddenMove函数，用于判断禁手
			printf("黑棋获胜!\n");
			return 1;
		}
		if(ForbiddenMove(i,j) == 1)				
		{
			printf("三三禁手，白棋胜\n");
			return 1;  
		}
		if(ForbiddenMove(i,j) == 2)
		{
			printf("四四禁手，白棋胜\n");
			return 1;  
		}
		if(ForbiddenMove(i,j) == 3)
		{
			printf("长连禁手，白棋胜\n");
			return 1; 
		}
		else
			return 0;
	}

	if(count%2 == 0)
	{
		if(Judge(Position2, i, j))    //Judge函数用于判断是否形成五连
		{	
			printf("白棋获胜!\n");
			return 1; 
		}
		else
			return 0;
	}

	return 0;
}