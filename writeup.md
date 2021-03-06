##Lab：Pied Piper

> 这个Lab是以斯坦福CS106B Fall2016中Lab的Huffman Encoding为蓝本构建的

在这个Lab里，你将打造一个压缩工具-Pied Piper。Pied Piper将使用二叉树和优先队列来实现Huffman编码，对文件进行压缩和解压。

+ [模板代码]()

Pied Piper是一个命令行界面（Command Line Interface）工具。这意味着它会从命令行读取参数，比如：

`./pipedpiper -encode filename -o file_comprssed`

`-encode`选项指定的是要编码的文件名，`-o`选项指定的是压缩后输出的文件名。

###Huffman编码简介

###Step1：计算字符频率

首先我们要做的是统计文件中所有字符出现的频率，比如我们有一个文件叫`example.txt`，里面的内容是`ab ab cab`，统计的结果应该是一个哈希表：

```
{' ':2, 'a':3, 'b':3, 'c':1, EOF:1}
```

###Step2：构造编码树

接下来，我们就要构造Huffman树了。构造的方法有很多，可以参考《C++数据结构与算法》P464页。

我们选用的是优先队列。优先队列是Huffman算法中是自然数据结构，因为它要求去除两个最低的概率，并在合适的位置上插入新的概率。

首先我们把上一步得到的结果按字符出现频率排序，得到一个队列。

![pqueue1](http://web.stanford.edu/class/cs106b/img/assn/huffman/pqueue1.png)

这个队列的每一项都可以被看成是一个Huffman树根节点。我们每次从队列中取最前面的两项，构造一个新的节点，作为这两项的父节点，然后插入到队列的合适位置（依然保持队列有序）。这样操作直到队列中只有一个元素为止。

![](http://web.stanford.edu/class/cs106b/img/assn/huffman/treegrid.png)


###Step3：构造编码哈希表

得到了Huffman树，我们只要遍历这颗树就可以得到每个字符的Huffman编码了。从根节点开始遍历，把左分支看成0，右分支看成1。

![](http://web.stanford.edu/class/cs106b/img/assn/huffman/tree1.png)

遍历上图的Huffman树的结果便是：

```
{' ':"00", 'a':"10", 'b':"11", 'c':"010", EOF:"011"}
```

###Step4：编码数据

编码数据时，只要讲每个字符替换成对应的二进制编码即可。需要注意的是我们写入的是二进制的0和1，而不是字符0和1。关于如何进行以bit为单位的读/写，在后文中有讲到。

值得关注的是，我们在写入文件时，不但要写入编码过的数据，还要在文件最开始的地方写入元信息。所谓元信息，就是第一步时我们构建的字符频率表。这个字符频率表可以被用来重新构建Huffman树。

> 这个元字符表直接写入字符就可以，不用按位写入。


###Step5：解码数据

我们首先读取元信息，然后重复第二步和第三步，拿到Huffman树。

如果我们有数据`1110010001001010011`。

使用以上的编码数据遍历Huffman树，1是右子树，0是左子树，如果到达了字符节点，就表示解码成功，重新从根节点开始继续遍历。

如第三步中的Huffman树

+ 输入1（右子树），1（右子树）到达字符节点'b'，返回根节点。**11**10010001001010011
+ 输入1（右子树），0（右子树）到达字符节点'a'，返回根节点。11**10**010001001010011

以此类推。就得到了解码后的文件。



>  思考：为什么这种遍历方式不会出错呢？两个不同字符的编码的起始有可能重合吗？

###关于我们提供的模板代码

#### `main.cpp`

首先解析参数，然后根据选项运行compress或者decompress。


#### `encoding.cpp`

```
freqTable buildFrequencyTable(ifstream& input);
HuffmanNode* buildEncodingTree(freqTable& freqTable);
encodingMap buildEncodingMap(HuffmanNode* HuffmanTree);
```

#### `HuffmanNode.h`

```
struct HuffmanNode {
    int character;      
    int count;           
    HuffmanNode* zero;  
    HuffmanNode* one;    
    HuffmanNode(int character = NOT_A_CHAR, int count = 0,
                HuffmanNode* zero = 0, HuffmanNode* one = 0);
    bool isLeaf() const;
};
```
Huffman节点的定义

#### `utility.cpp`

```
void wirteBit(string encodeStr, ofstream& outfile);
void readBit(string& encodeStr, ifstream& input);
```

###一些难点

#### 如何进行以bit为单位的读/写



#### 优先队列的读写

#### Makefile

#### 哈希表写入文件/从文件读取

###关于Pied Piper

我们给这个Huffman编码实现的这个小小的压缩软件，取名叫Pied Piper，主要是致敬美剧《硅谷》。美剧《硅谷》中的创业公司[Pied Piper](http://www.piedpiper.com)的产品的核心就是压缩算法。强烈推荐这部美剧！

###参考链接

+ [斯坦福CS106B Huffman Encoding Writeup](http://web.stanford.edu/class/cs106b//assn/huffman.html)
+ [斯坦福CS106B Huffman Encoding YEAH Hour](https://www.youtube.com/watch?v=BZarC2LkjeI)


