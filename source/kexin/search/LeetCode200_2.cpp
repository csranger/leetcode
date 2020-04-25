//
// Created by zhaohailong on 2020/4/18.
//

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int numsOfIslands = 0;

        vector<vector<int>> visit;
        for (int i = 0; i < grid.size(); i++) {
            visit.push_back(vector<int>());
            for (int j = 0; j < grid[i].size(); j++) {
                visit[i].push_back(0);
            }
        }

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1' && visit[i][j] == 0) {
                    Bfs(grid, visit, i, j);
                    numsOfIslands++;
                }
            }
        }
        return numsOfIslands;
    }

private:
    void Bfs(vector<vector<char>> &grid, vector<vector<int>> &visit, int x, int y)
    {
        static const int dx[] = { -1, 1, 0, 0 };  // 方向数组
        static const int dy[] = { 0, 0, -1, 1 };

        queue<pair<int, int>> qe;    // 1. 搜索队列 qe，将待搜索的位置(x,y) push进入队列，并标记此位置
        qe.push(make_pair(x, y));
        visit[x][y] = 1;

        // 以 x,y 点开始广度优先搜索
        while (!qe.empty()) {
            x = qe.front().first;
            y = qe.front().second;   // 2. 只要队列不为空，取队列头部元素，按照方向数组的4个方向，扩展到4个新位置

            qe.pop();     // 弹出队列头部元素

            for (int i = 0; i < 4; i++) {
                int newX = dx[i] + x;
                int newY = dy[i] + y;

                if (newX < 0 || newX >= grid.size() || newY < 0 || newY >= grid[newX].size()) {// 3. 新位置不在地图范围内则忽略
                    continue;
                }

                if (visit[newX][newY] == 0 && grid[newX][newY] == '1') {// 4. 新的点没有被搜索过，且新位置可到达，则将此位置push进入队列
                    qe.push(make_pair(newX, newY));
                    visit[newX][newY] = 1;
                }
            }
        }
    }
};

int main()
{
    vector<vector<char>> grid;
    vector<string> str = { "11000", "11000", "00100", "00011" };
    for (int i = 0; i < str.size(); i++) {
        grid.push_back(vector<char>());
        for (int j = 0; j < str[i].size(); j++) {
            grid[i].push_back(str[i][j]);
        }
    }

    Solution s;
    cout << s.numIslands(grid) << endl;

    return 0;
}