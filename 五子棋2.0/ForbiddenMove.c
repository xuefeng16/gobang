#include<stdio.h>
#include "FiveInRow.h"

int DoubleThree(int m, int j);
int DoubleFour(int m, int j);
int Overlong(int m, int j);

int ForbiddenMove(int m, int j)   //�жϽ���,�������ַ���1�����Ľ��ַ���2���������ַ���3�����ڽ���Ҫ������λ�ڽ�����ϣ����ֻ��ɨ��������Ӹ����ĵ�
{	
	if(DoubleThree(m, j))         //DoubleThree(int,int)�����������ж��������֣��������ַ���1�����򷵻�0
		return 1;

	else if(DoubleFour(m, j))	  //DoubleFour(int,int)�����������ж����Ľ��֣��������ַ���1�����򷵻�0
		return 2;
	
	else if(Overlong(m, j))       //Overlong(int,int)�����������жϳ������֣��������ַ���1�����򷵻�0
		return 3;
	
	else
		return 0;
}