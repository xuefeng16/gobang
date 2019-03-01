#include<stdio.h>
#include "FiveInRow.h"

int DoubleThree(int m, int j);
int DoubleFour(int m, int j);
int Overlong(int m, int j);

int ForbiddenMove(int m, int j)   //判断禁手,三三禁手返回1，四四禁手返回2，长连禁手返回3；由于禁手要求落子位于交叉点上，因此只需扫描最后落子附近的点
{	
	if(DoubleThree(m, j))         //DoubleThree(int,int)函数，用于判断三三禁手，产生禁手返回1，否则返回0
		return 1;

	else if(DoubleFour(m, j))	  //DoubleFour(int,int)函数，用于判断四四禁手，产生禁手返回1，否则返回0
		return 2;
	
	else if(Overlong(m, j))       //Overlong(int,int)函数，用于判断长连禁手，产生禁手返回1，否则返回0
		return 3;
	
	else
		return 0;
}