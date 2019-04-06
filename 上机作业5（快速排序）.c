#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

int a[N];
void QKSORT(int x,int y);
int SPLIT(int x,int y,int i);
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

	QKSORT(0,N-1);

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

void QKSORT(int x,int y)
{
	int k,i;
	k=(x+y)/2;
	if(x<y)
	{
		
		i=SPLIT(x,y,k);
		QKSORT(x,i-1);
		QKSORT(i+1,y);
	}
	return;
}

int SPLIT(int x,int y,int i)
{
	int j,T,k;
	k=(x+y)/2;

	T=a[k];
	a[k]=a[x];
	i=x;
	j=y;
	while(i!=j)
	{
		while(a[j]>=T && i<j) j--;
		if(i<j)
		{
			a[i]=a[j];
			i++;
			while(a[i]<=T && i<j) i++;
			if(i<j)
			{
				a[j]=a[i];
				j--;
			}
		}
	}
	a[i]=T;
	return i;
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