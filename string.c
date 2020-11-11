//定长顺序存储表示结构
typedef struct{
	char str[maxSize+1];
	int length;
}Str;

//变长分配存储表示
typedef struct{
	char *ch;
	int length;
}Str;

//赋值操作
int strassign(Str& str,char* ch){
	if(str.ch)
		free(str.ch);
	int len=0;
	char *c=ch;
	while(*c){
		++len;
		++c;
	}
	//如果为空串，返回空串
	if(len==0){
	str.ch=NULL;
	str.length=0;
	return 1;
}
	else{
		str.ch=(char*)malloc(sizeof(char) *(len+1));
		//len+1因为多一个'\0'
		if(str.ch==NULL)return 0;
		else{
			c=ch;
			for(int i=0;i<=len;++i,++c)
				str.ch[i]=*c;
			//使用<=是为了将ch最后的'\0'复制到新串作为结束标记
			str.length=len;
			return 1;
		}

}
}
//函数格式:strassign(str,"cur input");
//res:str.ch="cur input",str.len=9
