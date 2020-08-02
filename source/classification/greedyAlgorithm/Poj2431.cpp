//
// Created by zhaohailong on 2020/8/2.
//

/*
已知一条公路上，有一个起点与一个终点，这之间有n个加油站；已知从这n个加油站到终点的距离d与各个加油站可以加油的量 l,
起点位置至终点的距离L与起始时刻油箱中汽油量P；假设使用1个单位的汽油即走一个单位的距离，油箱没有上线，最少加几次油，
可以从起点开至终点？(如果无法到达，返回-1)
  start(16)              A(2)    B(5) C(3)        D(4)     End
     |____________________|________|__|____________|________|
           10                  4    1        6          4
       L = 25
       p = 16
       stop = {{15, 2},{11, 5},{10, 3},{4,  4}}    pair<加油站至终点距离，加油站可加汽油量>
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    // L: 起点到终点间距离
    // p: 起点初始的汽油量
    // pair<int, int>: pair<加油站至终点距离，加油站可加汽油量>
    int getMinimunStop(int L, int p, vector<pair<int, int>> &stop) {
        priority_queue<int> qe;             // 存储油量的最大堆
        int ret = 0;                        // 加油次数
        stop.push_back(make_pair(0, 0)); //将终点作为一个停靠点，添加至stop数组
        sort(stop.begin(), stop.end(), cmp);
        //  遍历各个停靠点
        for (int i = 0; i < stop.size(); i++) {
            int dis = L - stop[i].first;       // 从起点走到此处消耗了多少油
            // 需要加油
            while (!qe.empty() && p < dis) {
                p = p + qe.top();
                qe.pop();
                ret++;
            }
            // 无油可加
            if (qe.empty() && p < dis) {
                return -1;
            }
            // 走到当前停靠点使用 p-dis 油
            p = p - dis;
            L = stop[i].first;
            qe.push(stop[i].second);
        }
        return ret;
    }

    static bool cmp(pair<int, int> &p1, pair<int, int> &p2) {
        return p1.first > p2.first;
    }
};

int main() {
    int L = 25;
    int p = 16;
    vector<pair<int, int>> stop = {{15, 2},{11, 5},{10, 3},{4,  4}};
    Solution s;
    cout << s.getMinimunStop(L, p, stop) << endl;
}