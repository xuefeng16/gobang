#include<stdio.h>
#include <stdlib.h>
#include "FiveInRow.h"

void Retract(int Mode);

struct point GetPoint(int Mode)	    //GetPoint���������ڵõ��û���������꣬������ĸת��Ϊ���֣�����struct point����ֵ
{
	int m = 0, n = 0;
	struct point NextPoint;
	static int count = 0;
	static int count_Recoder = 0;   //��¼����ʱ��count,�Ӷ���ֹ��������
	
	count ++;

	scanf("%c %d", &n, &m);
	if(m == 0 && n == 10)   //�����ո�ͻ��з�
    	scanf("%c %d", &n, &m);

	if(n == 'R' && m == 1 && Mode != 2)
	{
		if(count >= (count_Recoder+2))
		{
			Retract(Mode);  
			count_Recoder = count;
			printf("��������λ��\n");

			scanf("%c %d", &n, &m);
			if(m == 0 && n == 10)   //�����ո�ͻ��з�
				scanf("%c %d", &n, &m);
		}

		else 
		{
			printf("���λ���֮�����ٸ���������������һ��λ��\n");
			scanf("%c %d", &n, &m);
			if(m == 0 && n == 10)   //�����ո�ͻ��з�
				scanf("%c %d", &n, &m);
		}
	}


	while(m<1 || m>15 || n<'A'|| n>'O'|| Position1[m][n-'A'+1]==1 ||Position2[m][n-'A'+1]==1) //��ֹ���ӳ����߽���ۼӵ�����������
	{
		if(m != 0 && n != 10 )
			printf("����λ���������������룡\n");
		scanf("%c %d", &n, &m);
	}

	NextPoint.x = m;
	NextPoint.y = n-'A'+1;  //����ĸת��Ϊ���֣�ʵ�����ӵ�λ���ǵ�m��j��

	return  NextPoint;
}