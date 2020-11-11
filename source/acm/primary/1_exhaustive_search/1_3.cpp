//
// Created by zhaohailong on 2020/11/9.
//

// BFS
// 迷宫的最短路径；起点到终点的最小步数，假设起点一定可以移动到终点。
// '#','.','S','G'分别代表墙壁、通道、起点、终点
// 限制条件
// N, M <= 100

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 100000000;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

using P = pair<int, int>;

class Solution {
public:
    int N_;
    int M_;
    vector<vector<char>> maze_; // 迷宫
    int sx_;                    // 起点
    int sy_;
    int gx_;                    // 终点
    int gy_;
    vector<vector<int>> d_;     // 记录距离并标记是否访问过


    bool solve(int N, int M, vector<vector<char>> &maze, int sx, int sy, int gx, int gy) {
        N_ = N, M_ = M;
        maze_.assign(maze.begin(), maze.end());
        sx_ = sx, sy_ = sy, gx_ = gx, gy_ = gy;
        for (int i = 0; i < N_; i++) {
            d_.push_back(vector<int>());
            for (int j = 0; j < M_; j++) {
                d_[i].push_back(INF);
            }
        }

        int res = bfs();
        return res;
    }

    // 返回终点到起点之前的最短距离
    // 如无法达到，则是 INF
    int bfs() {
        queue<P> que;
        // 起点加入队列，距离设为0
        que.push(P(sx_, sy_));
        d_[sx_][sy_] = 0;

        while (!que.empty()) {
            // 取出队列最前端元素
            P p = que.front();
            que.pop();

            // 到达终点，结束搜索
            if (p.first == gx_ && p.second == gy_) {
                break;
            }

            // 四个方向循环搜索
            for (int i = 0; i < 4; i++) {
                int nx = p.first + dx[i];
                int ny = p.second + dy[i];
                // 判断是否可以移动以及是否已经访问过
                if (nx >= 0 && ny >= 0 && nx < N_ && ny < M_ && maze_[nx][ny] != '#' && d_[nx][ny] == INF) {
                    // 可以移动的话，加入队列 且 距离是到p的距离+1
                    que.push(P(nx, ny));
                    d_[nx][ny] = d_[p.first][p.second] + 1;
                }
            }
        }
        return d_[gx_][gy_];
    }
};

int main() {
    int N = 10, M = 10;
    vector<vector<char>> maze = {
            {'#', 'S', '#', '#', '#', '#', '#', '#', '.', '#'},
            {'.', '.', '.', '.', '.', '.', '#', '.', '.', '#'},
            {'.', '#', '.', '#', '#', '.', '#', '#', '.', '#'},
            {'.', '#', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'#', '#', '.', '#', '#', '.', '#', '#', '#', '#'},
            {'.', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
            {'.', '#', '#', '#', '#', '#', '#', '#', '.', '#'},
            {'.', '.', '.', '.', '#', '.', '.', '.', '.', '.'},
            {'.', '#', '#', '#', '#', '.', '#', '#', '#', '.'},
            {'.', '.', '.', '.', '#', '.', '.', '.', 'G', '#'}
    };

    int sx = 0;
    int sy = 1;
    int gx = 9;
    int gy = 8;
    Solution s;
    cout << s.solve(N, M, maze, sx, sy, gx, gy) << endl;

    return 0;
}



