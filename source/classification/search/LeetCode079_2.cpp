//
// Created by zhaohailong on 2020/9/13.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<char>> m_board;
    string m_word;

    bool exist(vector<vector<char>> &board, string word) {
        m_board = board;
        m_word = std::move(word);  // 避免拷贝
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == m_word[0]) {
                    int step = 0;
                    vector<vector<int>> visit(board.size(), vector<int>(board[0].size(), 0));
                    if (Dfs(i, j, visit, step)) return true;
                }
            }
        }
        return false;
    }

    bool Dfs(int x, int y, vector<vector<int>> &visit, int step) {
        static int dx[] = {-1, 1, 0, 0};
        static int dy[] = {0, 0, -1, 1};

        visit[x][y] = 1;
        if (m_board[x][y] != m_word[step]) {
            return false;
        }
        if (step == m_word.size() - 1) {
            return true;
        }

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX < 0 || newY < 0 || newX >= m_board.size() || newY >= m_board[newX].size() ||
                visit[newX][newY] == 1) {
                continue;
            }

            if (Dfs(newX, newY, visit, step + 1)) {
                return true;
            }
            visit[newX][newY] = 0;
        }
        return false;
    }
};

int main() {
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                  {'S', 'F', 'C', 'S'},
                                  {'A', 'D', 'E', 'E'}};
    Solution s;
    string word = "ABCCED";
    cout << s.exist(board, word) << endl;

    return 0;
}