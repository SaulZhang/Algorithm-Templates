#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool cmp(char a,char b){return a<b;}
bool cmp1(char a,char b){return a>b;}
int main()
{
    int n,n1,n2;
    string str1,str2;
    cin>>n;
    while(1){
        str1 = to_string(n);
        str2 = to_string(n);
        while(str1.size()!=4)str1='0'+str1;//补前缀0
        while(str2.size()!=4)str2='0'+str2;//补前缀0
        sort(str1.begin(),str1.end(),cmp1);//降序
        sort(str2.begin(),str2.end(),cmp);//升序
        n = stoi(str1)-stoi(str2);//赋值
        printf("%04d - %04d = %04d\n",stoi(str1),stoi(str2),n);
        if(n==6174||n==0)break;//做差

    }
    return 0;
}
