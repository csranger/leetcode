//
// Created by zhaohailong on 2020/8/2.
//

/*
字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。返回一个表示每个字符串片段的长度的列表。

 

示例 1：

输入：S = "ababcbacadefegdehijhklij"
输出：[9,7,8]
解释：
划分结果为 "ababcbaca", "defegde", "hijhklij"。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-labels
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        int index[26] = {0};
        for (int i = 0; i < S.length(); i++) {
            index[S[i] - 'a'] = i;
        }

        int startJumpPos = 0;
        vector<int> ret;
        while (startJumpPos < S.length()) {
            // 从 startJumpPos 出开始跳跃
            int maxPos = index[S[startJumpPos] - 'a'];
            int i = startJumpPos + 1;
            while (i < S.length() && i <= maxPos) {
                maxPos = max(maxPos, index[S[i] - 'a']);
                i++;
            }
            ret.push_back(maxPos - startJumpPos + 1);
            startJumpPos = maxPos + 1;
        }
        return ret;
    }
};

int main() {
    string str = "ababcbacadefegdehijhklij";
    Solution s;
    vector<int> ret = s.partitionLabels(str);
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << endl;
    }

    return 0;
}