//
// Created by zhaohailong on 2020/8/5.
//

/*
给定一个会议时间安排的数组，每个会议时间都会包括开始和结束的时间 [[s1,e1],[s2,e2],...] (si < ei)，
为避免会议冲突，同时要考虑充分利用会议室资源，请你计算至少需要多少间会议室，才能满足这些会议安排。

示例 1:

输入: [[0, 30],[5, 10],[15, 20]]
输出: 2
示例 2:

输入: [[7,10],[2,4]]
输出: 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/meeting-rooms-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
    int minMeetingRooms(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), Compare);              // 根据会议开始时间排序
        priority_queue<int, vector<int>, greater<int>> rooms;     // 记录会议室结束时间最小值
        for (int i = 0; i < intervals.size(); i++) {
            vector<int> meeting = intervals[i];
            int start = meeting[0];
            int end = meeting[1];
            if (rooms.empty()) {
                rooms.push(end);
            } else if (rooms.top() <= start) {         // 有空会议室
                rooms.pop();
                rooms.push(end);
            } else {
                rooms.push(end);
            }
        }
        return rooms.size();
    }

    static bool Compare(vector<int> &v1, vector<int> &v2) {
        return v1[0] < v2[0];
    }
};
