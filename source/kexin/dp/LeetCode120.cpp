//
// Created by zhaohailong on 2020/6/21.
//

/*
给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。

 

例如，给定三角形：

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/triangle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        vector<vector<int>> dp = triangle;
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp[i].size(); j++) {
                dp[i][j] = 0;
            }
        }
        for (int i = triangle.size() - 1; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                if (i == triangle.size() - 1) {
                    dp[i][j] = triangle[i][j];
                } else {
                    dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
                }
            }
        }
        return dp[0][0];
    }
};

int main()
{
    vector<vector<int>> a = {{ 2 },
                             { 3, 4 },
                             { 6, 5, 7 },
                             { 4, 1, 8, 3 }};
    Solution s;
    cout << s.minimumTotal(a) << endl;

    return 0;
}