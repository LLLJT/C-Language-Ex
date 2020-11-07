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
	//出栈操作
	p=lst->next;
	x=lst->data;
	lst->next=p->next;
	free(p);
	return 1;
}
//判断一个表达式中的括号是否正确配对
int match(char exp[],int n){
	//定义并初始化栈
	char stack[maxSize];
	int top=-1;
	
	int i;
	for(i=0;i<n;++i){
		if(exp[i]=='(')
			stack[++top]='(';
		if(exp[i]==')'){
			if(top==-1)return 0;
			else --top;
				}
}
//栈空，说明匹配
if(top==-1)return 1;
else return 0;
}






























