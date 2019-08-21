#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int N = 10000+5;
double A[N];
int n;
double ans=0;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>A[i];
    sort(A,A+n);
    for(int i=0;i<n;i++){
        if(i==0||i==1)
            ans+=A[i]*pow(2.0,-(n-1));
        else
            ans+=A[i]*pow(2.0,-(n-i));
    }
    cout<<int(ans)<<endl;
    return 0;
}
/*
8
10 15 12 3 4 13 1 15
*/
