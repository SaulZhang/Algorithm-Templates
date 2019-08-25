#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
#include <vector>
using namespace std;
int k,loc=0;
string str;
vector<char> Vec;//存储需要删除的字符
map<int,unordered_map<char,int>> Ma;
map<char,vector<int>>ch2id;
set<char> S,Snot;
int main()
{
    cin>>k>>str;
    int len = str.size(),idx=0;
    for(int i=0;i<len;i++){
        if(i==0)
            Ma[i][str[i]]++,idx=0;
        else{
            if(str[idx]==str[i]){
                Ma[idx][str[i]]++;
            }
            else{
                idx=i;
                Ma[idx][str[i]]++;
            }
        }
    }

    for(auto it=Ma.begin();it!=Ma.end();it++){
        for(auto it1 = it->second.begin();it1!=it->second.end();it1++){
            if(it1->second%k==0){//不满足k条件
                if(Snot.find(it1->first)==Snot.end()){//不在冲突集合里面
                    Ma[it->first][it1->first]/=k;
                    ch2id[it1->first].push_back(it->first);//记录已经变更的索引
                    if(S.find(it1->first)==S.end()){//还没记录
                        Vec.push_back(it1->first);
                        S.insert(it1->first);//插入到已获得的集合中
                    }
                }
            }
            else{
                Snot.insert(it1->first);
                if(S.find(it1->first)!=S.end()){//错误的提前操作
                    //还原数量
                    for(int i=0;i<ch2id[it1->first].size();i++)
                        Ma[ch2id[it1->first][i]][it1->first]*=k;
                    ch2id[it1->first].clear();
                    S.erase(it1->first);//在S中该元素
                }
            }
        }
    }
    if(Vec.size()!=0){
        for(int i=0;i<Vec.size();i++)
            if(Snot.find(Vec[i])==Snot.end())
                cout<<Vec[i];
        cout<<endl;
    }
    for(auto it=Ma.begin();it!=Ma.end();it++){
        for(auto it1 = it->second.begin();it1!=it->second.end();it1++){
            for(int i=1;i<=it1->second;i++){
                cout<<it1->first;
            }
        }
    }
    cout<<endl;
    return 0;
}
