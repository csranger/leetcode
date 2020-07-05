//
// Created by zhaohailong on 2020/7/5.
//

/*
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/group-anagrams
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ret;
        map<string, vector<string>> strMap;

        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if (strMap.find(temp) == strMap.end()) {
                vector<string> item;
                strMap[temp] = item;
            }
            strMap[temp].push_back(strs[i]);

        }

        map<string, vector<string>>::iterator iter;
        for (iter = strMap.begin(); iter != strMap.end(); iter++) {
            ret.push_back(iter->second);
        }
        return ret;
    }
};