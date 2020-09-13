//
// Created by zhaohailong on 2020/9/5.
//

/*
给出集合[1,2,3,…,n]，其所有元素共有n! 种排列。

按大小顺序列出所有排列情况，并一一标记，当n = 3 时, 所有排列如下：

"123"
"132"
"213"
"231"
"312"
"321"
给定n 和k，返回第k个排列。

说明：

给定 n的范围是 [1, 9]。
给定 k的范围是[1, n!]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutation-sequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        for (int i = 0; i <= n; i++) {
            nums.push_back(i);
        }

        string ret;
        while (nums.size() > 1) {
            ret += '0' + DetermineFirstNum(nums, n, k);
            n = nums.size() - 1;
        }
        return ret;
    }

    // 利用 nums 里的数进行排列，找出第 k 个排列的首数字
    static int DetermineFirstNum(vector<int> &nums, int n, int &k) {
        if (k == 1) {
            int ret = nums[1];
            vector<int>::iterator it = begin(nums);
            nums.erase(it + 1);
            return ret;
        }
        int index = 1;
        while (n > 1 && k > index * Factorial(n - 1)) {
            index++;
        }
        // 更新 index 和 nums
        k = k - ((index - 1) * Factorial(n - 1));
        int ret = nums[index];
        auto it = begin(nums);
        nums.erase(it + index);
        return ret;
    }


    static int Factorial(int n) {
        if (n == 1) return 1;
        return n * Factorial(n - 1);
    }
};

int main() {

    vector<int> nums = {0, 1, 4};
    int n = 2;
    int k = 1;
    cout << Solution::DetermineFirstNum(nums, n, k) << endl;

//    int n = 4;
//    int k = 9;
//    Solution s;
//    cout << s.getPermutation(n, k) << endl;

    return 0;
}


