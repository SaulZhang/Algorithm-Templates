#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int N = 100+5;
int n,state[N];
int w1=101,w2=101;
string statement[N];
vector<int> wolf;
bool flag=true;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>statement[i];
    }
    for(int i=1;i<=n;i++){
        state[i]=0;//-1:wolf    1:human     0:unknown
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)
                continue;
            fill(state+1,state+1+n,0);
            flag=true;
            for(int k=1;k<=n;k++){//依次遍历两个liars
                int idx = stoi(statement[k].substr(1,statement[k].size()-1));
                if(k==i||k==j){
                    if(statement[k][0]=='-'){
                        state[idx] = 1;
                    }
                    else{
                        state[idx] = -1;
                    }
                }
                else{
                    if(state[idx]!=0){
                        if(statement[k][0]=='-'&&state[idx]==1||statement[k][0]=='+'&&state[idx]==-1){
                            flag=false;
                            break;
                        }
                    }
                    else{
                        if(statement[k][0]=='-'){
                            state[idx] = -1;
                        }
                        else{
                            state[idx] = 1;
                        }
                    }

                }
            }
            if(!flag)
                continue;
//            cout<<"i="<<i<<" j="<<j<<endl;
//            for(int k=1;k<=n;k++)
//                cout<<state[k]<<" ";
//            cout<<endl;

            wolf.clear();
            for(int k=1;k<=n;k++){
                if(state[k]==-1||state[k]==0){
                    if(wolf.size()<2){
                        wolf.push_back(k);
                    }
                    else{
                        wolf.clear();
                        break;
                    }
                }
            }
            if(wolf.size()==2){
                int tmp1 = wolf[0];
                int tmp2 = wolf[1];
                if(tmp1>tmp2)
                    swap(tmp1,tmp2);
                if(tmp1<w1){
                    w1 = tmp1;
                    w2 = tmp2;
                }
                else if(tmp1==w1&&tmp2>w2){//题目有问题吧？！
                    w1 = tmp1;
                    w2 = tmp2;
                }
            }
        }

    }
    if(w1!=101){
        cout<<w1<<" "<<w2<<endl;
    }
    else{
        cout<<"No Solution"<<endl;
    }
    return 0;
}
/*
6
+6
+3
+1
-5
-2
+4
*/
