#include <iostream>
#include <vector>
using namespace std;
const int N = 1e3+5;
vector<int>Tree[N],Vec,pre,m_pre,post,m_post;
int n;
void insert(int x,int root){
    if(Vec[x]<Vec[root]){
        if(Tree[root][0]==-1)
            Tree[root][0]=x;
        else
            insert(x,Tree[root][0]);
    }
    if(Vec[x]>=Vec[root]){
        if(Tree[root][1]==-1)
            Tree[root][1]=x;
        else
            insert(x,Tree[root][1]);
    }
}
void preOrder(int x){
    pre.push_back(Vec[x]);
    if(Tree[x][0]!=-1) preOrder(Tree[x][0]);
    if(Tree[x][1]!=-1) preOrder(Tree[x][1]);
}
void postOrder(int x){
    if(Tree[x][0]!=-1) postOrder(Tree[x][0]);
    if(Tree[x][1]!=-1) postOrder(Tree[x][1]);
    post.push_back(Vec[x]);
}
void m_preOrder(int x){
    m_pre.push_back(Vec[x]);
    if(Tree[x][1]!=-1) m_preOrder(Tree[x][1]);
    if(Tree[x][0]!=-1) m_preOrder(Tree[x][0]);
}
void m_postOrder(int x){
    if(Tree[x][1]!=-1) m_postOrder(Tree[x][1]);
    if(Tree[x][0]!=-1) m_postOrder(Tree[x][0]);
    m_post.push_back(Vec[x]);
}
bool isEqual(vector<int> v1,vector<int> v2){
    for(int i=0;i<n;i++){
        if(v1[i]!=v2[i])
            return false;
    }
    return true;
}
int main()
{
    cin>>n;
    Vec.resize(n+1);
    for(int i=0;i<n;i++) Tree[i].resize(2,-1);
    for(int i=0;i<n;i++) cin>>Vec[i];
    for(int i=1;i<n;i++) insert(i,0);
    preOrder(0),m_preOrder(0);
    if(isEqual(pre,Vec)){
        cout<<"YES"<<endl;
        postOrder(0);
        for(int i=0;i<n;i++){
            cout<<post[i];
            if(i==n-1)
                cout<<endl;
            else
                cout<<" ";
        }
    }
    else if(isEqual(m_pre,Vec)){
        cout<<"YES"<<endl;
        m_postOrder(0);
        for(int i=0;i<n;i++){
            cout<<m_post[i];
            if(i==n-1)
                cout<<endl;
            else
                cout<<" ";
        }
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}
