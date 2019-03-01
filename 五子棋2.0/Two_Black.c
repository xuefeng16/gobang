#include<stdio.h>
#include "FiveInRow.h"

int LiveTwo_Black(int i, int j) //能形成活二的点
{
	int k = 0;
	int count = 0;

	for(k = 0; k <= 7; k++)  //_ _ _●_ _ 左侧第三个空位
	{
		if( (i+3*dx[k])>=1 && (i+3*dx[k]) <= 15 && (i-2*dx[k])>=1 && (i-2*dx[k])<= 15 && (j-2*dy[k])>= 1 && (j-2*dy[k]) <= 15 && (j+3*dy[k]) >=1 && (j+3*dy[k])<= 15 && Position1[i-2*dx[k]][j-2*dy[k]] == 0 && Position1[i-dx[k]][j-dy[k]] == 0 && Position1[i+dx[k]][j+dy[k]] == 1 &&
			Position1[i+2*dx[k]][j+2*dy[k]] == 0 && Position1[i+3*dx[k]][j+3*dy[k]] == 0 && Position2[i-2*dx[k]][j-2*dy[k]] == 0 && Position2[i-dx[k]][j-dy[k]] == 0 && Position2[i+2*dx[k]][j+2*dy[k]] == 0 && Position2[i+3*dx[k]][j+3*dy[k]] == 0)
			count ++;
	}
	return count;
}
int DeadTwo_Black(int i, int j) //能形成冲二的点
{
	int k = 0;
	int count = 0;

	for(k = 0; k <= 7; k++)  //_ _ _●_ _ 左侧第二个空位
	{
		int k = 0;
		int count = 0;
		if( (i+4*dx[k])>=1 && (i+4*dx[k]) <= 15 && (i-dx[k])>=1 && (i-dx[k])<= 15 && (j-dy[k])>= 1 && (j-dy[k]) <= 15 && (j+4*dy[k]) >=1 && (j+4*dy[k])<= 15 && Position1[i-dx[k]][j-dy[k]] == 0 && Position1[i+dx[k]][j+dy[k]] == 0 && Position1[i+2*dx[k]][j+2*dy[k]] == 1 &&
			Position1[i+3*dx[k]][j+3*dy[k]] == 0 && Position1[i+4*dx[k]][j+4*dy[k]] == 0 && Position2[i-dx[k]][j-dy[k]] == 0 && Position2[i+dx[k]][j+dy[k]] == 0 && Position2[i+3*dx[k]][j+3*dy[k]] == 0 && Position2[i+4*dx[k]][j+4*dy[k]] == 0)
			count ++;
	}
	return count;
}