#include<stdio.h>
#include <stdlib.h>
#include "FiveInRow.h"

void DrawBoard()    //�����̺���
{
	int i = 0, j = 0;
	int count_Black = 0, count_White = 0;//�ֱ��¼���ӺͰ��ӵĸ���
	static int count = 0;
	count ++;

	system("cls");
	system("color f0");

	printf("         ==��������Ϸ==\n\n\n" );
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
		printf("�˻�ģʽ����R1�ɻ��壬�����λ���֮�����ٸ�����\n");
	if(count_Black == count_White && count != 1)
		printf("�������������λ��(��ĸ��д)   ��������%d  ��������%d\n",count_Black, count_White);
	if(count_Black > count_White)
		printf("�������������λ��(��ĸ��д)   ��������%d  ��������%d\n",count_Black, count_White);
	if(count_Black == 113)
		printf("����\n");
}
