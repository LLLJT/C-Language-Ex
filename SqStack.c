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

//运算函数
//完成a op b的运算
int op(int a,char op,int b){
	if(op=="+")return a+b;
	if(op=="-")return a-b;
	if(op=="*")return a*b;
	if(op=='/'){
		if(b==0){
			print("error");
			return 0;
}
		else{
			return a/b;
} 	
}
}
//后缀式计算函数
int com(char exp[]){
	//ab为2个操作数，c来保存结果
	int i,a,b,c;
	//初始化栈和定义栈
	int stack[maxSize];
	int top=-1;
	char op;
	for(i=0;exp[i]!='\0';i++){
		//字符型和整形的转换
		if(exp[i]>='0'&&exp[i]<='9')stack[++top]=exp[i]-'0';
		//不是数字而是操作符
		else {
			op=exp[i];
			b=stack[top--];
			a=stack[top--];
			c=op(a,op,b);
			stack[++top]=c
}
}	
return stack[top];
}

//------------顺序队列---------------
//初始化队列
void initQueue(SqQueue &qu){
	qu.front=qu.rear=0;
}
//判断栈空算法
int isQueueEmpty(SqQueue qu){
	if(qu.front==qu.rear)return 1;
	else return 0;
}

//进队算法
int enQueue(SqQueue &qu,int x){
	//判断队满算法
	if((qu.rear+1)%maxSize==qu.front)return 0;
	//若未满，先移动指针
	qu.rear=(qu.rear+1)%maxSize;
	//存入元素
	qu.data[qu.rear]=x;
	return 1;
}
//出栈算法
int deQueue(SqQueue &qu,int &x){
	//判断栈空
	if(qu.front==qu.rear)return 0;
	//移动指针
	qu.front=(qu.front+1)%maxSize;
	x=qu.data[qu.front];
	return 1;
}



//--------------链队------------------

//初始化链队算法
void initQueue(LiQueue *&lqu){
	lqu=(LiQue)malloc(sizeof(LiQueue));
	//队空状态
	lqu->front=lqu->rear=NULL;
}

//判断队空
int isQueueEmpty(LiQueue *lqu){
	if(lqu->rear==NULL||lqu->front==NULL)return 1;
	else return 0;
}
///入队算法
void enQueue(LiQueue *lqu,int x){
	QNode *p;
	p=(QNode*)malloc(sizeof(QNode));
	p->data=x;
	p->next=NULL;
	if(lqu->rear==NULL)lqu->front=lqu->rear=p;
	else{	//将新结点链接到队尾，rear指向它
		lqu->rear->next=p;
		lqu->rear=p;
}
}
//出队算法
int deQueue(LiQueue *lqu,int &x){
	QNode *p;
	//队空情况
	if(lqu->rear==NULL)return 0;
	else p=lqu->front;
	//只有一个元素
	if(lqu->front==lqu->rear)lqu->front=lqu->rear==NULL;
	else lqu->front=lqu->front->next;
	x=p->data;
	free(p);
	return 1;

}











































