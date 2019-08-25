#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5+5;
int A[N];
int S1=0,S2=0;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>A[i];
    }
    sort(A+1,A+1+n);
    for(int i=1;i<=n/2;i++)
        S1+=A[i];
    for(int i=n/2+1;i<=n;i++)
        S2+=A[i];
    cout<<n%2<<" "<<S2-S1<<endl;
    return 0;
}
/*
13
110 79 218 69 3721 100 29 135 2 6 13 5188 85
*/
