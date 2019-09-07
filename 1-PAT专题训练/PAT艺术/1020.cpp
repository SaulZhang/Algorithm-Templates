#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int N = 30+5;
int Post[N],In[N],n;
vector<int>Vec;
map<int,int>Ma;
bool cmp(int a,int b){return Ma[a]<Ma[b];}
void build(int ist,int ied,int pst,int ped,int idx){
    if(ist>ied)return;
    int i=ist;
    while(i<=ied&&In[i]!=Post[ped])i++;
    int len = i-ist;
    Vec.push_back(Post[ped]);Ma[Post[ped]]=idx;
    build(ist,i-1,pst,pst+len-1,2*idx+1);
    build(i+1,ied,pst+len,ped-1,2*idx+2);
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>Post[i];
    for(int i=0;i<n;i++)cin>>In[i];
    build(0,n-1,0,n-1,0);
    sort(Vec.begin(),Vec.end(),cmp);
    for(int i=0;i<n;i++){
        cout<<Vec[i];
        if(i!=n-1)cout<<" ";
    }
    return 0;
}
