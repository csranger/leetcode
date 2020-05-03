//
// Created by zhaohailong on 2020/5/3.
//

/*
所有 DNA 都由一系列缩写为 A，C，G 和 T 的核苷酸组成，例如：“ACGAATTCCG”。在研究 DNA 时，识别 DNA 中的重复序列有时会对研究非常有帮助。

编写一个函数来查找 DNA 分子中所有出现超过一次的 10 个字母长的序列（子串）。

 

示例：

输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
输出：["AAAAACCCCC", "CCCCCAAAAA"]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/repeated-dna-sequences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        vector<string> ret;
        int right = 9;
        map<string, int> strMap;
        while (right < s.length()) {
            int left = right - 9;
            string temp = s.substr(left, 10);
            if (strMap.find(temp) == strMap.end()) {
                strMap[temp] = 1;
            } else if (strMap[temp] == 1) {
                strMap[temp]++;
                ret.push_back(temp);
            } else {
                strMap[temp]++;
            }
            right++;
        }
        return ret;
    }
};

int main()
{
    string str = "AAAAAAAAAAAA";
    Solution s;
    vector<string> ret = s.findRepeatedDnaSequences(str);
    cout << "size: " << ret.size() << endl;
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << endl;
    }

    return 0;
}











