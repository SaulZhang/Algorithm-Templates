#include <iostream>
#include <string>
#include <map>
using namespace std;
int num1,num2,num3;
map<int,char> Ma;
string change(int x){
    string res="";
    while(x>0){
        res = Ma[x%13]+res;x/=13;
    }
    while(res.size()<2)res = '0'+res;
    return res;
}
int main()
{
    string ans="";
    Ma[0]='0',Ma[1]='1',Ma[2]='2',Ma[3]='3',Ma[4]='4',Ma[5]='5';
    Ma[6]='6',Ma[7]='7',Ma[8]='8',Ma[9]='9',Ma[10]='A';
    Ma[11]='B',Ma[12]='C';
    cin>>num1>>num2>>num3;
    ans +=(change(num1)+change(num2)+change(num3));
    cout<<'#'<<ans<<endl;
    return 0;
}
/*
15 43 71
*/
