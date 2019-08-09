/*
问题代码，只过了两个用例，暂时找不出问题在哪。
*/
#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int N=30+5;
int loc = 0;
string inOd="";
string postOd="";

struct Node{
    char data;
    Node* lchild;
    Node* rchild;
}Tree[N];

Node* create(){
    Tree[loc].lchild=Tree[loc].rchild=NULL;
    return &Tree[loc++];
}

Node* build(int ist,int ied,int pst,int ped){
    Node* T = create();
    T->data = postOd[ped];
    int idx=ist;
    for(int i=ist;i<=ied;i++){
        if(inOd[i]==postOd[ped]){
            idx = i;
            break;
        }
    }
    int len = idx-ist;
    if(idx!=ist)
        T->lchild=build(ist,idx-1,pst,pst+len-1);
    if(idx!=ied)
        T->rchild=build(idx+1,ied,pst+len,ped-1);
    return T;
}

queue<Node> Que;

int main()
{
    string str;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>str;postOd+=str;
    }
     for(int i=0;i<n;i++){
        cin>>str;inOd+=str;
    }
    Node* T = build(0,n-1,0,n-1);
    Que.push(*T);
    int cnt=0;
    while(!Que.empty()){
        Node tmp = Que.front();
        Que.pop();
        cout<<tmp.data;
        cnt++;
        if(cnt!=n)cout<<" ";
        if(tmp.lchild!=NULL)
            Que.push(*tmp.lchild);
        if(tmp.rchild!=NULL)
            Que.push(*tmp.rchild);
    }

    return 0;
}
/*
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7

6
6 5 4 3 2 1
6 5 4 3 2 1
*/
