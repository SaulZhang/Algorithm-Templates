#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N = 10+5;
vector<int> Vec[N],le,in;
int n,root;
char a,b;
bool mark[N];
queue<int>Que;
void Level(int x){
    Que.push(x);
    while(!Que.empty()){
        int top = Que.front();
        Que.pop();
        le.push_back(top);
        if(Vec[top][0]!=-1)
            Que.push(Vec[top][0]);
        if(Vec[top][1]!=-1)
            Que.push(Vec[top][1]);
    }
}
void inOrder(int x){
    if(Vec[x][0]!=-1)
        inOrder(Vec[x][0]);
    in.push_back(x);
    if(Vec[x][1]!=-1)
        inOrder(Vec[x][1]);
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        if(b=='-')
            Vec[i].push_back(-1);
        else
            Vec[i].push_back(int(b-'0')),mark[int(b-'0')]=true;
        if(a=='-')
            Vec[i].push_back(-1);
        else
            Vec[i].push_back(int(a-'0')),mark[int(a-'0')]=true;
    }
    for(int i=0;i<n;i++){
        if(!mark[i]){
            root=i;break;
        }
    }
    Level(root);
    inOrder(root);
    for(int i=0;i<le.size();i++){
        cout<<le[i];
        if(i!=le.size()-1)
            cout<<" ";
        else
            cout<<endl;
    }
    for(int i=0;i<in.size();i++){
        cout<<in[i];
        if(i!=in.size()-1)
            cout<<" ";
        else
            cout<<endl;
    }
    return 0;
}
/*
8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6
*/
