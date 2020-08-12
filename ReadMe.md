[TOC]

# 一、贪心算法(前7道)
## 预备知识
贪心法：遵循某种规律，不断贪心的选取当前最优策略的算法设计方法。

## 1.1 LeetCode455 用更小的饼干满足更多的孩子
1. 贪心：某个孩子可以用更小的糖果满足，则没必要用更大糖果满足，因为可以保留更大的糖果满足需求因子更大的孩子

## 1.2 LeetCode376 删除一些元素获取摆动序列
1. 贪心：当序列有一段连续的递增(或递减时)，为形成摇摆序列，我们只需要保留这些连续的递增(或递减时)的首尾元素，
   这样更可能使得尾部的后一个元素成为摇摆子序列的下一个元素。
2. 状态机

## 1.3 LeetCode402 移除 k 个数字使新数字最小
1. 贪心：若去掉某一位数字，为使得新数字最小，尽可能让新数字优先最高位最小 + 
   从高位到低位遍历，如果当前数字(单调栈top)大于下一位数字，则把当前数字从栈中pop掉
2. 单调栈 

## 1.4 LeetCode055 跳跃游戏
1. nums[] -> index[] -> 遍历 index[] 记录 maxIndex(贪心：在每一步选择中都采取在当前状态下最好或最优（即最有利）的选择)
2. index[] 表示当前位置能跳的最远位置index

## 1.5 LeetCode045 跳跃游戏 II (经典，再做几次)
1. 思考为了使得跳跃次数最少，什么时机跳最优？
2. 起始位置0，可跳到最远距离是 nums[0]，在索引 0~nums[0] 区间遍历，记录遍历过程中可达到的最远距离，
   索引位置j∈[0,nums[0]]，则跳到索引j处，最远距离 j+nums[j]。
3. 0~nums[0] 区间遍历结束意味着必须跳，此时跳跃次数 + 1。
4. 0~nums[0] 区间遍历结束时当前位置是上一轮的可达到的最远距离。

## 1.6 LeetCode452 用最少数量的箭引爆气球
1. 贪心：对于某个气球，至少需要1只弓箭将其击穿，在这只气球被击穿同时，尽可能击穿其他更多的气球
2. 按照气球左端点排序，遍历气球数组，同时维护一个射击区间，尽可能射击更多气球，每射击一个新气球
   更新一次射击区间。如果新的气球没办法击穿，则新增一个弓箭手，维护一个射击区间。
3. 自定义 sort 函数里的 compare 函数对 vector<vector<int>> 进行排序

## 1.7 Poj2431 最优加油方法 (经典，再做几次)
1. 贪心：(1) 在油用光的时候加油最合适 (2) 在油量最多的加油站加油最合适
2. 思路：(1) 设置一个最大堆，用来存储经过加油站的汽油量
        (2) 按照从起点至终点的方向，遍历各个加油站之间的距离
        (3) 每次需要走两个加油站之间的距离d，如果发现汽油不够走距离d时，从最大堆中取出一个油量添加，直到可以足够走距离d
        (4) 如果把最大堆的汽油都添加仍然不够进行距离d，则无法达到终点
        (5) 当前油量p减少d
        (6) 将当前加油站油量添加至最大堆
3. 优先队列/最大堆 priority_queue<int, vector<int>, less<int> >  等同于 priority_queue<int>
4. 最小堆/升序队列 priority_queue<int, vector<int>, greater<int>> 

## 1.8 LeetCode763 划分字母区间 (再做几次)
1. 类似跳跃游戏，重点是起跳位置需跳到最远处进行更新

## 1.9 LeetCode1167 链接棒材的最低费用
1. 贪心：为使得费用最低，每次都从所有棒材中选择最短的两根棒材进行链接
2. 最小堆/优先队列priority_queue<int, vector<int>, greater<int>> 

## 1.10 LeetCode253 会议室 II (再做几次)
1. 贪心：会议排序，当新会议要开始时比较此会议开始时间和所有房间会议结束时间最小值(最早结束会议)，如果不冲突不需要安排新会议室

## 1.11 LeetCode1094 拼车
1. 思路和会议室 II 同
2. 自定义优先队列的比较器 
```c++
struct PQCmp {
    // 按照结束位置在优先队列里排序，最小优先队列
    bool operator()(Trip &p1, Trip &p2) {
        return p1.first > p2.first;
    }
};
```

## 1.12 LeetCode1055 形成字符串的最短路径
1. 华为

# 二、搜索(前5道)(二维数组、邻接表上搜索)
## 2.1 LeetCode200:岛屿数量：二维数组上连一起为一个岛
1. 深搜模版题 二维数组记录访问过的点
2. 广搜模版题 搜索队列searchQueue 二维数组记录访问过的点 将带搜索的位置push进入到队列 放入搜索队列意味着已经搜索过+准备搜索周围位置

## 2.2 LeetCode127:单词接龙
1. 广搜模版题  邻接表map<string,vector<string>>表示图 
    - 记录搜索过程步数  
    - 搜索队列queue<pair<顶点,步数>>
    - 集合set<string>记录搜索过的结点
    - 尽量使用 const 和 & 减少时间消耗
2. 广搜模版特点: (1) push 进入 searchQueue 时同时要 insert 进 visit
               (2) 从 searchQueue 取出要搜索结点后要从 searchQueue 里 pop 掉此结点                
               (3) 放入搜索队列可以多放点其他信息，比如 step
3. 广搜模版
```c++
void Bfs(map graph, set visit, T start, T target) {
    queue<pair<string, int>> searchQueue;
    searchQueue.push(make_pair(beginWord, 1));
    visit.insert(beginWord);

    while (!searchQueue.empty()) {
        string cur = searchQueue.front().first;
        int step = searchQueue.front().second;
        searchQueue.pop();

        // 此处取出当前搜索结点进行处理

        for (string &word: graph[cur]) {
            if (visit.find(word) != visit.end()) {
                continue;
            }

            searchQueue.push(make_pair(word, step + 1));
            visit.insert(word);
        }
    }
}
```               
    
## 2.3 LeetCode126:单词接龙2(hard)
1. 记录所有路径的广搜
2. 邻接表表示图 起点到终点多条路径保存
    - 搜索队列使用 vector<Qitem> 替换 queue<pair<string,int>> 从而保存所有路径
    - Qitem 保存着前驱节点位置和步数信息，比 pair<string,int> 多了一个前驱结点在队列中的位置
    - 使用map<string, int> 替换集合记录搜索过的结点:记录达到m每个位置所需最小步数，存取不同前驱到达该位置情况
    - 使用变量 front 表示搜索队列的队列头，而不需要pop掉
    
## 2.4 Leetcode473:火柴拼正方形
1. 回溯算法
2. 关键是如何进行回溯
```c++
sides[j] += nums[i];    // nums 的第 i 根火柴放入 sides 的第 j 条边上，接着放入第 i + 1 根火柴
if (Backtrack( nums, sides, target, i + 1)) {
    return true;
}
sides[j] -= nums[i];    // nums 的第 i 根火柴放入 sides 的第 j 条边上，无法成功则撤回放入 j + 1 条边上
```

## 2.5 LeetCode407:接雨水 II(hard)
1. 带优先级的广度优先搜索 优先队列 未做

## 2.6 LeetCode079:单词搜索
1. 深搜 + 回溯算法
2. 核心，从 x,y 开始深搜时先保存当前结点，如果失败在回退。board[x][y] = 0;是为了再次搜索这个位置肯定走不通，因为不等于目标word
```C++
char temp = board[x][y];
board[x][y] = 0;
...
... 以 x,y 为起点进行深搜
...
board[x][y] = temp;
return false;
```

## 2.7 LeetCode994 腐烂的橘子
1. 思路基本和 岛屿数量 广搜一样
2. 特点是每次需要将队列里的所有节点一次性搜索完

## 2.8 LeetCode695 岛屿的最大面积
1. 深搜模版题
2. 广搜模版题
3. 用于练习搜索常用套路模版

## 2.9 LeetCode1293:网格中的最短路径(hard)

# 三、二叉树与图(前5道)(二叉树、图的搜索)
## 预备知识
```c++
              1
             / \
            2   5
           / \   \
          3   4   6
```
1. 二叉树的深度遍历
    - 前序遍历: 1->2->3->4->5->6 当前结点->左子树->右子树
    - 中序遍历: 3->2->4->1->5->6 左子树->当前结点->右子树
    - 后序遍历: 3->4->2->6->5->1 左子树->右子树->当前结点
2. 二叉树的层次遍历 : 1->2->5->3->4->6

## 3.1 LeetCode113 路径之和2
1. 记录路径的深度搜索模版题 前序遍历 
2. 记录路径 所以 需要 回溯算法
```c++
void Preorder(TreeNode *node, vector<int> &visit, vector<vector<int>> &path, int &sum, int &target) {
```

## 3.2 LeetCode236:最近的公共祖先
1. 记录路径的深度搜索模版题 前序遍历 
2. 记录路径 所以 需要 回溯算法
3. finish 变量用于找到目标路径后不再寻找。
```c++
void Preorder(TreeNode *node, vector<TreeNode *> &visit, vector<TreeNode *> &path, TreeNode *target, int &finish)
```

## 3.3 LeetCode144:二叉树转链表(最经典前中后序)
1. 使用vector<Treenode *>保存所有结点
2. 原地转链表

## 3.4 LeetCode199:侧面观察二叉树
1. 二叉树广搜 二叉树层次遍历 结点与层数绑定为pair压入队列

## 3.5 LeetCode207:有向图判断环
1. 未做

## 3.6 LeetCode337:打家劫舍 III
1. 二叉树深搜 使用到layer

# 四、动态规划(前8道)
## 4.1 LeetCode070 爬楼梯
1. 动态规划 dp[i]表示爬到第i阶多少种不同的方法
2. dp[i]=dp[i−1]+dp[i−2]

## 4.2 LeetCode337 打家劫舍
1. 动态规划
2. dp[i] = max(nums[i]+dp[i-2], dp[i-1])

## 4.3 LeetCode053 最大子序和
1. 动态规划 dp[i] 表示以 nums[i] 结尾的最大子序和
2. dp[i] = max(nums[i-1]+nums[i], nums[i])
3. 经典

## 4.4 LeetCode322 零钱兑换：凑成总金额所需的最少的硬币个数
1. 方法1：背包，动态规划 dp[i] 表示金额 i 的最少使用钞票的张数 
    - dp[i] = min(dp[i-c1], dp[i-c2], ..., dp[i-cn]) + 1 = min(dp[i-c1] + 1, dp[i-c2] + 1, ..., dp[i-cn] + 1)
    - c1, c2 ... cn 表示第 n 枚硬币的面值
2. 方法2：贪心
    - 想要总硬币数最少，肯定是优先用大面值硬币，所以对 coins 按从大到小排序
    - 先丢大硬币，再丢会超过总额时，就可以递归下一层丢的是稍小面值的硬币
    ```
    k = amount / coins[c_index] 计算最大能投几个
    amount - k * coins[c_index] 减去扔了 k 个硬币
    count + k 加 k 个硬币
    ```

## 4.5 LeetCode120 三角形最小路径和
1. 动态规划 二维dp[i][j] 表示数组三角形第i行，第j列的最优解  
2. 从下到上递推
    - dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + nums[i][j]
    
## 4.6 LeetCode300 最长上升子序列
1. 动态规划 dp[i] 为考虑前 i 个元素，以第 i 个数字结尾的最长上升子序列的长度，注意 nums[i] 必须被选取 o(n2)
2. dp[i] = max[dp[j]] + 1, 其中0≤j<i且num[j]<num[i]

## 4.7 LeetCode064 最小路径和
1. 动态规划 二维dp[i][j] 表示从 (0,0) 走到 (i,j) 位置时最小路径和
2. dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + nums[i][j]

## 4.8 LeetCode174 地下城游戏
1. 动态规划 从右下到左上递推 dp[i][j] 表示从 (i,j) 位置到右下角至少需要多少血量，在行走过程中至少保持生命值为1
2. dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1]) - nums[i][j])

## 4.9 LeetCode337 打家劫舍 III
1. 动态规划 后序遍历 二叉树深搜


## 4.10 LeetCode085:最大矩形
1. 华为

## 4.11 LeetCode221 最大正方形
1. 华为

## 4.12 LeetCode005 最长回文子串
1. 华为

# 五、复杂数据结构:trie树(字典树/前缀树)+并查集+线段树(前4道经典题目)
## Trie 树 (功能类似于 hash 表)
1. Trie 树数据结构
    - Trie 树的构造
    - Trie 树的前序遍历 
    - Trie 树获取全部单词
2. Trie 树整体功能
    - 将 word 插入 Trie 树
    - 搜索 Trie 树中是否有 word
    - 确认 Trie 树中是否有前缀为 prefix 的单词

## Union Find 并查集
## SegmentTree 线段树
1. 是平衡二叉搜索树，除了最后一层，其他都是满的二叉树
2. 线段树是完全二叉树，所以可以使用数组保存。如果跟结点索引为 i，则左子树跟结点索引 2i+1，右 2i+2
## 4.1 LeetCode307 区域和检索 - 数组可修改
## 4.2 LeetCode400 字典序的第 k 个小数字
## 4.2 LeetCode820  单词的压缩编码
1. 华为


# 六、位运算
## 4.1 LeetCode136
## 4.2 LeetCode137
## 4.3 LeetCode260
## 4.4 LeetCode338
## 4.5 LeetCode318

# 七、哈希表与字符串(前6道)
## 2.1 LeetCode409 最长回文串
1. 字符哈希 int charMap[128]

## 2.2 LeetCode290 词语模式
1. 字符串哈希 map strMap<string, char>

## 2.3 LeetCode049 同字符词语分组
1. 数组哈希
2. 熟练 map<string, vector<string>> 操作 (在做几次)

## 2.4 LeetCode003 无重复字符的最长子串
1. 字符哈希：判断当前字符是否已经存在
2. 滑动窗口：左右两指针

## 2.5 LeetCode187 重复的DNA序列
1. 字符串哈希 map strMap<string, int> 滑动窗口

## 2.6 LeetCode076 最小窗口子串
1. 哈希维护窗口 (在做几次)
2. 窗口字符串哈希 键是字符 值是出现次数
3. 比较做指针在窗口哈希次数大于出现在字符串t时右移

# 八、二分搜索与二叉查找树(查找、分治)
## 4.1 LeetCode035:插入位置
1. 二分查找

## 4.2 LeetCode034:区间查找
1. 二分查找

## 4.3 LeetCode033:旋转数组查找(未做)
1. 二分查找、搜索旋转数组

## 4.4 LeetCode449:序列化和反序列化二叉搜索树
1. 二叉查找树前序遍历 
2. 整形转字符串 to_string 字符串转整形 stoi
3. 字符串拆分为整数 
4. 字符串与数字间处理
5. 二叉查找树插入结点

## 4.5 LeetCode315:计算右侧小于当前元素的个数，逆序数
1. 二叉查找树应用
2. 逆序数 二叉查找树中有多少元素小于当前插入元素 二叉查找树添加新成员左子树结点数量

# 九、递归、回溯、分治
## 5.1 LeetCode078:子集：返回数组所有可能子集

## 5.2 LeetCode---:子集 II:无重复子集
1. 回溯深搜

## 5.3 LeetCode---:组合数之和2
1. 回溯深搜

## 5.4 LeetCode---:生成括号
1. 回溯深搜

## 5.5 LeetCode---:N皇后
1. 递归设计

## 5.6 LeetCode---:计算右侧小于当前元素的个数，逆序数
1. 分治 
2. 归并排序

## 5.7 LeetCod394:字符串解码
1. 递归解法
2. 辅助栈解法
3. 常见数学函数
```c++
#include <cmath>
pow(4,2); // 4的平方=16
sqrt(4); // 4的平方根=2
abs(-4);
```

# 十、方法：前缀和
## 

# 十一、方法：单调栈
## 

# 十二、stl综合
## 13.1 LeetCode533 孤独像素 II
1. 读题 stl使用 c++语言熟练