/* 数组元素循环右移 */

void ShiftRightCircular(ElemType *A,int n,int k)
{
/************** begin *****************/
int s,e,temp;
if(k>0){
	k = k%n;
    s=0;e=n-k-1;
    while(s < e)
	{
		temp = A[s];
		A[s] = A[e];
		A[e] = temp;
		s++;
		e--;
	}
     s=n-k;e=n-1;
    while(s < e)
	{
		temp = A[s];
		A[s] = A[e];
		A[e] = temp;
		s++;
		e--;
	}
     s=0;e=n-1;
    while(s < e)
	{
		temp = A[s];
		A[s] = A[e];
		A[e] = temp;
		s++;
		e--;
	}
}
if(k<0){ShiftRightCircular(A, n, n+k);}


/**************  end  *****************/
}



/* 矩阵加法 */
TSMatrix ADD(TSMatrix A,TSMatrix B)
//返回矩阵A、B相加的结果
{
/************** begin *****************/
        int ai,bi,ci,aj,bj,cj,ap,bp,cp;
TSMatrix C;
    ap = bp = cp = 1;
    if(A.mu != B.mu || A.nu != B.nu){
        return C;
    }
    C.mu = A.mu;
    C.nu = A.nu;
    while(ap <= A.tu && bp <= B.tu){
        ai = A.data[ap].i;
        bi = B.data[bp].i;
        if(ai > bi){
            ci = bi;
            while(ci == B.data[bp].i){
                C.data[cp].i = ci;
                C.data[cp].j = B.data[bp].j;
                C.data[cp].e = B.data[bp].e; 
                ++bp;
                ++cp;
            }            
        }else if(ai < bi){
           ci = ai;
           while(ci == A.data[ap].i){
                C.data[cp].i = ci;
                C.data[cp].j = A.data[ap].j;
                C.data[cp].e = A.data[ap].e;
                ++ap;
                ++cp;
            }            
        }else if(ai == bi){
            ci = ai;            
            aj = A.data[ap].j;
            bj = B.data[bp].j;
            if(aj > bj){          
                C.data[cp].i = ci;
                C.data[cp].j = bj;
                C.data[cp].e = B.data[bp].e;
                ++cp;
                ++bp;
            }else if(aj < bj){ 
                C.data[cp].i = ci;
                C.data[cp].j = aj;
                C.data[cp].e = A.data[ap].e;
                ++cp;
                ++ap;
            }else if(aj == bj){                
                if(A.data[ap].e + B.data[bp].e != 0){
                    C.data[cp].i = ci;
                    C.data[cp].j = aj;
                    C.data[cp].e = A.data[ap].e + B.data[bp].e;
                    ++cp;
                }
                ++ap;
                ++bp;
            }            
        }
    }
    //以上为稀疏矩阵A或B中的元素完全加完的情况
    //以下为稀疏矩阵A或B中的元素部分剩余的情况
    while(ap <= A.tu){
        C.data[cp].i = A.data[ap].i;
        C.data[cp].j = A.data[ap].j;
        C.data[cp].e = A.data[ap].e;
        ++cp;
        ++ap;
    }
    while(bp <= B.tu){
        C.data[cp].i = B.data[bp].i;
        C.data[cp].j = B.data[bp].j;
        C.data[cp].e = B.data[bp].e;
        ++cp;
        ++bp;
    }
    C.tu = --cp;
    return C;

/**************  end  *****************/
}


/* 字符串替换 */
void Replace(HString &S,HString T,HString V)
//
{
/************** begin *****************/
int i = 0, j = 0, k = 0, m = 0,h=0, location = 0;
	char temp[100];
	while (i < S.length)
	{
		while (j < T.length)
		{
			if (S.ch[i] == T.ch[j])
			{
				i++;
				j++;
				continue;
			}
			break;
		}
		if (j == T.length)
		{
			location = i - j;
			k = location+T.length;
			for (m=0; k < S.length; k++,m++)
			{
				temp[m] = S.ch[k];
			}
			temp[m] = '\0';
			for (m = 0; m < V.length; m++)
			{
				S.ch[location] = V.ch[m];
				location++;
			}
			for (m = location, k = 0; k < strlen(temp); m++, k++)
			{
				S.ch[m] = temp[k];
			}
			S.ch[m] = '\0';
			S.length = S.length - T.length + V.length;
			i = location;
			j = 0;
			continue;
		}
		j = 0;
		i +=1;
	}


/**************  end  *****************/
}