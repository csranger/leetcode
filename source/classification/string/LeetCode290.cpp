//
// Created by zhaohailong on 2020/5/2.
//

/*
给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。

这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。

示例1:

输入: pattern = "abba", str = "dog cat cat dog"
输出: true
示例 2:

输入:pattern = "abba", str = "dog cat cat fish"
输出: false
示例 3:

输入: pattern = "aaaa", str = "dog cat cat dog"
输出: false
示例 4:

输入: pattern = "abba", str = "dog dog dog dog"
输出: false
说明:
你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。    

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-pattern
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str)
    {
        map<string, char> strMap;
        int charMap[128] = { 0 };
        vector<string> wordVec = Split(str);
        if (wordVec.size() != pattern.length()) {
            return false;
        }
        for (int i = 0; i < wordVec.size(); i++) {
            if (strMap.find(wordVec[i]) == strMap.end() && charMap[pattern[i]] == 0) {
                strMap[wordVec[i]] = pattern[i];
                charMap[pattern[i]] = 1;
            } else if (strMap.find(wordVec[i]) == strMap.end() && charMap[pattern[i]] == 1) {
                return false;
            } else {
                if (strMap[wordVec[i]] != pattern[i]) {
                    return false;
                }
            }
        }
        return true;
    }

    vector<string> Split(string str)
    {
        str += " ";
        vector<string> ret;
        string word;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] != ' ') word += str[i];
            else {
                ret.push_back(word);
                word = "";
            }
        }
        return ret;
    }
};

int main()
{
    Solution s;

    string pattern = "abba";
    string str = "dog cat cat fish";
    vector<string> ret = s.Split(str);
    cout << ret.size() << endl;
    cout << ret[0] << endl;
    cout << ret[1] << endl;
    cout << ret[2] << endl;
    cout << ret[3] << endl;
    cout << s.wordPattern(pattern, str) << endl;

    // 2
    string pattern2 = "jquery";
    string str2 = "jquery";
    cout << s.wordPattern(pattern2, str2) << endl;
}