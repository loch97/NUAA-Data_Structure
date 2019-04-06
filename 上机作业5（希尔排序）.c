#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

int a[N];
void SHLSORT(int n);
int SORT(int x);

void main()
{
	int i,x,y;

	srand((unsigned)time(NULL));//随机数种子初始化
	printf("随机产生的这%d个数是:\n",N);
	for(i=0;i<N;i++)			//从0开始循环向数组里存入100个随机数
	{
		a[i]=rand()%1000;
		if(i%10==0) printf("\n");
		printf("%d\t",a[i]);
	}

	SHLSORT(N);
	printf("\n排序之后,这%d个数是:\n",N);
	for(i=0;i<N;i++)
	{
		if(i%10==0) printf("\n");
		printf("%d\t",a[i]);
	}

	printf("\n请输入要查找的数据:\n");
	scanf("%d",&x);
	y=SORT(x);
	if(y==-1) printf("该数据不存在!\n");
	else printf("%d是第%d位.\n",x,y);
	return;
}

void SHLSORT(int n)
{
	int i,j,T,h=n/2;
	while(h>0)
	{
		for(j=h;j<n;j++)
		{
			T=a[j];
			i=j-h;
			while(i>=0 && a[i]>T)
			{
				a[i+h]=a[i];
				i-=h;
			}
			a[i+h]=T;
		}
		h=h/2;
	}
	return;
}

int SORT(int x)
{
	int k,low=0,high=N;

	while(low<=high)
	{
		k=(low+high)/2;
		if(x==a[k]) return k+1;
		else if(a[k]>x) high=k-1;
		else low=k+1;
	}
	return -1;
}