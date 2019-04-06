#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

struct node
{
	struct node *L;
	int num;
	struct node *R;
}*b[100];

struct node* Inbsort(int a[100],int n,struct node *BT);
void Intrav(struct node *BT);

void main()
{
	int i,a[100];
	struct node *BT=NULL; 

	srand((unsigned)time(NULL));			//��������ӳ�ʼ��
	printf("��������100���������:\n");
	for(i=0;i<100;i++)						//��0��ʼѭ�������������100�������
	{
		a[i]=rand()%1000;
		printf("%d\t",a[i]);
	}

	BT=Inbsort(a,100,BT);
	printf("���ɶ�������������������Ľ��Ϊ:\n");
	Intrav(BT);
	return;
}

struct node* Inbsort(int a[100],int n,struct node *BT)
{
	int k;
	struct node *q;
	q=(struct node*)malloc(sizeof(struct node));

	for(k=0;k<n;k++)
	{
		b[k]=(struct node*)malloc(sizeof(struct node));
		b[k]->num=a[k];
		b[k]->L=NULL;
		b[k]->R=NULL;
		q=BT;
		if(q==NULL) BT=b[k];
		else 
		{
			while(q->L!=b[k] && q->R!=b[k])
			{
				if(b[k]->num < q->num)
				{	
					if(q->L!=NULL) q=q->L;
					else q->L=b[k];
				}
				else
				{
					if(q->R!=NULL) q=q->R;
					else q->R=b[k];
				}
			}
		}
	}
	return BT;
}

void Intrav(struct node *BT)
{
	if(BT!=NULL)
	{
		Intrav(BT->L);
		printf("%d\t",BT->num);
		Intrav(BT->R);
	}
	return;
}