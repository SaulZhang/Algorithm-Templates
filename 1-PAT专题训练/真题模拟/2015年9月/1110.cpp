#include <iostream>
#include <map>
#include <string>
#include <queue>
using namespace std;
struct Node{
    int l,r;
}node[20+5];
int n,root,last;
string l,r;
map<int,bool>mark;
queue<int> Que;
bool hasNone=false,res=true;
void levelOrder(int x){
    Que.push(x);
    while(!Que.empty()){
        int top=Que.front();
        Que.pop();
        last = top;
        if(node[top].l!=-1){
            Que.push(node[top].l);
            if(hasNone)res=false;
        }
        else{
            if(!hasNone)hasNone=true;
        }
        if(node[top].r!=-1){
            Que.push(node[top].r);
            if(hasNone)res=false;
        }
        else{
            if(!hasNone)hasNone=true;
        }
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>l>>r;
        if(l!="-")
            node[i].l = stoi(l),mark[stoi(l)]=true;
        else
            node[i].l = -1;
        if(r!="-")
            node[i].r = stoi(r),mark[stoi(r)]=true;
        else
            node[i].r = -1;
    }
    while(mark[root]&&root<n)root++;
    levelOrder(root);
    if(res)
        cout<<"YES "<<last<<endl;
    else
        cout<<"NO "<<root<<endl;
    return 0;
}
/*
9
7 8
- -
- -
- -
0 1
2 3
4 5
- -
- -
*/
