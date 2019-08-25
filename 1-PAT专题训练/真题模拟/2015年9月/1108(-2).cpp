#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int n,cnt=0;
string str,first;
double curSum=0;
bool hasFirst=false;
bool check(string str){
    int len = str.size();
    int cntDot=0,cntDigit=0;
    for(int i=0;i<len;i++){
        if(i==0){
            if(!(str[i]=='-'||isdigit(str[i])||str[i]=='.'))
                return false;
            if(str[i]=='.')
                cntDigit++;
        }
        else{
            if(!(str[i]=='.'||isdigit(str[i])))
                return false;
            if(str[i]=='.')
               cntDot++;
            if(cntDot==1&&isdigit(str[i]))
               cntDigit++;
        }
    }
    if(cntDot>1)
        return false;
    if(cntDigit>=3)
        return false;
    return true;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>str;
        if(check(str)&&stof(str)>=-1000&&stof(str)<=1000){
            curSum += stof(str);
            cnt++;
            if(!hasFirst){
                first = str;
                hasFirst = true;
            }
        }
        else{
            cout<<"ERROR: "<<str<<" is not a legal number"<<endl;
        }
    }
    if(cnt!=0){
        if(cnt==1)
            printf("The average of %d numbers is %s\n",cnt,first.c_str());
        else
            printf("The average of %d numbers is %.2f\n",cnt,curSum/cnt);
    }
    else{
        printf("The average of 0 numbers is Undefined\n");
    }
}
/*
7
5 a aaa 9999 2.3.4 7.123 a
*/
