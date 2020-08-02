project(leetcode)


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
#                       搜素
#####################################################################
add_executable(LeetCode200 search/LeetCode200.cpp)
add_executable(LeetCode200_2 search/LeetCode200_2.cpp)
add_executable(LeetCode127 search/LeetCode127.cpp)
add_executable(LeetCode126 search/LeetCode126.cpp)
add_executable(LeetCode473 search/LeetCode473.cpp)
#add_executable(LeetCode407 search/LeetCode407.cpp)
#add_executable(LeetCode079 search/LeetCode079.cpp)


#####################################################################
#                        递归回溯归并
#####################################################################
add_executable(LeetCode078 backtrackingMerge/LeetCode078.cpp)


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
#                        二叉树和图
#####################################################################
add_executable(TreeDfs treemap/TreeDfs.cpp)
add_executable(LeetCode113 treemap/LeetCode113.cpp)
add_executable(LeetCode236 treemap/LeetCode236.cpp)
add_executable(LeetCode114 treemap/LeetCode114.cpp)
add_executable(LeetCode114_2 treemap/LeetCode114_2.cpp)
add_executable(LeetCode199 treemap/LeetCode199.cpp)


#####################################################################
#                        二分查找和二叉查找树
#####################################################################
add_executable(Binaryearch bintree/BinarySearch.cpp)
add_executable(BinTree bintree/BinTree.cpp)
add_executable(LeetCode035 bintree/LeetCode035.cpp)
add_executable(LeetCode034 bintree/LeetCode034.cpp)
#add_executable(LeetCode033 bintree/LeetCode033.cpp)
add_executable(LeetCode449 bintree/LeetCode449.cpp)
add_executable(LeetCode315 bintree/LeetCode315.cpp)


#####################################################################
#                       模拟测试
#####################################################################
add_executable(Tlv exam/Tlv.cpp)
#12.27
add_executable(work1227_1 exam/work1227_1.cpp)
add_executable(work1227_2 exam/work1227_2.cpp)
add_executable(work1227_3 exam/work1227_3.cpp)
#3.20
add_executable(work0320_1_LeetCode1122 exam/work0320_1_LeetCode1122.cpp)
add_executable(work0320_2_LeetCode604 exam/work0320_2_LeetCode604.cpp)
#add_executable(work0320_3 exam/work0320_3.cpp)
#songlaoshi
#add_executable(LeetCode640 exam/LeetCode640.cpp)
#9.26
add_executable(work0926_1 exam/work0926_1_LeetCode1086.cpp)
add_executable(work0926_2 exam/work0926_2_LeetCode751.cpp)
#add_executable(work0926_3 exam/work0926_3_LeetCode547.cpp)
#2020.5.29
#add_executable(work0529_1 exam/work0529_1.cpp)
#add_executable(work0529_2 exam/work0529_2.cpp)
#add_executable(work0529_3 exam/work0529_3.cpp)
# 2020.5.25 http://3ms.huawei.com/km/groups/3942602/blogs/details/6762735#preview_attachment_box_6762735
#add_executable(expert0525_1 exam/expert0515_1.cpp)
add_executable(expert0515_2_LeetCode1055 exam/expert0515_2_LeetCode1055.cpp)