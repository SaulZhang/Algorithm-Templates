#include <iostream>
#include <vector>
#include <stack>
using namespace std;
const int N = 20+5;
struct Node{
    string data;
    int l,r;
}node[N];
vector<int> Vec[N];
string s1="",ans="";
int li,ri,rootId[N],root,n;
stack<char> S;
void inOrder(int x,int state){//左分支 state=0，右分支state=1
    if(Vec[x][0]!=0){
        inOrder(Vec[x][0],0);
    }
    if(Vec[x][0]==0&&Vec[x][1]==0&&state==0){
        ans+="(";
        S.push('(');
    }
    if(Vec[x][0]==0&&Vec[x][1]!=0&&node[x].data=="-"){
        ans+="(";
        S.push('(');
    }
    ans+=node[x].data;
    if(Vec[x][0]==0&&Vec[x][1]==0&&state==1){
        while(!S.empty()){
            ans+=")";
            S.pop();
        }
    }
    if(Vec[x][1]!=0){
        inOrder(Vec[x][1],1);
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<N;i++)
        Vec[i].push_back(0),Vec[i].push_back(0);
    for(int i=1;i<=n;i++){
        cin>>s1>>li>>ri;
        node[i] = {s1,li,ri};
    }
    for(int i=1;i<=n;i++){
        if(node[i].l!=-1){
            rootId[node[i].l]++;
            Vec[i][0] = node[i].l;
        }
        if(node[i].r!=-1){
            rootId[node[i].r]++;
            Vec[i][1] = node[i].r;
        }
    }
    for(int i=1;i<=n;i++){
        if(rootId[i]==0){
           root = i;
           break;
        }
    }
//    cout<<"root="<<root<<endl;
    inOrder(root,-1);
    cout<<ans<<endl;
    return 0;
}
/*
8
* 8 7
a -1 -1
* 4 1
+ 2 5
b -1 -1
d -1 -1
- -1 6
c -1 -1

8
2.35 -1 -1
* 6 1
- -1 4
% 7 8
+ 2 3
a -1 -1
str -1 -1
871 -1 -1
*/
