//
// Created by zhaohailong on 2020/5/22.
//

/*
给你一个不同学生的分数列表，请按 学生的 id 顺序 返回每个学生 最高的五科 成绩的 平均分。

对于每条 items[i] 记录， items[i][0] 为学生的 id，items[i][1] 为学生的分数。平均分请采用整数除法计算。

 

示例：

输入：[[1,91],[1,92],[2,93],[2,97],[1,60],[2,77],[1,65],[1,87],[1,100],[2,100],[2,76]]
输出：[[1,87],[2,88]]
解释：
id = 1 的学生平均分为 87。
id = 2 的学生平均分为 88.6。但由于整数除法的缘故，平均分会被转换为 88。
 

提示：

1 <= items.length <= 1000
items[i].length == 2
学生的 ID 在 1 到 1000 之间
学生的分数在 1 到 100 之间
每个学生至少有五个分数

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/high-five
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>> &items)
    {
        map<int, vector<int>> scores;
        for (int i = 0; i < items.size(); i++) {
            if (scores.find(items[i][0]) == scores.end()) {
                scores[items[i][0]] = vector<int>();
            }
            scores[items[i][0]].push_back(items[i][1]);
        }

        // average score
        vector<vector<int>> ret;
        for (int i = 0; i < scores.size(); i++) {
            vector<int> stuAllScores = scores[i];
            sort(stuAllScores.begin(), stuAllScores.end(), greater<int>());
            int sum = 0;
            for (int j = 0; j < 5; j++) {
                sum += stuAllScores[i];
            }
            ret[i] = vector<int>();
            ret[i].push_back(sum / 5);
        }
        return ret;
    }
};

int main()
{

    vector<vector<int>> items = {{ 1, 91 },
                                 { 1, 92 },
                                 { 2, 93 },
                                 { 2, 97 },
                                 { 1, 60 },
                                 { 2, 77 },
                                 { 1, 65 },
                                 { 1, 87 },
                                 { 1, 100 }};
    Solution s;
    vector<vector<int>> ret =  s.highFive(items);
    cout << ret[0][0] << endl;
    return 0;
}