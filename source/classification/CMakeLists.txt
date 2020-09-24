project(leetcode)


#####################################################################
#                       stl&math
#####################################################################
add_executable(LeetCode060 stl&math/LeetCode060.cpp)
add_executable(LeetCode347 stl&math/LeetCode347.cpp)


#####################################################################
#                       贪心算法
#####################################################################
add_executable(PayMoney greedyAlgorithm/PayMoney.cpp)
add_executable(LeetCode455 greedyAlgorithm/LeetCode455.cpp)
add_executable(LeetCode376 greedyAlgorithm/LeetCode376.cpp)
add_executable(LeetCode402 greedyAlgorithm/LeetCode402.cpp)
add_executable(LeetCode055 greedyAlgorithm/LeetCode055.cpp)
add_executable(LeetCode045 greedyAlgorithm/LeetCode045.cpp)
add_executable(LeetCode452 greedyAlgorithm/LeetCode452.cpp)
add_executable(Poj2431 greedyAlgorithm/Poj2431.cpp)
add_executable(Leetcode763 greedyAlgorithm/LeetCode763.cpp)
add_executable(Leetcode1167 greedyAlgorithm/LeetCode1167.cpp)
add_executable(Leetcode253 greedyAlgorithm/LeetCode253.cpp)
add_executable(Leetcode1094 greedyAlgorithm/LeetCode1094.cpp)


#####################################################################
#                       搜素
#####################################################################
add_executable(LeetCode200 search/LeetCode200.cpp)
add_executable(LeetCode200_2 search/LeetCode200_2.cpp)
add_executable(LeetCode127 search/LeetCode127.cpp)
add_executable(LeetCode126 search/LeetCode126.cpp)
#add_executable(LeetCode407 search/LeetCode407.cpp)
add_executable(LeetCode079 search/LeetCode079.cpp)
add_executable(LeetCode079_2 search/LeetCode079_2.cpp)
add_executable(LeetCode994 search/LeetCode994.cpp)
add_executable(LeetCode695 search/LeetCode695.cpp)
add_executable(LeetCode695_2 search/LeetCode695_2.cpp)
add_executable(LeetCode815 search/LeetCode815.cpp)


#####################################################################
#                       动态规划
#####################################################################
add_executable(LeetCode070 dp/LeetCode070.cpp)
add_executable(LeetCode198 dp/LeetCode198.cpp)
add_executable(LeetCode053 dp/LeetCode053.cpp)
add_executable(LeetCode337 dp/LeetCode337.cpp)
add_executable(LeetCode322 dp/LeetCode322.cpp)
add_executable(LeetCode322_2 dp/LeetCode322_2.cpp)
add_executable(LeetCode120 dp/LeetCode120.cpp)
add_executable(LeetCode120_2 dp/LeetCode120_2.cpp)
add_executable(LeetCode300 dp/LeetCode300.cpp)
add_executable(LeetCode064 dp/LeetCode064.cpp)


#####################################################################
#                        递归归并
#####################################################################
add_executable(LeetCode394 recursion&merge/LeetCode394.cpp)
add_executable(LeetCode226 recursion&merge/LeetCode226.cpp) # 二叉树递归
add_executable(LeetCode404 recursion&merge/LeetCode404.cpp) # 二叉树递归



#####################################################################
#                       高级数据结构
#####################################################################
add_executable(TrieNode complexDataStruct/TrieNode.cpp)
add_executable(TrieTree complexDataStruct/TrieTree.cpp)
add_executable(UF complexDataStruct/UnionFind.cpp)
add_executable(SegmentTree complexDataStruct/SegmentTree.cpp)
add_executable(LeetCode307 complexDataStruct/LeetCode307.cpp)


#####################################################################
#                       哈希表与字符串
#####################################################################
add_executable(LeetCode409 string/LeetCode409.cpp)
add_executable(LeetCode290 string/LeetCode290.cpp)
add_executable(LeetCode049 string/LeetCode049.cpp)
add_executable(LeetCode003 string/LeetCode003.cpp)
add_executable(LeetCode187 string/LeetCode187.cpp)
add_executable(LeetCode076 string/LeetCode076.cpp)


#####################################################################
#                  二叉树与有向图的搜索
#####################################################################
add_executable(TreeDfs tree&map/TreeDfsBfs.cpp)
add_executable(LeetCode113 tree&map/LeetCode113.cpp)
add_executable(LeetCode236 tree&map/LeetCode236.cpp)
add_executable(LeetCode114 tree&map/LeetCode114.cpp)
add_executable(LeetCode114_2 tree&map/LeetCode114_2.cpp)
add_executable(LeetCode199 tree&map/LeetCode199.cpp)
add_executable(LeetCode332 tree&map/LeetCode332.cpp)
add_executable(LeetCode107 tree&map/LeetCode107.cpp)
add_executable(LeetCode637 tree&map/LeetCode637.cpp)
add_executable(LeetCode094 tree&map/LeetCode094.cpp)
add_executable(LeetCode617 tree&map/LeetCode617.cpp) # 二叉树中序遍历，递归


#####################################################################
#                        二分查找和二叉搜索树
#####################################################################
add_executable(Binaryearch bintree/BinarySearch.cpp)
add_executable(BinTree bintree/BinTree.cpp)
add_executable(LeetCode035 bintree/LeetCode035.cpp)
add_executable(LeetCode034 bintree/LeetCode034.cpp)
#add_executable(LeetCode033 bintree/LeetCode033.cpp)
add_executable(LeetCode449 bintree/LeetCode449.cpp)
add_executable(LeetCode315 bintree/LeetCode315.cpp)
add_executable(LeetCode538 bintree/LeetCode538.cpp) # 二叉搜索树的反序中序遍历


#####################################################################
#                       栈
#####################################################################
add_executable(LeetCode739 stack/LeetCode739.cpp) # 单调栈
add_executable(LeetCode084 stack/LeetCode084.cpp) # 单调栈
add_executable(LeetCode394_2 stack/LeetCode394_2.cpp) # 辅助栈


#####################################################################
#                       回溯算法
#####################################################################
add_executable(LeetCode473 backtrack/LeetCode473.cpp)
add_executable(LeetCode077 backtrack/LeetCode077.cpp)
add_executable(LeetCode039 backtrack/LeetCode039.cpp)
add_executable(LeetCode040 backtrack/LeetCode040.cpp)
add_executable(LeetCode216 backtrack/LeetCode216.cpp)
add_executable(LeetCode037 backtrack/LeetCode037.cpp)
add_executable(LeetCode078 backtrack/LeetCode078.cpp) # 数组所有可能的子集
add_executable(LeetCode047 backtrack/LeetCode047.cpp) # 数组所有所有不重复的全排列


#####################################################################
#                       滑动窗口
#####################################################################
add_executable(LeetCode1208 slidingWindow/LeetCode1208.cpp)