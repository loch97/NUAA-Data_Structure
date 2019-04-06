#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

void createList();
void createList_L(int a[]);
int print(int point);
void delete_point(int point);

struct node1     //定义顺序表
{
	int num;
	struct node2 *p;
}gewei[10];

struct node2    //定义线性链表
{
	int info;
	struct node2 *next;
}*p[10][100];

void main()
{
	int a[100],i,p_num,choice;
	srand((unsigned)time(NULL));        //初始化随机数种子
	
	createList();
	for(i=0;i<100;i++) a[i]=rand()%100; //向数组中存入100个随机数
	createList_L(a);
	while(1)
	{
		printf("请输入要查询的关键字:\n");
		scanf("%d",&p_num);
		if(print(p_num)!=0)
		{
			printf("请输入要删除的数据:\n");
			scanf("%d",&p_num);
			delete_point(p_num);
		}
		printf("是否退出? 1 for yes, 0 for no\n");
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
		for(k=0;k<100;k++) p[j][k]=(struct node2*)malloc(sizeof(struct node2)); //向系统申请结点的存储单元
	}
	for(i=0;i<10;i++)
	{
		gewei[i].num=i;
		gewei[i].p=p[i][0];
	}
}

void createList_L(int a[]) //创建线性链表
{
	int i=0,b[10]={0},c=0;
	for(i=0;i<100;i++)
	{
		 c=a[i]%10;
		 (*p[c][b[c]]).info=a[i];       //结点赋值
		 p[c][b[c]]->next=p[c][b[c]+1]; //指针赋值
		 b[c]++;
	}
	for(c=0;c<10;c++)					//处理链表末尾的指针为空指针
	{
		if(b[c]==0) gewei[c].p=NULL;
		else
			p[c][b[c]-1]->next=NULL;
	}
}

int print(int point) //按关键字输出
{
	struct node2 *z=gewei[point].p;

	if(gewei[point].p==NULL)
	{
		printf("无数据.\n");
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

void delete_point(int point) //删除所选的数据
{
	int c=point%10,j=0;
	struct node2 *z=gewei[c].p,*a,*b;
	a=gewei[c].p;
	for(;;)
	{
		if((*z).next==NULL && (*z).info==point) {gewei[c].p=NULL;free((*a).next);z=gewei[c].p;j++;break;}  //线性链表第一位需要删除的情况
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
	if(j!=0) printf("删除成功!\n");
	else printf("无此数据!!\n");
}