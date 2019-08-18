#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;
string str1,str2;
set<char> S;
int main()
{
    getline(cin,str1);
    getline(cin,str2);
    transform(str1.begin(),str1.end(),str1.begin(),::toupper);
    transform(str2.begin(),str2.end(),str2.begin(),::toupper);
    for(int i=0;i<str2.size();i++)
        S.insert(str2[i]);
    for(int i=0;i<str1.size();i++){
        if(S.find(str1[i])==S.end()){
            cout<<(char)toupper(str1[i]);
            S.insert(toupper(str1[i]));
        }
    }
    return 0;
}
/*
7_This_is_a_test
_hs_s_a_es
*/
