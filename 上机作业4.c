#include <stdio.h>
#include <stdlib.h>
#define N 8
#define M 15

int W[N]={5,29,7,8,14,23,3,11};
int WEI[M],PRT[M],LCH[M],RCH[M],c=0,d=0;

void HUFM();
void SELECT(int n);
int L_length();

main()
{
	int b=0,L;
	HUFM();
	printf("\tWEI\tPRT\tLCH\tRCH\n");
	for(b;b<M;b++)							//循环输出数组各个元素
	{	
		printf("%d\t%d\t%d\t%d\t%d\n",b,WEI[b],PRT[b],LCH[b],RCH[b]);
	}
	printf("带权路径长度是%d.\n",L=L_length());

}

void HUFM()
{
	int k,i,BT;
	for(i=0;i<M;i++) PRT[i]=LCH[i]=RCH[i]=0;//数组元素置初值
	for(i=0;i<N;i++) WEI[i]=W[i];
	for(k=N;k<M;k++)
	{
		SELECT(k);							//调用select函数
		PRT[c]=k;
		PRT[d]=k;
		LCH[k]=c;
		RCH[k]=d;
		WEI[k]=WEI[c]+WEI[d];
	}
	BT=M;
	return;
}

void SELECT(int n)
{
	int k;
	c=0;
	while(PRT[c]!=0) c++;
	for(k=c;k<n;k++)
		if(PRT[k]==0 && WEI[k]<WEI[c]) c=k;
	d=0;
	while(d==c || PRT[d]!=0) d++;
	for(k=d;k<n;k++)
		if(PRT[k]==0 && k!=c && WEI[k]<WEI[d]) d=k;
	return;
}

int L_length()
{
	int i,j,m,L=0;
	for(i=0;i<N;i++)
	{
		m=0;
		j=i;
		while(PRT[j]!=0)
		{
			m++;
			j=PRT[j];
		}
		L+=m*WEI[i];
	}
	return L;
}
