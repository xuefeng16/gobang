#include<stdio.h>
#include "FiveInRow.h"


int DoubleFour(int m, int j)  //DoubleFour(int,int)函数，用于判断四四禁手，产生禁手返回1，否则返回0
{
	int count = 0;		      //计数器
	int a = 0, b = 0;

	//相连的活四或冲四
	//活四_●●●●_
	for(a = j-4; a <= j-1; a ++) //行
	{
		if(a>=1 && a<=10 && Position1[m][a]==0 && Position1[m][a+1]==1 && Position1[m][a+2]==1 && Position1[m][a+3]==1 && Position1[m][a+4]==1 && Position1[m][a+5]==0 && Position2[m][a]==0 && Position2[m][a+5]==0)
			count ++;
	}

	for(a = m-4; a <= m-1; a ++) //列
	{
		if(a>0 && a<11 && Position1[a][j]==0 && Position1[a+1][j]==1 && Position1[a+2][j]==1 && Position1[a+3][j]==1 && Position1[a+4][j]==1 && Position1[a+5][j]==0 && Position2[a][j]==0 && Position2[a+5][j]==0)
			count ++;
	}

	for(a = m-4, b= j-4; a <= m-1; a++, b++) //一三象限对角线
	{
		if(a>0 && a<11 && b>0 && b<11 && Position1[a][b]==0 && Position1[a+1][b+1]==1 && Position1[a+2][b+2]==1 && Position1[a+3][b+3]==1 && Position1[a+4][b+4]==1 && Position1[a+5][b+5]==0 && Position2[a][b]==0 && Position2[a+5][b+5]==0)
			count ++;
	}

	for(a = m-4,b= j+4; a <= m-1; a ++, b --) //二四象限对角线
	{
		if(a>0 && a<11 && b>5 && b<16 && Position1[a][b]==0 && Position1[a+1][b-1]==1 && Position1[a+2][b-2]==1 && Position1[a+3][b-3]==1 && Position1[a+4][b-4]==1 && Position1[a+5][b-5]==0 && Position2[a][b]==0 && Position2[a+5][b-5]==0)
			count ++;
	}

	//冲四
	//◎●●●●_
	for(a = j-4; a <= j-1; a ++)//行
	{
		if(((a>=1 && Position2[m][a]==1)|| a==0 ) && a <= 10 && Position1[m][a+1]==1 && Position1[m][a+2]==1 && Position1[m][a+3]==1 && Position1[m][a+4]==1 && Position1[m][a+5]==0 && Position2[m][a+5]==0)
			count ++;
	}

	for(a = m-4; a <= m-1; a ++)//列
	{
		if(((a>=1 && Position2[a][j]==1)|| a==0) && a <= 10 && Position1[a+1][j]==1 && Position1[a+2][j]==1 && Position1[a+3][j]==1 && Position1[a+4][j]==1 && Position1[a+5][j]==0 && Position2[a+5][j]==0)
			count ++;
	}

	for(a = m-4, b = j-4; a <= m-1; a++, b++)//一三象限对角线
	{
		if(((a>=1 && b>=1 && Position2[a][b]==1)|| a==0 || b==0) && a <= 10 && b<= 10 && Position1[a+1][b+1]==1 && Position1[a+2][b+2]==1 && Position1[a+3][b+3]==1 && Position1[a+4][b+4]==1 && Position1[a+5][b+5]==0 && Position2[a+5][b+5]==0)
			count ++;
	}

	for(a = m+4, b = j-4; b <= j-1; a--, b++)//二四象限对角线
	{
		if(((a<= 15 && b>=1 && Position2[a][b]==1)|| a==16 || b==0) && b <= 10 && a>=6 && Position1[a-1][b+1]==1 && Position1[a-2][b+2]==1 && Position1[a-3][b+3]==1 && Position1[a-4][b+4]==1 && Position1[a-5][b+5]==0 && Position2[a-5][b+5]==0)
			count ++;
	}

	//_●●●●◎
	for(a = j-4; a <= j-1; a ++)//行
	{
		if(((a<=10 && a>=1 && Position2[m][a+5]==1)|| a==11 ) && Position1[m][a]==0 && Position1[m][a+1]==1 && Position1[m][a+2]==1 && Position1[m][a+3]==1 && Position1[m][a+4]==1 && Position2[m][a]==0)
			count ++;
	}

	for(a = m-4; a <= m-1; a ++)//列
	{
		if(((a<=10 && a>=1 && Position2[a+5][j]==1)|| a==11 ) && Position1[a][j]==0 && Position1[a+1][j]==1 && Position1[a+2][j]==1 && Position1[a+3][j]==1 && Position1[a+4][j]==1 && Position2[a][j]==0)
			count ++;
	}

	for(a = m-4, b = j-4; a <= m-1; a++, b++)//一三象限对角线
	{
		if(((a<=10 && b<=10 && Position2[a+5][b+5]==1)|| a==11 || b==11) && a>=1 && b>=1 && Position1[a+1][b+1]==1 && Position1[a+2][b+2]==1 && Position1[a+3][b+3]==1 && Position1[a+4][b+4]==1 && Position1[a+5][b+5]==0 && Position2[a][b]==0)
			count ++;
	}

	for(a = m-4, b = j+4; a <= m-1; a++, b--)//二四象限对角线
	{
		if(((a>=1 && b<=15 && Position2[a][b]==1)|| a==0 || b==16) && a<=10 && b>=6 && Position1[a+1][b-1]==1 && Position1[a+2][b-2]==1 && Position1[a+3][b-3]==1 && Position1[a+4][b-4]==1 && Position1[a+5][b-5]==0 && Position2[a+5][b-5]==0)
			count ++;
	}

	//间断的的活四或冲四
	//_●●_●●_
	for(a = j-5; a <= j-1; a ++)//行
	{
		if(a==j-3)
			a++;
		if(((a>=1 && a<= 9 && (Position2[m][a]==0||Position2[m][a+6]==0)) || (a==0 && Position2[m][6]==0 ) || (a==10 && Position2[m][10]==0)) && Position1[m][a]==0 && Position1[m][a+1]==1 && Position1[m][a+2]==1&& Position1[m][a+3]==0 && Position1[m][a+4]==1 && Position1[m][a+5]==1 && Position1[m][a+6]==0 && Position2[m][a+3]==0)
			count ++;
	}

	for(a = m-5; a <= m-1; a ++)//列
	{
		if(a==m-3)
			a++;
		if(((a>=1 && a<= 9 && (Position2[a][j]==0||Position2[a+6][j]==0)) || (a==0 && Position2[6][j]==0 ) || (a==10 && Position2[10][j]==0))&& Position1[a][j]==0 && Position1[a+1][j]==1 && Position1[a+2][j]==1&& Position1[a+3][j]==0 && Position1[a+4][j]==1 && Position1[a+5][j]==1 && Position1[a+6][j]==0 && Position2[a+3][j]==0 )
			count ++;
	}
	for(a = m-5,b = j-5; a <= m-1; a ++, b ++)//一三象限对角线
	{
		if(a==m-3)
		{
			a++;
			b++;
		}
		if(((a>=1 && a<= 9 && b>=1 && b<= 9 && (Position2[a][b]==0||Position2[a+6][b+6]==0)) || (a==0 && Position2[a+6][b+6]==0 ) || (a==10 && Position2[a][b]==0)||(b==0 && Position2[a+6][b+6]==0)||(b==10 && Position2[a][b]==0)) && Position1[a][b]==0 && Position1[a+1][b+1]==1 && Position1[a+2][b+2]==1&& Position1[a+3][b+3]==0 && Position1[a+4][b+4]==1 && Position1[a+5][b+5]==1 && Position1[a+6][b+6]==0 && Position2[a+3][b+3]==0)
			count ++;
	}
	for(a = m-5, b = j+5; a <= m-1; a++, b--)//二四象限对角线
	{
		if(a==m-3)
		{	
			a++;
			b--;
		}
		if(((a>=1 && a<= 9 && b>=7 && b<= 15 && (Position2[a][b]==0||Position2[a+6][b-6]==0)) || (a==0 && Position2[a+6][b-6]==0 ) || (a==10 && Position2[a][b]==0)||(b==6 && Position2[a][b]==0)||(b==15 && Position2[a][b-6]==0)) && Position1[a][b]==0 && Position1[a+1][b-1]==1 && Position1[a+2][b-2]==1&& Position1[a+3][b-3]==0 && Position1[a+4][b-4]==1 && Position1[a+5][b-5]==1 && Position1[a+6][b-6]==0 && Position2[a+3][b-3]==0)
			count ++;
	}
	//_●_●●●_
	for(a = j-5; a <= j-1; a ++)//行
	{
		if(a==j-2)
			a++;
		if(((a>=1 && a<= 9 && (Position2[m][a]==0||Position2[m][a+6]==0)) || (a==0 && Position2[m][6]==0 ) || (a==10 && Position2[m][a]==0)) && Position1[m][a]==0 && Position1[m][a+1]==1 && Position1[m][a+2]==0 && Position1[m][a+3]==1 && Position1[m][a+4]==1 && Position1[m][a+5]==1 && Position1[m][a+6]==0 && Position2[m][a+2]==0)
			count ++;
	}

	for(a = m-5; a <= m-1; a ++)//列
	{
		if(a==m-2)
			a++;
		if(((a>=1 && a<= 9 && (Position2[a][j]==0||Position2[a+6][j]==0)) || (a==0 && Position2[6][j]==0 ) || (a==10 && Position2[a][j]==0)) && Position1[a][j]==0 && Position1[a+1][j]==1 && Position1[a+2][j]==0 && Position1[a+3][j]==1 && Position1[a+4][j]==1 && Position1[a+5][j]==1 && Position1[a+6][j]==0 && Position2[a+2][j]==0)
			count ++;
	}

	for(a = m-5,b = j-5; a <= m-1; a ++, b ++)//一三象限对角线
	{
		if(a==m-2)
		{
			a++;
			b++;
		}
		if(((a>=1 && a<= 9 && b>=1 && b<= 9 && (Position2[a][b]==0||Position2[a+6][b+6]==0)) || (a==0 && Position2[a+6][b+6]==0 ) || (a==10 && Position2[a][b]==0)||(b==0 && Position2[a+6][b+6]==0)||(b==10 && Position2[a][b]==0)) && Position1[a][b]==0 && Position1[a+1][b+1]==1 && Position1[a+2][b+2]==0 && Position1[a+3][b+3]==1 && Position1[a+4][b+4]==1 && Position1[a+5][b+5]==1 && Position1[a+6][b+6]==0 && Position2[a+2][b+2]==0)
			count ++;
	}

	for(a = m-5, b = j+5; a <= m-1; a++, b--)//二四象限对角线
	{
		if(a==m-2)
		{	
			a++;
			b--;
		}
		if(((a>=1 && a<= 9 && b>=7 && b<= 15 && (Position2[a][b]==0||Position2[a+6][b-6]==0)) || (a==0 && Position2[a+6][b-6]==0 ) || (a==10 && Position2[a][b]==0)||(b==6 && Position2[a][b]==0)||(b==15 && Position2[a][b-6]==0)) && Position1[a][b]==0 && Position1[a+1][b-1]==1 && Position1[a+2][b-2]==0&& Position1[a+3][b-3]==1 && Position1[a+4][b-4]==1 && Position1[a+5][b-5]==1 && Position1[a+6][b-6]==0 && Position2[a+2][b-2]==0)
			count ++;
	}

	//_●●●_●_
	for(a = j-5; a <= j-1; a ++)//行
	{
		if(a==j-4)
			a++;
		if(((a>=1 && a<= 9 && (Position2[m][a]==0||Position2[m][a+6]==0)) || (a==0 && Position2[m][6]==0 ) || (a==10 && Position2[m][a]==0)) && Position1[m][a]==0 && Position1[m][a+1]==1 && Position1[m][a+2]==1 && Position1[m][a+3]==1 && Position1[m][a+4]==0 && Position1[m][a+5]==1 && Position1[m][a+6]==0 && Position2[m][a+4]==0)
			count ++;
	}

	for(a = m-5; a <= m-1; a ++)//列
	{
		if(a==m-4)
			a++;
		if(((a>=1 && a<= 9 && (Position2[a][j]==0||Position2[a+6][j]==0)) || (a==0 && Position2[6][j]==0 ) || (a==10 && Position2[a][j]==0)) && Position1[a][j]==0 && Position1[a+1][j]==1 && Position1[a+2][j]==1 && Position1[a+3][j]==1 && Position1[a+4][j]==0 && Position1[a+5][j]==1 && Position1[a+6][j]==0 && Position2[a+4][j]==0)
			count ++;
	}

	for(a = m-5,b = j-5; a <= m-1; a ++, b ++)//一三象限对角线
	{
		if(a==m-4)
		{
			a++;
			b++;
		}
		if(((a>=1 && a<= 9 && b>=1 && b<= 9 && (Position2[a][b]==0||Position2[a+6][b+6]==0)) || (a==0 && Position2[a+6][b+6]==0 ) || (a==10 && Position2[a][b]==0)||(b==0 && Position2[a+6][b+6]==0)||(b==10 && Position2[a][b]==0)) && Position1[a][b]==0 && Position1[a+1][b+1]==1 && Position1[a+2][b+2]==1 && Position1[a+3][b+3]==1 && Position1[a+4][b+4]==0 && Position1[a+5][b+5]==1 && Position1[a+6][b+6]==0 && Position2[a+4][b+4]==0)
			count ++;
	}

	for(a = m-5, b = j+5; a <= m-1; a++, b--)//二四象限对角线
	{
		if(a==m-4)
		{	
			a++;
			b--;
		}
		if(((a>=1 && a<= 9 && b>=7 && b<= 15 && (Position2[a][b]==0||Position2[a+6][b-6]==0)) || (a==0 && Position2[a+6][b-6]==0 ) || (a==10 && Position2[a][b]==0)||(b==6 && Position2[a][b]==0)||(b==15 && Position2[a][b-6]==0)) && Position1[a][b]==0 && Position1[a+1][b-1]==1 && Position1[a+2][b-2]==1 && Position1[a+3][b-3]==1 && Position1[a+4][b-4]==0 && Position1[a+5][b-5]==1 && Position1[a+6][b-6]==0 && Position2[a+4][b-4]==0)
			count ++;
	}

	if(count >= 2)
	{
		return 1;
	}
	else
		return 0;
}