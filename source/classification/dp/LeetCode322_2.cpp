//
// Created by zhaohailong on 2020/6/19.
//

/*
给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

 

示例 1:

输入: coins = [1, 2, 5], amount = 11
输出: 3
解释: 11 = 5 + 5 + 1
示例 2:

输入: coins = [2], amount = 3
输出: -1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/coin-change
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int coinChange(vector<int> &coins, int amount)
    {
        if (amount == 0) return 0;
        sort(coins.begin(), coins.end(), greater<int>());
        int ret = amount + 1;
        CoinChange(coins, amount, 0, 0, ret);
        return ret > amount ? -1 : ret;
    }

private:
    void CoinChange(vector<int> &coins, int amount, int coinIndex, int count, int &ret)
    {
        // 找到了，记录结果
        if (amount == 0) {
            ret = min(ret, count);
            return;
        }
        // 所有可能遍历完
        if (coinIndex == coins.size()) {
            return;
        }

        // 核心
        for (int k = amount / coins[coinIndex]; k >= 0 && k + count < ret; k--) {
            CoinChange(coins, amount - k * coins[coinIndex], coinIndex + 1, count + k, ret);
        }
    }
};

int main()
{
    vector<int> coins = { 1, 2, 5 };
    int amount = 11;
    Solution s;
    cout << s.coinChange(coins, amount) << endl;

    return 0;
}