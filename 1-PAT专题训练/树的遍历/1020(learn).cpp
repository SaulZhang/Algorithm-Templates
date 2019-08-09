/*不用建树，学习%柳神*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 35;
int in[N],post[N];
struct Node{
    int value,idx;
    Node(int _value,int _idx){
        value=_value,idx=_idx;
    }
    bool operator<(const Node&x)const{return idx<x.idx;}
};
vector<Node>Vec;
void build(int ist,int ied,int pst,int ped,int index){
    if(ist>ied)return;
    int rootId=ist;
    while(rootId<=ied&&in[rootId]!=post[ped])rootId++;
    Vec.push_back(Node(post[ped],index));
    int len = rootId-ist;
    build(ist,rootId-1,pst,pst+len-1,2*index+1);
    build(rootId+1,ied,pst+len,ped-1,2*index+2);
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>post[i];
    for(int i=0;i<n;i++)cin>>in[i];
    build(0,n-1,0,n-1,0);
    sort(Vec.begin(),Vec.end());
    for(int i=0;i<Vec.size();i++){
        cout<<Vec[i].value;
        if(i!=Vec.size()-1)
            cout<<" ";
    }
    return 0;
}
/*
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
*/
