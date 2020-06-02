//
// Created by zhaohailong on 2020/5/31.
//

/*
给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。

示例:

输入:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
输出: 6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximal-rectangle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <string>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    int shortestWay(string source, string target)
    {
        // target 如果包括 source 不存在的字符
        for (int i = 0; i < target.length(); i++) {
            if (source.find(target[i]) == string::npos) {
                return -1;
            }
        }

        // target 可以由 source 子串组合
        int ret = 0;
        int pos = 0;
        int i = 0;
        while (i < target.length()) {
            pos = source.find(target[i], pos);
            if (pos == string::npos) {
                ret++;
                pos = 0;
            } else {
                pos++;
                i++;
            }
        }
        return ret + 1;
    }
};

int main()
{
    string source = "abcad", target = "bdad";
    Solution s;
    cout << s.shortestWay(source, target) << endl;
    string source2 = "xyz", target2 = "xzyxz";
    cout << s.shortestWay(source2, target2) << endl;
}

