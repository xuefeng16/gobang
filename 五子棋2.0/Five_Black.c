#include<stdio.h>
#include "FiveInRow.h"

int Five_Black(int i, int j)  //能形成五连的位置
{
	int k = 0;
	int count = 0; 

	for(k = 0; k <= 7; k++)  //_●●●●
	{
		if( (i+4*dx[k])>=1 && (i+4*dx[k]) <= 15 && (j+4*dy[k]) >= 1 && (j+4*dy[k])<= 15 && i>=1 && i<=15 && j>=1 &&j<=15  && Position1[i+dx[k]][j+dy[k]] == 1 && Position1[i+2*dx[k]][j+2*dy[k]] == 1 &&
			Position1[i+3*dx[k]][j+3*dy[k]] == 1 && Position1[i+4*dx[k]][j+4*dy[k]] == 1)
			count ++;
	}


	for(k = 0; k <= 7; k++)   //●_●●●
	{
		if( (i+3*dx[k])>=1 && (i+3*dx[k])<=15 && (i-dx[k])>= 1 && (i-dx[k])<=15 && (j-dy[k])>=1 && (j-dy[k])<=15 && (j+3*dy[k]) >= 1 && (j+3*dy[k])<= 15 && Position1[i-dx[k]][j-dy[k]] == 1 && 
			Position1[i+dx[k]][j+dy[k]] == 1 && Position1[i+2*dx[k]][j+2*dy[k]] == 1 && Position1[i+3*dx[k]][j+3*dy[k]] == 1)
			count ++;
	}

	for(k = 0; k <= 7; k++)  //●●_●●
	{
		if( (i+2*dx[k])>=1 && (i+2*dx[k]) <= 15 && (i-2*dx[k])>=1 && (i-2*dx[k]) <= 15 && (j+2*dy[k]) >= 1 && (j+2*dy[k])<= 15 && (j-2*dy[k]) >= 1 && (j-2*dy[k])<= 15 && Position1[i-2*dx[k]][j-2*dy[k]] == 1 &&
			Position1[i-dx[k]][j-dy[k]] == 1 && Position1[i+dx[k]][j+dy[k]] == 1 && Position1[i+2*dx[k]][j+2*dy[k]] == 1)
			count ++;
	}
	return count;
}