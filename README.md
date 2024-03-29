# 基本算法梳理
Story some algorithm templates with program design competion.<br>
[This is the time of accumulation but not the time of display.]

## 大纲：

#### 1.数论【[[王道考研计算机机试指南--专题训练]Chapter4 数学问题](https://blog.csdn.net/qq_37053885/article/details/87968177)】：
  进制转换<br>
  素数筛<br>
  分解质因数<br>
  求最大公约数，最小公倍数<br>
  数位拆解(可以用字符串模拟)(stoi()、stoll()等)<br>
  二分求幂，矩阵快速幂<br>
  
#### 2.图论【[[王道考研计算机机试指南--专题训练]Chapter5图论](https://blog.csdn.net/qq_37053885/article/details/88376733)】：

图的存储:
- 邻接矩阵[稠密]
- 邻接链表[稀疏]
- 链式前向星(与邻接链表相似，但访问数组的速度比vector快，[√](https://github.com/SaulZhang/Algorithm-Templates/blob/master/2-%E5%9B%BE%E8%AE%BA/%E9%93%BE%E5%BC%8F%E5%89%8D%E5%90%91%E6%98%9F/main.cpp))

最短路:
- 【单源最短路径】Dijkstra算法([√](https://github.com/SaulZhang/Algorithm-Templates/blob/master/2-%E5%9B%BE%E8%AE%BA/%E6%9C%80%E7%9F%AD%E8%B7%AF/Dijkstra/main.cpp))<br>
- 【多源最短路径】Floyd算法<br>

- 搜索满足特定条件的路径：DFS算法找到所有从起点到达终点的路径，再逐一进行判断

做题是在构建图结构的时候需要留意以下坑点：
①是否可能存在多重边(求最短路时保留最短边)
②非连通图，最短路可能不存在

#### 3.树：
- 并查集([√](https://github.com/SaulZhang/Algorithm-Templates/blob/master/3-%E6%A0%91/%E5%B9%B6%E6%9F%A5%E9%9B%86/main.cpp))
- 树的构造(已知先序遍历和中序遍历的结果构造二叉树求后序([√](https://github.com/SaulZhang/Algorithm-Templates/blob/master/3-%E6%A0%91/%E5%B9%B6%E6%9F%A5%E9%9B%86/%E6%A0%91%E7%9A%84%E6%9E%84%E9%80%A0/%E5%85%88%E5%BA%8F%2B%E4%B8%AD%E5%BA%8F-%3E%E5%90%8E%E7%BB%AD/main.cpp)))<br>
  已知中序遍历和后序遍历的结果构造二叉树求先序<br>
  已知先序和后序求可以构造的二叉树的数目或判定是否可以构造出一颗二叉树<br>
  查找树中满足指定条件的路径(dfs)
- BST： BST的中序遍历序列的结果即为所有数按照从小到大进行排序的结果。
- AVL树：AVL树的创建(左旋、右旋、先左旋后右旋、先右旋后左旋)
- 红黑树：性质判定

#### 4.动态规划【[[王道考研计算机机试指南--专题训练]Chapter7动态规划](https://blog.csdn.net/qq_37053885/article/details/88540841)】：
- 最长递增子序列【LIS】(O(nlogn)复杂度算法([√](https://github.com/SaulZhang/Algorithm-Templates/blob/master/4-%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92/LIS.cpp)))
- 背包问题(0-1背包/完全背包/多重背包/刚好装满/分组([√](https://github.com/SaulZhang/Algorithm-Templates/tree/master/4-%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92)))
- 最长公共子序列【LCS】
- 矩阵链/三角剖分
- 斐波那契数列【爬楼梯问题】
- 线路布线

#### 5.搜索(DFS/BFS)【[[王道考研计算机机试指南--专题训练]Chapter6搜索](https://blog.csdn.net/qq_37053885/article/details/88429255)】:

- DFS(扩展最后的访问的结点)利用函数的递归调用栈进行搜索，一般是在搜索的解空间树上面进行遍历，如果是有向无环图那么一般不需要对结点的访问状态进行标记(参考树的遍历)。[关键词：遍历所有从根结点到叶节点路径]
DFS往往与递归调用相联系，在有些递归求解递推的问题中可能存在大量的重复计算，因此可以采用记忆化搜索的方法对中间的结果进行存储，避免大量的重复搜索。
【DFS往往可以和回溯法相结合，对于回溯法一般都要维护一条从起点到当前的路径，分为排列树（8皇后）和子集树(TSP)两种】

- BFS(扩展最近的结点)利用队列来完成结点扩展的过程，每个结点仅有一次扩展的机会，在结点的扩展过程中需要一次性扩展完该结点邻域中未被访问过的结点，并且需要对访问过的结点进行标记[如果是有向无环图那么一般不需要对结点的访问状态进行标记]，避免陷入无限访问的死循环中，由于其每次都是对最近的结点进行扩展，因此可以对于每一次的扩展在结点中维护一个步长信息，对于该步长信息具有最短最优的性质。[关键词：一次扩展，最优性质，状态标记]


#### 6.队/栈/堆的基本应用

- 【栈】表达式求值【中缀->后缀->求值】(逆波兰[√](https://github.com/SaulZhang/Algorithm-Templates/blob/master/6-%E9%98%9F-%E6%A0%88-%E5%A0%86%E7%9A%84%E5%9F%BA%E6%9C%AC%E5%BA%94%E7%94%A8/%E8%A1%A8%E8%BE%BE%E5%BC%8F%E6%B1%82%E5%80%BC/main.cpp))，火车调度问题
- 【队列】BFS，LevelOrder，job
- 【优先队列】HuffmanTree的构建，Dijkstra的优化，选择排序。

#### 7.哈希(hash)
（散列表、散列函数【设计原则，尽可能保证映射满足随机独立的均匀分布】、冲突解决策略）<br>
- 效率的衡量：装填因子=词条数/hash表的长度
- 散列函数：① 除余法:hash(key)=key mod M ② MAD法：(a×key+b) mod M ③ 其他(平方取中法、折叠法、位异或法) ④ 伪随机数法
- 冲突处理的方法：开散列/封闭地址：①多槽位法 ②独立链(将多槽位中的固定槽位改进为动态的列表) ③公共溢出区(将冲突的词条均存放到公共的溢出池中)<br>
                 闭散列策略/开放地址(散列地址空间仅限于覆盖散列表覆盖的地址范围无需引入次级关联结构)：①线性探测(linear probing) ht[hash(key)+i mod M],i=0,1,2..,采用查找链的方法进行指定词条的查找，冲突的词条必定属于同一个查找链。删除某一词条的时候仍需保持冲突集之间的连续型，因此需要为每个桶设置一个标记位，判断其此时是否插入过元素 ②平方探测法(quadratic probing) (hash(key)+j^2) mod M,j=0,1,2,... 抑制聚集区段的扩大，提高平均插入和查找的效率。
- 散列的应用：桶排序、基数排序、寻找区间内的最大间隙


#### 8.排序算法【快排、堆排序、归并排序、选择、插入、冒泡】
![各排序算法时间复杂对比](https://github.com/SaulZhang/Algorithm-Templates/raw/master/pic/%E5%90%84%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95%E6%97%B6%E9%97%B4%E5%A4%8D%E6%9D%82%E5%BA%A6.png)

  具体实现（[√](https://github.com/SaulZhang/Algorithm-Templates/blob/master/7-%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95/main.cpp)）:
- 插入排序：(简单插入排序、折半插入排序、希尔排序)
- 交换排序:(冒泡排序、快速排序)
- 选择排序：(简单选择排序、堆排序[(√)](https://github.com/SaulZhang/Algorithm-Templates/blob/master/7-%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95/%E5%A0%86%E6%8E%92%E5%BA%8F.cpp)【稳定】)
- 归并排序：
- 桶排序【数据范围有限】
- 基数排序【数据的位数有限】
...
除此之外还有一些比较小众和奇葩的排序：
睡眠排序
猴排序

#### 9.字符串相关算法
- KMP算法（[√](https://github.com/SaulZhang/Algorithm-Templates/blob/master/8-%E5%AD%97%E7%AC%A6%E4%B8%B2%E7%9B%B8%E5%85%B3/KMP.cpp)）

#### 10.启发式搜索算法

- 遗传算法(GA)
- 禁忌搜索
- 模拟退火
- 蚁群算法
- 粒子群算法
