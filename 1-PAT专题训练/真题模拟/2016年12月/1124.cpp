#include <iostream>
#include <map>
#include <string>
using namespace std;
const int M = 1000+5;
string A[M];
map<string,bool>isVis;
int m,n,s;
int main()
{
    cin>>m>>n>>s;
    for(int i=1;i<=m;i++){
        cin>>A[i];
    }
    int st = s,cnt=0;
    while(st<=m){
        if(!isVis[A[st]]){
            cout<<A[st]<<endl;
            cnt++;
            isVis[A[st]]=true;
            st+=n;
        }
        else{
            st+=1;
        }
    }
    if(cnt==0)
        cout<<"Keep going..."<<endl;
    return 0;
}
/*
9 3 2
Imgonnawin!
PickMe
PickMeMeMeee
LookHere
Imgonnawin!
TryAgainAgain
TryAgainAgain
Imgonnawin!
TryAgainAgain
*/
