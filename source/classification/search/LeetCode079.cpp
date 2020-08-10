//
// Created by zhaohailong on 2020/8/10.
//

/*
给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

 

示例:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true
给定 word = "SEE", 返回 true
给定 word = "ABCB", 返回 false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-search
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>> &board, string word) {
        vector<vector<int>> visit;
        for (int i = 0; i < board.size(); i++) {
            visit.push_back(vector<int>(board[i].size(), 0));
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0]) {
                    return Dfs(board, visit, i, j, word, 0);
                }
            }
        }
        return false;
    }

    // 从起始点 x,y 开始搜索 word
    bool Dfs(vector<vector<char>> &board, vector<vector<int>> &visit, int x, int y, const string &word, int step) {
        if (board[x][y] != word[step] || step >= word.size()) {
            return false;
        }
        if (step == word.size() - 1) {
            return true;
        }

        visit[x][y] = 1;

        static const int dx[] = {-1, 1, 0, 0};
        static const int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX < 0 || newY < 0 || newX >= board.size() || newY >= board[newX].size()) {
                continue;
            }
            if (visit[newX][newY] == 0) {
                return Dfs(board, visit, newX, newY, word, step);
            }
        }
        return false;
    }
};




