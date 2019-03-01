#include<stdio.h>
#include "FiveInRow.h"

void Recorder( struct point Point)   //��¼ǰ��������Ϣ���Ӷ�ʵ�ֻ��� 
{
	B_recoder2[0] = B_recoder1[0];
	B_recoder2[1] = B_recoder1[1];
		
	B_recoder1[0] = B[15-Point.x][Point.y*2];
	B_recoder1[1] = B[15-Point.x][Point.y*2+1];

	Record3[0] = Record2[0];
	Record3[1] = Record2[1];

	Record2[0] = Record1[0];
	Record2[1] = Record1[1];

	Record1[0] = Point.x;
	Record1[1] = Point.y;
}

void Retract(int Mode)       //���壬�������λ���֮�����ٸ�����
{
	if(Mode == White)
	{	
			Position1[Record1[0]][Record1[1]] = 0;
			Position2[Record2[0]][Record2[1]] = 0;

			B[15-Record1[0]][Record1[1]*2] = B_recoder1[0];
			B[15-Record1[0]][Record1[1]*2+1] = B_recoder1[1];

			B[15-Record2[0]][Record2[1]*2] = B_recoder2[0];
			B[15-Record2[0]][Record2[1]*2+1] = B_recoder2[1];

			B[15-Record3[0]][Record3[1]*2] = Current_chess1[0];
			B[15-Record3[0]][Record3[1]*2+1] = Current_chess1[1];	

			Putchess(Record3[0],Record3[1],Black);
		}

	if(Mode == Black)
	{	
		Position2[Record1[0]][Record1[1]] = 0;
		Position1[Record2[0]][Record2[1]] = 0;

		B[15-Record1[0]][Record1[1]*2] = B_recoder1[0];
		B[15-Record1[0]][Record1[1]*2+1] = B_recoder1[1];

		B[15-Record2[0]][Record2[1]*2] = B_recoder2[0];
		B[15-Record2[0]][Record2[1]*2+1] = B_recoder2[1];

		B[15-Record3[0]][Record3[1]*2] = Current_chess2[0];
		B[15-Record3[0]][Record3[1]*2+1] = Current_chess2[1];

		Putchess(Record3[0],Record3[1],White);
	}

	DrawBoard();
}