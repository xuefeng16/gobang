#include<stdio.h>
#include <stdlib.h>
#include "FiveInRow.h"
void Recorder( struct point Point);

void PvC_White()      //�˻���ս�����ִ����
{
	struct point Point;
	int count = 0;    //��������ʵ����Һ͵������ӵ�ת��

	DrawBoard();
	while(1)
	{
		count ++;
		if (count%2 == 1)
		{
			Point = FindNextStep(White);       //Ѱ�ҵ�����һ����λ��
		}

		else
		{
			Point = GetPoint(White);           //GetPoint���������ڵõ��û���������꣬������ĸת��Ϊ���֣�����struct point����ֵ
		}

		Recorder( Point );   //��¼ǰ��������Ϣ���Ӷ�ʵ�ֻ��� 

		if (count%2 == 1)
			Putchess( Point.x, Point.y, Black);//���õ�������λ�÷���������
		else
			Putchess( Point.x, Point.y, White);

		DrawBoard();

		if(count%2 == 1)	//�����������λ��
			printf("  �����������%c%d\n",Point.y + 'A'-1, Point.x);

		if(count%2 == 0)
			Evaluate(White);//������λ�õļ�ֵ

		if ( Announce(Point.x, Point.y) == 1)  //Announce����������������Ϸ�������Ϸ�����򷵻�1
			break;			//����whileѭ��
	}
}