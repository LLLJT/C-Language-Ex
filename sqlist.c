#include <stdio.h>




//顺序表的定义
typedef struct{
int data[maxSize];

int length;

}Sqlist;

//单链表节点定义
typedef struct Lnode{
//data中存结点数据域
int data;
//指向后继结点的指针
struct LNode *next;
}LNode;


//双链表结点定义
typedef struct DLNode{
int data;
//指向前驱结点的指针
struct DLNode  *prior;
//指向后驱结点的指针
struct DLNode *next;
}DLNode;

//返回第一个比x大的元的函数
int findElem(Sqlist L,int x){
int i;
for(int i=0;i<L.length;++i){
	if(x<L.data[i]){return i;}

}
return i;
}

//插入元素，由于L本身要发生改变，所以要引用型
void insertElem(Sqlist &L,int x)
{
int p,i;
//调用findElem()找到插入位置p
p=findElem(L,x)
//从右往左，逐个将元素右移一个位置
for(i=L.length-1;i>=p;--i)
	L.data[i+1]=L.data[i];
L.data[p]=x;
++(L.length);
}

//查找算法
int findElem(Sqlist L,int e){
int i;
for(i=0;i<L.length;++i)
	if(e==L.data[i])
		return i;
return -1;

}

//插入数据元素的算法
int insertElem(Sqlist &L,int p,int e){
int i;
if(p<0||p>L.length||L.length=maxSize)
	return 0;
for(i=L.length-1;i>=p;--i)
//所有元素向后移一位
	L.data[i+1]=L.data[i];
L.data[p]=e;
//多出一个元素，因此自增1
++(L.length);
return 1;
}

//删除算法

//需要改变的用引用型，即前面加个地址符
int delElem(Sqlist &L,int p,int &e){
int i;
if(p<0||p>L.length-1)return 0;
e=L.data[p];
for(i=p;i<=L.length-1;i++)
	L.data[i]=L.data[i+1];
--(L.length);
return 1;

}
//-----------------------------------单链表操作------------------------

void merge(LNode *A,LNode *B,LNode *&C){
LNode *p=A->next;
LNode *q=B->next;
LNode *r;
C=A;
C->next=NULL;
free(B);
r=C;
while(p!=NULL && q!=NULL){
//p的数值小于q的数值
	if(p->data<=q->data){
		r->next=p;p=p->next;
		r=r->next;	
}
	else{
		r->next=q;
		q=q->next;
		r=r->next;

}


}
//insert end,set null
r->next=NULL;
//rested linkedlist link to the tail of LNode C 
if(p!=NULL)r->next=p;
if(q!=null)r->next=q;
}


//利用尾插法建立单链表C
void createlistR(LNode *&c,int a[],int n)
{
//s用来指向新申请的结点，r始终指向C的终端结点
LNode *s,*r；
int i;
C=(LNode *)malloc(sizeof(LNode));
C->next=NULL;
r=c;
for(i=0;i<n;i++){
s=(LNode *)malloc(sizeof(LNode));
//r来接纳新结点，并每接受一个新结点向后移指向新的结点
s->data=a[i];
r->next=s;
r=r->next;

}
//insert end
r->next=NULL;
}


//头插法
void createlistF(LNode *&C,int a[],int n)
{
LNode *s;
int i;
C=(LNode *)malloc(sizeof(LNode));
C->next=NULL;
for(i=0;i<n;i++)
s=(LNode *)malloc(sizeof(LNode));
s->data=a[i];
//s指向新结点的指针域next指向c中的开始结点
s->next=C->next;
//头结点的指针域next指向s结点，使得s成为新的开始结点
C->next=s;
}

//归并成递减的单链表
void merge(LNode *A,LNode *B,LNode *&C)
{
LNode *p=A->next;
LNode *q=B->next;
LNode *s;
C=A;
C->next=NULL;
free(B);
while(p!=NULL && q!=NULL){
if(p->data <= q->data){
s=p;
//头插法
p=p->next;
s->next=C->next;
C-next=s;
}
else{
s=q;
q=q->next;
s->next=C->next;
C->next=s;
}
}
//while 结束
//必须将剩余元素逐个插入C的头部才能得到最终的递减序列
while(p!=NULL){
s=p;
p=p->next;
s->next=C->next;
C->next=s;

}
while(q!=NULL){
s=p;
p=p->next;
s->next=C->next;
C->next=s;
}
}

///查找链表c中是否存在一个值为x结点，若存在，则删除，否则返回0
int findAndDelete(LNode *C,int x){
LNode *p,*q;
p=C;

while(p->next!=NULL){
if(p->next->data==x)
break;
p=p->next;
}
if(p->next==NULL)return 0;
else{
//开始删除
q=p->next;
p->next=p->next->next;
free(q);
//删除结束
return 1;
}
}


//---------------------------------双链表的操作---------------------
//尾插法建立双链表
void createDlistR(DLNode *&L,int a[],int n){
DLNode *s,*r;
int i;
L=(DNode*)malloc(sizeof(DLNode));
L->prior=NULL;
L->next=NULL;
//r始终指向终端结点，开始头结点也是尾结点
r=L;
for(i=0;i<n;++i){
	s=(DLNode*)malloc(sizeof(DLNode));
	s->data=a[i];
//将s插入到L的尾部，并且r指向s，s->prior=r这一句是和建立单链表不同的地方
	r->next=s;
	s->prior=r;
	r=s;
}
r->next=NULL；
}

//双链表查找算法
DLNode* findNode(DLNode *C,int x){
	DLNode *p=C->next;
	while(p!=NULL){
		if(p->data==x)break;
		p=p->next;
}
//如果找到，p的内容是结点地址，没找到则返回NULL
return p;
}

//插入结点算法
//s->next=p->next;
//s->prior=p;
//p->next=s;
//s->next->prior=s

//删除结点算法,删除p的后继结点
/*
q=p->next;
p->next=q->next;
q->next->prior=p;
free(q);
*/

//逆置线性表
//i 指向第一个元素，j指向第二个元素，边交换i和j所指元素，边让i和j相向而行，直到相遇。
/*_
for(int i=left;j=right;i<j;i++,j--){
	temp=a[i];
	a[i]=a[j];
	a[j]=temp;

}
*/

//-------------------------------栈和队列的存储结构，算法，应用
//顺序栈
typedef struct{
	int data[maxSize];
	int top;
}SqStack;


//链栈

typedef struct{
	int data;
	struct LNode *next;
}LNode;

//顺序队列

typedef struct{
	int data[maxSize];
	//队首指针
	int front;
	//队尾指针
	int rear;
}SqQueue;

//队结点
typedef struct QNode{
	int data;
	struct QNode *next;
}QNode;
//链队类型定义
typedef struct{
	QNode *front;
	QNode *rear;
}LiQueue;


//初始化栈
void initStack(Sqstack &st){
	//将头指针设为-1
	st.top==-1;
}

//判断栈空代码
int isEmpty(SqStack st){
	if(st.top==-1)return 1;
	else return 0;
}

//进栈
int push(SqStack &st,int x){
	if(st.top==maxSize-1){
		return 0;
}
	//移动指针
	++(st.top);
	st.data[st.top]=x;
	return 1;
}

//出栈
int pop(SqStack &st,int &x){
	if(st.top==-1)return 0;
	//输出数据，再转移指针
	s=st.data[st.top];
	--(st.top);
	return 1;
}
//--------------链栈----------------
//初始化链栈
void initStack(LNode *&lst){
lst=(LNode*)malloc(sizeof(LNode));
lst->next=NULL;
}
//判断栈空代码
int isEmpty(LNode *lst){
	if(lst->next==null)return 1;
	else return 0;
}

//进栈
void push(LNode *lst,int x){
	LNode *p;
	p=(LNode*)malloc(sizeof(LNode));
	p->next=NULL;
	//头插法
	p->data=x;
	p->next=lst->next;
	lst->next=p;
}
//出栈
int pop(LNode *lst,int &x){
	LNode *p;
	if(lst->next==NULl)return 0;
	p=lst->next;
	x=lst->data;
	lst->next=p->next;
	free(p);
	return 1;
}































