#include <stdio.h>
#include <stdlib.h>
#define M 50
#define element_type int

typedef struct 
{
    element_type data[M];
    int top;
}Stack;

int ACK1(int a,int b,int c)//递归函数的递归算法
{
	int ack;
	if(a==0) ack=b+1;
	else
		if(c==0)
		{
			if(a==1) ack=b;
			else
				if(a==2) ack=0;
				else
					if(a==3) ack=1;
					else ack=2;
		}
		else ack=ACK1(a-1,ACK1(a,b,c-1),b);
	return ack;
}

//开始
Stack * init_stack()
{
    Stack * stack;
    stack = (Stack*)malloc(sizeof(element_type)*M);
    stack->top = -1;
    return stack;
}

int is_empty(Stack *stack)
{
    if(stack->top==-1)
	{
        printf("栈空\n");
        return 1;
    }
    return 0;
}

int is_full(Stack *stack)
{
    if(stack->top==M-1)
	{
        printf("栈满\n");
        return 1;
    }
    return 0;
}

void PUSH(Stack * stack,element_type elem)
{
    if(!is_full(stack)){
        stack->data[++stack->top]=elem;
    }
}

element_type POP(Stack *stack)
{
    if(is_empty(stack)){
        return -1;
    }
    return stack->data[stack->top--];
}
//结束

int ACK2(int a,int b,int c)//递归函数的非递归算法
{
	int t=0;
	Stack *S1,*S2,*S3;
    S1= init_stack();
	S2= init_stack();
	S3= init_stack();
	PUSH(S1,a);
	PUSH(S2,b);
	PUSH(S3,c);
	while(S1->top!=-1)
	{
		a=POP(S1);
		b=POP(S2);
		c=POP(S3);
		if(a!=0&&c!=0)
		{
			PUSH(S1,a);
			PUSH(S2,b);
			PUSH(S3,c);
			PUSH(S1,a);
			PUSH(S2,b);
			PUSH(S3,c-1);
		}
		else
		{
			if(a==0) t=b+1;
			else
			{
				if(a==1) t=b;
				else if(a==2) t=0;
				else if(a==3) t=1;
				else t=2;
			}
			if(S1->top!=-1)
			{
				a=POP(S1);
				b=POP(S2);
				c=POP(S3);
				PUSH(S1,a-1);
				PUSH(S2,t);
				PUSH(S3,b);
			}
		}
	}
	return t;
}

 

main()
{
	int a,b,c,f,slc;

	printf("请输入三个数:\n");
	scanf("%d%d%d",&a,&b,&c);

	printf("请选择算法,输入0为递归算法,输入1为非递归算法.\n");
	scanf("%d",&slc);
	if(slc==0) f=ACK1(a,b,c);
	else if(slc==1) f=ACK2(a,b,c);
	else
	{
		printf("输入错误请重新输入.\n");
		exit(0);
	}					
	printf("ACK函数的值是%d.\n",f);
}