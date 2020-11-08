//
// Created by zhaohailong on 2020/11/9.
//


// DFS
// POJ2386
// 大小 N✖️M 的院子，下雨积水。八连通的积水认为连在一起。求有多少水洼？'W'表示积水，'.'表示没有积水
// 八连通指下图中相对 W 的 * 部分
//      * * *
//      * W *
//      * * *
// 限制条件
// N, M <= 100

#include <iostream>
#include <vector>

using namespace std;

const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

class Solution {
public:
    vector<vector<char>> field_;
    int N_;
    int M_;

    int solve(int N, int M, vector<vector<char>> &field) {
        N_ = N;
        M_ = M;
        field_.assign(field.begin(), field.end());

        int res = 0;
        for (int i = 0; i < N_; i++) {
            for (int j = 0; j < M_; j++) {
                if (field_[i][j] == 'W') {
                    dfs(i, j);
                    res++;
                }
            }
        }
        return res;
    }

    void dfs(int x, int y) {
        field_[x][y] = '.';

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N_ && ny >= 0 && ny < M_ && field_[nx][ny] == 'W') {
                dfs(nx, ny);
            }
        }
    }

};

int main() {
    vector<vector<char>> field = {
            {'W', '.', '.', '.', '.', '.', '.', '.', '.', 'W', 'W', '.'},
            {'W', '.', '.', '.', '.', '.', '.', '.', '.', 'W', 'W', '.'},
            {'W', '.', '.', '.', '.', '.', '.', '.', '.', 'W', 'W', '.'},
            {'W', '.', '.', '.', '.', '.', '.', '.', '.', 'W', 'W', '.'},
            {'W', '.', '.', '.', '.', '.', '.', '.', '.', 'W', 'W', '.'},
            {'W', '.', '.', '.', '.', '.', '.', '.', '.', 'W', 'W', '.'},
            {'W', '.', '.', '.', '.', '.', '.', '.', '.', 'W', 'W', '.'},
            {'W', '.', '.', '.', '.', '.', '.', '.', '.', 'W', 'W', '.'},
            {'W', '.', '.', '.', '.', '.', '.', '.', '.', 'W', 'W', '.'},
            {'W', '.', '.', '.', '.', '.', '.', '.', '.', 'W', 'W', '.'}
    };
    int N = field.size();
    int M = field[0].size();
    Solution s;
    cout << s.solve(N, M, field) << endl;

    return 0;
}



