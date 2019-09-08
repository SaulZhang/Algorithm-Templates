#include <iostream>
#include <vector>
using namespace std;
const int N = 50000+5;
int n,pre[N],in[N],cnt=0;
vector<int> Vec[N],ans;
bool flag = false;
int build(int pst,int ped,int ist,int ied){
    int rootIdx=ist;
    while(rootIdx<=ied&&pre[pst]!=in[rootIdx])rootIdx++;
    int len = rootIdx-ist;
    if(rootIdx!=ist) Vec[pst][0] = build(pst+1,pst+len,ist,rootIdx-1);
    if(rootIdx!=ied) Vec[pst][1] = build(pst+len+1,ped,rootIdx+1,ied);
    if(!flag){cout<<pre[pst]<<endl;flag=true;}
    return pst;//树里面存储的是结点的编号i，而结点的值必须通过preOrder[i]来获得
}
int main()
{
    for(int i=1;i<=N;i++){
        Vec[i].push_back(0);
        Vec[i].push_back(0);
    }
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>pre[i];
    for(int i=1;i<=n;i++)
        cin>>in[i];
    build(1,n,1,n);
    return 0;
}
/*
7
1 2 3 4 5 6 7
2 3 1 5 4 7 6
*/
