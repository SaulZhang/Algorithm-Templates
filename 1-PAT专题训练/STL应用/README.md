### STL应用专题

- 如果需要判断某个元素是否在一个大小为n的集合当中，那么采用set结构存储集合，查询的时间为O(logN)，而采用map结构查询的时间为O(1).所有能用map就尽量用map。以1063为例，如果采用set去存储的话，那么时间复杂度为O(K(M*logM))>1e8,而采用map的话，时间复杂度为O(KM)=1e7

- 1022：需要注意一个细节，cin是不会接受'\n'的，而getline(cin,str)会接受'\n'，因此如果在cin后面跟一个getline()那么要在getline()先采用getchar()吸收换行符。而在getline()后面跟一个getline()则不需要采用getchar吸收换行符。 

- 1047：当字符的输入输出量比较大的时候而且已经没有办法再优化仍然是超时的情况下，最好统一采用scanf和printf，string类型转为char[N].
