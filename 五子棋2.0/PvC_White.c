#include<stdio.h>
#include <stdlib.h>
#include "FiveInRow.h"
void Recorder( struct point Point);

void PvC_White()      //人机对战，玩家执白子
{
	struct point Point;
	int count = 0;    //计数器，实现玩家和电脑落子的转换

	DrawBoard();
	while(1)
	{
		count ++;
		if (count%2 == 1)
		{
			Point = FindNextStep(White);       //寻找电脑下一步的位置
		}

		else
		{
			Point = GetPoint(White);           //GetPoint函数，用于得到用户输入的坐标，并将字母转化为数字，返回struct point类型值
		}

		Recorder( Point );   //记录前三步的信息，从而实现悔棋 

		if (count%2 == 1)
			Putchess( Point.x, Point.y, Black);//将得到的棋子位置放入棋盘中
		else
			Putchess( Point.x, Point.y, White);

		DrawBoard();

		if(count%2 == 1)	//输出电脑落子位置
			printf("  电脑最后落子%c%d\n",Point.y + 'A'-1, Point.x);

		if(count%2 == 0)
			Evaluate(White);//分析空位置的价值

		if ( Announce(Point.x, Point.y) == 1)  //Announce函数，用于宣布游戏结果，游戏结束则返回1
			break;			//结束while循环
	}
}