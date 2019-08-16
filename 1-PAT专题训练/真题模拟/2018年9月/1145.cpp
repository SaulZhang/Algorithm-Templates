#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
using namespace std;
const int N = 10000+5;
int Hash[N],TSize,n,m,x,totSearch=0;
map<int,int> SearchTime;
set<int> hasVis;
bool isPrime(int x){
    int up = sqrt(x)+1;
    for(int i=2;i<up;i++)
        if(x%i==0)
            return false;
    return true;
}

int main()
{
    fill(Hash,Hash+N,-1);
    cin>>TSize>>n>>m;
    while(!isPrime(TSize))
        TSize++;
    for(int i=1;i<=n;i++){
        hasVis.clear();
        cin>>x;
        int cnt=0;
        int pos=0;
        while(1){
            pos = (x%TSize + cnt*cnt)%TSize;
            if(Hash[pos]==-1){
                Hash[pos] = x;
                SearchTime[x] = cnt+1;
                break;
            }
            else{
                if(hasVis.find(pos)!=hasVis.end()){
                    SearchTime[x] = cnt+1;
                    cout<<x<<" cannot be inserted."<<endl;
                    break;
                }
                hasVis.insert(pos);
                cnt++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cin>>x;
        int cnt=0,pos=0;
        if(SearchTime.count(x)!=0){
            totSearch += SearchTime[x];
        }
        else{
            hasVis.clear();
            cnt=0;
            while(1){
                pos = (x%TSize + cnt*cnt)%TSize;
                if(Hash[pos]==x){
                    break;
                }
                else{
                    if(hasVis.find(pos)!=hasVis.end()){
                        break;
                    }
                    hasVis.insert(pos);
                    cnt++;
                }
            }
            totSearch += cnt+1;
        }
    }
    printf("%.1f",1.0*totSearch/m);
    return 0;
}
/*
4 5 4
10 6 4 15 11
11 4 15 2
*/
