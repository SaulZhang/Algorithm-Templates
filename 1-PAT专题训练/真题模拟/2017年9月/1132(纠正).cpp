#include <iostream>
#include <string>
using namespace std;
int n;
string str;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>str;
        long long num1 = stoll(str);
        long long num2 = stoll(str.substr(0,str.size()/2));
        long long num3 = stoll(str.substr(str.size()/2,str.size()/2));
        if((num2!=0&&num3!=0)&&num1%(num2*num3)==0)
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
