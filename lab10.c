/* 排序 */
void sort(int a[],int n,int k)
//将a中元素递增排序
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
int save[k+1];
int i,j,num=0;
for(i=0;i<=k;i++){
    save[i]=0;
}
for(i=0;i<n;i++){
    save[a[i]]++;
}
for(i=0;i<k+1;i++){
    if(save[i]!=0)
    for(j=0;j<save[i];j++)
    a[num++]=i;
}
    /********** End **********/
}


/* 求中位数 */
int partition(int a[], int low, int high) //快排的一次排序过程
{
    int q = a[low];
    while (low < high)
    {
        while (low < high && a[high] >= q)
            high--;
        if(low<high){
        a[low] = a[high]; low++;
        while (low < high && a[low] <= q)
            low++;
        if(low<high){
        a[high] = a[low];high--;
        }
        }
    }
    a[low] = q;
    return low;
}

int MidValue(int a[], int n) //使用快排，找到的元素如果位于中间位置，则直接停止
{
    int index;
    if(n%2)index = n / 2;
    else index=n / 2-1;
    int left = 0;
    int right = n - 1;
    int q = -1;
    while (index != q)
    {
        q = partition(a, left, right);
        if (q < index)
            left = q + 1;
        else if (q>index)
            right = q - 1;
    }
    return a[index];
}

