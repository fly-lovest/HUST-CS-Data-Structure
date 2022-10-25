/* 二叉排序树的判断 */
int temp = 0;
 int Btree[100];
 
 void Inorder(BiTree T) {     //中序遍历二叉树，并将每个结点数据存入数组中
     if (T != NULL) {
         Inorder(T->lchild);
         Btree[temp] = T->data.key;
         temp++;
         Inorder(T->rchild);
     }
 }
 int Judgesort_bitree(int Btree[]) {    //判断是否是二叉排序树
     int i, sign = 1;
     for (i = 0; i<temp - 1; i++) {
         if (Btree[i]>Btree[i + 1]) {
             sign = 0;
             break;
         }
     }
     return sign;
 }
status JudgeBiTree(BiTree T)
//判断二叉树T是否为二叉排序树
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
 Inorder(T);
 int i;
 i=Judgesort_bitree(Btree);
 return i;
    /********** End **********/
}