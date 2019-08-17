#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string ans[40+5],mark;
int d,n,cnt,pos,len;
int main()
{
    cin>>d>>n;
    fill(ans,ans+n+1,"");
    ans[1]=to_string(d);
    for(int i=2;i<=n;i++){
        cnt=0,len = ans[i-1].size(),pos=0;
        while(pos<=len-1){
            if(pos==0){
                mark = ans[i-1].substr(pos,1);
                cnt=1;
            }
            else{
                if(ans[i-1].substr(pos,1)==mark){
                    cnt++;
                }
                else{
                    ans[i]=(ans[i]+mark+to_string(cnt));
                    mark = ans[i-1].substr(pos,1);
                    cnt=1;
                }
            }
            if(pos+1==len){
                ans[i]=(ans[i]+mark+to_string(cnt));
            }
            pos++;
        }
    }
    cout<<ans[n]<<endl;
    return 0;
}
/*
1 8
*/
