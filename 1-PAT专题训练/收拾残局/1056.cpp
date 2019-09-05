#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e3+5;
int W[N],Np,Ng,Rank[N];
vector<int> NextTurn,tmp1,tmpNext;
bool cmp(int a,int b){return W[a]<W[b];}
int main()
{
    cin>>Np>>Ng;
    NextTurn.resize(Np);
    for(int i=0;i<Np;i++)cin>>W[i];
    for(int i=0;i<Np;i++)cin>>NextTurn[i];
    while(NextTurn.size()!=1){
        tmpNext.clear();
        tmp1.clear();
        for(int i=0;i<NextTurn.size();i++){
            tmp1.push_back(NextTurn[i]);
            if((i+1)%Ng==0){
                tmpNext.push_back(*max_element(tmp1.begin(),tmp1.end(),cmp));
                tmp1.clear();
            }
            else if(i==NextTurn.size()-1&&tmp1.size()!=0){
                tmpNext.push_back(*max_element(tmp1.begin(),tmp1.end(),cmp));
                tmp1.clear();
            }
        }
        for(int i=0;i<NextTurn.size();i++){
            if(find(tmpNext.begin(), tmpNext.end(),NextTurn[i])==tmpNext.end()){
                Rank[NextTurn[i]]=tmpNext.size()+1;
            }
        }
        NextTurn = tmpNext;
    }
    Rank[NextTurn[0]]=1;
    for(int i=0;i<Np;i++){
        cout<<Rank[i];
        if(i!=Np-1)
            cout<<" ";
    }
    return 0;
}
