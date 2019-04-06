#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int MAX(int a[],int p,int q)//MAX函数
{
	int m,m1,m2;
	if(p==q)//比较区间端点
	{
		m=a[p];
	}
	else
	{
		m1=MAX(a,p,(p+q)/2);//递归调用MAX函数，求前半部分的最大值
		m2=MAX(a,(p+q)/2+1,q);//求后半部分的最大值
		if(m1>m2)
			m=m1;
		else m=m2;
	}
	return m;
}

void main()
{
	int i,a[100],m;
	int Max=a[0];//初始化最大值为数组中第一个元素

	srand((unsigned)time(NULL));//随机数种子初始化
	for(i=0;i<100;i++)//从0开始循环向数组里存入100个随机数
	{
		a[i]=rand()%1000;
	}

	for(i=1;i<100;i++)//循环比较
	{
		if(Max<=a[i])
			Max=a[i];
	}
	printf("方法1:数组中的最大值是 %d\n",Max);

	m=MAX(a,0,99);
	printf("方法2:数组中的最大值是 %d.\n",m);
}
