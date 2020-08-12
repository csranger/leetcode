//
// Created by zhaohailong on 2020/8/11.
//

#include <vector>
#include <queue>

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
                    maxArea = max(maxArea, Bfs(grid, visit, i, j));
                }
            }
        }
        return maxArea;
    }

    int Bfs(vector<vector<int>> &grid, vector<vector<int>> &visit, int x, int y) {
        queue<pair<int, int>> searchQueue;

        int ret = 1;
        searchQueue.push(make_pair(x, y));
        visit[x][y] = 1;

        while (!searchQueue.empty()) {
            x = searchQueue.front().first;
            y = searchQueue.front().second;

            searchQueue.pop();

            static const int dx[] = {-1,1,0,0};
            static const int dy[] = {0,0,-1,1};
            for (int i = 0; i < 4; i++) {
                int newX = dx[i] + x;
                int newY = dy[i] + y;

                if (newX < 0 || newY < 0 || newX >= grid.size() || newY >= grid[newX].size()) {
                    continue;
                }

                if (grid[newX][newY] == 1 && visit[newX][newY] == 0) {
                    ret++;
                    searchQueue.push(make_pair(newX, newY));
                    visit[newX][newY] = 1;
                }
            }
        }
        return ret;
    }
};

