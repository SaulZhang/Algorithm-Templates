# 基本算法梳理
Story some algorithm templates with program design competion.

## 大纲：

#### 1.数论：

#### 2.图论：

图的存储:
- 邻接矩阵[稠密]
- 邻接链表[稀疏]
- 链式前向星(与邻接链表相似，但访问数组的速度比vector快，[√](https://github.com/SaulZhang/Algorithm-Templates/blob/master/2-%E5%9B%BE%E8%AE%BA/%E9%93%BE%E5%BC%8F%E5%89%8D%E5%90%91%E6%98%9F/main.cpp))

最短路:
Dijkstra算法([√](https://github.com/SaulZhang/Algorithm-Templates/blob/master/2-%E5%9B%BE%E8%AE%BA/%E6%9C%80%E7%9F%AD%E8%B7%AF/Dijkstra/main.cpp))

做题是在构建图结构的时候需要留意以下坑点：
①是否可能存在多重边(求最短路时保留最短边)
②非连通图，最短路可能不存在

#### 3.树：
- 并查集([√](https://github.com/SaulZhang/Algorithm-Templates/blob/master/3-%E6%A0%91/%E5%B9%B6%E6%9F%A5%E9%9B%86/main.cpp))
- 树的构造(已知先序遍历和中序遍历的结果构造二叉树([√](https://github.com/SaulZhang/Algorithm-Templates/blob/master/3-%E6%A0%91/%E5%B9%B6%E6%9F%A5%E9%9B%86/%E6%A0%91%E7%9A%84%E6%9E%84%E9%80%A0/%E5%85%88%E5%BA%8F%2B%E4%B8%AD%E5%BA%8F-%3E%E5%90%8E%E7%BB%AD/main.cpp)))

#### 4.动态规划：
- LIS(O(nlogn)复杂度算法([√](https://github.com/SaulZhang/Algorithm-Templates/blob/master/4-%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92/LIS.cpp)))
- 背包问题(0-1背包/完全背包/多重背包/刚好装满([√](https://github.com/SaulZhang/Algorithm-Templates/tree/master/4-%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92)))


#### 5.搜索(DFS/BFS):

DFS利用函数的递归调用栈进行搜索，一般是在搜索的解空间树上面进行遍历，一般不需要对结点的访问状态进行标记。[关键词：遍历所有从根结点到叶节点路径]
DFS往往与递归调用相联系，在有些递归求解递推的问题中可能存在大量的重复计算，因此可以采用记忆化搜索的方法对中间的结果进行存储，避免大量的重复搜索。


BFS利用队列来完成结点扩展的过程，每个结点仅有一次扩展的机会，在结点的扩展过程中需要一次性扩展完该结点邻域中未被访问过的结点，并且需要对访问过的结点进行标记，避免陷入无限访问的死循环中，由于其每次都是对最近的结点进行扩展，因此可以对于每一次的扩展在结点中维护一个步长信息，对于该步长信息具有最短最优的性质。[关键词：一次扩展，最优性质，状态标记]


#### 6.队/栈/堆的基本应用

- 表达式求值(逆波兰[√](https://github.com/SaulZhang/Algorithm-Templates/blob/master/6-%E9%98%9F-%E6%A0%88-%E5%A0%86%E7%9A%84%E5%9F%BA%E6%9C%AC%E5%BA%94%E7%94%A8/%E8%A1%A8%E8%BE%BE%E5%BC%8F%E6%B1%82%E5%80%BC/main.cpp))

#### 7.排序算法
![各排序算法时间复杂对比](https://github.com/SaulZhang/Algorithm-Templates/raw/master/pic/%E5%90%84%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95%E6%97%B6%E9%97%B4%E5%A4%8D%E6%9D%82%E5%BA%A6.png)

### 具体实现（[√](https://github.com/SaulZhang/Algorithm-Templates/blob/master/7-%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95/main.cpp)）:
- 插入排序：(简单插入排序、折半插入排序、希尔排序)
- 交换排序:(冒泡排序、快速排序)
- 选择排序：(简单选择排序、堆排序)
- 归并排序

...
除此之外还有一些比较小众和奇葩的排序：
基数排序
桶排序
睡眠排序
猴排序

#### 8.字符串相关算法
- KMP算法（[√](https://github.com/SaulZhang/Algorithm-Templates/blob/master/8-%E5%AD%97%E7%AC%A6%E4%B8%B2%E7%9B%B8%E5%85%B3/KMP.cpp)）
