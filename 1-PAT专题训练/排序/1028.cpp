#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Item{
    string id,name;
    int grade;
    Item(string _id,string _name,int _grade){id = _id,name = _name,grade = _grade;}
};
vector<Item> item;
bool cmp1(Item a,Item b){
    return a.id<b.id;
}
bool cmp2(Item a,Item b){
    if(a.name!=b.name)
        return a.name<b.name;
    else
        return a.id<b.id;
}
bool cmp3(Item a,Item b){
    if(a.grade!=b.grade)
        return a.grade<b.grade;
    else
        return a.id<b.id;
}
int n,c,grade;
string id,name;
int main()
{
    cin>>n>>c;
    for(int i=1;i<=n;i++){
        cin>>id>>name>>grade;
        item.push_back(Item(id,name,grade));
    }
    if(c==1){
        sort(item.begin(),item.end(),cmp1);
    }
    else if(c==2){
        sort(item.begin(),item.end(),cmp2);
    }
    else if(c==3){
        sort(item.begin(),item.end(),cmp3);
    }

    for(int i=0;i<item.size();i++){
        cout<<item[i].id<<" "<<item[i].name<<" "<<item[i].grade<<endl;
    }
    return 0;
}
/*
3 1
000007 James 85
000010 Amy 90
000001 Zoe 60
*/
