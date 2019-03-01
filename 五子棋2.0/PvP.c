#include<stdio.h>
#include <stdlib.h>
#include "FiveInRow.h"

void PvP()   //人人对战
{
	struct point Point;      //用于表示棋盘上的坐标，Point.x为行, Point.y为列
	int count=0;
	DrawBoard();

	while(1)
	{
		count ++;
		Point = GetPoint(2);  //GetPoint函数，用于得到用户输入的坐标，并将字母转化为数字，返回struct point类型值

		if(count%2 == 1)
			Putchess(Point.x, Point.y, Black);
		else
			Putchess(Point.x, Point.y, White);

		DrawBoard();

		if ( Announce(Point.x, Point.y) == 1)	//Announce函数，用于宣布游戏结果，游戏结束则返回1
			break;	 		//如果一方胜利或和棋则结束while循环
	}
}