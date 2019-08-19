#include <iostream>
#include <string>
using namespace std;
int n;
string str;
double abs(double x){return x>=0?x:-1.0*x;}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>str;
        if(abs((1.0*stoll(str)/((stoll(str.substr(0,str.size()/2)))*(stoll(str.substr(str.size()/2,str.size()/2)))))
               -int(((1.0*stoll(str)/((stoll(str.substr(0,str.size()/2)))*(stoll(str.substr(str.size()/2,str.size()/2)))))))<1e-7))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
/*
3
167334
2333
12345678
*/
