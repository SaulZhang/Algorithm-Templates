## 图的遍历

图的存储:邻接矩阵，邻接链表，链式前向星

图的遍历：dfs/bfs

![#c5f015](https://placehold.it/15/c5f015/000000?text=+) `My Try:` 

- 1003：(我的思路)，转化为有约束的求连通分量的个数问题，首先将和被敌军占领的城市相连的所有highway关闭，然后采用并查集求出当前所有城市构成的连通分量的个数m,由于被敌军占领的城市本身就是一个独立的分量，因此最后的答案为m-2.

- 1021：（一个样例超时没过）

- 1034：（一个样例错误没过）

- 1072:(题目好像理解错了，做了一个小时才发现给的用例的意思没理解对。原本的理解，要找的recommendation gas station应该使得所有station到达gas sation的距离总和最小，同时保证该gas station达到所有house的距离再service distance之内，然后用Floyd来求出所有结点之间的最短距离，有一个用例会超时)

- 1076：图的dfs，求小于等于距离L的邻居个数(有；两个用例出错。)

![#f03c15](https://placehold.it/15/f03c15/000000?text=+) `Revise：` 

- 1021：为了避免超时，只需要采用两次dfs便可以求出答案，无需采用n次dfs。同时关于连通分量的问题，只需要记录一次遍历节点dfs的次数即可，无需再采用并查集的方法进行求解，可以节省不少的时间，避免出错。

- 1072："gas station has to be built at such a location that the minimum distance between the station and any of the residential housing is as far away as possible."这句话的意思没有理解对，把between...and...看成了两个条件。总体来说，要求的应该是，所有station与house之间的最短局里mindis应该要取得最大值，也就是木桶效应中的短板要竟可能的长，符合现实中的生活场景。
其次，采用Floyd算法可以求出任意两点之间的距离但时间复杂度为1e9，超时了。因此这里应该要采用dijkstra算法求10个station的dis数组，时间复杂度为O(NKM)=1e8,比Floyd算法少了一个数量级

![#1589F0](https://placehold.it/15/1589F0/000000?text=+) `Summary:` 
