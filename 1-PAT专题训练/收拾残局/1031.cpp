#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
    string str;
    cin>>str;
    int n1=0,n2=0;
    int N = str.size();
    for(int i=1;i<=N;i++){
        int tmp_n1 = i;
        int tmp_n2 = N+2-2*tmp_n1;
        if(tmp_n2>=tmp_n1&&tmp_n2>=3){
            n1=max(n1,tmp_n1);
        }
    }
    n2 = N+2-2*n1;
    int pos=0;
    for(int i=1;i<=n1;i++){
        if(i!=n1){
            cout<<str[pos];
            for(int i=1;i<=n2-2;i++)cout<<" ";

            cout<<str[str.size()-1-pos]<<endl;;
        }
        else
            cout<<str.substr(pos,n2)<<endl;
        pos++;
    }
    return 0;
}
/*
helloworld!helloworld!helloworld!helloworld!helloworld!helloworld!helloworld!helloworld!helloworld!helloworld!helloworld!helloworld!
*/
