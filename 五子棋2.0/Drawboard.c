#include<stdio.h>
#include <stdlib.h>
#include "FiveInRow.h"

void DrawBoard()    //画棋盘函数
{
	int i = 0, j = 0;
	int count_Black = 0, count_White = 0;//分别记录黑子和白子的个数
	static int count = 0;
	count ++;

	system("cls");
	system("color f0");

	printf("         ==五子棋游戏==\n\n\n" );
	for(i = 0; i<= 15; i++)
		for(j = 0 ; j <= 32; j++)
			printf("%c",B[i][j]);
		

	for(i = 1; i<= 15; i++)
		for(j = 1 ; j <= 15; j++)
		{
			if(Position1[i][j]== 1)
				count_Black ++;
			if(Position2[i][j]== 1)
				count_White ++;
		}
	if(count != 1)
		printf("人机模式输入R1可悔棋，但两次悔棋之间至少隔两步\n");
	if(count_Black == count_White && count != 1)
		printf("请黑子输入落子位置(字母大写)   黑子数：%d  白字数：%d\n",count_Black, count_White);
	if(count_Black > count_White)
		printf("请白子输入落子位置(字母大写)   黑子数：%d  白字数：%d\n",count_Black, count_White);
	if(count_Black == 113)
		printf("和棋\n");
}
