#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 100+5;
int loc = 0;

struct Node{
    string name;
    int k;
    int height;
    vector<Node*> Vec;
}Tree[N];

Node *create(){
    Tree[loc].height = 0;
    Tree[loc].k = 0;
    return &Tree[loc++];
}

map<string,Node*> ID_Node;
int Level_Num[N];
int Max_height=0;
queue<Node*> Que;

int main()
{
    fill(Level_Num,Level_Num+N,0);
    int n,m;
    cin>>n;
    if(n!=0){
        ID_Node["01"]=create();
        cin>>m;
        string ID,ch;
        int k;
        for(int i=0;i<m;i++){
            cin>>ID>>k;
            if(ID_Node.count(ID)==0)
                ID_Node[ID]=create();
            ID_Node[ID]->k = k;
            ID_Node[ID]->name = ID;
            for(int j=0;j<k;j++){
                cin>>ch;
                if(ID_Node.count(ch)==0){
                    ID_Node[ch] = create();
                    ID_Node[ch]->name = ch;
                }
                ID_Node[ch]->height = ID_Node[ID]->height+1;
                ID_Node[ID]->Vec.push_back(ID_Node[ch]);
            }
        }
        Que.push(ID_Node["01"]);
        while(!Que.empty()){
            Node* tmp = Que.front();
            Que.pop();
            if(tmp->k==0)
                Level_Num[tmp->height]++;
            else{
                for(int i=0;i<tmp->k;i++)
                    Que.push(tmp->Vec[i]);
            }
            Max_height = max(Max_height,tmp->height);
        }
        for(int i=0;i<=Max_height;i++){
            cout<<Level_Num[i];
            if(i!=Max_height)
                cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
/*
2 1
01 1 02

6 3
01 2 02 03
02 2 04 05
05 1 06

7 3
01 2 02 05
02 2 03 04
05 2 06 07

4 3
01 1 02
02 1 03
03 1 04
*/
