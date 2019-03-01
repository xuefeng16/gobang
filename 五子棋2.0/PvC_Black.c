#include<stdio.h>
#include <stdlib.h>
#include "FiveInRow.h"
void Recorder( struct point Point);

int Record1[2] = {0};
int Record2[2] = {0};
int Record3[2] = {0};
char B_recoder1[2] = {0};
char B_recoder2[2] = {0};

void PvC_Black()      //�˻���ս�����ִ����
{
	struct point Point;
	int count = 0;    //��������ʵ����Һ͵������ӵ�ת��

	DrawBoard();
	while(1)
	{
		count ++;
		if (count%2 == 1)
		{
			Point = GetPoint(Black);           //GetPoint���������ڵõ��û���������꣬������ĸת��Ϊ���֣�����struct point����ֵ
		}

		else
		{
			Point = FindNextStep(Black);       //Ѱ�ҵ�����һ����λ��
		}

		Recorder(Point);     //��¼ǰ��������Ϣ���Ӷ�ʵ�ֻ���       

		if (count%2 == 1)
			Putchess( Point.x, Point.y, Black);//���õ�������λ�÷���������
		else
			Putchess( Point.x, Point.y, White);

		DrawBoard();

		if(count%2 == 0)	 //�����������λ��
			printf("  �����������%c%d\n",Point.y + 'A'-1, Point.x);

		if(count%2 == 1)
			Evaluate(Black);//������λ�õļ�ֵ

		if ( Announce(Point.x, Point.y) == 1)//Announce����������������Ϸ�������Ϸ�����򷵻�1
			break;			//����whileѭ��
	}
}