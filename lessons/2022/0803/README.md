这节课的主题是单调队列优化以及状态压缩DP
第一部分：单调队列优化
题目如下：
1，Window
给定你n个数a1~an，和一个确定长度的区间K，让你求出每个K长区间内的最大值和最小值，并按照顺序输出
输入
5 3
1 2 3 4 5
输出
3 1
4 2
5 3
k<=n<=5000000

queue <int> q1;
q1.push()
pop()
size()
front()
back()
empty()

deque <int> q2;
q2.push_front()
push_back()
pop_back()
pop_front()
...

建议使用结构体，队列里是位置 或都存（pair）,有位置好找值，光有值不好找位置。
for (int i=1; i<=n; i++)
{
	//if 维护时效性
	//while 维护单调性 * 2
	//压队   回答问题 *2
}




2,志愿者选拔(fOj  1894) vol
世博会马上就要开幕了，福州大学组织了一次志愿者选拔活动。
参加志愿者选拔的同学们排队接受面试官们的面试。参加面试的同学们按照先来先面试并且先结束的原则接受面试官们的考查。
面试中每个人的人品是主要考查对象之一。(提高人品的方法有扶老奶奶过街，不闯红灯等)
作为主面试官的JOhn想知道当前正在接受面试的同学队伍中人品值最高的是多少。于是他请你帮忙编写一个程序来计算。
Input
输入数据第一行为一整数T，表示有T组输入数据。
每组数据第一行为”START”，表示面试开始
接下来的数据中有三种情况：
1 C NAME RP_VALUE 名字为NAME的人品值为RP_VALUE的同学加入面试队伍。(名字长度不大于5，0 <= RP_VALUE <= 1,000,000,000)
2 G 排在面试队伍最前面的同学面试结束离开考场。
3 Q 主面试官JOhn想知道当前正在接受面试的队伍中人品最高的值是多少。
最后一行为”END”，表示所有的面试结束，面试的同学们可以依次离开了。
所有参加面试的同学总人数不超过1,000,000
Output
对于每个询问Q,输出当前正在接受面试的队伍中人品最高的值,如果当前没有人正在接受面试则输出-1。
Sample Input
2
START
C Tiny 1000000000
C Lina 0
Q
G
Q
END
START
Q
C ccQ 200
C cxw 100
Q
G
Q
C wzc 500
Q
END
Sample Output
1000000000
0
-1
200
100

3,广告印刷 ad
【问题描述】
　　最近，afy决定给TOJ印刷广告，广告牌是刷在城市的建筑物上的，城市里有紧靠着的N个建筑。afy决定在上面找一块尽可能大的矩形放置广告牌。我们假设每个建筑物都有一个高度，从左到右给出每个建筑物的高度H1,H2…HN，且0<Hi<=1,000,000,000，并且我们假设每个建筑物的宽度均为1。要求输出广告牌的最大面积。
【输入文件】
中的第一行是一个数n (n<= 400,000 )
第二行是n个数，分别表示每个建筑物高度H1,H2…HN，且0<Hi<=1,000,000,000。
【输出文件】
输出文件 ad.Out 中一共有一行，表示广告牌的最大面积。
【输入样例】
6
5 8 4 4 8 4
【输出样例】
24


4,烽火传递 fire
(烽火传递)烽火台又称烽燧，是重要的防御设施，一般建在险要处或交通要道上。一旦有敌情发生，白天燃烧柴草，通过浓烟表达信息：夜晚燃烧干柴，以火光传递军情。在某两座城市之间有n个烽火台，每个烽火台发出信号都有一定的代价。为了使情报准确的传递，在m个烽火台中至少要有一个发出信号。现输入n,m和每个烽火台发出的信号的代价，请计算总共最少需要话费多少代价，才能使敌军来袭之时，情报能在这两座城市之间准确的传递。
例如，有5个烽火台，它们发出信号的代价为1,2,5,6,2，且m为3，则总共最少花费的代价为4，即由第2个和第5个烽火台发出信号。
输入格式 Input FOrmat
         第一行有两个数n,m分别表示n个烽火台，在m个烽火台中至少要有一个发出信号。
         第二行为n个数，表示每一个烽火台的代价。
输出格式 Output FOrmat      
        一个数，即最小代价。        
样例
输入
5 3
1 2 5 6 2
输出
4

点燃了i的以i为结尾的最小代价
f[i]=min(f[k])+a[i];   i-k<=m
前缀和维护

f[10]  - f[6]-f[9]
f[11] - f[7] - f[10]
f[12] - f[8]- f[11]
....
第二部分：状态压缩DP
5->LIS
6->CF940E
7->POJ2373
8->LuoguP3957