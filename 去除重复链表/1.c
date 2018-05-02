#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node * link;
}Linknode;
void dele(Linknode * T)//删除重复结点的算法
{
    Linknode * p,* q,* r;
    p=T->link;
    while(p)    // p用于遍历链表
    {
         q=p;
         while(q->link) // q遍历p后面的结点，并与p数值比较
         {
             if(q->link->data==p->data)
             {
                 r=q->link; // r保存需要删掉的结点
                 q->link=r->link;   // 需要删掉的结点的前后结点相接
                 free(r);
             }
             else
                 q=q->link;
         }
         p=p->link;
    }
}
int main()
{
	Linknode * p1,* p2,*first;
	p1=p2=(Linknode *)malloc(sizeof(Linknode));
	first=NULL;
	do{
		if(first==NULL)
			first=p1;
		else
			p2->link=p1;
		p2=p1;
		p1=(Linknode *)malloc(sizeof(Linknode));
		scanf("%d",&p1->data);
	    p1->link=NULL;
	}while(p1->data>0);
	dele(first);
	while(first->link!=NULL)
	{
		first=first->link;
		printf("%d\t",first->data);
	}
	return 0;
}