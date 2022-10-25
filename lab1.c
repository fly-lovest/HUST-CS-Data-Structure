/* 计算函数值 */

int suanfa(int a[],int n, int arrsize)
{
/**********begin**********/
#define INT_MAX 2147483647
long int k=1,m=1,i,j;
if(n>arrsize) return 0;
for(i=1;i<=n;i++){
    k=i*k;
    m=2*m;
    j=k*m;
    if(j>INT_MAX||k>INT_MAX||m>INT_MAX) return 0;
    a[i-1]=j;

}

/**********end**********/
}