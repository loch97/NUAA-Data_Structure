#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int MAX(int a[],int p,int q)//MAX����
{
	int m,m1,m2;
	if(p==q)//�Ƚ�����˵�
	{
		m=a[p];
	}
	else
	{
		m1=MAX(a,p,(p+q)/2);//�ݹ����MAX��������ǰ�벿�ֵ����ֵ
		m2=MAX(a,(p+q)/2+1,q);//���벿�ֵ����ֵ
		if(m1>m2)
			m=m1;
		else m=m2;
	}
	return m;
}

void main()
{
	int i,a[100],m;
	int Max=a[0];//��ʼ�����ֵΪ�����е�һ��Ԫ��

	srand((unsigned)time(NULL));//��������ӳ�ʼ��
	for(i=0;i<100;i++)//��0��ʼѭ�������������100�������
	{
		a[i]=rand()%1000;
	}

	for(i=1;i<100;i++)//ѭ���Ƚ�
	{
		if(Max<=a[i])
			Max=a[i];
	}
	printf("����1:�����е����ֵ�� %d\n",Max);

	m=MAX(a,0,99);
	printf("����2:�����е����ֵ�� %d.\n",m);
}
