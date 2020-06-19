[TOC]
# 一、搜索(前5道经典搜索题目)(在做几次)
## 1.1 LeetCode200:岛屿数量：二维数组上连一起为一个岛
1. 深搜 二维数组记录访问过的点
2. 广搜 搜索队列 Q 二维数组记录访问过的点 将带搜索的位置push进入到队列

## 1.2 LeetCode127:词语阶梯
1. 广搜  邻接表map<string,vector<string>>表示图  记录搜索过程步数  
    - 搜索队列queue<pair<顶点,步数>>
    - 集合set<string>记录搜索过的结点
    - 尽量使用 const 和 & 减少时间消耗
    
## 1.3 LeetCode126:词语阶梯2(hard)
1. 记录路径的宽搜 邻接表表示图 起点到终点多条路径保存
    - 搜索队列使用 vector<Qitem> 替换 queue<pair<string,int>> 从而保存所有路径
    - Qitem 保存着前驱节点位置和步数信息，比 pair<string,int> 多了一个前驱结点在队列中的位置
    - 使用map<string, int> 替换集合记录搜索过的结点:记录达到m每个位置所需最小步数，存取不同前驱到达该位置情况
    - 使用变量 front 表示搜索队列的队列头，而不需要pop掉
    
## 1.4 Leetcode473:火柴拼正方形
1. 回溯深搜

## 1.5 搜集雨水(hard)
1. 带优先级的广度优先搜索 优先队列

## 1.6 LeetCode079:单词搜索
1. 回溯深搜 未做

# 二、哈希表与字符串(前6道经典哈希表与字符串相关题目)
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

# 三、二叉树与图(前5道经典二叉树和图题目)
## 3.1 LeetCode113 路径之和2
1. 经典二叉树深搜 前序遍历 记录路径

## 3.2 LeetCode236:最近的公共祖先
1. 深度搜索 获取跟结点到指定结点之间路径(在写几次)

## 3.3 LeetCode144:二叉树转链表(最经典前中后序)
1. 使用vector<Treenode *>保存所有结点
2. 原地转链表

## 3.4 LeetCode199:侧面观察二叉树
1. 二叉树宽搜 二叉树层次遍历 结点与层数绑定为pair压入队列

## 3.5 LeetCode207:有向图判断环
1. 未做

## 3.6 LeetCode337:打家劫舍 III
1. 二叉树深搜 使用到layer

# 四、二分搜索与二叉查找树(查找、分治)
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

# 五、递归、回溯、分治相关题目
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

# 六、贪心算法(前7道经典搜索题目)
## 6.1 LeetCode455 用更小的饼干满足更多的孩子
1. 贪心：某个孩子可以用更小的糖果满足，则没必要用更大糖果满足，因为可以保留更大的糖果满足需求因子更大的孩子

## 6.2 LeetCode376 删除一些元素获取摆动序列
1. 贪心：当序列有一段连续的递增(或递减时)，为形成摇摆序列，我们只需要保留这些连续的递增(或递减时)的首尾元素，
   这样更可能使得尾部的后一个元素成为摇摆子序列的下一个元素。
2. 状态机

## 6.3 LeetCode402 移除 k 个数字使新数字最小
1. 贪心：若去掉某一位数字，为使得新数字最小，尽可能让新数字优先最高位最小
2. 单调栈 

## 6.4 LeetCode055 跳跃游戏
1. nums[] -> index[] -> 遍历 index[] 记录 maxIndex(贪心：在每一步选择中都采取在当前状态下最好或最优（即最有利）的选择)
2. index[] 表示当前位置能跳的最远位置index

## 6.5 LeetCode045 跳跃游戏 II
1. 为了使得跳跃次数最少，什么时机跳最优？ 起始位置0，可到到最远距离是 nums[0]，在索引 0~nums[0] 区间遍历，记录遍历过程中可达到的最远距离，
   索引位置j∈[0,nums[0]]，则跳到索引j处，最远距离 j+nums[j]。

## 6.6 LeetCode452 用最少数量的箭引爆气球
1. 贪心：对于某个气球，至少需要1只弓箭将其击穿，在这只气球被击穿同时，尽可能击穿其他更多的气球
2. 按照气球左端点排序，遍历气球数组，同时维护一个射击区间，尽可能射击更多气球，每射击一个新气球
   更新一次射击区间。如果新的气球没办法击穿，则新增一个弓箭手，维护一个射击区间。
3. 自定义 sort 函数里的 compare 函数

## 6.7 Poj2431 最优加油方法



# 七、动态规划(前5到经典动态规划题目)
## 7.1 LeetCode070 爬楼梯
1. 动态规划
2. dp[i]=dp[i−1]+dp[i−2]

## 7.2 LeetCode337 打家劫舍
1. 动态规划
2. dp[i] = max(nums[i]+dp[i-2], dp[i-1])

## 7.3 LeetCode053 最大子序和
1. 动态规划 dp[i] 表示以第n个数字结尾的最大子端和
2. dp[i] = max(nums[i-1]+nums[i], nums[i])
3. 经典

## 7.4 LeetCode322 零钱兑换：凑成总金额所需的最少的硬币个数
1. 动态规划 dp[i] 表示金额 i 的最少使用钞票的张数
2. dp[i] = min(dp[i-1], dp[i-2], dp[i-5]) + 1

## 7.5 LeetCode

## 7.6 LeetCode337 打家劫舍 III
1. 动态规划 后序遍历 二叉树深搜

# 八、复杂数据结构

# 九、实战练习
## 9.1 TLV 解码
1. uint8_t * 字节流数据强转成结构体 TLV * memcpy_s获取数据
2. pragma pack(1) 指定按照1字节内存对齐
3. 大端字节序，数字移位处理，对解析时异常值的处理

## 9.2 work_1227_1 返回3个严格递增数组中共同的值
1. 哈希表

## 9.3 work_1227_2 二叉树上路径上遇到某结点值的概率
1. 二叉树层次遍历

## 9.4 work_1227_3 TLV 编码
1. 

## 9.5 work0320_1_LeetCode1122 数组的相对排序
1. 排序 也可使用map解

## 9.6 work0320_2_LeetCode604 迭代压缩字符串(有技巧性)
1. 逻辑处理复杂 需要在写几次

## 9.7 work0320_3 
1. 未做

## 9.8 work0926_1 work0926_1_LeetCode1086 前五科的均分
1. stl基础运用 map<int, vector<int>> scores; scores.insert(make_pair(items[i][0], vector<int>()));
2. map内部实现了一个红黑树，该结构具有自动排序的功能，因此map内部的所有元素都是有序的
3. unordered_map: unordered_map内部实现了一个哈希表，因此其元素的排列顺序是杂乱的，无序的

## 9.9 work0926_2 work0926_1_LeetCode751 IP 到 CIDR
1. 理解题目 位运算 字符串

## 9.10 work0926_3 work0926_1_LeetCode547 朋友圈

## 9.11 expert_LeetCode640 求解方程(song)
1. 整形转字符串 to_string 字符串转整形 stoi
2. 分类讨论

## 9.12 expert_LeetCodeCode1293 网格中的最短路径(song)

## 9.13 [expert0515_1](http://3ms.huawei.com/km/groups/3942602/blogs/details/6762735#preview_attachment_box_6762735)
1. 很简单练习编码速度

## 9.14 expert0515_2_LeetCode1055 形成字符串的最短路径

## 9.15 expert0515_3_LeetCode085

# 十、方法：位运算
## 

# 十一、方法：前缀和
## 

# 十二、方法：单调栈
## 

# 十三、stl综合
## 13.1 LeetCode533 孤独像素 II
1. 读题 stl使用 c++语言熟练