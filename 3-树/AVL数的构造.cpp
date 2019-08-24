//PAT 1123
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Node{
    int data;
    Node *l,*r;
};
int getHeight(Node* tree){
    if (tree==NULL)
        return 0;
    return max(getHeight(tree->l),getHeight(tree->r))+1;
}
Node* leftRotate(Node* tree){
    Node* temp = tree->r;
    tree->r = temp->l;
    temp->l = tree;
    return temp;
}
Node* rightRotate(Node* tree){
    Node* temp = tree->l;
    tree->l = temp->r;
    temp->r = tree;
    return temp;
}
Node* leftRightRotate(Node* tree){
    tree->l = leftRotate(tree->l);
    return rightRotate(tree);
}
Node* rightLeftRotate(Node* tree){
    tree->r = rightRotate(tree->r);
    return leftRotate(tree);
}
Node* Insert(Node* tree,int data){
    if(tree==NULL){
        tree = new Node();
        tree->data = data;
    }
    else if(data<tree->data){
        tree->l = Insert(tree->l,data);//从上往下递归
        int lh = getHeight(tree->l);//从下往上检查
        int rh = getHeight(tree->r);
        if(lh-rh>1){
            if(data<tree->l->data){
                tree = rightRotate(tree);
            }
            else{
                tree = leftRightRotate(tree);
            }
        }
    }
    else{
        tree->r = Insert(tree->r,data);//从上往下递归
        int lh = getHeight(tree->l);//从下往上检查
        int rh = getHeight(tree->r);
        if(rh-lh>1){
            if(data>tree->r->data){
                tree = leftRotate(tree);
            }
            else{
                tree = rightLeftRotate(tree);
            }
        }
    }
    return tree;
}
queue<Node*> Que;
vector<int> Vec;
bool isNone=false,ans=true;
void levelOrder(Node* tree){
    if(tree!=NULL)
        Que.push(tree);
    while(!Que.empty()){
        Node* top = Que.front();
        Que.pop();
        Vec.push_back(top->data);
        if(top->l!=NULL){
            Que.push(top->l);
            if(isNone)ans=false;
        }
        else{
            isNone=true;
        }
        if(top->r!=NULL){
            Que.push(top->r);
            if(isNone)ans=false;
        }
        else{
            isNone=true;
        }

    }
}

int main()
{
    int n,x;
    cin>>n;
    Node* root=NULL;
    for(int i=1;i<=n;i++){
        cin>>x;
        root = Insert(root,x);
    }
    levelOrder(root);
    for(int i=0;i<Vec.size();i++){
        cout<<Vec[i];
        if(i!=Vec.size()-1)
            cout<<" ";
        else
            cout<<endl;
    }
    if(ans)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
/*
8
88 70 61 96 120 90 65 68
*/
