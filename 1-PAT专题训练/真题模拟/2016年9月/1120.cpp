#include <iostream>
#include <map>
using namespace std;
map<int,int>Ma;
int n,x;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        int curSum=0;
        while(x!=0){
            curSum+=x%10;
            x/=10;
        }
        Ma[curSum]++;
    }
    int cnt=0;
    cout<<Ma.size()<<endl;
    for(auto it=Ma.begin();it!=Ma.end();it++){
        cout<<it->first;cnt++;
        if(cnt==Ma.size())
            cout<<endl;
        else
            cout<<" ";
    }
    return 0;
}
