#include<stdio.h>
#include "FiveInRow.h"
#include "Value.h"
#include "Pattern.h"

void Evaluate_Black(int Mode);
void Evaluate_White(int Mode);
int Value[16][16]= {0};
int BoardValue [16][16] = {          //�����̸�λ�õļ�ֵ������ÿ������Value_Black��Value_White�ĳ�ʼ����������������ֵ�𽥼�С
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

int Value_Black[16][16] = {0};          //��λ�ù��ں��ӵ�ֵ
int Value_White[16][16] = {0};			//��λ�ù��ڰ��ӵ�ֵ
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};//8������4���ߣ��෴�ķ����4�����ÿ�����ϵĸ���ֻ�轫���4��������Ӽ���
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};//0����y��������1�����һ���޽�ƽ���ߣ�2����x���������Դ�����

void Evaluate(int Mode)     //������λ�õļ�ֵ
{
	int i, j;

	Evaluate_Black( Mode);  //���ۿ�λ�ù��ں��ӵ�ֵ
	Evaluate_White( Mode);  //���ۿ�λ�ù��ڰ��ӵ�ֵ

	for(i = 1; i<= 15; i++)
		for(j = 1; j<= 15; j++)
			Value[i][j] = Value_Black[i][j] + Value_White[i][j]; //�ܼ�ֵ���ڹ��ں��ӺͰ��Ӽ�ֵ�ĺ�
}

void Evaluate_Black(int Mode)	    
{
	int i, j;
	for(i = 15; i >= 0; i --)
		for(j = 0; j <= 15; j ++)
		{
			Value_Black[i][j]= BoardValue[i][j];//��Value_Black��ʼ�����������ۼ�

			if(Position1[i][j] == 0 && Position2[i][j] == 0)   //������λ���γɵ����Σ����϶�Ӧ��ֵ�������ε�ֵ��Value.h��
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
			Value_White[i][j]= BoardValue[i][j];//��Value_Black��ʼ�����������ۼ�
			if(Position1[i][j] == 0 && Position2[i][j] == 0)//������λ���γɵ����Σ����϶�Ӧ��ֵ�������ε�ֵ��Value.h��
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