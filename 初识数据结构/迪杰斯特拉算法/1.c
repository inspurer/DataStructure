#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define max 10000
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
vexnode ga[20];
int edge[10][10];
int dnum,bnum;
void initedge()
{
	int i,j;
	for(i=0;i<dnum;i++)
		for(j=0;j<dnum;j++)
		{
			if(i==j)
				edge[i][j]=0;
			else
				edge[i][j]=max;
		}
}
typedef struct{
	char data[100];
	int top;
}seqstack;
void initstack (seqstack * s)
{
	s->top=0;
}
void push (seqstack * s,int e)
{
	s->data[s->top]=e;
	s->top++;
}
int pop (seqstack * s)
{
	int r;
	s->top--;
	r=s->data[s->top];
	return r;
}
int stackempty (seqstack * s)
{
	if(s->top==0)
		return 1;
	return 0;
}
seqstack s;
void creat ()
{
	int i,j,k,per;
	int num[10];
	edgenode *s;
	printf("输入顶点数和边数(顶点从0开始编号):\n");
	scanf("%d %d",&dnum,&bnum);
	for(i=0;i<dnum;i++)
		num[i]=i;
	for(i=0;i<dnum;i++)
	{
		ga[i].vertex=num[i];
		ga[i].link=NULL;
	}
	initedge();
	printf("请输入路径和权值:\n");
	for(k=0;k<bnum;k++)
	{
		scanf("%d%d%d",&i,&j,&per);
		s=(edgenode*)malloc(sizeof(edgenode));
		s->adjvex=j;
		s->next=ga[i].link;
		ga[i].link=s;
		edge[i][j]=per;
	}
}
void shortpath(int v)
{
	int i,j,w;
	int pre;
	int dist[10];
	int path[10];
	int s[10];
	for(i=0;i<dnum;i++)
	{
		dist[i]=edge[v][i];
		s[i]=0;
		if(i!=v&&dist[i]<max)
			path[i]=v;
		else
			path[i]=-1;
	}
	s[v]=1;
	dist[v]=0;
	for(i=0;i<dnum-1;i++)
	{
		int min=max;
		int u=v;
		for(j=0;j<dnum;j++)
			if(!s[j]&&dist[j]<min)
			{
				u=j;
				min=dist[j];
			}
			s[u]=1;
			for(w=0;w<dnum;w++)
				if(!s[w]&&edge[u][w]<max&&dist[u]+edge[u][w]<dist[w])
				{
					dist[w]=dist[u]+edge[u][w];
					path[w]=u;
				}
	}
	initstack(&s);
	for(i=0;i<dnum;i++)
	{
		if(i==v)
		{
			printf("从%d出发搜索到达%d得到的最短路径为:无\n其距离为0\n",v,i);
			continue;
		}
		printf("从%d出发搜索到达%d得到的最短路径为:",v,i);
		push(&s,i);
		pre=path[i];
		while(pre!=v)
		{
			push(&s,pre);
			pre=path[pre];
		}
		while(!stackempty(&s))
		{
			j=pop(&s);
			if(j!=i)
			printf("%d->",j);
			else
				printf("%d\n",j);
		}
		printf("其距离为%d\n",dist[i]);
	}
}
int main()
{
	int i;
	creat();
	printf("从哪一个点开始搜索?(<%d)\n",dnum);
	scanf("%d",&i);
	shortpath(i);
	return 0;
}

