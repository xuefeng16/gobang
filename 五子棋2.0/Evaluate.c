#include<stdio.h>
#include "FiveInRow.h"
#include "Value.h"
#include "Pattern.h"

void Evaluate_Black(int Mode);
void Evaluate_White(int Mode);
int Value[16][16]= {0};
int BoardValue [16][16] = {          //空棋盘个位置的价值，用于每次评估Value_Black和Value_White的初始化；从中心向四周值逐渐减小
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 
	{-1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{-1,0,1,2,2,2,2,2,2,2,2,2,2,2,1,0},
	{-1,0,1,2,3,3,3,3,3,3,3,3,3,2,1,0},
	{-1,0,1,2,3,4,4,4,4,4,4,4,3,2,1,0},
	{-1,0,1,2,3,4,5,5,5,5,5,4,3,2,1,0},
	{-1,0,1,2,3,4,5,6,6,6,5,4,3,2,1,0},
	{-1,0,1,2,3,4,5,6,7,6,5,4,3,2,1,0},
	{-1,0,1,2,3,4,5,6,6,6,5,4,3,2,1,0},
	{-1,0,1,2,3,4,5,5,5,5,5,4,3,2,1,0},
	{-1,0,1,2,3,4,4,4,4,4,4,4,3,2,1,0},
	{-1,0,1,2,3,3,3,3,3,3,3,3,3,2,1,0},
	{-1,0,1,2,2,2,2,2,2,2,2,2,2,2,1,0},
	{-1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};

int Value_Black[16][16] = {0};          //空位置关于黑子的值
int Value_White[16][16] = {0};			//空位置关于白子的值
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};//8个方向，4条线；相反的方向差4，因此每条线上的个数只需将相差4个的数相加即可
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};//0代表y轴正方向，1代表第一象限角平分线，2代表x轴正方向，以此类推

void Evaluate(int Mode)     //分析空位置的价值
{
	int i, j;

	Evaluate_Black( Mode);  //评价空位置关于黑子的值
	Evaluate_White( Mode);  //评价空位置关于白子的值

	for(i = 1; i<= 15; i++)
		for(j = 1; j<= 15; j++)
			Value[i][j] = Value_Black[i][j] + Value_White[i][j]; //总价值等于关于黑子和白子价值的和
}

void Evaluate_Black(int Mode)	    
{
	int i, j;
	for(i = 15; i >= 0; i --)
		for(j = 0; j <= 15; j ++)
		{
			Value_Black[i][j]= BoardValue[i][j];//对Value_Black初始化，避免其累加

			if(Position1[i][j] == 0 && Position2[i][j] == 0)   //分析空位能形成的棋形，加上对应的值，各棋形的值在Value.h中
			{
				if(DeadTwo_Black(i,j)==1)
					Value_Black[i][j] += D2;
				if(LiveTwo_Black(i,j)==1)
					Value_Black[i][j] += L2;
				if(LiveTwo_Black(i,j)>=2)
					Value_Black[i][j] += L2L2;
				if(LiveThree_Black(i,j)==1)				
					Value_Black[i][j] += L3;
				if(DeadFour_Black(i,j)==1)
					Value_Black[i][j] += D4;
				if(LiveThree_Black(i,j)>=2)
					Value_Black[i][j] += L3L3;			
				if(DeadFour_Black(i,j)>=1 &&  LiveThree_Black(i,j)>=1)
					Value_Black[i][j] += D4L3;
				if(DeadFour_Black(i,j)>=2)
					Value_Black[i][j] += D4D4;
				if(LiveFour_Black(i,j)>=1)
				{
					if(Mode == Black)
						Value_Black[i][j] += L4;
					else 
						Value_Black[i][j] += L4*2;
				}
				if(Five_Black(i,j)>=1)
				{
					if(Mode == Black)
						Value_Black[i][j] += MAX;
					else 
						Value_Black[i][j] += MAX*2;
				}
			}
			else
				Value_Black[i][j] = -1;
		}
}

void Evaluate_White(int Mode)	    
{
	int i, j;
	for(i = 15; i >= 1; i --)
		for(j = 1; j <= 15; j ++)
		{	
			Value_White[i][j]= BoardValue[i][j];//对Value_Black初始化，避免其累加
			if(Position1[i][j] == 0 && Position2[i][j] == 0)//分析空位能形成的棋形，加上对应的值，各棋形的值在Value.h中
			{	
				if(DeadTwo_White(i,j)==1)
					Value_White[i][j] += D2;
				if(LiveTwo_White(i,j)==1)
					Value_White[i][j] += L2;
				if(LiveTwo_White(i,j)>=2)
					Value_White[i][j] += L2L2;
				if(LiveThree_White(i,j)==1)				
					Value_White[i][j] += L3;
				if(DeadFour_White(i,j)==1)
					Value_White[i][j] += D4;
				if(LiveThree_White(i,j)>=2)
					Value_White[i][j] += L3L3;			
				if(DeadFour_White(i,j)>=1 &&  LiveThree_White(i,j)>=1)
					Value_White[i][j] += D4L3;
				if(DeadFour_White(i,j)>=2)
					Value_White[i][j] += D4D4;
				if(LiveFour_White(i,j)>=1)
				{
					if(Mode == Black)
						Value_White[i][j] += L4*2;
					else 
						Value_White[i][j] += L4;
				}
				if(Five_White(i,j)>=1)
				{
					if(Mode == Black)
						Value_White[i][j] += MAX*2;
					else 
						Value_White[i][j] += MAX;
				}
			}
			else
				Value_White[i][j] = -1;
		}
}