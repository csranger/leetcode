//
// Created by zhaohailong on 2020/4/18.
//

#include <vector>
#include <queue>
#include <iostream>

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
                    Bfs(grid, visit, i, j);
                    numsOfIslands++;
                }
            }
        }
        return numsOfIslands;
    }

    void Bfs(vector<vector<char>> &grid, vector<vector<int>> &visit, int x, int y) {
        queue<pair<int, int>> searchQueue;
        searchQueue.push(make_pair(x, y));
        visit[x][y] = 1;

        static const int dx[] = {-1, 1, 0, 0};
        static const int dy[] = {0, 0, -1, 1};

        while (!searchQueue.empty()) {
            x = searchQueue.front().first;
            y = searchQueue.front().second;

            searchQueue.pop();

            for (int k = 0; k < 4; k++) {
                int newX = x + dx[k];
                int newY = y + dy[k];

                if (newX < 0 || newY < 0 || newX >= grid.size() || newY >= grid[newX].size()) {
                    continue;
                }
                if (grid[newX][newY] == '1' && visit[newX][newY] == 0) {
                    searchQueue.push(make_pair(newX, newY));
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