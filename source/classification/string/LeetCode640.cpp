//
// Created by zhaohailong on 2020/5/17.
//

/*
求解一个给定的方程，将x以字符串"x=#value"的形式返回。该方程仅包含'+'，' - '操作，变量 x 和其对应系数。

如果方程没有解，请返回“No solution”。

如果方程有无限解，则返回“Infinite solutions”。

如果方程中只有一个解，要保证返回值 x 是一个整数。

示例 1：

输入: "3x+5=6+2x-2"
输出: "x=-1"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/solve-the-equation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string solveEquation(string equation)
    {
        equation += "+";
        vector<int> left, right;
        int leftFlag = 1;
        int leftSum = 0, rightSum = 0;
        string temp;
        for (int i = 0; i < equation.length(); i++) {
            if (i >= 1 && equation[i - 1] == '=') {
                leftFlag = -1;
            }
            // 获取得到 +5 或者 -3x
            if (i > 0 && (equation[i] == '+' || equation[i] == '-' || equation[i] == '=')) {
                // 2x -2x x -x
                if (temp == "x") {
                    leftSum += leftFlag * 1;
                } else if (temp == "-x") {
                    leftSum += leftFlag * -1;
                } else if (temp.size() > 0 && temp[temp.size() - 1] == 'x') {
                    leftSum += leftFlag * stoi(temp.substr(0, temp.size() - 1));
                } else if (temp.size() > 0) { // +5 -6
                    int number = -1 * leftFlag * stoi(temp);
                    rightSum += number;
                }
                temp = "";
                if (equation[i] == '-') {
                    temp += equation[i];
                }
            } else {
                temp += equation[i];
            }
        }

        // 根据 rightSum 和 leftSum 判断是否有解
        string ret;
        if (leftSum == 0 && rightSum == 0) {
            ret = "Infinite solutions";
        } else if (leftSum == 0 && rightSum != 0) {
            ret = "No solution";
        } else {
            ret = "x=" + to_string(rightSum / leftSum);
        }
        return ret;
    }

};

int main()
{
    string str = "x+1=2x+3";
    Solution s;
    cout << s.solveEquation(str) << endl;
    string str2 = "-x=-1";
    cout << s.solveEquation(str2) << endl;
    string str3 = "-x=1";
    cout << s.solveEquation(str3) << endl;
}