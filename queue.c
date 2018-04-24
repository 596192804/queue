#include"queue.h"
#include<stdlib.h>
#include<stdio.h>
void InitAQueue(AQueue *Q)//循环队列初始化
{
    Q->front=0;
    Q->rear=0;
    Q->data_size=0;
    for(int i=0;i<MAXQUEUE;i++)
    {
        Q->data[i]=NULL;
    }
}

void DestoryAQueue(AQueue *Q)//销毁队列
{
  for(int i=0;i<MAXQUEUE;i++)
    {
        Q->data[i]=NULL;
    }
    Q->front=0;
    Q->rear=0;
    Q->data_size=0;
}

Status IsFullAQueue(const AQueue *Q)//检测循环队列是否满
{
	if ((Q->rear+1) % MAXQUEUE==Q->front)
		return TRUE;
	else return FLASE;
}

Status IsEmptyAQueue(const AQueue *Q)//检测循环队列是否为空
{
	if (Q->rear == Q->front)
		return TRUE;
	else return FLASE;
}

Status GetHeadAQueue(AQueue *Q, void **e)//查看循环队列队头元素
{
	if (IsEmptyAQueue(Q) == TRUE)
		return FLASE;
	else
	{
		e =&Q->data[Q->front];
		return TRUE;	
	}
}

int LengthAQueue(AQueue *Q)// 确定循环队列的长度
{
	int t = Q->rear;
	if (Q->rear<Q->front)
		t += MAXQUEUE;
	return(t - Q->front + 1);
}

Status EnAQueue(AQueue *Q, void *data)//循环队列入列
{
	if (IsFullAQueue(Q) == TRUE)
		return FLASE;
	Q->data[Q->rear] = data;
	Q->rear = (Q->rear+1) % MAXQUEUE;
	Q->data_size += sizeof(data);
	return TRUE;
}

Status DeAQueue(AQueue *Q)//出队
{
	if (IsEmptyAQueue(Q) == TRUE)
		return FLASE;
	Q->data_size -= sizeof(Q->data[Q->front]);
	Q->data[Q->front++] = NULL;
	if (Q->front == MAXQUEUE)
		Q->front -= MAXQUEUE;
	return TRUE;
}

void ClearAQueue(AQueue *Q)//清空循环队列
{
	DestoryAQueue(Q);
}

Status TraverseAQueue(const AQueue *Q, void(*foo)(void *q))//遍历循环队列
{
	int t = Q->front;
	if (IsEmptyAQueue(Q) == TRUE)
		return FLASE;
	for (; t != Q->rear;)
	{
		(*foo)(Q->data[t++]);
		if (t == MAXQUEUE)
			t -= MAXQUEUE;
	}
	return TRUE;
}

void APrint(void *q)//循环队列输出操作
{
	if (sizeof(q) == sizeof(int))
	{
		printf("%d\t", *(int*)q);
	}
	else if (sizeof(q) == sizeof(char))
	{
		printf("%c\t", *((char*)q));
	}
	else if (sizeof(q) == sizeof(float))
	{
		printf("%f\t", *((float*)q));
	}

}

void InitLQueue(LQueue *Q)//链队列初始化
{
	Q->front = NULL;
	Q->rear = NULL;
	Q->data_size = 0;
}

void DestoryLQueue(LQueue *Q)//销毁循环队列
{
  Node* p=Q->front;
  for(;Q->front!=NULL;)
  {
    Q->front=Q->front->next;
    free(p);
    p=Q->front;
  }
  Q->data_size=0;
}

Status IsEmptyLQueue(const LQueue *Q)//检测链式队列是否为空
{
  if(Q->front==NULL&&Q->rear==NULL)
    return TRUE;
  else
    return FLASE;
}

Status GetHeadLQueue(LQueue *Q, void **e)//查看链式队列的对头元素
{
  if(IsEmptyLQueue(Q)==TRUE)
    return FLASE;
  *e=Q->front->data;
  return TRUE;
}

int LengthLQueue(LQueue *Q)//确定循环队列的长度
{
  return(Q->data_size/sizeof(Q->front->data));
}

Status EnLQueue(LQueue *Q, void *data)//链式队列的入列
{
  if(IsEmptyLQueue(Q)==TRUE)
    return FLASE;
  Node* p=(Node*)malloc(sizeof(Node));
  p->data=data;
  p->next=NULL;
  Q->rear=p;
  if(Q->data_size==0)
    Q->front=p;
  Q->data_size+=sizeof(data);
  return TRUE;
}

Status DeLQueue(LQueue *Q)//链式队列出列
{
  if(IsEmptyLQueue(Q)==TRUE)
    return FLASE;
  Node* p;
  p=Q->front;
  Q->data_size-=sizeof(Q->front->data);
  Q->front=Q->front->next;
  free(p);
  p=Q->front;
  return TRUE;
}

void ClearLQueue(LQueue *Q)//清空链式队列
{
  DestoryLQueue(Q);
}

Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))//遍历链式队列
{
 Node* p=Q->front;
 if(IsEmptyLQueue(Q)==TRUE)
    return FLASE;
  for(;p!=NULL;p=p->next)//Q为const,不能改变Q内部的值
  {
      (*foo)(p->data);
  }
  return TRUE;
}

 void LPrint(void *q)//链队列输出操作
 {
    int choose=0,flag=0;
    void*p=q;
    for(flag=1;flag!=0;)
    {
        printf("\n\t1:int\n\t2:float\n\t3:char\n\t请输入你的选择：");
        scanf_s("%d",&choose);
        switch(choose)
        {
            case 1:printf("%d",*(int*)p);
                   flag=0;break;
            case 2:printf("%f",*(float*)p);
                   flag=0;break;
            case 3:printf("%c",*(char*)p);
                   flag=0;break;
            default:printf("无效选择，请重选\n");
        }
    }

 }

