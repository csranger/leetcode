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
        vector<int> ends(S.size(), -1);
        for (int i = 0; i < S.size(); i++) {
            ends[S[i] - 'a'] = i;
        }
        vector<int> ret;
        // i 遍历每一个字符，找出一定段内最远索引位置 maxPos
        int i = 0;
        while (i < ends.size()) {
            // 以下同跳跃游戏相同代码
            int maxPos = ends[S[i] - 'a'];
            int j = i + 1;
            while (j < ends.size() && j <= maxPos) {
                maxPos =max(maxPos, ends[S[j] - 'a']);
                j++;
            }
            ret.push_back(maxPos - i + 1);
            i = maxPos + 1;
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