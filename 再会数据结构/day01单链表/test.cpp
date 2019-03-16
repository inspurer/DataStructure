#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct item{
	char name[20];    //保存客户姓名 
	char gender[20];  //保存客户性别 
	int  age;         //保存客户年龄 
	char tel[20];     //保存客户号码 
} guest;
typedef struct node {
	guest data;         //数据域 
	struct node * next; //指针域 
}* link;

link T;//头指针
void init() {
	link p,s;
	FILE *fp;
	int i  = 0;
	s = p=(link)malloc(sizeof(struct node));
	p->next = 	NULL;

	if((fp=fopen("1.txt","r"))==NULL) {
		printf("load error!");
		exit(1);
	}
	while(!feof(fp)) {

		fscanf(fp,"%s\t%s\t%d\t%s\t\n",p->data.name,p->data.gender,&p->data.age,p->data.tel);
		i++;
		if(i!=1) {
			s->next = p;
			s=p;
		}
		else{
			T->next = p;
		}
		p=(link)malloc(sizeof(struct node));
		p->next = NULL;


	}
	printf("总人数i=====%d\n",i);
	if(fclose(fp)) {
		printf("Can't close the file!\n");
		exit(1);
	}
}

//查找
int find() {
	link p;
	char mod[25];
	printf("请输入要查找的客户姓名:\n");
	scanf("%s",mod);
	p = T->next;
	while(p!=NULL&&strcmp(p->data.name,mod)!=0)
		p=p->next;
	if(p==NULL) {
		printf("并无此人!\n");
		return 0;
	} else {
		printf("查询信息如下：\n");
		printf("%s\t\n","姓名性别年龄联系方式");
		printf("%s\t",p->data.name);
		printf("%s\t",p->data.gender);
		printf("%d\t",p->data.age);
		printf("%s\n",p->data.tel);
		return 1;
	}
}


//浏览
void look() {
	link p;
	p=T->next;
	while(p!=NULL) {
		printf("%s\t%s\t%s\t%s\n","姓名","性别","年龄","联系方式");
		printf("%s\t",p->data.name);
		printf("%s\t",p->data.gender);
		printf("%d\t",p->data.age);
		printf("%s\n",p->data.tel);
		p=p->next;
	}
}


//删除
int del() {
	link p,q;
	FILE *fp;
	char mod[25];
	printf("请输入需要删除的客户名称:\n");
	scanf("%s",mod);
	p=T;
	while(p->next!=NULL&&strcmp(p->next->data.name,mod)!=0)
		p=p->next;
	if(p->next==NULL) {
		printf("并无此人！\n");
		return 0;
	}
	q = p;
	p = p->next;
	q->next = p->next; 
	delete(p);
	printf("删除成功！\n");
	if((fp=fopen("1.txt","wt"))==NULL) {
		printf("error!\n");
		exit(0);
	}
	
	p=T->next;
	while(p!=NULL) {
		printf("%s",p->data.name);
		fprintf(fp,"%s\t%s\t%d\t%s\t\n",p->data.name,p->data.gender,p->data.age,p->data.tel);
		p = p->next; 

	}
	if(fclose(fp)) {
		printf("can't close the file!\n");
		exit(1);
	}
}


//添加
void create() {
	link p,s;
	FILE *fp;
	int yn;
	s=T;
	while(s->next!=NULL) {
		s=s->next;
	}
	do {
		p=(link)malloc(sizeof(struct node));
		printf("请输入客户姓名：\n");
		scanf("%s",p->data.name);
		printf("请输入客户性别：\n");
		scanf("%s",p->data.gender);
		printf("请输入客户年龄：\n");
		scanf("%d",&p->data.age);
		printf("请输入客户联系方式：\n");
		scanf("%s",p->data.tel);
		p->next=NULL;
		s->next=p;
		s=p;
		if((fp=fopen("1.txt","at"))==NULL) {
			printf("write error!\n");
			exit(0);
		}
		printf("写了一次\n");
		fprintf(fp,"%s\t%s\t%d\t%s\n",p->data.name,p->data.gender,p->data.age,p->data.tel);
		if(fclose(fp)) {
			printf("can't close the file!\n");
			exit(0);
		}
		printf("添加成功!\n");
		printf("是否继续添加请输入0或1:");
		scanf("%d",&yn);
	} while(yn);
}


//修改
int revise() {
	link p;
	FILE *fp;
	char mod[25];
	int n;
	printf("请修改客户名称:\n");
	scanf("%s",mod);
	p=T->next;
	while(p!=NULL&&strcmp(p->data.name,mod)!=0)
		p=p->next;
	if(p==NULL) {
		printf("并无此人！\n");
		return 0;
	}
	printf("1.姓名 2.性别 3.年龄 4.联系方式\n");
	do {
		printf("请输入修改项:\n");
		scanf("%d",&n);
		fflush(stdin);
		switch(n) {
			case 1:
				printf("请输入修改后的姓名:\n");
				scanf("%s",p->data.name);
				break;
			case 2:
				printf("请输入修改后的性别:\n");
				scanf("%s",p->data.gender);
				break;
			case 3:
				printf("请输入修改后的年龄:\n");
				scanf("%d",&p->data.age);
				break;
			case 4:
				printf("请输入修改后的联系方式:\n");
				scanf("%s",p->data.tel);
				break;
		}
		printf("是否继续修改？输入0或1\n");
		scanf("%d",&n);
	} while(n);
	p=T->next;
	if((fp=fopen("1.txt","wt"))==NULL) {
		printf("error!\n");
		exit(0);
	}
	while(p!=NULL) {

		fprintf(fp,"%s\t%s\t%d\t%s\t\n",p->data.name,p->data.gender,p->data.age,p->data.tel);
		printf("修改成功！\n");
		p = p->next; 

	}
	if(fclose(fp)) {
		printf("can't close the file!\n");
		exit(1);
	}
}
int main() {
	//初始化头指针
	T=(link)malloc(sizeof(struct node));
	T->next = NULL;
	init();
	//link1 p = T->next;
	//printf("%s",p->data.name);
	//revise1();
	look();
	del();
	look(); 
	/*init1();
	look1();
	find1();
	del1();
	look1();*/
	//create1();
	//del1(); 
	return 0;
}

