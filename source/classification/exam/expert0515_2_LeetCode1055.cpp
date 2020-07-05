//
// Created by zhaohailong on 2020/5/31.
//

/*
对于任何字符串，我们可以通过删除其中一些字符（也可能不删除）来构造该字符串的子序列。

给定源字符串 source 和目标字符串 target，找出源字符串中能通过串联形成目标字符串的子序列的最小数量。如果无法通过串联源字符串中的子序列来构造目标字符串，则返回 -1。

 

示例 1：

输入：source = "abc", target = "abcbc"
输出：2
解释：目标字符串 "abcbc" 可以由 "abc" 和 "bc" 形成，它们都是源字符串 "abc" 的子序列。
示例 2：

输入：source = "abc", target = "acdbc"
输出：-1
解释：由于目标字符串中包含字符 "d"，所以无法由源字符串的子序列构建目标字符串。
示例 3：

输入：source = "xyz", target = "xzyxz"
输出：3
解释：目标字符串可以按如下方式构建： "xz" + "y" + "xz"。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shortest-way-to-form-string
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

