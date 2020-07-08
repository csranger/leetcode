//
// Created by zhaohailong on 2020/6/4.
//

/*
有1，5，10，20，100，200元的钞票无数张，现使用这些钞票支付 x 元，最少支付多少张？


 尽可能多的使用面值较大的钞票。贪心法：遵循某种规律，不断贪心选取当前最优策略的算法设计方法。
 为什么这是对的？
 因为任意面额是比自己小的面额的倍数关系。
 所以，如果增加 7 元面额，就不成立了。例如 14 按照贪心应该是 1张10元加上4张1元，实际上最优是两张7元即可。
 */

#include <iostream>

using namespace std;

int MinNumBanknote(int x)
{
    int RMB[] = { 200, 100, 20, 10, 5, 1 };
    int ret = 0;
    for (int i = 0; i < 6; i++) {
        if (x >= RMB[i]) {
            ret += x / RMB[i];
            cout << "RMB " << RMB[i] << " : " << x / RMB[i] << "张" << endl;
            x = x % RMB[i];
        }
    }
    return ret;
}

int main()
{
    int x = 421;
    int ret = MinNumBanknote(x);
    cout << ret << endl;

    return 0;
}