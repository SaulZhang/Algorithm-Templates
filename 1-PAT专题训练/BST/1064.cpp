#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int N = 2e3+5;
int n;
vector<int> Vec,res[N];
int main()
{
    cin>>n;
    Vec.resize(n+1);
    for(int i=1;i<=n;i++) cin>>Vec[i];
    int le = ceil(log2(n+1));
    int re = n-(pow(2,le-1)-1);
    sort(Vec.begin()+1,Vec.end());
    for(int i=le;i>=1;i--){
        if(i==le){
            int j=1;
            while(j<=re){
                res[i].push_back(Vec[2*j-1]);
                j++;
            }
            for(int j=res[le].size();j>=1;j--) Vec.erase(Vec.begin()+1+2*(j-1));
        }
        else{
            int j=1;
            while(j<=pow(2,i-1)){
                res[i].push_back(Vec[2*j-1]);
                j++;
            }
            for(int j=res[i].size();j>=1;j--) Vec.erase(Vec.begin()+1+2*(j-1));
        }
    }
    for(int i=1;i<=le;i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j];
            if(i==le&&j==res[i].size()-1){
                cout<<endl;
            }
            else{
                cout<<" ";
            }
        }
    }
    return 0;
}
