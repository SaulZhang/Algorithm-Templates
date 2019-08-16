#include <iostream>
#include <set>
using namespace std;
int n,x;
set<int> S;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
       cin>>x;
       if(x>0)
         S.insert(x);
    }
    if(S.size()==0)
        cout<<1<<endl;
    else{
        for(int i=1;i<=n+1;i++){
            if(S.find(i)==S.end()){
                cout<<i<<endl;
                break;;
            }
        }
    }
    return 0;
}
/*
14
5 -25 9 6 1 3 4 2 5 17 7 8 10 12
*/
