#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
struct Node{
    int s,d,e;
}node[100000+5];
int st,n,k,s,d,e;
vector<Node> vec,ans;
int main()
{
    scanf("%d%d%d",&st,&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&s,&d,&e);
        node[s] = {s,d,e};
    }
    for(;st!=-1;st=node[st].e)
        vec.push_back(node[st]);
    for(int i=0;i<vec.size();i++)
        if(vec[i].d<0) ans.push_back(vec[i]);
    for(int i=0;i<vec.size();i++)
        if(vec[i].d>=0&&vec[i].d<=k) ans.push_back(vec[i]);
    for(int i=0;i<vec.size();i++)
        if(vec[i].d>k) ans.push_back(vec[i]);
    for(int i=0;i<ans.size()-1;i++)
        printf("%05d %d %05d\n",ans[i].s,ans[i].d,ans[i+1].s);
    printf("%05d %d -1\n",ans[ans.size()-1].s,ans[ans.size()-1].d);
    return 0;
}
/*
00100 9 10
23333 10 27777
00000 0 99999
00100 18 12309
68237 -6 23333
33218 -4 00000
48652 -2 -1
99999 5 68237
27777 11 48652
12309 7 33218
*/
