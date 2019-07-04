/*
HDU 1710
已知先序遍历和中序遍历的结果求后续遍历的结果
http://acm.hdu.edu.cn/showproblem.php?pid=1710
*/
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* lchild;
    TreeNode* rchild;
}Tree[1001];

int loc=0;
int Pre[1001],In[1001];
vector<int> ans;

TreeNode* create(){
    Tree[loc].lchild=Tree[loc].rchild=NULL;
    return &Tree[loc++];
}

//根据前序遍历和后续遍历的结果构造二叉树
TreeNode* construct(int pl,int pr,int il,int ir){//pl,pr分别为前序遍历其实字符的起始和终止下标
                                                  //il,ir分别为中序遍历其实字符的起始和终止下标
    TreeNode* T = create();

    T->data = Pre[pl];

    int rootIn;

    for(int i=il;i<=ir;i++){
        if(In[i]==Pre[pl]){
            rootIn = i;
            break;
        }
    }

    if(rootIn!=il){//递归构造左子树
        T->lchild = construct(pl+1,pl+rootIn-il,il,rootIn-1);
    }
    if(rootIn!=ir){//递归构造右子树
        T->rchild = construct(pl+rootIn-il+1,pr,rootIn+1,ir);
    }

    //ans.push_back(Pre[pl]);

    return T;
}

//后续遍历
void postOrder(TreeNode* T){

    if(T->lchild!=NULL){
        postOrder(T->lchild);
    }

    if(T->rchild!=NULL){
        postOrder(T->rchild);
    }

    ans.push_back(T->data);

}


int main()
{
    int n;

    while(~scanf("%d",&n)){
        ans.clear();
        for(int i=0;i<n;i++)
            cin>>Pre[i];
        for(int i=0;i<n;i++)
            cin>>In[i];

        loc=0;

        TreeNode* T = construct(0,n-1,0,n-1);

        postOrder(T);

        for(int i=0;i<ans.size();i++){
            if(i==ans.size()-1)//行尾没有括号
                cout<<ans[i];
            else
                cout<<ans[i]<<" ";
        }

    }
    return 0;
}
/*
9
1 2 4 7 3 5 8 9 6
4 7 2 1 8 5 9 3 6
*/


