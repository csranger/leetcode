//
// Created by zhaohailong on 2020/8/8.
//

/*
假设你是一位顺风车司机，车上最初有 capacity 个空座位可以用来载客。由于道路的限制，车 只能 向一个方向行驶（也就是说，不允许掉头或改变方向，你可以将其想象为一个向量）。

这儿有一份乘客行程计划表 trips[][]，其中 trips[i] = [num_passengers, start_location, end_location] 包含了第 i 组乘客的行程信息：

必须接送的乘客数量；
乘客的上车地点；
以及乘客的下车地点。
这些给出的地点位置是从你的 初始 出发位置向前行驶到这些地点所需的距离（它们一定在你的行驶方向上）。

请你根据给出的行程计划表和车子的座位数，来判断你的车是否可以顺利完成接送所有乘客的任务（当且仅当你可以在所有给定的行程中接送所有乘客时，返回 true，否则请返回 false）。

 

示例 1：

输入：trips = [[2,1,5],[3,3,7]], capacity = 4
输出：false
示例 2：

输入：trips = [[2,1,5],[3,3,7]], capacity = 5
输出：true
示例 3：

输入：trips = [[2,1,5],[3,5,7]], capacity = 3
输出：true
示例 4：

输入：trips = [[3,2,7],[3,7,9],[8,3,9]], capacity = 11
输出：true

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/car-pooling
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <vector>
#include <queue>

using namespace std;

// pair<int, int> : pair<结束位置, 人数>
using Trip = pair<int, int>;

struct PQCmp {
    // 按照结束位置在优先队列里排序，最小优先队列
    bool operator()(Trip &p1, Trip &p2) {
        return p1.first > p2.first;
    }
};

class Solution {
public:
    bool carPooling(vector<vector<int>> &trips, int capacity) {
        sort(trips.begin(), trips.end(), Cmp);
        priority_queue<Trip, vector<Trip>, PQCmp> endLocationQe;
        int allNum = 0;
        for (auto &trip : trips) {
            int num = trip[0];
            int start = trip[1];
            int end = trip[2];
            if (endLocationQe.empty()) {
                endLocationQe.push(make_pair(end, num));
                allNum += num;
                if (allNum > capacity) {
                    return false;
                }
                continue;
            }
            while (!endLocationQe.empty() && start >= endLocationQe.top().first) {
                allNum -= endLocationQe.top().second;
                endLocationQe.pop();
            }
            allNum += num;
            endLocationQe.push(make_pair(end, num));
            if (allNum > capacity) {
                return false;
            }
        }
        return true;
    }

    static bool Cmp(vector<int> &v1, vector<int> &v2) {
        return v1[1] < v2[1];
    }
};