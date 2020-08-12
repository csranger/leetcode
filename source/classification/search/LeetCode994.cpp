//
// Created by zhaohailong on 2020/8/11.
//

#include <vector>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int fresh = 0;
        vector<pair<int, int>> rotVec;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                }
                if (grid[i][j] == 2) {
                    rotVec.push_back(make_pair(i, j));
                }
            }
        }
        if (fresh == 0) {
            return 0;
        }
        vector<vector<int>> visit;
        for (int i = 0; i < grid.size(); i++) {
            visit.push_back(vector<int>(grid[i].size(), 0));
        }
        return Bfs(grid, visit, rotVec, fresh);
    }

    int Bfs(vector<vector<int>> &grid, vector<vector<int>> &visit, vector<pair<int, int>> &begin, int fresh)
    {
        queue<pair<int, int>> searchQueue;
        for (int i = 0; i < begin.size(); i++) {
            searchQueue.push(make_pair(begin[i].first, begin[i].second));
            visit[begin[i].first][begin[i].second] = 1;
        }

        int time = 0;
        while (!searchQueue.empty()) {
            static const int dx[] = { -1, 1, 0, 0 };
            static const int dy[] = { 0, 0, -1, 1 };

            int cnt = searchQueue.size();
            for (int i = 0; i < cnt; i++) {
                int x = searchQueue.front().first;
                int y = searchQueue.front().second;
                searchQueue.pop();

                for (int j = 0; j < 4; j++) {
                    int newX = x + dx[j];
                    int newY = y + dy[j];

                    if (newX < 0 || newY < 0 || newX >= grid.size() || newY >= grid[newX].size()) {
                        continue;
                    }
                    if (visit[newX][newY] == 0 && grid[newX][newY] == 1) {
                        searchQueue.push(make_pair(newX, newY));
                        visit[newX][newY] = 1;
                        fresh--;
                    }
                }
            }
            time++;
            if (fresh <= 0) {
                break;
            }
        }
        if (fresh > 0) {
            return -1;
        }
        return time;
    }
};