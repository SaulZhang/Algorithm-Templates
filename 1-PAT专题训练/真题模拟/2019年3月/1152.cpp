#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int n,k;
string str;
bool isPrime(long long x){
    int up = int(sqrt(x))+1;
    if(x==2)
        return true;
    for(int i=2;i<up;i++)
        if(x%i==0)
            return false;
    return true;
}
int main()
{
    cin>>n>>k>>str;
    bool flag=false;
    if(k<=n)//这里有个1分的陷阱，窝的天。做这种题没有给一直变量之间的关系，一定要做好异常处理
        for(int i=0;i<=str.size()-k;i++){
            if(isPrime(atoll(str.substr(i,k).c_str()))){
                cout<<str.substr(i,k)<<endl;
                flag=true;
                break;
            }
        }
    if(!flag)
        cout<<404<<endl;
    return 0;
}
/*
20 5
23654987725541023819

10 3
2468024680
*/
