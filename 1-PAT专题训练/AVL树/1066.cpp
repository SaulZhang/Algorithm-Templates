#include <iostream>
using namespace std;
const int N = 20+5;
struct Node{
    int data;
    Node *l,*r;
};
int n,A[N];
int getHeight(Node* tree){
    if(tree==NULL)
        return 0;
    else
        return max(getHeight(tree->l),getHeight(tree->r))+1;
}
Node* LeftRotate(Node* tree){
    Node* temp = tree->r;
    tree->r = temp->l;
    temp->l = tree;
    return temp;
}
Node* RightRotate(Node* tree){
    Node* temp = tree->l;
    tree->l = temp->r;
    temp->r = tree;
    return temp;
}

Node* LeftRightRotate(Node* tree){
    tree->l = LeftRotate(tree->l);
    return RightRotate(tree);
}
Node* RightLeftRotate(Node* tree){
    tree->r = RightRotate(tree->r);
    return LeftRotate(tree);
}

Node* Insert(Node* tree,int x){
    if(tree==NULL){
        tree = new Node();
        tree->l=tree->r=NULL;
        tree->data = x;
    }
    else if(x<tree->data){
        tree->l=Insert(tree->l,x);
        int lh = getHeight(tree->l);
        int rh = getHeight(tree->r);
        if(lh-rh>1){
            if(x<tree->l->data){
                tree = RightRotate(tree);
            }
            else{
                tree = LeftRightRotate(tree);
            }
        }
    }
    else{
        tree->r=Insert(tree->r,x);
        int lh = getHeight(tree->l);
        int rh = getHeight(tree->r);
        if(rh-lh>1){
            if(x>tree->r->data){
                tree = LeftRotate(tree);
            }
            else{
                tree = RightLeftRotate(tree);
            }
        }
    }
    return tree;
}

int main()
{
    cin>>n;
    Node* root = NULL;
    for(int i=1;i<=n;i++)
        cin>>A[i];
    for(int i=1;i<=n;i++)
        root = Insert(root,A[i]);
    cout<<root->data<<endl;
    return 0;
}
