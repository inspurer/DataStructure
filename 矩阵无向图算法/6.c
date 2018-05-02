#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define  n  8
typedef  char  vextype;
typedef  int  adjtype;
typedef  struct xt
{ 
	vextype  vex[n];
    adjtype  arcs[n][n];
} graph;
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
graph *ga;
int visited[n];
void creat()
{
	int i,j,k;  
	printf("Input the vexs:\n");
	for(i=0;i<6;i++)
	{
      scanf("%c",&ga->vex[i]);
	  fflush(stdin);
	}
	printf("Input the arcs:\n");
	for ( i=0; i<n; i++ )
		for ( j=0; j<n; j++ )
          ga->arcs[i][j]=0;
		for ( k=0; k<n; k++ )
		{ 
			scanf("%d%d",&i,&j);
			i--;
			j--;
			ga->arcs[i][j]=1;  
			ga->arcs[j][i]=1; 
		}
}
DFS(int i) /*从vi+1出发搜索用邻接矩阵表示的图*/
{ int j;
  printf("node:%c\n",ga->vex[i]);/*访问出发点vi+1*/
  visited[i]=1; /*标记vi+1 已访问过*/
  for ( j=0; j<n; j++ ) /*依次搜索vi+1 的邻接点*/
  if ((ga->arcs[i][j]==1)&&(!visited[j])) 
      DFS(j); 
   /*若vi+1的邻接点vj+1未曾访问过，则从vj+1 出发进行搜索*/
}
BFS(int i) 
 /*从vk+1出发广度优先搜索用邻接矩阵表示的图*/
{ int visited[n];
  int j;
  memset(visited,0,4*n);
  InitQueue(&Q);  /*置空队Q*/
  printf("node:%c\n",ga->vex[i]);  /*访问出发点vk+1*/
  visited[i]=1; /*标记已访问过*/
  EnQueue(&Q,i); /*已访问过的顶点（序号）入队*/
  while (!QueueEmpty(&Q))   /*队非空时执行*/
  { 
	  i=DeQueue(&Q);   /*队头元素序号出队*/
      for ( j=0; j<n; j++)
        if ((ga->arcs[i][j]==1)&&(!visited[j]))//DFS's visited influenced
           { /*访问vi+1的未曾访问的点vj+1 */
              printf("node:%c\n",ga->vex[j]);
              visited[j]=1; 
              EnQueue(&Q,j); /*访问过的顶点入队*/
            } 
     } /*while*/
 } /*DFS*/
int main()
{ 
	ga=(graph *)malloc(sizeof(struct xt));
	creat();
	printf("深度优先搜索遍历:\n");
	DFS(0);
	printf("广度优先搜索遍历:\n");
	BFS(0);
	return 0;
}
  

