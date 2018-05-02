#include<stdio.h>
#include<malloc.h>
typedef struct{
	int data[100];
	int top;
}seqstack;
typedef struct node{
	int data;
	struct node * next;
}linknode,*linklist;
void initstack (seqstack * s)//stack
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
void reserve (linklist head)
{
	linklist p;
	seqstack s;
	p=head->next;
	initstack(&s);
	while(p)
	{
		push(&s,p->data);
		p=p->next;
	}
	p=head->next;
	while(p)
	{
		p->data=pop(&s);
		p=p->next;
	}
}
int main()
{
	linklist p,p1,p2,head;
	p1=p2=(linklist)malloc(sizeof(linknode));//start to creat the linknode
	head=NULL;
	do{
		if(head==NULL)
			head=p1;
		else
			p2->next=p1;
		p2=p1;
		p1=(linklist)malloc(sizeof(linknode));
		scanf("%d",&p1->data);
	    p1->next=NULL;
	}while(p1->data>0);//ending of creating linknode
	p=head->next;
	while(p)
	{
		printf("%d",p->data);
		p=p->next;
	}
	reserve(head);
	p=head->next;
	while(p)
	{
		printf("%d\t",p->data);
		p=p->next;
	}
	return 0;
}
