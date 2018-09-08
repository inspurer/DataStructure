#include<stdio.h>
#include<malloc.h>
typedef struct node{
	int data;
	struct node * next;
}linknode,*linklist;
linklist creat1 (linklist head)
{
	linklist p1,p2;
	p1=p2=(linklist)malloc(sizeof(linknode));
	while(head==NULL||(p1->data)>0)
	{
		if(head==NULL)
			head=p2;
		else 
			p2->next=p1;
		p2=p1;
		p1=(linklist)malloc(sizeof(linknode));
		if(p1!=NULL)
		{
			scanf("%d",&p1->data);
			p1->next=NULL;
		}
	}
	return head;
}
linklist creat2(linklist head)
{
	int i;
	linklist p;
	head=(linklist)malloc(sizeof(linknode));
	head->next=NULL;
	scanf("%d",&i);
	while(i>0)
	{
		p=(linklist)malloc(sizeof(linknode));
		p->data=i;
		p->next=head->next;
		head->next=p;
		scanf("%d",&i);
	}
	return head;
}
linklist delet(linklist head)
{
	int i,j=0;
	linklist p1,p2;
	printf("你想要删除哪一个节点?\n");
	scanf("%d",&i);
	if(i==1)
	{
		p1=head->next;
		head->next=p1->next;
		free(p1);
		return head;
	}
	while((i-j)>1&&p1)
	{
		if(j==0)
			p1=head->next;
		else
			p1=p1->next;
		j++;
	}
	if((i-j)>1){
		printf("删除失败...\n");
		return head;
	}
	p2=p1->next;
	p1->next=p2->next;
	free(p2);
	printf("删除成功!\n");
	return head;
}
linklist add(linklist head)
{
	int i,j=0;
	linklist p1,p2;
	p2=(linklist)malloc(sizeof(linknode));
	printf("\n你想要在哪一个节点后插入?\n");
	scanf("%d",&i);
	printf("请输入增加节点的数据域.\n");
	scanf("%d",&p2->data);
	while((i-j)>=1&&p1)
	{
		if(j==0)
			p1=head->next;
		else
			p1=p1->next;
		j++;
	}
	if((i-j)>=1)
	{
		printf("添加失败...\n");
		return head;
	}
	p2->next=p1->next;
	p1->next=p2;
	printf("添加成功!\n");
	return head;
}
void research1(linklist head)
{
	int i,j=1;
	linklist p=head->next;
	printf("你想检索哪一个节点的数据域?\n");
	scanf("%d",&i);
	while(j<i&&p)
	{
		p=p->next;
		j++;
	}
	if(j==i)
		printf("\n检索成功!数据域为%d",p->data);
	else
		printf("查无此节点...\n");
}
void research2(linklist head)
{
	int i,count=1;
	linklist p=head->next;
	printf("检索哪一个值的位置?\n");
	scanf("%d",&i);
	while(p->data!=i&&p)
	{
		p=p->next;
		count++;
	}
	if(p)
		printf("检索成功!第%d个节点",count);
	else
		printf("查无此节点...\n");
}
linklist deletdouble(linklist head)
{
    linklist p,q,r;
    p=head->next;
    while(p)    // p用于遍历链表
    {
         q=p;
         while(q->next) // q遍历p后面的结点，并与p数值比较
         {
             if(q->next->data==p->data)
             {
                 r=q->next; // r保存需要删掉的结点
                 q->next=r->next;   // 需要删掉的结点的前后结点相接
                 free(r);
             }
             else
                 q=q->next;
         }
         p=p->next;
    }
	return head;
}
void print(linklist head)
{
	linklist p1=head->next;
	while(p1)
	{
		printf("%d\t",p1->data);
		p1=p1->next;
	}
}
int main()
{
	int i;
	linklist head=NULL;
	printf("输入1建立正序链表(后插法),否则建立反序链表(前插法)\n");
	scanf("%d",&i);
	printf("开始新建链表，数据非正结束\n");
	if(i==1)
	head=creat1(head);//为什么一定要返回呢
	else
		head=creat2(head);
	printf("新建的单链表为:\n");
	print(head);
	head=add(head);
	head=delet(head);
	head=deletdouble(head);
	printf("输入1按地址检索,否则按值检索\n");
	scanf("%d",&i);
	if(i==1)
	research1(head);
	else
	research2(head);
	printf("\n操作(默认去重)后的单链表为:\n");
	print(head);
	return 0;
}
	
	



