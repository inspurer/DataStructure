#include<stdio.h>
#include<malloc.h>
#include<string.h>
typedef struct node1
{
	int adjvex;        
	struct node1 *next;
}edgenode;
typedef struct
{
	int vertex;
	edgenode *link;
}vexnode;
typedef struct node {	
    int data;	         //队列结点数据
    struct node *link;            //结点链指针
}QueueNode;
typedef struct {
    QueueNode *rear,*front;
}LinkQueue;
LinkQueue Q;
void InitQueue(LinkQueue *Q){//void InitQueue(LinkQueue Q){
    Q->rear=Q->front=NULL;  // Q.rear=Q.front=NULL;
}                           //
int QueueEmpty(LinkQueue *Q ) {
    return Q->front==NULL;
}
int EnQueue (LinkQueue *Q,int x ) {//入队
    QueueNode *p=(QueueNode *)malloc(sizeof(QueueNode));
    p->data=x;  
	p->link=NULL;
    if(Q->front==NULL )  
        //空,创建第一个结点
       Q->front=Q->rear=p;
    else Q->rear->link=p; //入队
		 Q->rear=p;
    return 1;
}
int DeQueue(LinkQueue *Q) {//出队
//删去队头结点，并返回队头元素的值
	int x;
	QueueNode * p;
    if(QueueEmpty(Q)) 
		return 0;	//判队空
    p=Q->front;		
    x=p->data;	//保存队头的值
 	Q->front= Q->front->link; 	//新队头
	free(p);
    return x;				
}
vexnode ga[20];
int dnum,bnum;
void creat ()
{
	int i,j,k;
	int num[10];
	edgenode *s;
	printf("输入顶点个数:\n");
	scanf("%d",&dnum);
	printf("输入边个数:\n");
	scanf("%d",&bnum);
	printf("输入顶点ID:\n");
	for(i=1;i<=dnum;i++)
		scanf("%d",&num[i]);
	for(i=1;i<=dnum;i++)
	{
		ga[i].vertex=num[i];
		ga[i].link=NULL;
	}
	printf("请输入各个顶点对：\n");
	for(k=0;k<bnum;k++)
	{
		scanf("%d%d",&i,&j);
		s=(edgenode*)malloc(sizeof(edgenode));
		s->adjvex=j;
		s->next=ga[i].link;
		ga[i].link=s;
		s=(edgenode*)malloc(sizeof(edgenode));
		s->adjvex=i;
		s->next=ga[j].link;
		ga[j].link=s;
	}
}
int visited[20];
void DFSL(int i)
{
	edgenode *p;
	printf("node:%d\n",ga[i].vertex);
	visited[i]=1;
	p=ga[i].link;
    while(p!=NULL)
	{
		if(!visited[p->adjvex])
			DFSL(p->adjvex);
		p=p->next;
	}
}
void BFSL(int k)
{
	edgenode *p;
    InitQueue(&Q);
	printf("node:%d\n",ga[k].vertex);
	visited[k]=1;
	EnQueue(&Q,k);
	while(!QueueEmpty(&Q))
	{
		k=DeQueue(&Q);
		p=ga[k].link;
		while(p!=NULL)
		{
			if(!visited[p->adjvex])
			{
				
				printf("node:%d\n",ga[p->adjvex].vertex);
				visited[p->adjvex]=1;
				EnQueue(&Q,p->adjvex);
			}
			p=p->next;
		}
	}
}
void count()
{
	int count1=0,count2=0,i,j;
	edgenode *p;
	printf("求哪一个顶点的出度和入度\n");
	scanf("%d",&i);
	p=ga[i].link;
	while(p)
	{
		count1++;
		p=p->next;
	}
	for(j=1;j<=dnum;j++)
	{
		p=ga[j].link;
		while(p)
		{
			if(p->adjvex==i)
				count2++;
			p=p->next;
		}
	}
	printf("顶点%d的出度:%d  入度:%d\n",i,count1,count2);
}
void add()
{
	int i,j;
	edgenode *p,*q;
	q=(edgenode *)malloc(sizeof(edgenode));
	q->next=NULL;
	printf("新增哪一条边:\n");
	scanf("%d %d",&i,&j);
	q->adjvex=j;
	p=ga[i].link;
	while(p->next)
		p=p->next;
	p->next=q;
	q->adjvex=i;
	p=ga[j].link;
	while(p->next)
		p=p->next;
	p->next=q;
}
void delet()
{
	int i,j;
	edgenode *p,*q;
	printf("你想删除哪一边\n");
	scanf("%d %d",&i,&j);
	p=ga[i].link;
	if(p->adjvex==j)
		ga[i].link=p->next;
	else
		while(p)
		{
			q=p;
			p=p->next;
			if(p->adjvex==j)
			{
				q->next=p->next;
				free(p);
				break;
			}
		}
	p=ga[j].link;
	if(p->adjvex==i)
		ga[j].link=p->next;
	else
		while(p)
		{
			q=p;
			p=p->next;
			if(p->adjvex==i)
			{
				q->next=p->next;
				free(p);
				break;
			}
		}
}
void main()
{
	memset(visited,0,80);
	creat();
	printf("深度优先遍历如下:\n");
	DFSL(1);
	printf("广度优先遍历如下:\n");
	memset(visited,0,80);
	BFSL(1);
	count();
	add();
	printf("广度优先遍历如下:\n");
	memset(visited,0,80);
    BFSL(1);
	delet();
	printf("广度优先遍历如下:\n");
	memset(visited,0,80);
	BFSL(1);
}

