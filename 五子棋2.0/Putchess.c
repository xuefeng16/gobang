#include <stdio.h>
#include "FiveInRow.h"

void Transform()    //将Current_chess1换成chess
{
	int a, b;

	for(a = 1; a <= 15; a ++)			
	{
		for(b = 1; b <= 15; b ++)
		{
			if(Position1[a][b]==1)
			{
				B[15-a][b*2] = chess1[0];
				B[15-a][b*2+1] = chess1[1];
			}
			if(Position2[a][b]==1)
			{
				B[15-a][b*2] = chess2[0];
				B[15-a][b*2+1] = chess2[1];
			}
		}
	}
}

void Putchess(int i, int j, int Mode)	//将输入的位置上放上棋子
{
	static int count = 0;
	Transform();		    //将Current_chess1换成chess

	if(Mode == Black)
	{
		Position1[i][j] = 1;
		B[15-i][j*2] = Current_chess1[0];
		B[15-i][j*2+1] = Current_chess1[1];
	}
	else
	{
		Position2[i][j] = 1;
		B[15-i][j*2] = Current_chess2[0];
		B[15-i][j*2+1] = Current_chess2[1];
	}
}