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
    vector<vector<char>> maze_;
    int sx_;
    int sy_;
    int gx_;
    int gy_;
    vector<vector<int>> d_;  // 记录距离并标记是否访问过


    bool solve(int N, int M, vector<vector<char>> &maze, int sx, int sy, int gx, int gy) {
        N_ = N, M_ = M;
        maze_.assign(maze.begin(), maze.end());
        sx_ = sx, sy_ = sy, gx_ = gx, gy_ = gy;
        for (int i = 0; i < N_; i++) {
            for (int j = 0; j < M_; j++) {
                d_[i][j] = INF;
            }
        }
    }

    int bfs() {
        queue<P> qe;
        qe.push(make_pair(sx_, sy_));

        int step = 0;
        while (!qe.empty()) {
            int cx = qe.front().first;
            int cy = qe.front().second;
            for (int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if (d_[nx][ny] != INF) {
                    qe.push(make_pair(nx, ny));
                    d_[cx][cy] = step;
                }
            }
            ++step;
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



