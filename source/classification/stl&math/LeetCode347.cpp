//
// Created by zhaohailong on 2020/9/7.
//

#include <vector>
#include <iostream>
#include <queue>

using namespace std;
using Ele = pair<int, int>;  // 元素，出现次数

struct Cmp {   // 按照 Ele 第二个元素从大到小排序，最大堆/优先队列
    bool operator()(Ele &e1, Ele &e2) {
        return e1.second < e2.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        if (nums.size() == 1) {
            return nums;
        }
        sort(nums.begin(), nums.end());
        priority_queue<Ele, vector<Ele>, Cmp> pq;
        int lastNum = nums[0];
        int cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (lastNum == nums[i]) {
                cnt++;
                continue;
            }
            pq.push(make_pair(lastNum, cnt));
            lastNum = nums[i];
            cnt = 1;
        }

        pq.push(make_pair(lastNum, cnt));

        // 取出前 k 个元素
        vector<int> topEle;
        for (int i = 0; i < k; i++) {
            int ele = pq.top().first;
            topEle.push_back(ele);
            pq.pop();
        }
        return topEle;
    }
};

int main()
{
//    vector<int> nums = {1, 1, 1, 2, 2, 3};
//    int k = 2;
//    Solution s;
//    vector<int> ret =  s.topKFrequent(nums, k);
//    for (int i = 0; i < ret.size(); i++) {
//        cout << ret[i] << endl;
//    }

//    vector<int> nums = {1};
//    int k = 1;
//    Solution s;
//    vector<int> ret =  s.topKFrequent(nums, k);
//    for (int i = 0; i < ret.size(); i++) {
//        cout << ret[i] << endl;
//    }

    vector<int> nums = {-1,-1};
    int k = 1;
    Solution s;
    vector<int> ret =  s.topKFrequent(nums, k);
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << endl;
    }



    return 0;
}