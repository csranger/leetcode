//
// Created by zhaohailong on 2020/8/11.
//

/*
给定一个包含了一些 0 和 1 的非空二维数组 grid 。

一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在水平或者竖直方向上相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。

找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为 0 。)

 

示例 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
对于上面这个给定矩阵应返回 6。注意答案不应该是 11 ，因为岛屿只能包含水平或垂直的四个方向的 1 。

示例 2:

[[0,0,0,0,0,0,0,0]]
对于上面这个给定的矩阵, 返回 0。

 

注意: 给定的矩阵grid 的长度和宽度都不超过 50。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-area-of-island
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        vector<vector<int>> visit;
        for (int i = 0; i < grid.size(); i++) {
            visit.push_back(vector<int>(grid[i].size(), 0));
        }
        int maxArea = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (visit[i][j] == 0 && grid[i][j] == 1) {
                    maxArea = max(maxArea, Dfs(grid, visit, i, j));
                }
            }
        }
        return maxArea;
    }

    int Dfs(vector<vector<int>> &grid, vector<vector<int>> &visit, int x, int y) {
        int ret = 1;
        visit[x][y] = 1;

        static const int dx[] = {-1, 1, 0, 0};
        static const int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX < 0 || newY < 0 || newX >= grid.size() || newY >= grid[newX].size()) {
                continue;
            }

            if (visit[newX][newY] == 0 && grid[newX][newY] == 1) {
                ret += Dfs(grid, visit, newX, newY);
            }
        }
        return ret;
    }
};













