#include <iostream>
#include <string>
#include <set>
using namespace std;
set<char> S;
int main()
{
    string str1,str2,ans;
    char c;
    getline(cin,str1);
    getline(cin,str2);
    for(int i=0;i<str2.size();i++)
        S.insert(str2[i]);
    for(int i=0;i<str1.size();i++)
        if(S.find(str1[i])==S.end()){
            ans += str1[i];
        }
    cout<<ans<<endl;
    return 0;
}
/*
They are students.
aeiou
*/
