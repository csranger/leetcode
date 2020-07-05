//
// Created by zhaohailong on 2020/5/12.
//

/*
返回3个严格递增数组中共同的值
例如输入：
 array1=[1,2,3,4,5]
 array2=[1,2,5,7,9]
 array3=[1,3,4,5,8]

返回：
 [1,5]

 知识点：哈希表
 */

#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> CommonValueOf3Array(vector<int> &array1, vector<int> &array2, vector<int> &array3)
    {
        vector<int> ret;
        map<int, int> intMap;
        for (int i = 0; i < array1.size(); i++) {
            intMap[array1[i]]++;
        }
        for (int i = 0; i < array2.size(); i++) {
            if (intMap.find(array2[i]) != intMap.end()) {
                intMap[array2[i]]++;
            }
        }
        for (int i = 0; i < array3.size(); i++) {
            if (intMap[array3[i]] == 2) {
                ret.push_back(array3[i]);
            }
        }
        return ret;
    }
};

int main()
{
    vector<int> a1 = { 1, 2, 3, 4, 5 };
    vector<int> a2 = { 1, 2, 5, 7, 9 };
    vector<int> a3 = { 1, 3, 4, 5, 8 };
    Solution s;
    vector<int> ret = s.CommonValueOf3Array(a1, a2, a3);
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << endl;
    }
}
