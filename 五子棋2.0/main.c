#include<stdio.h>
#include "FiveInRow.h"

int main()
{	
	int a = 0;
	DrawBoard();        //画棋盘函数
	
	printf("人人对战输入1，持黑子人机对战输入2，持白子人机对战输入3\n");
	scanf("%d", &a);
	
	while ( a < 1 || a >3)
	{
		printf("输入错误，请重新输入\n");
		scanf("%d", &a);
	}
	
	switch ( a ) 
	{
		case 1:
			PvP();	        //Player vs Player
			break;
		case 2:
			PvC_Black();    //Player(Black) vs Computer
			break;
		case 3:
			PvC_White();	//Player(White) vs Computer
	}
	while (1);
	return 0;
}

char chess1[2]="●";          //黑子
char Current_chess1[2]="▲";  //黑子当前落子
char chess2[2]="◎";          //白子
char Current_chess2[2]="△";  //白子当前落子

int Position1[16][16] = {0};  //记录黑子位置,有子的位置记为1,无子记录为0
int Position2[16][16] = {0};  //记录白子位置

char B[16][15*2+3] = {        //空棋盘
	"15┏┯┯┯┯┯┯┯┯┯┯┯┯┯┓\n",
	"14┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨\n",
	"13┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨\n",
	"12┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨\n",
	"11┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨\n",
	"10┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨\n",
	" 9┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨\n",
	" 8┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨\n",
	" 7┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨\n",
	" 6┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨\n",
	" 5┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨\n",
	" 4┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨\n",
	" 3┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨\n",
	" 2┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨\n",
	" 1┗┷┷┷┷┷┷┷┷┷┷┷┷┷┛\n",
	"  A B C D E F G H I J K L M N O \n"
	};
