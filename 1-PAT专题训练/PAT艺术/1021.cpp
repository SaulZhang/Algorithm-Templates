


张少杰

题目集列表

题目列表

提交列表

排名

共 3850 分

编程题
(共 3850 分) 
131/155

PAT (Advanced Level) Practice
公告
原PAT网站用户可在 https://patest.cn/bind_old_pat_user 页面绑定至拼题A账号。绑定后，原PAT网站的提交将被合并至拼题A网站用户的对应题目集中。

返回
1021 Deepest Root (25 分)

A graph which is connected and acyclic can be considered a tree. The height of the tree depends on the selected root. Now you are supposed to find the root that results in a highest tree. Such a root is called the deepest root.
Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (≤10
​4
​​) which is the number of nodes, and hence the nodes are numbered from 1 to N. Then N−1 lines follow, each describes an edge by given the two adjacent nodes' numbers.
Output Specification:
For each test case, print each of the deepest roots in a line. If such a root is not unique, print them in increasing order of their numbers. In case that the given graph is not a tree, print Error: K components where K is the number of connected components in the graph.
Sample Input 1:
5
1 2
1 3
1 4
2 5
Sample Output 1:
3
4
5
Sample Input 2:
5
1 3
1 4
2 5
3 4
Sample Output 2:
Error: 2 components
作者: CHEN, Yue
单位: 浙江大学
时间限制: 2000 ms
内存限制: 64 MB
代码长度限制: 16 KB

编译器 (31)

帮助



37
35
36

32

33
34
29
30
31
27
28

24
25

26
22
23
19

20
21
14
15
16

17
18
11

12
13









































    if(cnt>1){
        }
    }
    for(int i=1;i<=n;i++){
        if(!Vis[i]){
            cnt++,dfs(i,0);
        Vec[b].push_back(a);
    }
    int cnt=0;
        cin>>a>>b;
        Vec[a].push_back(b);
{
    cin>>n;
    for(int i=0;i<n-1;i++){
}
int main()
    }
    for(int i=0;i<Vec[x].size();i++)
        if(!Vis[Vec[x][i]])dfs(Vec[x][i],dep+1);
        tmp.clear();
        tmp.push_back(x);
    }
    else if(dep==maxDep){
        tmp.push_back(x);
    Vis[x]=true;
    if(dep>maxDep){
        maxDep=dep;












上一题
查看上次提交 提交
下一题



操作成功
×
endl, suggestion (occurred 2 times)
