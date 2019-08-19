#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
long long n;
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
    cur = to_string(n);
    if(check(cur)){
        cout<<cur<<" is a palindromic number."<<endl;
        find = true;
    }
    else{
        for(int i=1;i<=10;i++){
            n = stoll(cur)+stoll(Reverse(cur));
            cout<<cur<<" + "<<Reverse(cur)<<" = "<<to_string(n)<<endl;
            if(check(to_string(n))){
                cout<<n<<" is a palindromic number."<<endl;
                find=true;break;
            }
            cur = to_string(n);
        }
    }
    if(!find)
        cout<<"Not found in 10 iterations."<<endl;
    return 0;
}
/*
97152
*/
