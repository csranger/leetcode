//
// Created by zhaohailong on 2020/5/3.
//

/*
给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串。

示例：

输入: S = "ADOBECODEBANC", T = "ABC"
输出: "BANC"
说明：

如果 S 中不存这样的子串，则返回空字符串 ""。
如果 S 中存在这样的子串，我们保证它是唯一的答案。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-window-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {

private:
    bool IsWindowOk(int windowMap[], int tMap[], vector<int> &tVec)
    {
        for (int i = 0; i < tVec.size(); i++) {
            if (windowMap[tVec[i]] < tMap[tVec[i]]) {
                return false;
            }
        }
        return true;
    }

public:
    string minWindow(string s, string t)
    {
        vector<int> tVec;
        int windowMap[128] = { 0 }; // 窗口字符串对应的 字符哈希，键是字符，值是出现次数
        int tMap[128] = { 0 };
        for (int i = 0; i < t.length(); i++) {
            tMap[t[i]]++;
        }
        for (int i = 0; i < 128; i++) {
            if (tMap[i] > 0) {
                tVec.push_back(i);
            }
        }

        // 滑动窗口
        int left = 0, right;
        string ret;
        for (right = 0; right < s.length(); right++) {
            windowMap[s[right]]++;
            // 每到一个 right，就尝试右移 left 指针以使得窗口尽量小
            while (left < right) {
                char leftChar = s[left];
                if (tMap[leftChar] == 0) {  // 窗口头字符不在字符串 t 中
                    left++;
                } else if (windowMap[s[left]] > tMap[s[left]]) {// 窗口头字符在窗口出现次数超过字符串t
                    windowMap[s[left]]--;
                    left++;
                } else {        // 窗口头字符在窗口出现次数不超过字符串t，则不移动 left 指针
                    break;
                }
            }
            // 每到一个 right，就查看当前窗口是否包含字符串 t
            if (IsWindowOk(windowMap, tMap, tVec)) {
                if (ret.empty() || ret.length() > right - left + 1) {
                    ret = s.substr(left, right - left + 1);
                }
            }
        }
        return ret;
    }

};

int main()
{
    //1
    string s = "ADOBECODEBANC";
    string t = "ABC";

    Solution ss;
    cout << ss.minWindow(s, t) << endl;
    // 2
    string s2 = "a";
    string t2 = "aa";

    cout << ss.minWindow(s2, t2) << endl;

    return 0;
}



