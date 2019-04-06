#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

void createList();
void createList_L(int a[]);
int print(int point);
void delete_point(int point);

struct node1     //����˳���
{
	int num;
	struct node2 *p;
}gewei[10];

struct node2    //������������
{
	int info;
	struct node2 *next;
}*p[10][100];

void main()
{
	int a[100],i,p_num,choice;
	srand((unsigned)time(NULL));        //��ʼ�����������
	
	createList();
	for(i=0;i<100;i++) a[i]=rand()%100; //�������д���100�������
	createList_L(a);
	while(1)
	{
		printf("������Ҫ��ѯ�Ĺؼ���:\n");
		scanf("%d",&p_num);
		if(print(p_num)!=0)
		{
			printf("������Ҫɾ��������:\n");
			scanf("%d",&p_num);
			delete_point(p_num);
		}
		printf("�Ƿ��˳�? 1 for yes, 0 for no\n");
		scanf("%d",&choice);
		if(choice==1) exit(0);
		system("cls");
	}
	return;
}

void createList()
{
	int i=0,j=0,k=0;
	for(j=0;j<10;j++)
	{
		for(k=0;k<100;k++) p[j][k]=(struct node2*)malloc(sizeof(struct node2)); //��ϵͳ������Ĵ洢��Ԫ
	}
	for(i=0;i<10;i++)
	{
		gewei[i].num=i;
		gewei[i].p=p[i][0];
	}
}

void createList_L(int a[]) //������������
{
	int i=0,b[10]={0},c=0;
	for(i=0;i<100;i++)
	{
		 c=a[i]%10;
		 (*p[c][b[c]]).info=a[i];       //��㸳ֵ
		 p[c][b[c]]->next=p[c][b[c]+1]; //ָ�븳ֵ
		 b[c]++;
	}
	for(c=0;c<10;c++)					//��������ĩβ��ָ��Ϊ��ָ��
	{
		if(b[c]==0) gewei[c].p=NULL;
		else
			p[c][b[c]-1]->next=NULL;
	}
}

int print(int point) //���ؼ������
{
	struct node2 *z=gewei[point].p;

	if(gewei[point].p==NULL)
	{
		printf("������.\n");
		return 0;
	}
    else
    {
		for(;;)
		{
			printf("%d ",(*z).info);
			z=(*z).next;
			if(z==NULL) break;
		}
    }
	printf("\n");
	return 1;
}

void delete_point(int point) //ɾ����ѡ������
{
	int c=point%10,j=0;
	struct node2 *z=gewei[c].p,*a,*b;
	a=gewei[c].p;
	for(;;)
	{
		if((*z).next==NULL && (*z).info==point) {gewei[c].p=NULL;free((*a).next);z=gewei[c].p;j++;break;}  //���������һλ��Ҫɾ�������
		else if((*z).info==point) {gewei[c].p=(*a).next;z=gewei[c].p;free(a);a=z;j++;}
		else {z=(*z).next;break;}
	}
	if(a!=NULL) b=(*a).next;
	if(z!=NULL)
	{
		for(;;)
		{
			if((*z).next==NULL && (*z).info==point) {free((*a).next);a->next=NULL;j++;break;}
			else if((*z).next==NULL) break;
			else if((*z).info==point) {z=(*z).next;b=(*b).next;free((*a).next);a->next=b;j++;}
			else {z=(*z).next;a=b;b=(*b).next;}
		}
	}
	if(j!=0) printf("ɾ���ɹ�!\n");
	else printf("�޴�����!!\n");
}