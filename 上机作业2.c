#include <stdio.h>
#include <stdlib.h>
#define M 1000

int S[M][3];
int top;

int ACK1(int a,int b,int c)                //�ݹ麯���ĵݹ��㷨
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
		else ack=ACK1(a-1,ACK1(a,b,c-1),b);//�ݹ����ACK����
	return ack;
}

void PUSH(int a,int b,int c)				//��ջ
{
	if(top==M-1) printf("Stack-overflow.\n");//�ж��Ƿ�����
	top+=1;
	S[top][0]=a;
	S[top][1]=b;
	S[top][2]=c;
	return;
}

void POP(int *a,int *b,int *c)				//��ջ
{
	if(top==-1) printf("Stack-underflow.\n");//�ж��Ƿ�����
	else
	{
		*a=S[top][0];
		*b=S[top][1];
		*c=S[top][2];
		top-=1;
	}
	return;
}

int ACK2(int a,int b,int c)					//�ǵݹ��㷨
{
	int t=0;
	top=-1;
	PUSH(a,b,c);
	while(top!=-1)							//�ж��Ƿ�ջ��
	{
		POP(&a,&b,&c);
		if(a!=0&&c!=0)
		{
			PUSH(a,b,c);
			PUSH(a,b,c-1);
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
			if(top!=-1)
			{
				POP(&a,&b,&c);
				PUSH(a-1,t,b);
			}
		}
		
	}
	return t;

}



void main()
{
	int a,b,c,f1,f2;

	printf("������������:\n");
	scanf("%d%d%d",&a,&b,&c);

	f1=ACK1(a,b,c);
	f2=ACK2(a,b,c);	
	printf("ACK�����ݹ��㷨��ֵ��%d.\nACK�����ǵݹ��㷨��ֵ��%d\n",f1,f2);
	return;
}