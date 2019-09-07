#include <iostream>
#include <vector>
using namespace std;
const int N = 30+5;
int Pre[N],Post[N],n;
vector<int> In;
bool flag=true;
void build(int prst,int pred,int post,int poed){
    if(prst==pred){//达到了继续细分的终止条件
        In.push_back(Pre[prst]);
        return;
    }
    if(Pre[prst]==Post[poed]){
        int i=prst;
        while(i<=pred&&Pre[i]!=Post[poed-1])i++;
        if(i-prst==1)//此时整段待划分的区域可以完全位于左子树也可以完全位于右子树
            flag = false;
        build(prst+1,i-1,post,post+i-prst-1-1);//左子树
        In.push_back(Pre[prst]);
        build(i,pred,post+i-prst-1,poed-1);//右子树
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>Pre[i];
    for(int i=0;i<n;i++)cin>>Post[i];
    build(0,n-1,0,n-1);
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    for(int i=0;i<In.size();i++){
        cout<<In[i];
        if(i!=In.size()-1)cout<<" ";
        else cout<<endl;
    }
    return 0;
}
