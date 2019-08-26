#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 1e4+5;
int n,A[N],mx,nx;
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
bool vis[100+5][100+5];
int ans[100+5][100+5];
void getMN(int n,int&mx,int&nx){
    int up=int(sqrt(n));
    for(int i=2;i<=up;i++){
        if(n%i==0&&((n/i-i)<(mx-nx))){
                mx = n/i,nx=i;
        }
    }
}
bool inBound(int i,int j){
    if(i>=1&&i<=mx&&j>=1&&j<=nx)
        return true;
    return false;
}
void Fill(){
    int i=1,j=1,cnt=0,state=0;
    while(cnt!=n){
        if(cnt==0){
            ans[i][j]=A[cnt];
            cnt++;
            vis[i][j]=true;
        }
        else{
            int newi,newj;
            newi=i+dir[state][0];
            newj=j+dir[state][1];
            if(inBound(newi,newj)&&!vis[newi][newj]){
                ans[newi][newj] = A[cnt];cnt++;vis[newi][newj]=true,i = newi,j=newj;
            }
            else{
                state = (state+1)%4;
            }
        }
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>A[i];
    sort(A,A+n,greater<int>());
    mx=n,nx=1;
    getMN(n,mx,nx);
    Fill();
    for(int i=1;i<=mx;i++){
        for(int j=1;j<=nx;j++){
            cout<<ans[i][j];
            if(j!=nx)
                cout<<" ";
            else
                cout<<endl;
        }
    }
    return 0;
}
