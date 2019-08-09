/*不用建树，学习%柳神*/
#include <iostream>
#include <vector>
using namespace std;
const int N = 35;
int in[N],post[N];
vector<int>Vec;
void build(int ist,int ied,int pst,int ped){
    if(ist>ied)return;
    int rootId=ist;
    while(rootId<=ied&&in[rootId]!=post[ped])rootId++;
    Vec.push_back(post[ped]);
    int len = rootId-ist;
    build(ist,rootId-1,pst,pst+len-1);
    build(rootId+1,ied,pst+len,ped-1);
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>post[i];
    for(int i=0;i<n;i++)cin>>in[i];
    build(0,n-1,0,n-1);
    for(int i=0;i<Vec.size();i++){
        cout<<Vec[i];
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
