#include <iostream>
#include <string>
using namespace std;
const int N = 100+5;
string A[N];
int main()
{
    int n,minLen=10000;
    cin>>n;
    getchar();
    for(int i=1;i<=n;i++){
        getline(cin,A[i]);
        minLen=min(minLen,int(A[i].size()));
    }
    string ans="";
    for(int i=1;i<=minLen;i++){
        bool flag=true;
        char c = A[1][A[1].size()-i];

        for(int j=2;j<=n;j++){
            if(A[j][A[j].size()-i]==c)
                continue;
            else{
                flag=false;
                if(ans=="")
                    cout<<"nai"<<endl;
                else
                    cout<<ans<<endl;
                return 0;
            }
        }
        ans = c+ans;
    }
    cout<<ans<<endl;
    return 0;
}
