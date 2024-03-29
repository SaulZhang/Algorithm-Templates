### 深度优先搜索
-----------------

- 1103：原始的思路：一个运行时错误和一个超时，运行时错误估计有可能是爆栈了。两个错误都说明递归的深度有点深了，所以超时和爆栈了，因此需要进行优化。
这里参考柳神的思路：首先将x[i]^p的值按照顺序用数组先存储下来，知道x[i]^p>N为止，然后在存储下来的数组上，按照从大到小的顺序进行dfs，并加上一些剪枝。这样的优化基本就在于避免了大量的power函数的运算，提前打表存起来，方便后期的搜索。

(收获：在一些搜索的问题中，如果可以提前把状态存起来，那们就不用在搜索时进行大量的计算节省时间，以及当搜索的问题要求解要按照某一个顺序输出的时候，可以通过调整搜索的次序，使得解按照指定要去的顺序出现，可以避免额外的比较。同时，搜索的过程应该想象成一颗搜索树，如果根结点有多个的话，需要循环遍历根结点，进行多颗树的搜索。)

- 1114 ：将各家庭成员之间的关系采用邻接链表进行存储(结点之间为无向边)，然后采用dfs结合Vis数据对整个图进行遍历。最后一个测试用例没过。
