//
// Created by zhaohailong on 2020/9/13.
//

/*
给你两个长度相同的字符串，s 和 t。

将 s中的第i个字符变到t中的第 i 个字符需要|s[i] - t[i]|的开销
 （开销可能为 0），也就是两个字符的 ASCII 码值的差的绝对值。

用于变更字符串的最大预算是maxCost。在转化字符串时，总开销应当小于等于该预算，这也意味着字符串的转化可能是不完全的。

如果你可以将 s 的子字符串转化为它在 t 中对应的子字符串，则返回可以转化的最大长度。

如果 s 中没有子字符串可以转化成 t 中对应的子字符串，则返回 0。

示例 1：

输入：s = "abcd", t = "bcdf", cost = 3
输出：3
解释：s 中的 "abc" 可以变为 "bcd"。开销为 3，所以最大长度为 3。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/get-equal-substrings-within-budget
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> vec;
        vec.reserve(s.size());
        for (int i = 0; i < s.size(); i++) {
            vec.emplace_back(abs(t[i] - s[i]));
        }
        // 窗口和小于等于开销，右移右指针，窗口和大于开销，右移左指针
        int left = 0, right = 0;
        int sum = 0;
        int maxLen = 0;
        // 右结点右移
        for (right = 0; right < vec.size(); right++) {
            sum += vec[right];
            if (sum <= maxCost) {
                maxLen = max(right - left + 1, maxLen);
                continue;
            }
            // 左结点右移
            while (sum > maxCost && left < vec.size()) {
                sum -= vec[left];
                left++;
            }
        }
        return maxLen;
    }
};

int main() {
    string s = "pxezla";
    string t = "loewbi";
    Solution ss;
    cout << ss.equalSubstring(s, t, 25) << endl;

    return 0;
}