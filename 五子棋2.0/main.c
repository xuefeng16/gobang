#include<stdio.h>
#include "FiveInRow.h"

int main()
{	
	int a = 0;
	DrawBoard();        //�����̺���
	
	printf("���˶�ս����1���ֺ����˻���ս����2���ְ����˻���ս����3\n");
	scanf("%d", &a);
	
	while ( a < 1 || a >3)
	{
		printf("�����������������\n");
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

char chess1[2]="��";          //����
char Current_chess1[2]="��";  //���ӵ�ǰ����
char chess2[2]="��";          //����
char Current_chess2[2]="��";  //���ӵ�ǰ����

int Position1[16][16] = {0};  //��¼����λ��,���ӵ�λ�ü�Ϊ1,���Ӽ�¼Ϊ0
int Position2[16][16] = {0};  //��¼����λ��

char B[16][15*2+3] = {        //������
	"15���өөөөөөөөөөөөө�\n",
	"14�ĩ��������������\n",
	"13�ĩ��������������\n",
	"12�ĩ��������������\n",
	"11�ĩ��������������\n",
	"10�ĩ��������������\n",
	" 9�ĩ��������������\n",
	" 8�ĩ��������������\n",
	" 7�ĩ��������������\n",
	" 6�ĩ��������������\n",
	" 5�ĩ��������������\n",
	" 4�ĩ��������������\n",
	" 3�ĩ��������������\n",
	" 2�ĩ��������������\n",
	" 1���۩۩۩۩۩۩۩۩۩۩۩۩۩�\n",
	"  A B C D E F G H I J K L M N O \n"
	};
