#include<stdio.h>
#include "FiveInRow.h"

int DoubleThree(int m, int j)  //DoubleThree(int,int)�����������ж��������֣��������ַ���1�����򷵻�0
{	
	int count = 0;		//������
	int a = 0, b = 0;
	int row = 0, column = 0, diagona1 = 0, diagona2 = 0; //��ֹ�����_��_���_��_��_���_��_��Ϊ���֣���һ��������ͬʱ���֡��_��͡�_��������
														 //row, column, diagona1, diagona2���ֱ�����ͳ���ĸ������ϡ��_��͡�_���ĸ���
	//�����Ļ���	
	//_����_
	for(a = j-3; a <= j-1; a++)	   //��
	{
		if(a>=1 && a<=11 && Position1[m][a]==0 && Position1[m][a+1]==1 && Position1[m][a+2]==1 && Position1[m][a+3]==1 && Position1[m][a+4]==0 && Position2[m][a]==0 && Position2[m][a+4]==0)
			count ++;
	}

	for(a = m-3; a <= m-1; a++)    //��
	{	
		if(a>=1 && a<=11 && Position1[a][j]==0 && Position1[a+1][j]==1 && Position1[a+2][j]==1 && Position1[a+3][j]==1 && Position1[a+4][j]==0 && Position2[a][j]==0 && Position2[a+4][j]==0)
			count ++;
	}

	for(a= m-3, b= j-3; a <= m-1; a++, b++)  //һ�����޶Խ���
	{
		if(a>=1 && a <=11 && b>=1 && b<=11 && Position1[a][b]==0 && Position1[a+1][b+1]==1 && Position1[a+2][b+2]==1 && Position1[a+3][b+3]==1 && Position1[a+4][b+4]==0 && Position2[a][b]==0 && Position2[a+4][b+4]==0)
		{
			if( (a !=11 && b != 1) && (a !=11 && b!= 1 ) )   //��ֹ�ڽ�����ּٻ��������
				count ++;
		}
	}

	for(a= m-3, b= j+3; a <= m-1; a++, b--)  //�������޶Խ���
	{
		if(a>=1 && a <=11 && b>=5 && b<= 15 && Position1[a][b]==0 && Position1[a+1][b-1]==1 && Position1[a+2][b-2]==1 && Position1[a+3][b-3]==1 && Position1[a+4][b-4]==0 && Position2[a][b]==0 && Position2[a+4][b-4]==0)
			if( (a !=11 && b != 15) && (a !=1 && b!= 5 ) )   //��ֹ�ڽ�����ּٻ��������
				count ++;
	}

	//��ϵĻ���
	//_���_��_
	for(a = j-4; a<=j-1; a ++)  //��
	{
		if(a >=1 && a<= 10 &&Position1[m][a]==0 && Position1[m][a+1]==1 && Position1[m][a+2]==1 && Position1[m][a+3]==0 && Position1[m][a+4]==1 &&Position1[m][a+5]==0 && Position2[m][a]==0 && Position2[m][a+3]==0 && Position2[m][a+5]==0)
		{
			count ++;
			row ++;
		}
		if(a== j-4)
			a ++;
	}

	for(a = j-4; a<=m-1; a ++)  //��
	{
		if(a >=1 && a<= 10 && Position1[a][j]==0 && Position1[a+1][j]==1 && Position1[a+2][j]==1 && Position1[a+3][j]==0 && Position1[a+4][j]==1 &&Position1[a+5][j]==0 && Position2[a][j]==0 && Position2[a+3][j]==0 && Position2[a+5][j]==0)
		{
			count ++;
			column ++;
		}
		if(a== m-4)
			a ++;
	}

	for(a = m-4,b = j-4; a<= m-1; a++, b++)   //һ�����޶Խ���
	{
		if(a >=1 && a<= 10 && b>=1 && b <= 10 && Position1[a][b]==0 && Position1[a+1][b+1]==1 && Position1[a+2][b+2]==1 && Position1[a+3][b+3]==0 && Position1[a+4][b+4]==1 &&Position1[a+5][b+5]==0 && Position2[a][b]==0 && Position2[a+3][b+3]==0 && Position2[a+5][b+5]==0)
		{
			count ++;
			diagona1 ++;
		}
		if(a== m-4)
		{
			a ++;
			b ++;
		}
	}

	for(a = m-4,b = j+4; a<= m-1; a++, b--)  //�������޶Խ���
	{
		if(a >=1 && a<= 10 && b>=6 && b <= 15 && Position1[a][b]==0 && Position1[a+1][b-1]==1 && Position1[a+2][b-2]==1 && Position1[a+3][b-3]==0 && Position1[a+4][b-4]==1 &&Position1[a+5][b-5]==0 && Position2[a][b]==0 && Position2[a+3][b-3]==0 && Position2[a+5][b-5]==0)
		{
			count ++;
			diagona2 ++;
		}
		if(a== m-4)
		{
			a ++;
			b --;
		}
	}

	//_��_���_
	for(a = j-4; a<=j-1; a++)   //��
	{
		if(a >=1 && a<= 10 &&Position1[m][a]==0 && Position1[m][a+1]==1 && Position1[m][a+2]==0 && Position1[m][a+3]==1 && Position1[m][a+4]==1 &&Position1[m][a+5]==0 && Position2[m][a]==0 && Position2[m][a+2]==0 && Position2[m][a+5]==0)
		{
			count ++;
			row ++;
		}
		if(a== j-3)
			a ++;
	}

	for(a = j-4; a<=m-1; a ++)  //��
	{
		if(a >=1 && a<= 10 && Position1[a][j]==0 && Position1[a+1][j]==1 && Position1[a+2][j]==0 && Position1[a+3][j]==1 && Position1[a+4][j]==1 &&Position1[a+5][j]==0 && Position2[a][j]==0 && Position2[a+2][j]==0 && Position2[a+5][j]==0)
		{
			count ++;
			column ++;
		}
		if(a== m-3)
			a ++;
	}

	for(a = m-4,b = j-4; a<= m-1; a++, b++)  //һ�����޶Խ���
	{
		if(a >=1 && a<= 10 && b>=1 && b <= 10 && Position1[a][b]==0 && Position1[a+1][b+1]==1 && Position1[a+2][b+2]==0 && Position1[a+3][b+3]==1 && Position1[a+4][b+4]==1 &&Position1[a+5][b+5]==0 && Position2[a][b]==0 && Position2[a+2][b+2]==0 && Position2[a+5][b+5]==0)
		{
			count ++;
			diagona1 ++;
		}
		if(a== m-3)
		{
			a ++;
			b ++;
		}
	}

	for(a = m-4,b = j+4; a<= m-1; a++, b--) //�������޶Խ���
	{
		if(a >=1 && a<= 10 && b>=6 && b <= 15 && Position1[a][b]==0 && Position1[a+1][b-1]==1 && Position1[a+2][b-2]==0 && Position1[a+3][b-3]==1 && Position1[a+4][b-4]==1 &&Position1[a+5][b-5]==0 && Position2[a][b]==0 && Position2[a+2][b-2]==0 && Position2[a+5][b-5]==0)
		{
			count ++;
			diagona2 ++;
		}
		if(a== m-3)
		{
			a ++;
			b --;
		}
	}

	if(count == 2)
	{
		if( row == 2 || column == 2 || diagona1 == 2 || diagona2 == 2 )
			return 0;
		else 
			return 1;
	}

	else if(count >= 3)
		return 1;
	else 
		return 0;
}