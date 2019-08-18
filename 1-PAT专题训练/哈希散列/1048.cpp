#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
const int N = 100000+5;
int n,m,x;
bool flag = true;
map<int,int> M1,M2;
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>x; M1[x]++;
        if(m-x>0)M2[m-x]++;
    }
    for(int i=1;i<=m;i++){
        if(M1[i]!=0&&M2[i]!=0){
            if(i!=m-i||(i==m-i&&M1[i]>=2)){
                cout<<i<<" "<<m-i<<endl;
                flag=false; break;
            }
        }
    }
    if(flag) cout<<"No Solution"<<endl;
    return 0;
}
/*
8 15
1 2 8 7 2 4 11 15
*/
