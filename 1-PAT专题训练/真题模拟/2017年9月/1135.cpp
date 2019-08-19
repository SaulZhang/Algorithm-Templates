#include <iostream>
#include <vector>
using namespace std;
const int N = 30+5;
int n,k,x;
int pre[N],num_black=0,num=0;
vector<int>Vec[N],tmp;
bool flag=true;
void build(int x,int y){
    if(abs(pre[y])<abs(pre[x])){
        if(Vec[x][0]==0){
            Vec[x][0]=y;
        }
        else{
            build(Vec[x][0],y);
        }
    }
    if(abs(pre[y])>abs(pre[x])){
        if(Vec[x][1]==0){
            Vec[x][1]=y;
        }
        else{
            build(Vec[x][1],y);
        }
    }
}
void dfs(int x){

    tmp.push_back(pre[x]);

    if(Vec[x][0]==0&&Vec[x][1]==0){
        num = 0;
        for(int i=0;i<tmp.size();i++){
            if(tmp[i]>0)num++;
        }
//        cout<<"num="<<num<<endl;
        if(num_black==0){
            num_black = num;
        }
        else{
            if(num_black!=num){
                flag = false;
//                cout<<"no satisfy rule 3"<<endl;
            }
        }
    }
    if(Vec[x][0]!=0) dfs(Vec[x][0]);
    if(Vec[x][1]!=0) dfs(Vec[x][1]);

    tmp.pop_back();
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>pre[j];
        }
        for(int i=1;i<=k;i++){
            Vec[i].clear();
            Vec[i].push_back(0);
            Vec[i].push_back(0);
        }
        for(int j=2;j<=k;j++){
            build(1,j);
        }

        flag=true;
        if(flag&&pre[1]<0){
            flag=false;
//            cout<<"no satisfy rule 1"<<endl;
        }
        if(flag){
            for(int j=1;j<=k;j++){
                if(pre[j]<0&&!((Vec[j][0]==0&&Vec[j][1]==0)||(pre[Vec[j][0]]>0&&pre[Vec[j][1]]>0))){
                    flag=false;
//                    cout<<"no satisfy rule 2"<<endl;
                }
            }
        }
        if(flag){
            for(int j=1;j<=k;j++){
                num_black=0,num=0;
                if(flag)
                    dfs(j);
            }
        }
        if(flag)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;

    }

    return 0;
}
/*
3
9
7 -2 1 5 -4 -11 8 14 -15
9
11 -2 1 -7 5 -4 8 14 -15
8
10 -7 5 -6 8 15 -11 17
*/
