#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
#include <set>

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
                if (visit[i][j] == 0 && grid[i][j] == '1') {
                    Bfs(grid, visit, i, j);
                    numsOfIslands++;
                }
            }
        }
        return numsOfIslands;
    }

    void Bfs(vector<vector<char>> &grid, vector<vector<int>> &visit, int x, int y)
    {
        queue<pair<int, int>> qe;
        qe.push(make_pair(x, y));

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!qe.empty()) {

            int a = qe.front().first;
            int b = qe.front().second;
            visit[a][b] = 1;
            qe.pop();
            for (int i = 0; i < 4; i++) {
                int newX = a + dx[i];
                int newY = b + dy[i];
                if (newX < 0 || newX >= grid.size() || newY < 0 || newY >= grid[newX].size()) {
                    continue;
                }
                if (grid[newX][newY] = '1' && visit[newX][newY] == 0) {
                    qe.push(make_pair(newX, newY));
                }
            }
        }

    }
};

int main()
{
    string str = "hello,world";
    cout << str.find('z') << endl;

    return 0;
}











