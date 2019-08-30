#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;
struct Book{
    string id,title,author,publisher;
    set<string> keyword;
    int year;
};
vector<Book> Vec;
vector<string> res;
int n,m;
string key_word,token;
bool cmp(string a,string b){
    return a<b;
}
int main()
{
    cin>>n;
    Vec.resize(n);
    for(int i=0;i<n;i++){
        cin>>Vec[i].id;getchar();
        getline(cin,Vec[i].title);
        getline(cin,Vec[i].author);
        getline(cin,key_word);
        getline(cin,Vec[i].publisher);
        cin>>Vec[i].year;getchar();
        stringstream ss(key_word);
        while(ss>>token) {
            Vec[i].keyword.insert(token);
        }
    }
    cin>>m;
    string query;
    getchar();
    for(int i=0;i<m;i++){
        getline(cin,query);
        char type=query[0];
        string content = query.substr(3,query.size()-3);
        res.clear();
        if(type=='1'){
            for(int j=0;j<n;j++){
                if(Vec[j].title==content)
                    res.push_back(Vec[j].id);
            }
        }
        else if(type=='2'){
            for(int j=0;j<n;j++){
                if(Vec[j].author==content)
                    res.push_back(Vec[j].id);
            }
        }
        else if(type=='3'){
            for(int j=0;j<n;j++){
                if(Vec[j].keyword.find(content)!=Vec[j].keyword.end())
                    res.push_back(Vec[j].id);
            }
        }
        else if(type=='4'){
            for(int j=0;j<n;j++){
                if(Vec[j].publisher==content)
                    res.push_back(Vec[j].id);
            }
        }

        else if(type=='5'){
            for(int j=0;j<n;j++){
                if(Vec[j].year==stoi(content))
                    res.push_back(Vec[j].id);
            }
        }
        cout<<query<<endl;
        if(res.size()!=0){
            sort(res.begin(),res.end(),cmp);
            for(int j=0;j<res.size();j++){
                cout<<res[j]<<endl;;
            }
        }
        else
            cout<<"Not Found"<<endl;
    }
    return 0;
}
