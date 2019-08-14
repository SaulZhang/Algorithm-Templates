#include <iostream>
#include <vector>
using namespace std;
const int N = 1000+5;
const int inf = 99999999;
vector<int>Vec[N],tmppath;
int n,weight[N];
bool inc=true;
bool desc=true;
void dfs(int x){
    tmppath.push_back(weight[x]);
    if(Vec[x][0]==inf&&Vec[x][1]==inf){
        for(int i=0;i<tmppath.size()-1;i++){
            if(tmppath[i]>tmppath[i+1])
                inc = false;
            else if(tmppath[i]<tmppath[i+1]){
                desc = false;
            }
        }
        for(int i=0;i<tmppath.size();i++){
            cout<<tmppath[i];
            if(i!=tmppath.size()-1)
                cout<<" ";
            else
                cout<<endl;
        }
    }
    if(Vec[x][1]!=inf){
        dfs(Vec[x][1]);
    }
    if(Vec[x][0]!=inf){
        dfs(Vec[x][0]);
    }
    tmppath.pop_back();
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        Vec[i].push_back(inf);
        Vec[i].push_back(inf);
    }
    for(int i=1;i<=n;i++){
        cin>>weight[i];
        if(i!=1)//注意，需要对根进行特殊处理
            Vec[i/2][i%2]=i;//根据索引建树
    }
    dfs(1);
    if(inc){
        cout<<"Min Heap"<<endl;
    }
    else if(desc){
        cout<<"Max Heap"<<endl;
    }
    else{
        cout<<"Not Heap"<<endl;
    }

    return 0;
}
/*
8
98 72 86 60 65 12 23 50
*/
