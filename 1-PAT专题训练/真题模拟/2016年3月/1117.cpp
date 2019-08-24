/*
题意理解：
给出N个数，找到一个数E，从集合中选出E个数，要求这E个数均比E大
*/
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5+5;
int A[N],n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>A[i];
    sort(A+1,A+n+1,greater<int>());
    int e=1;
    while(A[e]>e&&e<=n)e++;
    cout<<e-1<<endl;
    return 0;
}
/*
10
6 7 6 9 3 10 8 2 7 8
*/
