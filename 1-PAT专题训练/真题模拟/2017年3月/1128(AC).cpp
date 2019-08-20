#include <iostream>
#include <set>
using namespace std;
const int N = 1000+5;
set<int> S;
int A[N],n,k;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>k;
        S.clear();
        for(int j=1;j<=k;j++){
            cin>>A[j];
            S.insert(A[j]);
        }
        bool flag = true;
        if(S.size()!=k)//行冲突
            cout<<"NO"<<endl;
        else{
            for(int j=1;j<=k;j++){
                for(int l=1;l<j;l++){
                    if(abs(A[j]-A[l])==abs(j-l)){
                        flag = false;
                        break;
                    }
                }
                if(!flag)break;
            }
            if(flag)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }

    }
    return 0;
}
/*
4
8 4 6 8 2 7 1 3 5
9 4 6 7 2 8 1 9 5 3
6 1 5 2 6 4 3
5 1 3 5 2 4
*/
