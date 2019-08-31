#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node{
    int h,d,ne;
}node[100000+5];
vector<Node> Vec_k,Vec_r;
int head,n,add,da,ne;
bool vis[100000+5]={false};
int main()
{
    scanf("%d %d",&head,&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d %d",&add,&da,&ne);
        node[add]=Node{add,da,ne};
    }
    for(int i=head;i!=-1;i=node[i].ne){
        if(!vis[abs(node[i].d)])
            Vec_k.push_back(node[i]),vis[abs(node[i].d)]=true;
        else
            Vec_r.push_back(node[i]);
    }
    for(int i=0;i<Vec_k.size();i++){
        if(i!=Vec_k.size()-1)
            printf("%05d %d %05d\n",Vec_k[i].h,Vec_k[i].d,Vec_k[i+1].h);
        else
            printf("%05d %d -1\n",Vec_k[i].h,Vec_k[i].d);
    }
    for(int i=0;i<Vec_r.size();i++){
        if(i!=Vec_r.size()-1)
            printf("%05d %d %05d\n",Vec_r[i].h,Vec_r[i].d,Vec_r[i+1].h);
        else
            printf("%05d %d -1\n",Vec_r[i].h,Vec_r[i].d);
    }
    return 0;
}
