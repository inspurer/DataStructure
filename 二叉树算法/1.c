#include<stdio.h>
#include<malloc.h>
typedef  struct  node{
	char  data;
	struct  node  *lchild,*rchild;
}bitree;
typedef struct{
	bitree *tree[100];
	int top;
}seqstack;
void initstack (seqstack * s)
{
	s->top=0;
}
int stackempty (seqstack * s)
{
	return s->top==0;
}
void push (seqstack * s,bitree * e)
{
	s->tree[s->top]=e;
	s->top++;
}
int stacksize(seqstack * s)
{
	return s->top;
}
bitree * pop (seqstack * s)
{
	bitree *r;
	s->top--;
	r=s->tree[s->top];
	return r;
}
bitree * creat1( )  /*返回指向根的指针*/
{  
	char  ch;
	int  front, rear;  /*队头和队尾指针*/
	bitree *Q[100];
	bitree  *root,*s;
	root=NULL;          /*置空二叉树*/
	front=1;
	rear=0;     /*置空队列*/
	ch=getchar( );      /*输入第一个字符*/
	while(ch!='#')     /*不是结束符*/
	{ 
		s=NULL;
		if(ch!='@')        /*@表示虚结点*/
		{ 
			s=(bitree *)malloc(sizeof(bitree));
			s->data=ch;
			s->lchild=NULL; 
			s->rchild=NULL; 
     }
  /*将虚结点指针NULL或新结点地址入队*/ 
  rear++;
  Q[rear]=s;    
    if(rear==1) 
       root=s;   /*输入的第一个结点为根结点*/
  else
      { 
	  if(s&&Q[front])/*孩子和双亲结点均不是虚结点*/ 
           if (rear%2==0)  Q[front]->lchild=s;/*左*/
           else  Q[front]->rchild=s;          /*右*/
        if (rear%2==1)  
           front++;  /*结点的两孩子处理完毕，出队*/
      } 
       ch=getchar( );  /*输入下一个字符*/
    } /*while*/
  return  root;      /*返回根指针*/
} /*creat1*/
bitree* creat2(bitree * r)
{
	char c;
	scanf("%c",&c);
	if(c=='@')
		r=NULL;
	else
	{
		r=(bitree*)malloc(sizeof(bitree));
		r->data=c;
		r->lchild=creat2(r->lchild);
	    r->rchild=creat2(r->rchild);
	}
	return r;
}
void preorder(bitree *r)
{
	bitree * p;
	seqstack s;
	initstack(&s);
	push(&s,r);
	while(!stackempty(&s))
	{
		p=pop(&s);
		printf("%c",p->data);
		if(p->rchild!=NULL)
			push(&s,p->rchild);
		if(p->lchild!=NULL)
			push(&s,p->lchild);
	}
}
void inorder(bitree * r)
{
	seqstack s;
	bitree *p=r;
	initstack(&s);
	while(!stackempty(&s)||p)
	{
		while(p!=NULL)
		{
			push(&s,p);
			p=p->lchild;
		}
		p=pop(&s);
		printf("%c",p->data);
		p=p->rchild;
	}
}
void postorder (bitree* r)
{
	if(r)
	{
		postorder(r->lchild);
		postorder(r->rchild);
		printf("%c",r->data);
	}
}
void postorder1(bitree * r)  // 后序遍历的非递归     双栈法  
{    
    seqstack s1,s2;    
    bitree * t,* curr ;           // 指向当前要检查的节点  
	t=r;
	initstack(&s1);
	initstack(&s2);
    push(&s1,t);  
    while(!stackempty(&s1))  // 栈空时结束    
    {  
        curr=pop(&s1);  
        push(&s2,curr);  
        if(curr->lchild)  
			push(&s1,curr->lchild);  
        if(curr->rchild)  
            push(&s1,curr->rchild);  
    }  
    while(!stackempty(&s2))  
        printf("%c",pop(&s2)->data);  
}  

int main()
{
	int i;
	bitree *BT=NULL;
	printf("输入1非递归建立二叉树,否则递归建立二叉树\n");
	scanf("%d",&i);
	fflush(stdin);//very important
	if(i==1)
	{
		printf("开始非递归建立二叉树\n");
		BT=creat1();
	}
	else{
		printf("开始递归建立二叉树\n");
		BT=creat2(BT);
	}
	printf("前序遍历\n");
	preorder(BT);
	printf("\n中序遍历:\n");
	inorder(BT);
	printf("\n后序遍历:\n");
	postorder1(BT);
	printf("\n");
	return 0;
}




