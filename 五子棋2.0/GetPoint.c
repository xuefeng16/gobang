#include<stdio.h>
#include <stdlib.h>
#include "FiveInRow.h"

void Retract(int Mode);

struct point GetPoint(int Mode)	    //GetPoint函数，用于得到用户输入的坐标，并将字母转化为数字，返回struct point类型值
{
	int m = 0, n = 0;
	struct point NextPoint;
	static int count = 0;
	static int count_Recoder = 0;   //记录悔棋时的count,从而防止连续悔棋
	
	count ++;

	scanf("%c %d", &n, &m);
	if(m == 0 && n == 10)   //跳过空格和换行符
    	scanf("%c %d", &n, &m);

	if(n == 'R' && m == 1 && Mode != 2)
	{
		if(count >= (count_Recoder+2))
		{
			Retract(Mode);  
			count_Recoder = count;
			printf("输入棋子位置\n");

			scanf("%c %d", &n, &m);
			if(m == 0 && n == 10)   //跳过空格和换行符
				scanf("%c %d", &n, &m);
		}

		else 
		{
			printf("两次悔棋之间至少隔两步，请输入下一步位置\n");
			scanf("%c %d", &n, &m);
			if(m == 0 && n == 10)   //跳过空格和换行符
				scanf("%c %d", &n, &m);
		}
	}


	while(m<1 || m>15 || n<'A'|| n>'O'|| Position1[m][n-'A'+1]==1 ||Position2[m][n-'A'+1]==1) //防止棋子超出边界和累加到已有棋子上
	{
		if(m != 0 && n != 10 )
			printf("输入位置有误，请重新输入！\n");
		scanf("%c %d", &n, &m);
	}

	NextPoint.x = m;
	NextPoint.y = n-'A'+1;  //将字母转化为数字，实际棋子的位置是第m行j列

	return  NextPoint;
}