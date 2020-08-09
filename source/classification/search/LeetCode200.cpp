//
// Created by zhaohailong on 2020/4/17.
//

/*
给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，
并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。

示例 1:

输入:
11000
11000
00100
00011

输出: 1
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        // 初始化 visit
        vector<vector<int>> visit;
        for (int i = 0; i < grid.size(); i++) {
            visit.push_back(vector<int>(grid[i].size(), 0));
        }

        int numsOfIslands = 0;
        // 遍历地图上所有点，如果当前点是陆地，且未被搜索过，调用搜索接口，完成搜索后 numsOfLands++
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1' && visit[i][j] == 0) {
                    Dfs(grid, visit, i, j);
                    numsOfIslands++;
                }
            }
        }
        return numsOfIslands;
    }

private:
    // 以 x,y 点开始在 grid 上进行深度搜索
    void Dfs(vector<vector<char>> &grid, vector<vector<int>> &visit, int x, int y) {
        visit[x][y] = 1;             // 1. 标记当前位置已被搜索

        static const int dx[] = {-1, 1, 0, 0};    // 利用方向数组探索上下左右四个方向，上(x-1,y)下(x+1,y)左(x,y-1)右(x,y+1)
        static const int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int newX = dx[i] + x;           // 2. 按照方向数组的4个方向，扩展4个新位置
            int newY = dy[i] + y;

            if (newX < 0 || newX >= visit.size() || newY < 0 || newY >= visit[newX].size()) {// 3.新位置不在范围内，忽略
                continue;
            }

            if (visit[newX][newY] == 0 && grid[newX][newY] == '1') { // 4. 新的点没有被搜索过，且新位置可到达，继续DFS该位置
                Dfs(grid, visit, newX, newY);
            }
        }
    }
};

int main() {
    vector<vector<char>> grid;
    char str[10][10] = {"11000", "11000", "00100", "00011"};
    for (int i = 0; i < 4; i++) {
        grid.push_back(vector<char>());
        for (int j = 0; j < 5; j++) {
            grid[i].push_back(str[i][j]);
        }
    }

    Solution s;
    cout << s.numIslands(grid) << endl;

    return 0;
}