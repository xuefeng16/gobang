#include<stdio.h>
#include "FiveInRow.h"

int DeadFour_Black(int i, int j)  //能形成冲四的位置
{	
	int k = 0;
	int count = 0;

	for(k = 0; k <= 7; k++)  //_ _●●● 左侧第一个空位
	{
		if( (i+4*dx[k])>=1 && (i+4*dx[k]) <= 15 && i>=1 && i<= 15 && j>= 1 && j <= 15 && (j+4*dy[k]) >=1 && (j+4*dy[k])<= 15 && Position1[i+dx[k]][j+dy[k]] == 0 && Position1[i+2*dx[k]][j+2*dy[k]] == 1 && Position1[i+3*dx[k]][j+3*dy[k]] == 1 &&
			Position1[i+4*dx[k]][j+4*dy[k]] == 1 && Position2[i+dx[k]][j+dy[k]] == 0)
			count ++;
	}

	for(k = 0; k <= 7; k++)  //_●_●● 左侧空位
	{
		if( (i+4*dx[k])>=1 && (i+4*dx[k]) <= 15 && i>=1 && i<=15 && j>= 1 && j <= 15 && (j+4*dy[k]) >= 2 && (j+4*dy[k])<= 15 && Position1[i+dx[k]][j+dy[k]] == 1 && Position1[i+2*dx[k]][j+2*dy[k]] == 0 && Position1[i+3*dx[k]][j+3*dy[k]] == 1 &&
			Position1[i+4*dx[k]][j+4*dy[k]] == 1 && Position2[i+2*dx[k]][j+2*dy[k]] == 0)
			count ++;
	}

	for(k = 0; k <= 7; k++)  //_●●_● 左侧空位
	{
		if( (i+4*dx[k])>=1 && (i+4*dx[k]) <= 15 && i>=1 && i<=15 && j>= 1 && j <= 15 && (j+4*dy[k]) >= 2 && (j+4*dy[k])<= 15 && Position1[i+dx[k]][j+dy[k]] == 1 && Position1[i+2*dx[k]][j+2*dy[k]] == 1 && Position1[i+3*dx[k]][j+3*dy[k]] == 0 &&
			Position1[i+4*dx[k]][j+4*dy[k]] == 1 && Position2[i+3*dx[k]][j+3*dy[k]] == 0)
			count ++;
	}

	for(k = 0; k <= 7; k++)  //_ _●●●◎ 中间空位
	{
		if( (i+3*dx[k])>=1 && (i+3*dx[k]) <= 15 && (i-dx[k])>=1 && (i-dx[k])<=15 && (j-dy[k])>= 1 && (j-dy[k]) <= 15 && (j+3*dy[k]) >= 1 && (j+3*dy[k])<= 15 && Position1[i-dx[k]][j-dy[k]] == 0 && Position1[i+dx[k]][j+dy[k]] == 1 && Position1[i+2*dx[k]][j+2*dy[k]] == 1 &&
			Position1[i+3*dx[k]][j+3*dy[k]] == 1 && Position2[i-dx[k]][j-dy[k]] == 0 &&(Position2[i+4*dx[k]][j+4*dy[k]] == 1|| (i+3*dx[k])==1 || (i+3*dx[k])==15 ||(j+3*dy[k])==1 || (j+3*dy[k])==15 ))
			count ++;
	}

	for(k = 0; k <= 7; k++)  //_●_●●◎ 中间空位
	{
		if( (i+2*dx[k])>=1 && (i+2*dx[k]) <= 15 && (i-2*dx[k])>=1 && (i-2*dx[k])<=15 && (j-2*dy[k])>= 1 && (j-2*dy[k]) <= 15 && (j+2*dy[k]) >= 1 && (j+2*dy[k])<= 15 && Position1[i-2*dx[k]][j-2*dy[k]] == 0 && Position1[i-dx[k]][j-dy[k]] == 1 && Position1[i+dx[k]][j+dy[k]] == 1 &&
			Position1[i+2*dx[k]][j+2*dy[k]] == 1 && Position2[i-2*dx[k]][j-2*dy[k]] == 0 &&(Position2[i+3*dx[k]][j+3*dy[k]] == 1|| (i+2*dx[k])==1 || (i+2*dx[k])==15 ||(j+2*dy[k])==1 || (j+2*dy[k])==15))
			count ++;
	}

	for(k = 0; k <= 7; k++)  //_●●_●◎ 中间空位
	{
		if( (i+dx[k])>=1 && (i+dx[k]) <= 15 && (i-3*dx[k])>=1 && (i-3*dx[k])<=15 && (j-3*dy[k])>= 1 && (j-3*dy[k]) <= 15 && (j+dy[k]) >= 1 && (j+dy[k])<= 15 && Position1[i-3*dx[k]][j-3*dy[k]] == 0 && Position1[i-2*dx[k]][j-2*dy[k]] == 1 && Position1[i-dx[k]][j-dy[k]] == 1 &&
			Position1[i+dx[k]][j+dy[k]] == 1 && Position2[i-3*dx[k]][j-3*dy[k]] == 0 &&(Position2[i+2*dx[k]][j+2*dy[k]] == 1|| (i+dx[k])==1 || (i+dx[k])==15 ||(j+dy[k])==1 || (j+dy[k])==15 ))
			count ++;
	}

	for(k = 0; k <= 7; k++)  //●_ _●● 左空位
	{
		if( (i-dx[k])>=1 && (i-dx[k]) <= 15 && (i+3*dx[k])>=1 && (i+3*dx[k])<=15 && (j+3*dy[k])>= 1 && (j+3*dy[k]) <= 15 && (j-dy[k]) >= 1 && (j-dy[k])<= 15 && Position1[i-dx[k]][j-dy[k]] == 1 && Position1[i+dx[k]][j+dy[k]] == 0 && Position1[i+2*dx[k]][j+2*dy[k]] == 1 &&
			Position1[i+3*dx[k]][j+3*dy[k]] == 1 && Position2[i+dx[k]][j+dy[k]] == 0)
			count ++;
	}

	for(k = 0; k <= 7; k++)  //●_ _●● 右空位
	{
		if( (i-2*dx[k])>=1 && (i-2*dx[k]) <= 15 && (i+2*dx[k])>=1 && (i+2*dx[k])<=15 && (j+2*dy[k])>= 1 && (j+2*dy[k]) <= 15 && (j-2*dy[k]) >= 1 && (j-2*dy[k])<= 15 && Position1[i-2*dx[k]][j-2*dy[k]] == 1 && Position1[i-dx[k]][j-dy[k]] == 0 && Position1[i+dx[k]][j+dy[k]] == 1 &&
			Position1[i+2*dx[k]][j+2*dy[k]] == 1 && Position2[i-dx[k]][j-dy[k]] == 0)
			count ++;
	}

	for(k = 0; k <= 7; k++)  //●_●_●
	{
		if( (i-dx[k])>=1 && (i-dx[k]) <= 15 && (i+3*dx[k])>=1 && (i+3*dx[k])<=15 && (j+3*dy[k])>= 1 && (j+3*dy[k]) <= 15 && (j-dy[k]) >= 1 && (j-dy[k])<= 15 && Position1[i-dx[k]][j-dy[k]] == 1 && Position1[i+dx[k]][j+dy[k]] == 1 && Position1[i+2*dx[k]][j+2*dy[k]] == 0 &&
			Position1[i+3*dx[k]][j+3*dy[k]] == 1 && Position2[i+2*dx[k]][j+2*dy[k]] == 0)
			count ++;
	}

	for(k = 0; k <= 7; k++)  //◎_●●●_◎
	{
		if((i+4*dx[k])>=1 && (i+4*dx[k]) <= 15 && i>=1 && i<=15 && j>= 1 && j<= 15 && (j+4*dy[k]) >= 1 && (j+4*dy[k])<= 15 && Position1[i+dx[k]][j+dy[k]] == 1 && Position1[i+2*dx[k]][j+2*dy[k]] == 1 && Position1[i+3*dx[k]][j+3*dy[k]] == 1 &&
			Position1[i+4*dx[k]][j+4*dy[k]] == 0 && Position2[i+4*dx[k]][j+4*dy[k]] == 0 &&(Position2[i+5*dx[k]][j+5*dy[k]] == 1|| (i+4*dx[k])==1 || (i+4*dx[k])==15 ||(j+4*dy[k])==1 || (j+4*dy[k])==15) &&(Position2[i-dx[k]][j-dy[k]] == 1|| i==1 || i==15 || j==1 || j==15))
			count ++;
	}
	return count;
}