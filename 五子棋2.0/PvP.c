#include<stdio.h>
#include <stdlib.h>
#include "FiveInRow.h"

void PvP()   //���˶�ս
{
	struct point Point;      //���ڱ�ʾ�����ϵ����꣬Point.xΪ��, Point.yΪ��
	int count=0;
	DrawBoard();

	while(1)
	{
		count ++;
		Point = GetPoint(2);  //GetPoint���������ڵõ��û���������꣬������ĸת��Ϊ���֣�����struct point����ֵ

		if(count%2 == 1)
			Putchess(Point.x, Point.y, Black);
		else
			Putchess(Point.x, Point.y, White);

		DrawBoard();

		if ( Announce(Point.x, Point.y) == 1)	//Announce����������������Ϸ�������Ϸ�����򷵻�1
			break;	 		//���һ��ʤ������������whileѭ��
	}
}