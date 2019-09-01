#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 100+5;
vector<int> Vec[N],In,A,res;
int n,l,r,x,Map[N];
void Inorder(int x){
    if(Vec[x][0]!=-1)
        Inorder(Vec[x][0]);
    In.push_back(x);
    if(Vec[x][1]!=-1)
        Inorder(Vec[x][1]);
}
void levelOrder(){
    queue<int> Que;
    Que.push(0);
    while(!Que.empty()){
        int top = Que.front();
        res.push_back(Map[top]);
        Que.pop();
        if(Vec[top][0]!=-1)
            Que.push(Vec[top][0]);
        if(Vec[top][1]!=-1)
            Que.push(Vec[top][1]);
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        Vec[i].resize(2,-1);
    for(int i=0;i<n;i++){
        cin>>l>>r;
        if(l!=-1) Vec[i][0]=l;
        if(r!=-1) Vec[i][1]=r;
    }
    for(int i=0;i<n;i++){
        cin>>x;
        A.push_back(x);
    }
    Inorder(0);
    sort(A.begin(),A.end());
    for(int i=0;i<n;i++)
        Map[In[i]]=A[i];
    levelOrder();
    for(int i=0;i<res.size();i++){
        cout<<res[i];
        if(i!=res.size()-1)
            cout<<" ";
        else
            cout<<endl;
    }
    return 0;
}
/*
9
1 6
2 3
-1 -1
-1 4
5 -1
-1 -1
7 -1
-1 8
-1 -1
73 45 11 58 82 25 67 38 42
*/
