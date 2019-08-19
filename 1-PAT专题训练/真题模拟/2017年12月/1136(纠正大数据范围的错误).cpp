#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string n;
string Reverse(string str);
string add(string str1,string str2){
    int len = str1.size();
    int c=0;
    string ans="";
    for(int i=len-1;i>=0;i--){
        ans += (str1[i] - '0' + str2[i] - '0' + c)%10 + '0';
        c = (str1[i] - '0' + str2[i] - '0' + c)/10;
    }
    if(c!=0)
        ans += c+'0';
    return Reverse(ans);
}
bool check(string str){
    bool flag=false;
    int len = str.size();
    for(int i=0;i<len/2;i++){
        if(str[i]!=str[len-1-i])
            return false;
    }
    return true;
}
string Reverse(string str){
    string res= "";
    for(int i=str.size()-1;i>=0;i--)
        res+=str[i];
    return res;
}
int main()
{
    string cur;
    bool find = false;
    cin>>n;
    if(check(n)){
        cout<<n<<" is a palindromic number."<<endl;
        find = true;
    }
    else{
        for(int i=1;i<=10;i++){
            cur = add(n,Reverse(n));
            cout<<n<<" + "<<Reverse(n)<<" = "<<cur<<endl;
            if(check(cur)){
                cout<<cur<<" is a palindromic number."<<endl;
                find=true;
                break;
            }
            n = cur;
        }
    }
    if(!find)
        cout<<"Not found in 10 iterations."<<endl;
    return 0;
}
/*
97152
*/
