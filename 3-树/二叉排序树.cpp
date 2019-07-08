#include <iostream>
#define N 100+5
using namespace std;

int loc=0;

struct TreeNode{
    int data;
    TreeNode* lchild;
    TreeNode* rchild;
}Tree[N];

TreeNode* create(){

    Tree[loc].lchild=Tree[loc].rchild=NULL;
    return &Tree[loc++];

}

TreeNode* Insert(TreeNode* T,int x){

    if(T==NULL){
        T = create();
        T->data = x;
        return T;
    }
    else if(x<T->data){
        T->lchild = Insert(T->lchild,x);
    }
    else if(x>=T->data){
        T->rchild = Insert(T->rchild,x);
    }

    return T;

}

//先序遍历
void preOrder(TreeNode* T){

    cout<<T->data<<" ";

    if(T->lchild!=NULL){
        preOrder(T->lchild);
    }

    if(T->rchild!=NULL){
        preOrder(T->rchild);
    }

}

//中序遍历
void inOrder(TreeNode* T){

    if(T->lchild!=NULL){
        inOrder(T->lchild);
    }

    cout<<T->data<<" ";

    if(T->rchild!=NULL){
        inOrder(T->rchild);
    }

}

//后续遍历
void postOrder(TreeNode* T){

    if(T->lchild!=NULL){
        postOrder(T->lchild);
    }

    if(T->rchild!=NULL){
        postOrder(T->rchild);
    }

    cout<<T->data<<" ";

}

int A[N];

int main()
{
    int n;

    while(~scanf("%d",&n)){
        loc=0;
        for(int i=0;i<n;i++)
            cin>>A[i];

        TreeNode* T=NULL;
        for(int i=0;i<n;i++){
            T = Insert(T,A[i]);
        }

        preOrder(T);
        cout<<endl;
        inOrder(T);
        cout<<endl;
        postOrder(T);
        cout<<endl;
    }
    return 0;
}
/*
5
1 6 5 9 8

1 6 5 9 8
1 5 6 8 9
5 8 9 6 1
*/
