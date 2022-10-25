/* 双向栈 */
//在下面的begin和end间填写相应代码
void inistack(TWSTACK &S)
//该函数实现初始化S，得到2个空栈。根据双向栈的示意图，理解初始化要求。
{
/***************begin***************/

S.top1=0;
S.top2=N-1;
/*************** end ***************/
}
int push(TWSTACK &S,int i,ElemType e)
//i取值1或2，分别对应左或右栈，将元素e压入S的对应栈。成功入栈返回1，否则返回0
{
/***************begin***************/
if(S.top1==S.top2+1) return 0;
if(i==1){
    S.elem[S.top1]=e;
    S.top1++;
    return 1;
}
if(i==2){
    S.elem[S.top2]=e;
    S.top2--;
    return 1;
}
return 0;

/*************** end ***************/
}
int pop(TWSTACK &S,int i, ElemType &e)
//i取值1或2，分别对应左或右栈，将S对应栈的栈顶元素出栈，赋值给e。成功出栈返回1，否则返回0
{
/***************begin***************/

if(i==1){
    if(S.top1==0)return 0;
    e=S.elem[S.top1-1];
    S.top1--;
    return 1;
}
if(i==2){
    if(S.top2==N-1)return 0;
    e=S.elem[S.top2+1];
    S.top2++;
    return 1;
}
return 0;

/*************** end ***************/
}


/* 循环队列 */
//在下面的begin和end间填写相应代码
void iniQueue(QUEUE &Q)
//该函数实现初始化Q
{
/***************begin***************/
Q.front=0;
Q.length=0;

/*************** end ***************/
}
int enQueue(QUEUE &Q,ElemType e)
//将元素e入队Q。成功入栈返回1，否则返回0
{
/***************begin***************/
if(Q.length==MAXLENGTH) return 0;
Q.elem[(Q.front+Q.length)%MAXLENGTH]=e;
Q.length++;
return 1;

/*************** end ***************/
}
int deQueue(QUEUE &Q, ElemType &e)
//将Q队首元素出队，赋值给e。成功出队返回1，否则返回0
{
/***************begin***************/
if(Q.length==0) return 0;
e=Q.elem[Q.front];
Q.front++;
Q.length--;
return 1;

/*************** end ***************/
}


/* 回文 */
int isPalindrome(char *str)
//判断字符串str是否回文，是则返回1，否则返回0
{
/**********begin**********/
int i=0;
char e,q,s;
TWSTACK S;
QUEUE Q;
iniQueue(Q);
inistack(S);
while(str[i]!='@'){
    enQueue(Q,str[i]);
    i++;
}
if(Q.length==0) return 1;
if(Q.length%2==1){
    while(Q.length!=(i+1)/2){
    deQueue(Q,e);
    push(S,1,e);
    }
    deQueue(Q,e);
    while(Q.length!=0){
        deQueue(Q,q);
        pop(S,1,s);
        if(q!=s) return 0;
    }
    return 1;
}

if(Q.length%2==0){
    while(Q.length!=i/2){
    deQueue(Q,e);
    push(S,1,e);
    }

    while(Q.length!=0){
        deQueue(Q,q);
        pop(S,1,s);
        if(q!=s) return 0;
    }
    return 1;
}

/********** end **********/
}

