# 1.0x3f
0x3f常用于给静态数组初始化成无穷大,这是由于memset按照字节赋值,使用0x3f恰好可以与其对应  
0x3f3f3f3f常用于表示INF,其值大约为1e9,使用这个值是因为其不会炸int
# 2.vector赋值
```c++
vector<int>g=f;g和f指向不同地址,g是f的拷贝,注意与Python和java的区别;
vector<int>&g=f;g和f指向相同地址,g是f的引用;
```
