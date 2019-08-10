#include <iostream>
using namespace std;
const int N = 1000+5;
int loc=0,n,d,Num[N]={0},maxDep=0;
struct TreeNode{
    int data;
    TreeNode *lchild,*rchild;
}Tree[N];
TreeNode* create(){
    Tree[loc].lchild=Tree[loc].rchild=NULL;
    return &Tree[loc++];
}
TreeNode* Insert(TreeNode*T,int x){
    if(T==NULL){
        T = create();
        T->data = x;
    }
    else{
        if(T->data>=x){
           T->lchild = Insert(T->lchild,x);
        }
        else{
           T->rchild =  Insert(T->rchild,x);
        }
    }
    return T;

}
void dfs(TreeNode* T,int dep){
    maxDep = max(maxDep,dep);
    Num[dep]++;
    if(T->lchild!=NULL)
        dfs(T->lchild,dep+1);
    if(T->rchild!=NULL)
        dfs(T->rchild,dep+1);
}
int main()
{
    cin>>n;
    TreeNode* root=NULL;
    for(int i=0;i<n;i++){
        cin>>d; root = Insert(root,d);
    }
    dfs(root,0);
    cout<<Num[maxDep]<<" + "<<Num[maxDep-1]<<" = "<<Num[maxDep]+Num[maxDep-1]<<endl;
    return 0;
}
/*
9
25 30 42 16 20 20 35 -5 28
*/
