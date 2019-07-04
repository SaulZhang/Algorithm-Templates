/*
HDU 1710
��֪�����������������Ľ������������Ľ��
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

//����ǰ������ͺ��������Ľ�����������
TreeNode* construct(int pl,int pr,int il,int ir){//pl,pr�ֱ�Ϊǰ�������ʵ�ַ�����ʼ����ֹ�±�
                                                  //il,ir�ֱ�Ϊ���������ʵ�ַ�����ʼ����ֹ�±�
    TreeNode* T = create();

    T->data = Pre[pl];

    int rootIn;

    for(int i=il;i<=ir;i++){
        if(In[i]==Pre[pl]){
            rootIn = i;
            break;
        }
    }

    if(rootIn!=il){//�ݹ鹹��������
        T->lchild = construct(pl+1,pl+rootIn-il,il,rootIn-1);
    }
    if(rootIn!=ir){//�ݹ鹹��������
        T->rchild = construct(pl+rootIn-il+1,pr,rootIn+1,ir);
    }

    //ans.push_back(Pre[pl]);

    return T;
}

//��������
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
            if(i==ans.size()-1)//��βû������
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


