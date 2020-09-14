//
// Created by zhaohailong on 2020/9/13.
//

/*
我们有一系列公交路线。每一条路线 routes[i]上都有一辆公交车在上面循环行驶。例如，有一条路线
routes[0] = [1, 5, 7]，表示第一辆 (下标为0) 公交车会一直按照1->5->7->1->5->7->1->...的车站路线行驶。

假设我们从S车站开始（初始时不在公交车上），要去往T站。 
 期间仅可乘坐公交车，求出最少乘坐的公交车数量。返回 -1 表示不可能到达终点车站。

示例：

输入：
routes = [[1, 2, 7], [3, 6, 7]]
S = 1
T = 6
输出：2
解释：
最优策略是先乘坐第一辆公交车到达车站 7, 然后换乘第二辆公交车到车站 6。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bus-routes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iostream>

using namespace std;
using Route = set<int>;

class Solution {
public:
    map<Route, vector<Route>> graph;
    set<Route> begins;
    set<Route> ends;

    int numBusesToDestination(vector<vector<int>> &routes, int S, int T) {
        if (S == T) {
            return 0;
        }
        ConstructGraph(routes, S, T);
        set<Route> visit;
        int step = 1;
        if (!Bfs(visit, step)) return -1;
        return step;
    }

    bool Bfs(set<Route> &visit, int &step) {
        queue<Route> Q;
        for (auto &it : begins) {
            if (ends.count(it)) {
                return true;
            }
            visit.emplace(it);
            Q.push(it);
        }

        while (!Q.empty()) {
            int size = Q.size();
            for (int i = 0; i < size; i++) {
                Route cur = Q.front();
                for (auto &it : graph[cur]) {
                    if (visit.count(it)) continue;
                    if (ends.count(it)) {
                        step++;
                        return true;
                    }
                    visit.emplace(it);
                    Q.push(it);
                }
                Q.pop();
            }
            step++;
        }
        return false;
    }

    void ConstructGraph(vector<vector<int>> &routes, int S, int T) {
        vector<Route> allRoutes;
        for (int i = 0; i < routes.size(); i++) {
            Route temp;
            for (int j = 0; j < routes[i].size(); j++) {
                temp.insert(routes[i][j]);
            }
            allRoutes.push_back(temp);
            temp.clear();
        }
        for (int i = 0; i < allRoutes.size(); i++) {
            for (int j = i + 1; j < allRoutes.size(); j++) {
                if (Connect(allRoutes[i], allRoutes[j])) {
                    graph[allRoutes[i]].emplace_back(allRoutes[j]);
                    graph[allRoutes[j]].emplace_back(allRoutes[i]);
                }
            }
        }
        // 初始化起始搜索点和终点
        for (auto &it : allRoutes) {
            if (it.count(S)) {
                begins.emplace(it);
            }
            if (it.count(T)) {
                ends.emplace(it);
            }
        }
    }

    bool Connect(Route &r1, Route &r2) {
        for (auto &it : r1) {
            if (r2.count(it)) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    vector<vector<int>> routes = {{7,  12},
                                  {4,  5,  15},
                                  {6},
                                  {15, 19},
                                  {9,  12, 13}};
    int S = 15;
    int T = 12;
    Solution ss;
    cout << ss.numBusesToDestination(routes, S, T) << endl;

    return 0;
}