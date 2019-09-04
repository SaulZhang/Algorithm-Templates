#include <iostream>
#include <map>
using namespace std;
const int N = 1e5+5;
int n,A[N];
map<int,int>Cnt;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>A[i];
        Cnt[A[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(Cnt[A[i]]==1){
            cout<<A[i];
            return 0;
        }
    }
    cout<<"None"<<endl;
    return 0;
}
