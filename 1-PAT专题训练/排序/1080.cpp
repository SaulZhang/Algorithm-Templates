#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int N = 1e4+5;
const int M = 100+5;
int n,m,k;
struct Item{
    int id,GE,GI;
    vector<int> app;
};
bool cmp(Item a,Item b){
    if(a.GE+a.GI!=b.GE+b.GI)
        return a.GE+a.GI>b.GE+b.GI;
    else
        return a.GE>b.GE;
}
map<int,Item> Ma;
vector<Item>Vec;
vector<int>Admit;
vector<int>Ans[M];
int main()
{
    cin>>n>>m>>k;
    Vec.resize(n);
    for(int i=0;i<n;i++)Vec[i].app.resize(k);
    Admit.resize(m);
    for(int i=0;i<m;i++)cin>>Admit[i];
    for(int i=0;i<n;i++){
        Vec[i].id = i;
        cin>>Vec[i].GE>>Vec[i].GI;
        for(int j=0;j<k;j++)
            cin>>Vec[i].app[j];
        Ma[i]=Vec[i];
    }
    sort(Vec.begin(),Vec.end(),cmp);
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            int scid = Vec[i].app[j];
            if(Ans[scid].size()<Admit[scid]){
                Ans[scid].push_back(Vec[i].id);
                break;
            }
            else{
                if(Vec[i].GE+Vec[i].GI==Ma[Ans[scid][Ans[scid].size()-1]].GE+Ma[Ans[scid][Ans[scid].size()-1]].GI){
                    if(Vec[i].GE==Ma[Ans[scid][Ans[scid].size()-1]].GE){
                        Ans[scid].push_back(Vec[i].id);
                        break;
                    }
                }
            }
        }
    }
    for(int i=0;i<m;i++)
        sort(Ans[i].begin(),Ans[i].end());
    for(int i=0;i<m;i++){
        for(int j=0;j<Ans[i].size();j++){
            cout<<Ans[i][j];
            if(j!=Ans[i].size()-1)
                cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
