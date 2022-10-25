/* 数据元素插入 */

int insert(SqList &L,ElemType x)
{
/**********begin**********/
if(L.length==0){
    L.elem[0]=x;
    L.length++;
    return 0;
}
int n,i;
int *newbase;
if(L.length>=L.listsize){
    newbase=(ElemType*)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
    L.elem=newbase;
    L.listsize+=LISTINCREMENT;
}
for(n=0;n<L.length;n++){
    if(x<L.elem[n]){
        for(i=L.length;i>n;i--){
            L.elem[i]=L.elem[i-1];
        }
        L.elem[n]=x;
        L.length++;
        L.listsize++;
        return 0;
    }
}

/**********end**********/
}


/* 双向链表 */
void  adjust(DuLinkList  L)
{
/**********Begin**********/

DuLinkList M= (DuLinkList)malloc(sizeof(struct Dnode)),pn, pr ,p=L->next,tail=M,head=M;
    int i=1;
    while (p != L) {
        if (i % 2 == 1) {
            pn = (DuLinkList)malloc(sizeof(struct Dnode));
            pn->data = p->data;
            tail->next = pn;
            pn->prior = tail;
            tail = pn;
        }
        if (i % 2 == 0) {
            pr = (DuLinkList)malloc(sizeof(struct Dnode));
            pr->data = p->data;
            head->prior = pr;
            pr->next = head;
            head = pr;
        }
        p = p->next;
        i++;
    }
    head->prior = tail;
    tail->next = head;
    p = L;
    do {
        p->data = M->data;
        p = p->next;
        M = M->next;
    }while (p != L);
    return;
 /**********End**********/
}


/* 多顺序表操作 */
void  TriSqList(SqList  &A,SqList  B,SqList  C)
{
/**********Begin**********/
	//BC求交，结果放在临时变量中 
	SqList temp;
	temp.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	temp.length=0;
	temp.listsize=LIST_INIT_SIZE;
	int i=0, j=0, k=0;
	ElemType* p, *q;
	
	while (i<B.length&&j<C.length)
	{
		if(B.elem[i]<C.elem[j]) i++;
		else if(B.elem[i]>C.elem[j]) j++;
		else
		{
			p=&(temp.elem[k]);
			*p=B.elem[i];
			i++;k++;
		}
	}
	temp.length=k;
	//从A中删除临时变量中存放的值
	i=0;j=0;
	while(i<A.length && j<temp.length)
	{
		if(A.elem[i]<temp.elem[j]) i++;
		else if(A.elem[i]>temp.elem[j]) j++;
		else
		{
			p=&(A.elem[i]);
			q=A.elem+A.length-1;
			for(++p;p<=q;++p) *(p-1)=*p;
			--A.length;
		}
	}

 /**********End**********/
}


/* 多单链表操作 */
void TriLinkList(LinkList  A,LinkList  B,LinkList  C)
{
/**********Begin**********/
int count = 0,i=0,j=0,length_a, length_b, length_c;
	node* p;
	p = A->next;
	while (p!= NULL)
	{
		p = p->next;
		count++;
	}
	length_a = count;
	int D[5200], E[5200], F[5200],temp[5200];
	p = A->next;
	for (;p != NULL;)
	{
		D[i] = (p->data);
		p = p->next;
		i++;
	}
	p = B->next;
	count = 0, i = 0;
	while (p != NULL)
	{
		p = p->next;
		count++;
	}
	length_b = count;
	p = B->next;
	while (p != NULL)
	{
		E[i] = (p->data);
		p = p->next;
		i++;
	}
	p = C->next;
	count = 0, i = 0;
	while (p != NULL)
	{
		p = p->next;
		count++;
	}
	length_c = count;
	p = C->next;
	while (p != NULL)
	{
		F[i] = (p->data);
		p = p->next;
		i++;
	}
	for (i = 0; i < length_a; i++)
	{
		int judgeb = 0, judgec = 0;
		int front = 0, last = 0, middle = 0;
		last = length_b - 1;
		while (front<=last)
		{
			middle = (front + last) / 2;
			if (E[middle] == D[i])
			{
				judgeb = 1;
				break;
			}
			if (E[middle] < D[i])
			{
				front = middle + 1;
				continue;
			}
			if (E[middle] > D[i])
			{
				last = middle - 1;
				continue;
			}
		}
		front=0;
		last = length_c - 1;
		while (front <= last)
		{
			middle = (front + last) / 2;
			if (F[middle] == D[i])
			{
				judgec = 1;
				break;
			}
			if (F[middle] < D[i])
			{
				front = middle + 1;
				continue;
			}
			if (F[middle] > D[i])
			{
				last = middle - 1;
				continue;
			}
		}
		if (judgeb == 1 && judgec == 1)
		{
			continue;
		}
		temp[j] = D[i];
		j++;
	}
	p = A->next;
	for (i = 0; i < j; i++)
	{
		p->data = temp[i];
		if (i == j - 1)
		{
			p->next = NULL;
		}
		p = p->next;
	}

 /**********End**********/
}