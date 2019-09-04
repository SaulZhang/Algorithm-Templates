#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n,nt;
int main()
{
    cin>>n;
    nt =n;
    vector<int>res,tmp;
    int up = int(sqrt(n))+1;
    int s=2;
    while(s<=up&&s<=nt){
        if(n%s==0){
            tmp.push_back(s);
            n/=s;
        }
        else{
            if(tmp.size()>res.size()) res = tmp;
            s-=tmp.size();//回退起始点
            tmp.clear();
            n = nt;
        }
        s++;
        if(s>nt&&tmp.size()>res.size())//尾部处理
            res = tmp;
    }
    if(res.size()!=0){
        cout<<res.size()<<endl;
        for(int i=0;i<res.size();i++){
            cout<<res[i];
            if(i!=res.size()-1)
                cout<<"*";
        }
    }
    else{
        cout<<1<<endl<<nt<<endl;
    }


    return 0;
}
/*
630
*/
