#include<stdio.h>
#include "FiveInRow.h"

int Announce (int i, int j) //Announce����������������Ϸ���
{
	static int count = 0;
	count ++;               //�����жϺ���,˫���жϰ���

	if(count%2 == 1) 
	{
		if(Judge(Position1, i, j) == 1 && ForbiddenMove(i,j) != 3)  //���������������Ľ���ͬʱ��������ʧЧ��������ж��Ƿ����������жϽ���
		{															//ForbiddenMove�����������жϽ���
			printf("�����ʤ!\n");
			return 1;
		}
		if(ForbiddenMove(i,j) == 1)				
		{
			printf("�������֣�����ʤ\n");
			return 1;  
		}
		if(ForbiddenMove(i,j) == 2)
		{
			printf("���Ľ��֣�����ʤ\n");
			return 1;  
		}
		if(ForbiddenMove(i,j) == 3)
		{
			printf("�������֣�����ʤ\n");
			return 1; 
		}
		else
			return 0;
	}

	if(count%2 == 0)
	{
		if(Judge(Position2, i, j))    //Judge���������ж��Ƿ��γ�����
		{	
			printf("�����ʤ!\n");
			return 1; 
		}
		else
			return 0;
	}

	return 0;
}