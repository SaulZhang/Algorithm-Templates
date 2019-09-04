#include <iostream>
#include <string>
using namespace std;
const int N = 54+5;
int A[N],tmp[N],n,res[N];
string str[N],tmpstr;
int main()
{
    for(int i=1;i<=54;i++){
        if(i<=13){
            tmpstr='S'+ to_string(i);
            str[i]=tmpstr;
        }
        else if(i<=26){
            tmpstr='H'+ to_string(i-13);
            str[i]=tmpstr;
        }
        else if(i<=39){
            tmpstr='C'+ to_string(i-26);
            str[i]=tmpstr;
        }
        else if(i<=52){
            tmpstr='D'+ to_string(i-39);
            str[i]=tmpstr;
        }
        else{
            tmpstr='J'+ to_string(i-52);
            str[i]=tmpstr;
        }
    }
    cin>>n;
    for(int i=1;i<=54;i++)cin>>A[i];
    for(int i=1;i<=54;i++)res[i]=i;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=54;i++)
            tmp[A[i]]=res[i];
        for(int i=1;i<=54;i++)
            res[i]= tmp[i];
    }
    for(int i=1;i<=54;i++){
        cout<<str[res[i]];
        if(i!=54)cout<<" ";
    }
    return 0;
}
