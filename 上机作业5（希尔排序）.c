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

	srand((unsigned)time(NULL));//��������ӳ�ʼ��
	printf("�����������%d������:\n",N);
	for(i=0;i<N;i++)			//��0��ʼѭ�������������100�������
	{
		a[i]=rand()%1000;
		if(i%10==0) printf("\n");
		printf("%d\t",a[i]);
	}

	SHLSORT(N);
	printf("\n����֮��,��%d������:\n",N);
	for(i=0;i<N;i++)
	{
		if(i%10==0) printf("\n");
		printf("%d\t",a[i]);
	}

	printf("\n������Ҫ���ҵ�����:\n");
	scanf("%d",&x);
	y=SORT(x);
	if(y==-1) printf("�����ݲ�����!\n");
	else printf("%d�ǵ�%dλ.\n",x,y);
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