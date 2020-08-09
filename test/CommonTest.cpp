#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        vector<vector<int>> visit;
        for (int i = 0; i < grid.size(); i++) {
            visit.push_back(vector<int>(grid[i].size(), 0));
        }

        int numsOfIslands = 0;
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

    void Dfs(vector<vector<char>> &grid, vector<vector<int>> &visit, int x, int y) {
        visit[x][y] = 1;

        static const int dx[] = {-1, 1, 0, 0};
        static const int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (newX < 0 || newY < 0 || newX >= grid.size() || newY >= grid[newX].size()) {
                continue;
            }
            if (grid[newX][newY] == '1' && visit[newX][newY] == 0) {
                Dfs(grid, visit, newX, newY);
            }
        }
    }
};