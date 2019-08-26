#include <iostream>
using namespace std;
const int N = 1e5;
int n;
double res=0,x;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lf",&x);
        res+=x*(n+1-i)*i;
    }
    printf("%.2f",res);
    return 0;
}
